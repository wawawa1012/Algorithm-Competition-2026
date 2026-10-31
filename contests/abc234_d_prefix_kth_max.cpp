/*
 * AtCoder ABC234 D — Prefix K-th Max
 * 来源：其他赛事原题，非 ADPC 原题。
 * 官方题面：https://atcoder.jp/contests/abc234/tasks/abc234_d?lang=en
 * 已核对官方题面、范围及两个样例，未在官方 OJ 提交。
 * 专题：备赛地图第 8 块，堆 / 优先队列的动态排名应用。
 * 目标：自行决定为了回答第 K 大，需要保留哪些信息。
 *
 * 给定 1 到 N 的一个排列 P 和整数 K。
 * 对每个 i=K,K+1,...,N，求前 i 个数中的第 K 大。
 * 每个前缀各输出一个答案，不改变原排列顺序。
 * 第 K 大：按从大到小排序后的第 K 个数。
 *
 * 输入：第一行 N K，第二行 P[1] ... P[N]。
 * 范围：1 <= K <= N <= 500000。
 * P 恰好包含 1 到 N 各一次，没有重复元素。
 * 输出：N-K+1 行，依次对应长度 K 到 N 的前缀。
 *
 * 官方样例 1 输入：
 * 3 2
 * 1 2 3
 * 输出：
 * 1
 * 2
 * 说明：前两个数 1、2 的第 2 大是 1；前三个数的第 2 大是 2。
 *
 * 官方样例 2 输入：
 * 11 5
 * 3 7 2 5 11 6 1 9 8 10 4
 * 输出：
 * 2
 * 3
 * 3
 * 5
 * 6
 * 7
 * 7
 *
 * 自行写完整 main、读入、算法和输出，不预填骨架。
 * 自测两个样例及至少两组边界，比如 K=1、K=N。
 */
#include <queue>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

vector<int> res;
void prefix_kth_max(const vector<int>& p,int k)
{
    int n=p.size();
    vector<int> pk(k);
    for (int i=0;i<k;i++)
    {
        pk[i]=p[i];
    }
    priority_queue<int,vector<int>,greater<int>> pq(pk.begin(),pk.end());
    res.push_back(pq.top());
    for (int i=k;i<n;i++)
    {
        pq.push(p[i]);
        if (pq.size()>k) pq.pop();
        res.push_back(pq.top());
    }
}

int main()
{
    int N,K;
    cin>>N>>K;
    vector<int> P(N);
    for (int& num:P)
    {
        cin>>num;
    }
    prefix_kth_max(P,K);
    for (int& num:res) cout<<num<< endl;
}
