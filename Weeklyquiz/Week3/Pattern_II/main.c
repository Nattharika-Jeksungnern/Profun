#include <stdio.h>
#include <stdlib.h>
char board[10][10];
int main()
{
    memset(board, ' ', sizeof(board));
    board[0][0] = '/';
    board[0][1] = '\\';
    board[0][2] = '_';
    board[0][3] = '/';
    board[0][4] = '\\';
    board[1][0] = '|';
    board[1][4] = '|';
    board[2][0] = '|';
    board[2][1] = '0';
    board[2][3] = '0';
    board[2][4] = '|';
    board[3][0] = '|';
    board[3][2] = 4;
    board[3][4] = '|';
    board[4][0] = '\\';
    board[4][4] = '/';
    board[5][1] = '\\';
    board[5][2] = '_';
    board[5][3] = '/';
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%c",2);
        }
        printf("\n");
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int j = n - i; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("-(•-•)-\n");
    printf("(-[]-)\n");
    printf("\\_ToT_/\n");
    printf("0-0\n");
    return 0;
}
