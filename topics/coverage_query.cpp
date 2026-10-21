// 每日预约数量查询（教练自命题）
// 一共有 D 天，编号 1..D。
// N 条预约，每条给出闭区间 [l,r]，表示该预约在这些天均生效。
// Q 次查询，每次给出一天 t，输出当天有多少条预约生效。
// 1 <= D,Q <= 200000，0 <= N <= 200000；1 <= l <= r <= D，1 <= t <= D。
// 要求总时间 O(D+N+Q)。
// 输入：D N Q，随后 N 行 l r，随后 Q 行查询日期 t。
// 样例输入：
// 7 3 4
// 1 3
// 2 5
// 5 7
// 1
// 3
// 5
// 7
// 样例输出（每行一个）：1 2 2 1

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

vector<int> coverage_query(const vector<pair<int,int>>& bookings,int d)
{
    vector<int> a(d+2,0);
    for (auto event:bookings) //O(N)
    {
        a[event.first]++;
        a[event.second+1]--;
    }
    vector<int> m(d+2,0);
    for (int i=1;i<d+1;i++)//O(D)
    {
        m[i]=a[i]+m[i-1];
    }
    return m;
}

int main() {
    int d, n, q;
    cin >> d >> n >> q;
    vector<pair<int,int>> bookings(n);
    for (auto& booking : bookings) cin >> booking.first >> booking.second;
    vector<int> queries(q);
    for (auto& day : queries) cin >> day;
    // 预处理：得到每一天的预约数量
    vector<int> m = coverage_query(bookings, d);

    // 回答查询，按顺序输出
    for (int day : queries) {
        cout << m[day] << '\n';
    }

    // TODO：预处理每天的预约数量，按输入顺序回答查询，每行一个整数。
    return 0;
}
