
const int M;  // Resource
const int N;  // Process
int Available[M];   // available resources of each resource
int Allocation[N][M];
int Need[N][M];
int Work[M];
bool Finish[N];

// 初始化
Finish[N] = false
Work = Available-Allocation

// 寻找Pi, Need[i] < Work
找到：Finish = true
Work += Allocation
继续找
// 找不打


