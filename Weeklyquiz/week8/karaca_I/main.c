#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100000];
    scanf("%s", str);
    for (int i = 0; i < strlen(str); ++i)
    {
        if (str[i] == 'a') str[i] = '0';
        else if (str[i] == 'e') str[i] = '1';
        else if (str[i] == 'i') str[i] = '2';
        else if (str[i] == 'o') str[i] = '3';
        else if (str[i] == 'u') str[i] = '4';
    }
    for (int i = 0; i < strlen(str); ++i)
    {
        printf("%c", str[strlen(str) - 1 - i]);
    }
    printf("ace");
    return 0;
}
