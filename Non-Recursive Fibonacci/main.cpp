#include <iostream>
#include <time.h>

using namespace std;

unsigned long long FiboNR(unsigned long long  n)
{
    unsigned long long F0 = 0;
    unsigned long long F1 = 1;

    unsigned long long Fn = 0;

    for (unsigned long long i=2; i <= n; i++)
    {
        Fn = F0 + F1;

        F0 = F1;
        F1 = Fn;
    }

    return Fn;
}

int main()
{
    clock_t t;
    t = clock();

    unsigned long long n = 60;

    cout << "Fibonacci number is " << FiboNR(n) << endl;

    t = clock() - t;

    cout << "It took " << t << " clicks, or " << t * .001 << " seconds to compute." << endl;
    return 0;
}
