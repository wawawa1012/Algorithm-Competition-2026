// AtCoder ABC229 D - Longest X
// 官方题面：https://atcoder.jp/contests/abc229/tasks/abc229_d?lang=en
// S 仅含 X 和 .，可以把至多 K 个 . 改成 X。
// 输出操作后最长连续 X 段的长度，可以不做操作。
// 1 <= |S| <= 200000，0 <= K <= 200000。
// 输入：第一行 S，第二行 K；输出一个整数。
// 样例 1：XX...X.X.X. / 2，输出 5。
// 样例 2：XXXX / 200000，输出 4。

#include <iostream>
#include <string>
using namespace std;
class solution
{
public:
    int longest_x(const string& s,int k)
    {
        //hint:变长滑动窗口
        int l=0;
        int dotCount=0;
        int longestX=0;
        for (int r=0;r<s.size();r++)
        {
            if (s[r]=='.')
            {
                dotCount++;
            }
            while(dotCount>k)
            {
                if (s[l]=='.') dotCount--;
                l++;
            }
            longestX=max(longestX,r-l+1);
        }
        return longestX;
    }
};

int main() {
    string s;
    int k;
    cin >> s >> k;

    // TODO：计算并输出答案。
    solution S;
    cout<<S.longest_x(s,k);
    return 0;
}
