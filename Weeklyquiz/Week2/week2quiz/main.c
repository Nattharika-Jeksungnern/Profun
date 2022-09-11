#include <stdio.h>


int main()
{
    int arr[10],b;
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &b);
        arr[i] = b;

    }
    for (int i = 0; i < 10; i+=2)
    {
        sum += arr[i];
    }
    for (int i = 1; i < 10; i+=2)
    {
        sum -= arr[i];
    }
    printf("%d", sum);
    return 0;
}
