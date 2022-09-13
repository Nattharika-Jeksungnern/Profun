#include <iostream>

using namespace std;
int board[8][8];
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        int x,y;
        cin >> x >> y;
        --x,--y;
        // x
        for (int i = 0; i < 8; ++i)
        {
            if (board[x][i] == 1) continue;
            else
            {
                cnt++;
                board[x][i] = 1;
            }
        }

        // y
        for (int i = 0; i < 8; ++i)
        {
            if (board[i][y] == 1) continue;
            else
            {
                cnt++;
                board[i][y] = 1;
            }
        }

    }
    // count 0;
    /*
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 0) cnt++;
        }
    }*/
    cout << 64 - cnt;
    return 0;
}
