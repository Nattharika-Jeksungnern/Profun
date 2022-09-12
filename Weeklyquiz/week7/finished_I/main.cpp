#include <iostream>
#include <ctype.h>
using namespace std;

int main()
{
    while(true)
    {
        string str;
        cin >> str;
        if (str == "finished") break;
        else
        {
            str[0] = toupper(str[0]);
            for (int i = 1; i < str.size(); ++i)
            {
                str[i] = tolower(str[i]);
            }
            cout << str << ' ';
        }
    }
    return 0;
}
