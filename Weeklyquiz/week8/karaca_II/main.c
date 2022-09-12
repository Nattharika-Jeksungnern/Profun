#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100000];
    scanf("%s", str);
    int l = strlen(str) - 1;
    for (int i = l; i >= 0; --i)
    {
        if (str[i] == 'a') str[i] = '0';
        else if (str[i] == 'e') str[i] = '1';
        else if (str[i] == 'i') str[i] = '2';
        else if (str[i] == 'o') str[i] = '3';
        else if (str[i] == 'u') str[i] = '4';
        printf("%c", str[i]);
    }
    printf("aca");
    return 0;
}
