#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    scanf("%s",&s[0]);
    int l = strlen(s);
    for (int i = l - 1; i >= 0; --i)
    {
        printf("%c", s[i]);
    }
    return 0;
}
