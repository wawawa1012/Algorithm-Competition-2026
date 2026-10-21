// AtCoder ABC188 D - Snuke Prime
// 官方题面：https://atcoder.jp/contests/abc188/tasks/abc188_d?lang=en
// N 项服务，第 i 项在第 a_i 天到第 b_i 天每天使用，首尾两天均包含。
// 单独购买该服务每天花 c_i；购买会员每天花 C，可覆盖当天所有服务。
// 会员可在任意一天开始时开通、任意一天结束时取消，没有额外费用。
// 求满足全部使用计划的最低总费用。
// 1 <= N <= 200000；1 <= C,c_i <= 1e9；1 <= a_i <= b_i <= 1e9。
// 输入 N C，随后 N 行 a_i b_i c_i；输出一个整数。
// 官方样例 1：
// 2 6
// 1 2 4
// 2 2 4
// 输出：10

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Service {
    long long a, b, c;
};

long long snuck_prime(const vector<Service>& services,long long C)
{
    long long res=0;
    map<long long, long long> mp;
    for (auto service:services)
    {
        long long a=service.a;
        long long b=service.b;
        long long c=service.c;
        mp[a]+=c;
        mp[b+1]-=c;
    }

    long long currCost=0,prev=0;
    for (const auto& event:mp)
    {
        long long date=event.first;
        // [prev,date) 内费用没有变化，共 date-prev 天，先结算这一段。
        res+=(date-prev)*min(currCost,C);
        // date 当天的费用变化，从这一段结束后开始生效。
        currCost+=event.second;
        prev=date;
    }
    return res;
}

int main() {
    int n;
    long long c;
    cin >> n >> c;
    vector<Service> services(n);
    for (auto& service : services) {
        cin >> service.a >> service.b >> service.c;
    }
    cout<<snuck_prime(services,c);
    return 0;
}
