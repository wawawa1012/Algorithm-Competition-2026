/*
 * AtCoder ABC086 C — Traveling（旅行计划）
 * 来源：其他赛事原题，非 ADPC 原题。
 * 官方题面：https://atcoder.jp/contests/abc086/tasks/arc089_a?lang=en
 * 已核对官方规则、数据范围及三个样例；未在官方 OJ 提交。
 * 2026-11-11 短混合第三题，不提前标算法或提供 IO 骨架。
 *
 * 在无限大的整数坐标平面上，你在时刻 0 位于 (0,0)。
 * 每秒必须向上、下、左、右之一移动一格，不能原地停留。
 * 计划要求在时刻 t_i 恰好位于 (x_i,y_i)，共有 N 项要求。
 * 判断能否用同一条行走路线满足全部要求，只输出 Yes 或 No。
 * 途中位置没有限制，也不必输出路线。
 *
 * 输入：第一行 N，随后 N 行，每行 t_i x_i y_i。
 * 范围：1<=N<=100000，1<=t_i<=100000，
 *       0<=x_i,y_i<=100000，t_i 严格递增。
 *
 * 官方样例 1：
 * 输入：
 * 2
 * 3 1 2
 * 6 1 1
 * 输出：
 * Yes
 *
 * 官方样例 2：
 * 输入：
 * 1
 * 2 100 100
 * 输出：
 * No
 *
 * 官方样例 3：
 * 输入：
 * 2
 * 5 1 1
 * 100 1 1
 * 输出：
 * No
 *
 * 写完整程序，自测三个样例和至少两组边界；可查语法表。
 */

#include <iostream>
#include <vector>
using namespace std;

bool traveling(const vector<int>& x,const vector<int>& y,const vector<int>& t)
{
    bool res=true;
    int n=x.size();
    //降维
    vector<int> place(n,0);
    for (int i=1;i<n;i++)
    {
        place[i]=x[i]+y[i];
    }
    for (int i=1;i<n;i++)
    {
        int distance = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
        if (abs(place[i]-place[i-1])%2!=(t[i]-t[i-1])%2||(t[i]-t[i-1])<distance) res=false;
    }
    return res;
}

int main()
{
    int N;
    cin>>N;
    vector<int> x(N+1,0),y(N+1,0),t(N+1,0);
    for (int i=1;i<N+1;i++)
    {
        cin>>t[i]>>x[i]>>y[i];
    }
    if (traveling(x,y,t)) cout<<"Yes";
    else cout<<"No";
}
