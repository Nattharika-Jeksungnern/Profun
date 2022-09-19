#include <iostream>
#include <string.h>
using namespace std;
int board[8][8];
int check[8][8];
int main()
{
    //memset(check, 1, sizeof(check));
    int n;
    cin >> n;
    int blank = 64;
    int x, y;
    for (int i = 0; i < n; ++i)
    {
        cin >> y >> x;
        --y,--x;
        for (int j = 0; j < 8; ++j)
        {
            if (check[y][j] == 0)
            {
                --blank;
                check[y][j] = 1;
            }
        }
        for (int j = 0; j < 8; ++j)
        {
            if (check[j][x] == 0)
            {
                --blank;
                check[j][x] = 1;
            }
        }
        int temp_y = y;
        int temp_x = x;
        while ( temp_y >= 0 && temp_x >= 0)
        {
            if (check[temp_y][temp_x] == 0)
            {
                --blank;
                check[temp_y][temp_x] = 1;
            }
            --temp_y;
            --temp_x;
        }

        temp_y = y;
        temp_x = x;
        while (temp_y >= 0 && temp_x < 8)
        {
            if (check[temp_y][temp_x] == 0)
            {
                --blank;
                check[temp_y][temp_x] = 1;
            }
            --temp_y;
            ++temp_x;
        }

        temp_y = y;
        temp_x = x;
        while (temp_y < 8 && temp_x < 8)
        {
            if (check[temp_y][temp_x] == 0)
            {
                --blank;
                check[temp_y][temp_x] = 1;
            }
            ++temp_y;
            ++temp_x;
        }
        temp_y = y;
        temp_x = x;
        while (temp_y < 8 && temp_x >= 0)
        {
            if (check[temp_y][temp_x] == 0)
            {
                --blank;
                check[temp_y][temp_x] = 1;
            }
            ++temp_y;
            --temp_x;
        }

    }
    cout << blank;
    return 0;
}
