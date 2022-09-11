#include <iostream>

using namespace std;
int N = 9;
int board[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
void print_board()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

// check this grid, row, column have this num or not
bool gridsafe(int row, int col, int num)
{
    //check row
    for (int i = 0; i < N; ++i)
    {
        if (board[row][i] == num)
            return false;
    }

    // check column
    for (int i = 0; i < N; ++i)
    {
        if (board[i][col] == num)
            return false;
    }

    // check grid
    int startrow = row - row % 3;
    int startcol = col - col % 3;

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i + startrow][j + startcol] == num)
                return false;
        }
    }

    // this grid is 0
    return true;
}

bool sudokusolve(int row, int col)
{
    //check ว่าสุด board ทั้งหมดยัง
    if (row == N - 1 && col == N)
        return true;

    //reset col if col  == N && row++
    if (col == N)
    {
        row++;
        col = 0;
    }
    // check this grid > 0
    if (board[row][col] > 0)
        return sudokusolve(row, col + 1);

    // this grid is 0, put number in this grid
    for (int num = 1; num < N + 1; ++num)
    {
        //start check that grid at row, col is safe or not
        if (gridsafe(row, col, num)) // can put that num in this grid
        {
            board[row][col] = num;

            // check that num is a true position
            // start from this grid until last grid at (8,8) if
            if (sudokusolve(row, col + 1))
                return true;
        }

        // if this position is false position
        board[row][col] = 0;
    }

    //can not solve
    return false;
}
int main()
{
    if (sudokusolve(0,0))
        print_board();
    else cout << "can not find solution\n";
    return 0;
}
