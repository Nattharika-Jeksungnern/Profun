#include <iostream>
#define N 9
using namespace std;

int grid[N][N];

bool havecol(int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;

    return false;
}


bool haverow(int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}


bool havebox(int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}



void sudokuGrid()
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {

            cout << grid[row][col] <<" ";
        }
        cout << '\n';
    }
}



bool findEmptyPlace(int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}




bool isValidPlace(int row, int col, int num)
{
    return !haverow(row, num) && !havecol(col, num) && !havebox(row - row%3 , col - col%3, num);
}


bool solveSudoku()
{
    int row, col;
    if (!findEmptyPlace(row, col))
        return true;
    for (int num = 1; num <= 9; num++)
    {

        if (isValidPlace(row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku())
                return true;

            grid[row][col] = 0;
        }
    }
    return false;
}





int main() {
    int in;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> in;
            grid[i][j] = in;
        }
    }
    if (solveSudoku())
        sudokuGrid();
    else
        cout << "No solution exists";
}

