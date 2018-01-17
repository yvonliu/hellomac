#include <iostream>

using namespace std;

void testAsm(uint32_t x)
{
    uint32_t dwRes;
 
    // Assumes dwSomeValue is not zero.
    asm ("bsfl %1,%0"
        : "=r" (dwRes)
        : "r" (x)
        : "cc");

    cout << x << " : " << dwRes << endl;
}

void asmRDTSC()
{
    long long tick;

    asm (
        "rdtsc \n\t"
        "shl $32, %%rdx \n\t"
        "or %%rdx, %0"
        : "=a" (tick)
        :
        : "rdx"
    );
    cout << "tick: " << tick << endl;
}