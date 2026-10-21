// 一段日期内的累计预约人次（教练自命题）
// D 天，编号 1..D；N 条预约各在闭区间 [l,r] 内每天生效。
// Q 次查询，每次给出闭区间 [L,R]，输出这些天的预约数量之和。
// 同一条预约连续生效 3 天，在这 3 天合计贡献 3 人次。
// 1 <= D,Q <= 200000，0 <= N <= 200000；全部端点在 1..D，左端不大于右端。
// 要求总时间 O(D+N+Q)。
// 输入 D N Q，随后 N 行预约 l r，随后 Q 行查询 L R。
// 样例输入：
// 7 3 3
// 1 3
// 2 5
// 5 7
// 1 3
// 2 5
// 5 7
// 样例输出（每行一个）：5 7 4

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<long long> coverage_range_query(const vector<pair<int,int>>& bookings,int d)
{
    int n=bookings.size();
    vector<int> a(d+2,0);
    for (auto booking:bookings)
    {
        a[booking.first]++;
        a[booking.second+1]--;
    }
    vector<int> m(d+2,0);
    for (int i=1;i<d+1;i++)
    {
        m[i]=a[i]+m[i-1];
    }
    vector<long long> res(d+1,0);
    for (int i=1;i<d+1;i++)
    {
        res[i]=m[i]+res[i-1];
    }
    return res;
}

int main() {
    int d, n, q;
    cin >> d >> n >> q;
    vector<pair<int,int>> bookings(n);
    for (auto& booking : bookings) cin >> booking.first >> booking.second;
    vector<pair<int,int>> queries(q);
    for (auto& query : queries) cin >> query.first >> query.second;

    // TODO：可以复用自己在 coverage_query.cpp 中写的每日覆盖数预处理。
    // 按查询输入顺序输出各段日期内的累计预约人次，每行一个整数。
    vector<long long> res=coverage_range_query(bookings,d);
    for (auto query:queries)
    {
        cout<<res[query.second]-res[query.first-1]<<"\n";
    }
    return 0;
}
