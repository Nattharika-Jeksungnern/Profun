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
    if (num == 1)
    {
        if (board[0][0] == 'X' || board[0][0] == 'O') return 1;
        else return 0;
    }
    else if (num == 2)
    {
        if (board[0][1] == 'X' || board[0][1] == 'O') return 1;
        else return 0;
    }
    else if (num == 3)
    {
        if (board[0][2] == 'X' || board[0][2] == 'O') return 1;
        else return 0;
    }
    else if (num == 4)
    {
        if (board[1][0] == 'X' || board[1][0] == 'O') return 1;
        else return 0;
    }
    else if (num == 5)
    {
        if (board[1][1] == 'X' || board[1][1] == 'O') return 1;
        else return 0;
    }
    else if (num == 6)
    {
        if (board[1][2] == 'X' || board[1][2] == 'O') return 1;
        else return 0;
    }
    else if (num == 7)
    {
        if (board[2][0] == 'X' || board[2][0] == 'O') return 1;
        else return 0;
    }
    else if (num == 8)
    {
        if (board[2][1] == 'X' || board[2][1] == 'O') return 1;
        else return 0;
    }
    else if (num == 9)
    {
        if (board[2][2] == 'X' || board[2][2] == 'O') return 1;
        else return 0;
    }
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
                if (num == 1) board[0][0] = 'O';
                else if (num == 2) board[0][1] = 'O';
                else if (num == 3) board[0][2] = 'O';
                else if (num == 4) board[1][0] = 'O';
                else if (num == 5) board[1][1] = 'O';
                else if (num == 6) board[1][2] = 'O';
                else if (num == 7) board[2][0] = 'O';
                else if (num == 8) board[2][1] = 'O';
                else if (num == 9) board[2][2] = 'O';

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
                if (num == 1) board[0][0] = 'X';
                else if (num == 2) board[0][1] = 'X';
                else if (num == 3) board[0][2] = 'X';
                else if (num == 4) board[1][0] = 'X';
                else if (num == 5) board[1][1] = 'X';
                else if (num == 6) board[1][2] = 'X';
                else if (num == 7) board[2][0] = 'X';
                else if (num == 8) board[2][1] = 'X';
                else if (num == 9) board[2][2] = 'X';
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
