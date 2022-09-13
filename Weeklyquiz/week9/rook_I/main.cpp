#include <iostream>

using namespace std;
int board[8][8];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x,y;
        cin >> x >> y;
        --x,--y;
        // x
        for (int i = 0; i < 8; ++i)
        {
            board[x][i] = 1;
        }

        // y
        for (int i = 0; i < 8; ++i)
        {
            board[i][y] = 1;
        }

    }
    // count 0;
    int cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if (board[i][j] == 0) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
