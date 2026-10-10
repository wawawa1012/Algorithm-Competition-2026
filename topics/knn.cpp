//
// Created by A on 2026/10/10.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int knn(int k,const vector<pair<pair<int,int>,int>>& pointSet,int x,int y)
    {
        int n=pointSet.size();
        vector<pair<pair<pair<int,int>,int>,int>> dist(n);
        for (int i=0;i<n;i++)
        {
            dist[i].first=pointSet[i];
            int px=pointSet[i].first.first;
            int py=pointSet[i].first.second;
            dist[i].second=(x-px)*(x-px)+(y-py)*(y-py);
        }
        sort(dist.begin(),dist.end(),[](auto& a,auto& b)
        {
            return a.second<b.second;
        });
        vector<int> cl;//存class
        for (int i=0;i<k;i++)
        {
            cl.push_back(dist[i].first.second);
        }
        int count=0;
        for (int& c:cl)
        {
            if (c==1) count++;
        }
        if (count>k/2) return 1;
        else return 0;
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<pair<int,int>,int>> pointSet(n);//坐标+class
    for (auto& p:pointSet)
    {
        cin>>p.first.first>>p.first.second>>p.second;
    }
    int a,b;//target坐标
    cin>>a>>b;
    solution s;
    cout<<s.knn(k,pointSet,a,b);
}