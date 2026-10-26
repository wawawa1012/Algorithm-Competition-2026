/*
 * E 语言学习中
 * 赛事：2024 年度第五届全国大学生算法设计与编程挑战赛（春季赛）。
 * 来源：ADPC 历届题，依据参赛者保存的原题截图和同页样例、范围整理。
 * 未登录官方 OJ 核对，不是教练自命题。
 * GitHub 存档（含题解，做题时只看本文件的题面）：
 * https://github.com/z01prime/z01prime.github.io/blob/86597054e31a7963f88403045a6c2a413e14e44e/2024/03/31/2024年度第五届全国大学生算法设计与编程挑战赛（春季赛）/index.html
 * 原题截图：https://s2.loli.net/2024/03/31/BfKLgsRpVimIlYM.png
 *
 * 今日 ADPC 混合识别训练，不提前给出算法分类或判定方法。
 *
 * 题意转述：
 * 有一种仅由 H、X 两个字符组成的语言，具有以下等价规则：
 * 1. HH 等价于 X，可以互相替换。
 * 2. XX 等价于 H，可以互相替换。
 * 3. 可以在任意位置加入 HHH。
 * 4. 可以在任意位置加入 XXX。
 * 规则可以嵌套、重复应用。
 *
 * 给定两串 S、T，有 q 次询问。
 * 每次给定 a b c d，判断 S[a..b] 和 T[c..d] 是否等价。
 * 下标从 1 开始，左右端点均包含；各次询问不修改原串。
 * 等价输出 YES，否则输出 NO，每个答案占一行。
 *
 * 输入：第一行 S，第二行 T，第三行 q，随后 q 行各四个整数 a b c d。
 * 范围（同页参赛记录）：1 <= |S|, |T| <= 100000，1 <= q <= 1000000。
 * S、T 只包含 H、X；所有区间合法且非空。
 *
 * 原题样例 1 输入：
 * H
 * X
 * 1
 * 1 1 1 1
 * 输出：
 * NO
 *
 * 原题样例 2 输入：
 * XXXHHHHXH
 * XXXXH
 * 4
 * 7 9 2 5
 * 7 9 1 4
 * 1 7 2 5
 * 1 7 2 4
 * 输出：
 * YES
 * NO
 * YES
 * NO
 *
 * 自行写完整程序；自测两个样例及至少两组边界反例。
 */

#include <iostream>
#include <vector>
using namespace std;

vector<bool> language(string S,string T,const vector<pair<int,int>>& s,const vector<pair<int,int>>& t)
{
    int q=s.size();
    vector<bool> res(q);
    vector<int> pre_sum1(S.size()+1,0);
    vector<int> pre_sum2(T.size()+1,0);
    for (int i=1;i<S.size()+1;i++)
    {
        int currNum = (S[i-1] == 'X') ? 1 : 2;
        pre_sum1[i]=pre_sum1[i-1]+currNum;
    }
    for (int j=1;j<T.size()+1;j++)
    {
        int currNum = (T[j-1] == 'X') ? 1 : 2;
        pre_sum2[j]=pre_sum2[j-1]+currNum;
    }
    for (int i=0;i<q;i++)
    {
        int si=pre_sum1[s[i].second]-pre_sum1[s[i].first-1];
        int ti=pre_sum2[t[i].second]-pre_sum2[t[i].first-1];
        res[i]=(si-ti)%3==0;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S,T;
    int q;
    cin>>S>>T>>q;
    vector<pair<int,int>> s(q),t(q);
    for (int i=0;i<q;i++)
    {
        cin>>s[i].first>>s[i].second>>t[i].first>>t[i].second;
    }
    vector<bool> res=language(S,T,s,t);
    for (bool val:res)
    {
        if (val) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}
