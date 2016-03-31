#include <cstdlib> // for random numbers
#include <vector> // for vectors
#include <iostream>
#include <time.h>
#include <stdlib.h>


using namespace std;


vector<vector<int>> BuildSequence(int Dimension, int NumberOfTests)
{
    vector<vector<int>> Sequence(NumberOfTests, vector<int>(Dimension)); // create 10000 x n matrix

    // INITIALIZE RANDOM SEED
    srand (time(NULL));

    for(int ColumnAssign = 0; ColumnAssign < Dimension; ++ColumnAssign) // assigns random values to entries of 10000 x n matrix
    {
        for(int RowAssign=0; RowAssign < NumberOfTests; ++RowAssign)
        {
            Sequence[RowAssign][ColumnAssign] = rand() % 1000000;
        }
    }

    return Sequence;
}

long long int InsertionMod (vector<vector<int>> A, int n, int RowCounter) // Modify this algorithm to return the number of steps
{
    long long int steps = 0;

    int i,j, temp;

    A[RowCounter][0]=-32768; //smallest possible integer using 2 bytes integer representation

    for (i=1; i<=n; i++)
    {
        j=i;

        while ( A[RowCounter][j] < A[RowCounter][j-1])
        { // swap
            temp=A[RowCounter][j];

            A[RowCounter][j]=A[RowCounter][j-1];
            A[RowCounter][j-1]=temp;
            j--;

            steps += 1;
        }

        steps += 1;
    }

    return steps;
}


int AverageCase(int n)
{
    int RealAverage = n*n/4 + 3*n/4;
}



int main()
{
    int NumberOfTests = 100000; // Number of lists we test, is the rows of Sequence


    cout << "Input Size, Calculated Average, Real Average" << endl;

    int Dimension[3] = {100, 500, 1000};

    // Build a vector of 10000 rows of Dimension random numbers.
    vector<vector<int> > Sequence = BuildSequence(Dimension[2], NumberOfTests);

    cout << "Built sequence" << endl;

    for(int DimensionCounter = 0; DimensionCounter < 7; DimensionCounter++)
    {
        cout << "Running test " << DimensionCounter << endl;

        int Dim = Dimension[DimensionCounter];

        long long int CalculatedAverage = 0;

        // Find the number of steps it takes to run each algorithm
        for(int TestNumber = 0; TestNumber < NumberOfTests; TestNumber++)
        {
            cout << "Calculating number of steps for " << TestNumber << endl;

            long long int steps = InsertionMod(Sequence, Dim, TestNumber);

            CalculatedAverage += steps;
        }

        CalculatedAverage /= NumberOfTests;

        cout << "Calculated average for " << DimensionCounter << endl;

        int RealAverage = AverageCase(Dim);

        cout << Dim << ", " << CalculatedAverage << ", " << RealAverage << endl;
    }
}
