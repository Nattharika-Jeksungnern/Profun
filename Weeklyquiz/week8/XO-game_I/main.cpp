#include <iostream>
#include <string.h>
using namespace std;

int check_x_axis(char board[][3], int x, char check)
{
    if (x == 3) return 0;
    int check_x = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[x][i] == check) check_x++;
    }
    if (check_x == 3) return 1;
    else return check_x_axis(board, ++x, check);
}

int check_y_axis(char board[][3], int y, char check)
{
    if (y == 3) return 0;
    int check_y = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][y] == check) check_y++;
    }
    if (check_y == 3) return 1;
    else return check_y_axis(board, ++y, check);
}

int check_oblique_left(char board[][3], char check)
{
    int left = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][i] == check) ++left;
    }
    if (left == 3) return 1;
    else return 0;
}

int check_oblique_right(char board[][3], char check)
{
    int right = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][3 - 1 - i] == check) ++right;
    }
    if (right == 3) return 1;
    else return 0;
}

int is_have_space(char board[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == '-') return 1;
        }
    }
    return 0;
}

int is_duplicate(char board[][3], int num)
{
    --num;
    int i = num/3;
    int j = num % 3;
    if (board[i][j] == 'X' || board[i][j] == 'O') return 1;
    else return 0;
}

int print_board(char board[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
}
int main()
{
    char board[3][3];
    memset(board, '-', sizeof(board));
    bool play = true;
    int player = 0; // 0 -> X, 1 -> O
    /*
    cout << check_x_axis(board, 0, '-') << '\n';
    cout << check_x_axis(board, 0, 'X') << '\n';
    cout << check_x_axis(board, 0, 'O') << '\n';
    cout << check_y_axis(board, 0, '-') << '\n';
    cout << check_y_axis(board, 0, 'X') << '\n';
    cout << check_y_axis(board, 0, 'O') << '\n';
    cout << check_oblique_left(board, '-') << '\n';
    cout << check_oblique_left(board, 'X') << '\n';
    cout << check_oblique_left(board, 'O') << '\n';
    cout << check_oblique_right(board, '-') << '\n';
    cout << check_oblique_right(board, 'X') << '\n';
    cout << check_oblique_right(board, 'O') << '\n';

    for (int i = 0; i < 9; ++i)
    {
        cout << is_duplicate(board, i) << '\n';
    }*/
    int EndGame = 0;
    while(play)
    {
        //O
        if (player)
        {
            int num;
            cout << "Player 2 select 1 - 9 : ";
            cin >> num;
            if (is_duplicate(board, num))
            {
                player = 1;
                cout << "Please the others.\n";
            }
            else
            {
                --num;
                board[num/3][num%3] = 'O';
                print_board(board);
                if (check_x_axis(board, 0, 'O') || check_y_axis(board, 0, 'O') || check_oblique_left(board, 'O') || check_oblique_right(board, 'O'))
                {
                    cout << "Player 2 WIN!!!!\n";
                    play = 0;
                    EndGame = 1;
                }
                else if (!is_have_space(board))
                {
                    cout << "TIE!!!!\n";
                    play = 0;
                    EndGame = 1;
                }
                player = 0;
            }
        }
        else
        {
            int num;
            cout << "Player 1 select 1 - 9 : ";
            cin >> num;
            if (is_duplicate(board, num))
            {
                player = 0;
                cout << "Please the others.\n";
            }
            else
            {
                --num;
                board[num/3][num%3] = 'X';
                print_board(board);
                if (check_x_axis(board, 0, 'X') || check_y_axis(board, 0, 'X') || check_oblique_left(board, 'X') || check_oblique_right(board, 'X'))
                {
                    cout << "Player 1 WIN!!!!\n";
                    play = 0;
                    EndGame = 1;
                }
                else if (!is_have_space(board))
                {
                    cout << "TIE!!!!\n";
                    play = 0;
                    EndGame = 1;
                }
                player = 1;
            }
        }
        if (EndGame)
        {
            cout << "Want to play it again?? : YES/NO\n";
            string s;
            cin >> s;
            if (s == "YES")
            {
                play = 1;
                player = 0;
                memset(board, '-', sizeof(board));
                EndGame = 0;
            }

        }
    }
    return 0;
}
