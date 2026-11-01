/*
 * AtCoder ABC141 D — Powerful Discount Tickets（强力折扣券）
 * 来源：其他赛事原题，非 ADPC 原题。
 * 官方题面：https://atcoder.jp/contests/abc141/tasks/abc141_d?lang=en
 * 已核对官方规则、范围及样例，未在官方 OJ 提交。
 * 专题：备赛地图第 8 块，堆的动态最值应用。
 * 本次自行判断优惠券的分配策略、堆中存什么及如何更新。
 *
 * 有 N 件商品，第 i 件原价为 A[i]；你有 M 张折扣券。
 * 一件原价 X 的商品若使用 Y 张券，最终价格为 floor(X / 2^Y)。
 * 等价地，每用一张券，可把选中商品的当前价格除以 2 并向下取整。
 * 同一件商品可以使用多张券，每张券只能用一次，可自由分配。
 * 求购买全部 N 件商品所需的最少总金额。
 *
 * 输入：第一行 N M，第二行 N 个整数 A[i]。
 * 范围：1 <= N,M <= 100000，1 <= A[i] <= 1000000000。
 * 输出：最小总金额。
 *
 * 官方样例 1 输入：
 * 3 3
 * 2 13 8
 * 输出：
 * 9
 * 说明：对 13 使用两张券，价格变为 3；对 8 使用一张，变为 4。
 * 总金额 2+3+4=9。
 *
 * 官方样例 2 输入：
 * 4 4
 * 1 9 3 5
 * 输出：
 * 6
 *
 * 官方样例 3 输入：
 * 1 100000
 * 1000000000
 * 输出：
 * 0
 *
 * 官方样例 4 输入：
 * 10 1
 * 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000
 * 输出：
 * 9500000000
 *
 * 自行写完整 main、读入、算法与输出，不预填骨架。
 * 自测官方样例及至少两组自己的边界；同时检查时间与数值范围。
 */

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

long long discount_tickets(const vector<int>& a,int m)
{
    int n=a.size();
    long long res=0;
    priority_queue<long long> pq(a.begin(),a.end());
    for (int i=0;i<m;i++)
    {
        int currMax=pq.top();
        currMax=currMax/2;
        pq.pop();
        pq.push(currMax);
    }
    for (int i=0;i<n;i++)
    {
        res+=pq.top();
        pq.pop();
    }
    return res;
}

int main()
{
    int N,M;
    cin>>N>>M;
    vector<int> A(N);
    for (int& num:A)
    {
        cin>>num;
    }
    cout<<discount_tickets(A,M);
}