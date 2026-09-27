//
// Created by A on 2026/9/27.
//
#include <string>
#include <stack>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int eval_rpn(const vector<string>& tokens)
    {
        stack<int> st;

        for (const string& token : tokens)
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);
            }
            else
            {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main()
{
    int n;
    cin>>n;
    vector<string> tokens(n);
    for (string& token:tokens)
    {
        cin>>token;
    }
    solution s;
    cout<<s.eval_rpn(tokens);
}