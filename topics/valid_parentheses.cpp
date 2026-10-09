//
// Created by A on 2026/10/4.
//
#include <iostream>
#include <stack>
using namespace std;

class solution
{
public:
    bool is_valid(const string& strs)
    {
        stack<char> st;
        for (char c:strs)
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
            default:
                if (!st.empty()&&st.top()==c) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};
int main()
{
    string strs;
    cin>>strs;
    solution s ;
    if (s.is_valid(strs))
        cout<<"YES";
    else cout<<"NO";
    return 0;
}