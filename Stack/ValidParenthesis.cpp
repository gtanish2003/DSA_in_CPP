#include <iostream>
#include <stack>
using namespace std;

bool isParenthesis(string expression)
{
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // if opening bracket, stack push
        //  if closing bracket,  stack top check and then popped out

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        {
            // for closing bracket

            if (!s.empty())
            {
                char top = s.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }

    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main(){
    string check="{{[()]}}";
    if (isParenthesis(check)){
        cout<<"String is well balanced!!!"<<endl;

    }
    else{
        cout<<"String is not balanced!!"<<endl;
    }
}