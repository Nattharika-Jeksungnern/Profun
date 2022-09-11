#include <iostream>

using namespace std;

int n;
int board[1000][1000];


// x axis
int x_axis(int x, int score)
{
    int check = 0;
    ++x;
    if (x == n) return 1;
    if (x < n)
    {
        for (int y = 0; y < n; ++y)
        {
            check += board[x][y];
        }

        if (check == score)
        {
            return x_axis(x,score);
        }
        else
        {
            return 0;
        }
    }
}

// y axis
int y_axis(int y, int score)
{
    int check = 0;
    ++y;
    if ( y == n) return 1;
    if (y < n)
    {
        for (int x = 0; x < n; ++x)
        {
            check += board[x][y];
        }
        if (check == score)
        {
            return y_axis(y,score);
        }
        else
        {
            return 0;
        }
    }
}

// Oblique left
int oblique_left(int score)
{
    int check = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i == j) check += board[i][j];
        }
    }
    if (check == score) return 1;
    else return 0;
}

// Oblique right
int oblique_right(int x, int y, int score, int check)
{
    if ( x == n || y == -1)
    {
        if (check == score) return 1;
        else return 0;
    }
    else
    {
        check += board[x][y];
        return oblique_right(++x, --y, score, check);
    }
}

int main()
{
    cin >> n;
    int m;
    // input
    for (int i = 0; i < n; ++ i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> m;
            board[i][j] = m;
        }
    }

    // x axis
    int score = n*(n*n+1)/2;

    if (x_axis(0, score) && y_axis(0,score) && oblique_left(score) && oblique_right(0, n - 1, score, 0)) cout << "YES.";
    else cout << "NO.";
    return 0;
}
