//
// Created by A on 2026/10/15.
//
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class solution
{
public:
    void remove_adjacent_duplicates(string s)
    {
        stack<char> st;
        for (char& c:s)
        {
            if (!st.empty()&&st.top()==c)
            {
                st.pop();
            }
            else st.push(c);
        }
        int size=st.size();
        vector<char> newS(size);
        if (size==0) cout<<"EMPTY";
        else
        {
            for (int i=size-1;i>=0;i--)
            {
                newS[i]=st.top();
                st.pop();
            }
            for (char& c:newS)
            {
                cout<<c;
            }
        }
    }
};

int main()
{
    string str;
    cin>>str;
    solution s;
    s.remove_adjacent_duplicates(str);
    return 0;
}