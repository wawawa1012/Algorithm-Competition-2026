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
    bool stack_permutation(const vector<int>& nums)
    {
        int n=nums.size();
        stack<int> st;
        int curr_target=0;
        for (int i=0;i<n;i++)
        {
            st.push(i + 1);
            while (!st.empty() && st.top() == nums[curr_target])
            {
                st.pop();
                curr_target++;
            }
        }
        return st.empty();
    }
};

int main()
{
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int& num:nums)
    {
        cin>>num;
    }
    solution s;
    if (s.stack_permutation(nums)) cout<<"YES";
    else cout<<"NO";
}