#include <iostream>

using namespace std;

int board[8][8];
int main()
{
    int n;
    cin >> n;
    int y,x;
    for (int i = 0; i < n; ++i)
    {
        cin >> y >> x;
        --y,--x;
        for (int j = 0; j < 8; ++j)
        {
            board[y][j] = 1;
        }
        for (int j = 0; j < 8; ++j)
        {
            board[j][x] = 1;
        }
        int temp_y = y;
        int temp_x = x;
        while ( temp_y >= 0 && temp_x >= 0)
        {
            board[temp_y][temp_x] = 1;
            --temp_y;
            --temp_x;
        }

        temp_y = y;
        temp_x = x;
        while (temp_y >= 0 && temp_x < 8)
        {
            board[temp_y][temp_x] = 1;
            --temp_y;
            ++temp_x;
        }

        temp_y = y;
        temp_x = x;
        while (temp_y < 8 && temp_x < 8)
        {
            board[temp_y][temp_x] = 1;
            ++temp_y;
            ++temp_x;
        }
        temp_y = y;
        temp_x = x;
        while (temp_y < 8 && temp_x >= 0)
        {
            board[temp_y][temp_x] = 1;
            ++temp_y;
            --temp_x;
        }

    }
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
    int sum = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 0) sum++;
        }
    }
    cout << sum;
    return 0;
}
