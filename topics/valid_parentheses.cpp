//
// Created by A on 2026/9/27.
//
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class solution
{
public:
    bool valid_parentheses(string s)
    {
        stack<char> st;
        for (char& c : s)
        {
            switch (c)
            {
            case '{':
                st.push('}');
                break;
            case '[':
                st.push(']');
                break;
            case '(':
                st.push(')');
                break;
            }
            if (c == '}'|| c == ']' || c == ')')
            {
                if (!st.empty()&&st.top() == c)
                    st.pop();
                else return false;
            }
        }
        if (st.empty()) return true;
        return false;
    }
};

int main()
{
    string s;
    cin >> s;
    solution so;
    if (so.valid_parentheses(s))cout << "yes";
    else cout << "no";
    return 0;
}
