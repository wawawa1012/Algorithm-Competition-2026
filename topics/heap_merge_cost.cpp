/*
 * 按规则合并果子
 * 来源：教练自命题，经典合并模型的堆操作入门版，非 ADPC 原题。
 * 专题：备赛地图第 8 块，堆 / 优先队列。
 * 目标：用小根堆维护当前所有堆的重量，练习取出、删除、重新加入。
 * 此题直接规定合并规则，只计算执行结果，不要求证明最优合并策略。
 *
 * 有 n 堆果子，第 i 堆重量为 a[i]。
 * 只要还剩至少两堆，就执行一次操作：
 * 取出当前重量最小的两堆，合并成一堆，放回剩余的堆中。
 * 本次费用等于新堆的重量。直到只剩一堆，求所有操作费用之和。
 * 重量相同的两堆仍是不同的堆；新合成的堆参与后续操作。
 *
 * 输入：第一行 n，第二行 n 个整数 a[i]。
 * 范围：1 <= n <= 100000，1 <= a[i] <= 1000000000。
 * 输出：累计合并费用。重量与累计费用注意数值范围。
 *
 * 样例输入：
 * 4
 * 1 2 3 4
 * 样例输出：
 * 19
 * 说明：
 * 1+2=3，费用 3，剩下 3、3、4；
 * 3+3=6，费用 6，剩下 4、6；
 * 4+6=10，费用 10；总费用 3+6+10=19。
 *
 * 自行写完整 main、读入、算法与输出。
 * 自测样例及至少两组边界，如只有一堆、重量很大。
 */
#include <queue>
#include <iostream>
#include <vector>
#include <functional>
using namespace std;

long long heap_merge_cost(const vector<int>& a)
{
    long long cost_res=0;
    priority_queue<long long,vector<long long>,greater<>> pq;
    for (int num:a)
    {
        pq.push(num);
    }
    while (pq.size()!=1)
    {
        long long numA=pq.top();
        pq.pop();
        long long numB=pq.top();
        pq.pop();
        cost_res+=numA+numB;
        pq.push(numA+numB);
    }
    return cost_res;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for (int& num:a)
    {
        cin>>num;
    }
    cout<<heap_merge_cost(a);
}