#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int board[n][n];

    // input
    int a;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a;
            board[i][j] = a;
        }
    }

    int score = n*(n*n+1)/2;

    //check x axis, oblique left
    int check_x;
    bool x = true;
    int oblique_left = 0;
    bool left = true;
    int oblique_right = 0;
    bool right = true;

    for (int i = 0; i < n; ++i)
    {
        check_x = 0;
        for (int j = 0; j < n; ++j)
        {
            // x axis
            check_x += board[i][j];
            // oblique left
            if (i == j)
            {
                //cout << oblique_left << "-*-";
                oblique_left += board[i][j];
            }


        }
        if (check_x != score)
        {
            x = false;

        }
        // oblique right
        oblique_right += board[i][n - 1 - i];
    }
    if (oblique_left != score)
    {
        left = false;
    }
    if (oblique_right != score)
    {
        right = false;
    }
    int check_y; bool y = true;
    for (int i = 0; i < n; ++i)
    {
        check_y = 0;
        for (int j = 0; j < n; ++j)
        {
            check_y += board[j][i];
        }
        if (check_y != score)
        {
            y = false;
        }
    }
    if (x && left && right && y) cout << "YES.";
    else cout << "NO.";
    return 0;
}
