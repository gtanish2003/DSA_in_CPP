#include <iostream>
using namespace std;

int checkpalindrome(string &str, int i, int j)
{

    if (i > j)
        return -1;
    if (str[i] != str[j])
    {
        return -1;
        
    }
    else
    {
        checkpalindrome(str, i++, j--);
    }
    return 1;
}

int main()
{
    string name = "noon";
    int answer = checkpalindrome(name, 0, name.length() - 1);
    cout << answer << endl;
}