//
// Created by A on 2026/10/18.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
    bool water_heater(vector<pair<pair<int,int>,int>>& people,int w)
    {
        const int n=people.size();
        sort(people.begin(),people.end(),[](const pair<pair<int,int>,int>& a,const pair<pair<int,int>,int>& b)
       {
          return a.first.second <b.first.second;
       });
        vector<pair<int,int>> beginTime(n);
        vector<pair<int,int>> endTime(n);
        for (int i=0;i<n;i++)
        {
            beginTime[i]={people[i].first.first,people[i].second};
            endTime[i]={people[i].first.second,people[i].second};
        }
        sort(beginTime.begin(),beginTime.end(),[](const pair<int,int>& a,const pair<int,int>& b)
        {
            return a.first<b.first;
        });
        long long currUsage=0;
        int b=0,e=0;
        for (int time=0;time<people[n-1].first.second;time++)
        {
            while (e<n&&endTime[e].first==time)
            {
                currUsage-=endTime[e].second;
                e++;
            }
            while(b<n&&beginTime[b].first==time)
            {
                currUsage+=beginTime[b].second;
                b++;
            }
            if (currUsage>w) return false;
        }
        return true;
    }
};

int main()
{
    int N,W;
    cin>>N>>W;
    vector<pair<pair<int,int>,int>> people(N);
    for (auto& person:people)
    {
        cin>>person.first.first>>person.first.second>>person.second;
    }
    solution s;
    if (s.water_heater(people,W)) cout<<"Yes";
    else cout<<"No";
}
