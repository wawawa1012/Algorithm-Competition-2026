//
// Created by A on 2026/10/15.
//
#include <iostream>
using namespace std;

class solution
{
public:
    int integer_sqrt(int n)
    {
        int left=0,right=32000;
        while (left<=right)
        {
            int mid=left+(right-left)/2;
            if (mid*mid<=n&&(mid+1)*(mid+1)>n) return mid;
            if ((mid+1)*(mid+1)<=n) left=mid+1;
            if (mid*mid>n) right=mid-1;
        }
        return -1;
    }
};

int main()
{
    int N;
    cin>>N;
    solution s;
    cout<<s.integer_sqrt(N);
    return 0;
}