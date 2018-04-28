#include <iostream>
#include <map>
#include <sys/time.h>
#include <queue>
#include <thread>
#include <unistd.h>
#include <mutex>
#include <atomic>

using namespace std;


typedef int TIMERID;

typedef void (*Function)();

struct Timer
{
    int id;
    int time;
    int interval;
    Function func;
    atomic<bool> valid;
    bool loop;
    Timer(int _id, int _interval, Function _func, bool _loop = false):id(_id), interval(_interval), func(_func), valid(true), loop(_loop) {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        int now = tv.tv_sec * 1000 + tv.tv_usec/1000;    // 以毫秒计
        time = now + interval;
    }
    void dump() {
        cout << "id = " << id << ", time = " << time << endl;
    }
};

struct cmp
{
    bool operator() (Timer* t1, Timer* t2)
    {
        return t1->time > t2->time;
    }
};

bool cmp2(Timer* t1, Timer* t2)
{
    return t1->time > t2->time;
}

mutex g_mtx;
atomic<bool> g_bExit(false);
int global_idx = 0;
map<int, Timer*> mTimers;
vector<Timer*> vTimers;

int StartTimer(int interval, Function func, bool loop) // 以毫秒计
{
    struct Timer *timer = new Timer(global_idx, interval, func, loop);
    mTimers[global_idx] = timer;    // 插入是LogN
    {
        unique_lock<mutex> lck(g_mtx);
        vTimers.push_back(timer);
        push_heap(vTimers.begin(), vTimers.end(), cmp2);
    }
    return global_idx++;
}

int Stop(int id)
{
    if(mTimers[id] != NULL)
    {
        // 直接从优先队列删除，自定义堆的话，可以更改值时间为最小后，自动调整，时间复杂度是logN
        // 先置为无效，在PerTickBookkeeping时删除
        mTimers[id]->valid = false;
        mTimers.erase(id);
    }
}

void PerTickBookkeeping()
{
    Timer *timer = NULL;
    {
        unique_lock<mutex> lck(g_mtx);
        if(!vTimers.empty())
        {
            pop_heap(vTimers.begin(), vTimers.end(), cmp2);
            timer = vTimers.back();
            if(timer == NULL)
            {
                vTimers.pop_back();    
            }
            else if(!timer->valid)
            {
                vTimers.pop_back();
                delete timer;
                timer = NULL;
            }
        }
    }
    if(timer != NULL)
    {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        int now = tv.tv_sec * 1000 + tv.tv_usec/1000;
        if(now > timer->time)
        {
            //timer->dump();
            timer->func();
            unique_lock<mutex> lck(g_mtx);
            vTimers.pop_back();
            if (timer->loop)
            {
                timer->time = now + timer->interval;
                vTimers.push_back(timer);
                push_heap(vTimers.begin(), vTimers.end(), cmp2);
            }
            else
            {
                delete timer;
                timer = NULL;
            }
        }
    }
}

void P1()
{
    cout << "P1--------------------->" << endl;
}
void P0()
{
    cout << "P0*********************>" << endl;
}

void P2()
{
    cout << "P2#####################>" << endl;
}

void work()
{
    while(!g_bExit)
    {
        PerTickBookkeeping();
        usleep(1000);
    }
}

int main()
{
    thread t1(work);
    TIMERID id1 = StartTimer(100, P0, true);
    TIMERID id2 =StartTimer(200, P1, true);
    TIMERID id3 = StartTimer(500, P2, true);

    sleep(5);
    Stop(id1);

    sleep(5);
    Stop(id2);
    
    sleep(5);
    Stop(id3);

    sleep(1);
    g_bExit = true;
    t1.join();
    return 0;
}
