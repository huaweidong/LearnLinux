#include <assert.h>
#include <stdio.h>

class UnShortPtr
{
public:
	UnShortPtr(unsigned char *pChar) {
		assert(pChar != 0 && (pChar+1) != 0);
		m_pChar = pChar;
    }
    unsigned short Get() const {
        return (*m_pChar) | (((unsigned short)*(m_pChar+1)) << 8);
    }
    unsigned short Set(unsigned short u) {
        assert(m_pChar != 0 && (m_pChar+1) != 0);
        m_pChar[0] = u & 0xFF;
        m_pChar[1] = (u >> 8) & 0xFF;
        return u;
    }
    UnShortPtr& operator ()() {
        return *this;
    }
	unsigned short operator *() const {
		return Get();
    }

    unsigned short operator ++() {  // 前置
        unsigned short u = Get();
        return Set(u+1);
    }

    unsigned short operator ++(int) {   // 后置
        unsigned short u = Get();
        Set(u+1);
        return u;
    }
    
private:
	unsigned char* m_pChar;
};

int main()
{
    unsigned char arr[2] = {0, 1};
    printf("%d\n", *(UnShortPtr)arr);
    printf("%d\n", ((UnShortPtr)arr)++);
    printf("%d\n", ++((UnShortPtr)arr));
    return 0;
}
