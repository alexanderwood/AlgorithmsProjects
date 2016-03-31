#include <iostream>
#include <cstdlib> // for random numbers
#include <cmath> // for math
#include <ctime> // for computing time

using namespace std;

int bound = 10000; // the upper bound on our random numbers

// return a uniformly distributed random number between
// 1 and some number, after the % sign.
int uniformRandom()
{
  return ( (int)(rand()%bound + 1) );
                /* rand()%k generates
                a random number between
                1 and k */
}

int main()
{
    const int n = 50; // Number of integers per list, is the columns of Sequence
    const int NumberOfTests = 10000; // Number of lists we test, is the rows of Sequence

    int hits = 0; // initialize the counter hits to 0

    int x = 0; // x is a random integer between 0 and bound
    srand(time(NULL));
    x = uniformRandom();

    cout << "A random integer x between 1 and " << bound << " is x=" << x << "." << endl;
    cout << "We are running the test on arrays of " << n << " integers " << NumberOfTests << " times." << endl;

            /* Generate a random sequence of integers between 0 and
            bound using a random number generator. Save this new
            sequence in a two dimensional array Sequence[10000][50]

            If x is equal to any of the numbers generated in the
            sequence increment hits by one (if x appears on the same
            sequence then do not increment hits every time)

            Repeat these steps 10000 times. */

    cout << endl;
    cout << "The program now creates Sequence[10000][n] and fills it with random integers between 0 and " << bound << "." << endl;

    int Sequence[NumberOfTests][n] = {0}; // create 10000 x n matrix

    for(int ColumnAssign = 0; ColumnAssign < n; ++ColumnAssign) // assigns random values to entries of 10000 x n matrix
    {
        for(int RowAssign=0; RowAssign < NumberOfTests; ++RowAssign)
        {
            Sequence[RowAssign][ColumnAssign] = uniformRandom();
        }
    }


    for(int Row = 0; Row < NumberOfTests; ++Row) // increments hits for each row which contains x
    {
        for(int Column = 0; Column < n; ++Column)
        {
            if (Sequence[Row][Column] == x)
            {
                hits++;
                break;
            }
        }
        // After break you end up here
    }

    cout << "hits = " << hits << endl;

    double doublehits = hits;
    double doubleNumberOfTests = NumberOfTests;
    double q = doublehits / doubleNumberOfTests;

    cout << "The average number of hits is A(n)= " << (( q /n )*(n*(n+1)/2)) + ((1-q)*n) << endl;
}
