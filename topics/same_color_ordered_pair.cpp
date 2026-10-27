/*
 * 同色有序配对
 * 来源：教练自命题，不是 ADPC 历届原题。
 * 专题：备赛地图第 6 块，按类别维护信息；衔接第 10 块 DP 候选优化。
 * 目标：独立确定判断后续配对时，需要保留前面哪些信息。
 * 不预填 IO、状态定义或算法。
 *
 * 题意：
 * 有 n 条按顺序排列的记录。第 i 条有颜色 c[i] 和两个整数 a[i]、b[i]。
 * 必须选出两个位置 i、j，满足 i<j 且 c[i]=c[j]。
 * 这一对的得分为 a[i]+b[j]。
 * 注意：使用前一个位置的 a 和后一个位置的 b，同一位置不能配给自己。
 * 求所有合法配对中的最大得分；若不存在合法配对，输出 IMPOSSIBLE。
 * 必须选择一对，因此有合法配对时，即使最大得分为负，也要输出该负数。
 *
 * 输入：
 * 第一行 n k，表示记录数量和颜色数量。
 * 接下来 n 行，第 i 行为 c[i] a[i] b[i]。
 * 范围：1 <= n,k <= 200000，1 <= c[i] <= k。
 * -1000000000 <= a[i],b[i] <= 1000000000。
 * 输出：最大得分，或 IMPOSSIBLE。
 *
 * 样例 1 输入：
 * 5 2
 * 1 3 8
 * 2 10 2
 * 1 7 4
 * 2 -2 9
 * 1 5 -1
 * 输出：
 * 19
 * 说明：选第 2、4 条记录，颜色都为 2，得分 10+9=19。
 *
 * 样例 2 输入：
 * 2 1
 * 1 -5 -4
 * 1 -3 -7
 * 输出：
 * -12
 *
 * 自行写完整程序；自测两个样例及至少两组自己构造的边界反例。
 */
#include <iostream>
#include <vector>
using namespace std;

int same_color_ordered_pair(const vector<int>& a,const vector<int>& b,const vector<int>& c,int k)
{
    int n=a.size();
    vector<int> dp(n,-2000000001); //以i结尾的max
    vector<int> best(k+1,-1000000001);
    int m=dp[0];
    best[c[0]]=max(best[c[0]],a[0]);
    for (int i=1;i<n;i++)
    {
        if (best[c[i]]!=-1000000001)
        {
            dp[i]=b[i]+best[c[i]];
        }
        m=max(m,dp[i]);
        best[c[i]]=max(best[c[i]],a[i]);
    }
    return m;
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n),b(n),c(n);
    for (int i=0;i<n;i++)
    {
        cin>>c[i]>>a[i]>>b[i];
    }
    int res=same_color_ordered_pair(a,b,c,k);
    if (res!=-2000000001) cout<<res;
    else cout<<"IMPOSSIBLE";
}
