//
// Created by A on 2026/10/12.
//
//时间限制nlogn第一感觉像是预排序啊（因为没有什么其他的算法储备），然后再用双指针压缩
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int shopping_pair(vector<int>& products,int budget)
    {
        int max_val=-1;
        sort(products.begin(),products.end());
        int left=0,right=products.size()-1;
        while (left<right)
        {
            int currSum=products[left]+products[right];
            if (currSum>budget) right--;
            else
            {
                max_val=max(max_val,currSum);
                left++;
            }
        }
        return max_val;
    }
};

int main()
{
    int n,B;
    cin>>n>>B;
    vector<int> products(n);
    for (int& product:products)
    {
        cin>>product;
    }
    solution s;
    cout<<s.shopping_pair(products,B);
    return 0;
}