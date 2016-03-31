#include <iostream>
#include <cstdlib> // for random numbers
#include <cmath> // for math
#include <ctime> // for computing time

using namespace std;

int bound = 10000; // the upper bound on our random numbers

int Find(int x, int A[], int n) // array of size n
{
    int j;

    for(j=0; j < n; j++)
    {
        if (x == A[j])
        {
            return (j+1); // the position is 1 more than the index
        }
    }

    return 0; // x is not part of the array
}

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

    cout << "The calculated average is A(n)= " << (( q /n )*(n*(n+1)/2)) + ((1-q)*n) << endl;

    cout << "Next we want to find the real average." << endl;

        /* Using the sequences created, we will run algorithm Find
        10,000 times, each time using an input of Sequence[][]. Let
        total-steps be a variable that tells you the number of steps
        executed so far, and keep doing this until all 10,000 steps
        are executed.
        */

    int totalSteps = 0; // the number of steps executed so far

    for(int Row = 0; Row < NumberOfTests; ++Row) // adds total number of steps in rows where x appears
    {
        for(int Column = 0; Column < n; ++Column)
        {
            if (Sequence[Row][Column] == x)
            {
                totalSteps += Column + 1;

                //cout << "total steps after row " << Row + 1 << " is " << totalSteps << endl;

                break;
            }
        }
    }


    bool True = 0; // used in for loop to tell us if the row had x in it
                   // we add n to totalSteps for each row which does not
                   // contain x

    for(int Row = 0; Row < NumberOfTests; ++Row) // adds total number of steps in rows where x does not appear
    {
        for(int Column = 0; Column < n; ++Column)
        {
            if (Sequence[Row][Column] == x)
            {
                True = 1;
                //cout << "True changed to 1" << endl;

                break;
            }

            True = 0;
        }

        if (True == 0)
        {
            totalSteps += n;
            //cout << "--total steps after row " << Row + 1 << " is " << totalSteps << endl;
        }
    }

    double doubletotalSteps = totalSteps;

    cout << "total steps: " << totalSteps << endl;
    cout << "The real average A1(n) = " << doubletotalSteps / doubleNumberOfTests << endl;
}
