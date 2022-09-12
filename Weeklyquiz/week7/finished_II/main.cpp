#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    string ans[10000];
    int i = 0;
    while(true)
    {
        string str;
        cin >> str;
        if (str == "finished") break;
        else
        {
            if (str[0] >= 'a' && str[0] <= 'z')
                str[0] -= 32;
            for (int i = 1; i < str.size(); ++i)
            {
                if (str[i] >= 'A' && str[i] <= 'Z')
                    str[i] += 32;
            }
            ans[i] = str;
        }
        ++i;
    }
    for (int j = 0; j <= i; ++j)
    {
        cout << ans[j] << ' ';
    }
    return 0;
}
