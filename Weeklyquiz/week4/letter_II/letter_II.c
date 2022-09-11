#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10000];
    scanf("%s", &s[0]);
    int l = strlen(s);
    for (int i = 0; i < l; ++i)
    {
        printf("%c", s[l-1-i]);
    }
    return 0;
}
