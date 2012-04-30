#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_SIZE = 100;

int matrix[MAX_SIZE][MAX_SIZE] = {0};


void PrintMatrix(int matrix[][MAX_SIZE], int sizeOfMatrix)
{
    for (int i = 0; i < sizeOfMatrix; i ++)
    {
        for (int j = 0; j < sizeOfMatrix; j++)
        {
            printf("%3d", matrix[i][j]);
        }
        cout << endl;
    }
}


void FillMatrix(int mat[][MAX_SIZE], int sizeOfMat)
{
    int coordX = 0, coordY = 0;
    int count = sizeOfMat * sizeOfMat;
    int stepsCount = sizeOfMat; // number of iterations in current direction
    int stepPosition = 0; // number of current iteration in current derection
    int direction = 0;
    int stepChange = -1; // flag to show us, if we must change stepsCount

    for (int traveller = 1; traveller <= count; traveller++)
    {
        mat[coordX][coordY] = traveller;

        if (stepPosition < stepsCount - 1)
        {
            stepPosition ++;
        }
        else
        {
            stepPosition = 1;
            if (stepChange == 1)
            {
                stepsCount --;
            }

            stepChange = (stepChange + 1) % 2;
            direction = (direction + 1) % 4;
        }
        switch(direction)
        {
            case 0: coordY ++; break;
            case 1: coordX ++; break;
            case 2: coordY --; break;
            case 3: coordX --; break;
        }


    }

    PrintMatrix(mat, sizeOfMat);

}

int main()
{

    cout << "Enter a size of matrix: ";
    int sizeOfMatrix = 0;
    cin >> sizeOfMatrix;


    FillMatrix(matrix, sizeOfMatrix);

    return 0;
}
