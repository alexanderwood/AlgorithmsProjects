#include <iostream>
#include <time.h>

// This program uses recursive functions to calculate a number in the Fibonacci sequence

using namespace std;


unsigned long long FiboR(unsigned long long FibIndex)
{
    if (FibIndex < 2)
        return FibIndex;
    else
        return FiboR(FibIndex - 1) + FiboR(FibIndex - 2);
}

int main()
{
    clock_t t;
    t = clock();

/*    cout << "Enter 0-based index of desired Fibonacci number: ";
    int Index = 0;
    cin >> Index;
*/

 //   cout << "Calculating.." << endl;
    unsigned long long Index = 25;

    cout << "Fibonacci number is: " << FiboR(Index) << endl;

    t = clock() - t;

    cout << "It took " << t << " clicks, or " << t * .001;
    cout << " seconds to compute." << endl;
    return 0;
}
