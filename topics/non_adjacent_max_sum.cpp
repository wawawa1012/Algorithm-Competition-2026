/*
 * 不相邻取数
 * 来源：教练自命题（经典模型的独立题面），不是 ADPC 历届原题。
 * 专题：备赛地图第 10 块，基础动态规划；练习自行定义状态与转移。
 *
 * 有 n 个整数排成一行，可以选择其中任意多个数，但不能同时选择
 * 原数组中相邻的两个位置。每个位置最多选一次，也可以一个都不选。
 * 求所选数字之和的最大值；一个都不选时和为 0。
 *
 * 注意：这是按原数组的位置判断相邻，不是把相同数值视作同一位置。
 *
 * 输入：
 * 第一行一个整数 n。
 * 第二行 n 个整数 a[1]..a[n]。
 * 范围：1 <= n <= 200000，-1000000000 <= a[i] <= 1000000000。
 *
 * 输出：最大总和，一个整数。
 *
 * 样例 1 输入：
 * 5
 * 2 7 9 3 1
 * 样例 1 输出：
 * 12
 * 说明：选择原第 1、3、5 个位置，和为 2+9+1=12。
 *
 * 样例 2 输入：
 * 3
 * -5 -2 -8
 * 样例 2 输出：
 * 0
 *
 * 自行写完整 main、读入、算法和输出。
 * 自测：两个样例 + 至少两组边界反例。
 */

#include <iostream>
#include <vector>
using namespace std;
long long non_adjacent_max(const vector<int>& a)
{
    vector<long long>dp(a.size(),0);
    dp[1]=max(0,a[1]);
    for (int i=2;i<a.size();i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+max(a[i],0));
    }
    return dp[a.size()-1];
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for (int i=1;i<a.size();i++)
    {
        cin>>a[i];
    }
    cout<<non_adjacent_max(a);
}
