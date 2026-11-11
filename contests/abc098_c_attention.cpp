/*
 * AtCoder ABC098 C — Attention（选队长）
 * 来源：其他赛事原题，非 ADPC 原题。
 * 官方题面：https://atcoder.jp/contests/abc098/tasks/arc098_a?lang=en
 * 已实际核对原题规则、范围和三个官方样例；未在官方 OJ 提交。
 * 2026-11-11 短混合练习第二题，不提前标具体算法或给实现。
 *
 * N 个人从西到东（从左到右）站成一排，站位不能改变。
 * 字符串 S 表示他们的朝向：E 表示向东（右），W 表示向西（左）。
 * 选择其中一个人当队长，要求其余所有人都面朝队长所在的位置。
 * 队长本人朝哪边都可以，不计他转身。
 * 求最少需要多少人改变朝向。
 *
 * 输入：第一行 N，第二行长度为 N 的字符串 S，只含 E/W。
 * 范围：2 <= N <= 300000。
 * 输出：最少转身人数。
 *
 * 官方样例 1 输入：
 * 5
 * WEEWW
 * 输出：
 * 1
 * 说明：选从左数第 3 个人为队长，仅最左边的人需要转身。
 *
 * 官方样例 2 输入：
 * 12
 * WEWEWEEEWWWE
 * 输出：
 * 4
 *
 * 官方样例 3 输入：
 * 8
 * WWWWWEEE
 * 输出：
 * 3
 *
 * 自行选择方法，写完整 main、读入、算法和输出，不预填骨架。
 * 自测三个样例及至少两组边界，可查语法表，不看本题题解。
 */

#include <iostream>
#include <vector>
using namespace std;

/*int attention(const vector<char>& s)
{
    int n=s.size();
    vector<int> pre_sum(n,0);
    pre_sum[0]=s[0]=='W'?1:0;
    for (int i=1;i<n;i++)
    {
        if (s[i]=='W') pre_sum[i]=pre_sum[i-1]+1;
        else pre_sum[i]=pre_sum[i-1];
    }
    int res=n-1-pre_sum[n-1]+pre_sum[0];
    for (int i=1;i<n;i++)
    {
    int l = pre_sum[i-1];
    int r = (n-i-1) - (pre_sum[n-1] - pre_sum[i]);
        int curr=l+r;
        res=min(res,curr);
    }
    return res;
}*/

int attention(const vector<char>& s)
{
    int n=s.size();
    int res=1e9;
    int curr=0;
    for (int i=1;i<n;i++)
    {
        if (s[i]=='E') curr++;
    }
    res=min(res,curr);
    int pre_curr=res; //前一个人当队长时的转身数
    for (int i=1;i<n;i++)
    {
        int cur=0;
        if (s[i-1]=='W') cur++;
        if (s[i]=='E') cur--;
        pre_curr=pre_curr+cur;
        res=min(res,pre_curr);
    }
    return res;
}

int main()
{
    int N;
    cin>>N;
    vector<char> S(N);
    for (char& c:S)
    {
        cin>>c;
    }
    cout<<attention(S);
}