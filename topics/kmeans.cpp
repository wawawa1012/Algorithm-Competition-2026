//
// Created by A on 2026/10/14.
//
#include <iomanip>
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class solution
{
public:
    void kmeans(const vector<pair<double,double>>& pointSet,const int k)
    {
        vector<pair<pair<double,double>,int>> center(k);
        const int n=pointSet.size();
        for (int i=0;i<k;i++)//初始化cluster中心
        {
            center[i].first=pointSet[i];
            center[i].second=i;
        }
        vector<pair<pair<double,double>,int>> point(n);
        for (int i=0;i<n;i++)//初始cluster设为-1
        {
            point[i].second=-1;
        }
        // 每轮完整执行“分配 -> 统计 -> 更新”，最多 100 轮。
        for (int iter=0;iter<100;iter++)
        {
            bool changed=false;
            for (int i=0;i<n;i++)
            {
                point[i].first=pointSet[i];
                double min_dis = numeric_limits<double>::infinity();
                int bestCluster=0;
                for (int j=0;j<k;j++)
                {
                    double dx=center[j].first.first-pointSet[i].first;
                    double dy=center[j].first.second-pointSet[i].second;
                    double dist=dx*dx+dy*dy;
                    if (dist<min_dis)
                    {
                        min_dis=dist;
                        bestCluster=j;
                    }
                }
                // 找完全部中心，再比较最终编号与上一轮编号。
                if (point[i].second!=bestCluster) changed=true;
                point[i].second=bestCluster;
            }
            vector<pair<pair<double,double>,int>> newCenter(k);//更新中心坐标，int是编号为i的点个数
            for (int i=0;i<n;i++)
            {
                int cluster=point[i].second;
                newCenter[cluster].first.first+=point[i].first.first;
                newCenter[cluster].first.second+=point[i].first.second;
                newCenter[cluster].second+=1;
            }
            for (int i=0;i<k;i++)
            {
                if (newCenter[i].second==0) continue;
                center[i].first.first=newCenter[i].first.first/newCenter[i].second;
                center[i].first.second=newCenter[i].first.second/newCenter[i].second;
            }
            if (!changed) break;
        }
        cout<<fixed<<setprecision(6);
        for (auto& pair:center)
        {
            cout<<pair.first.first<<" "<<pair.first.second<<endl;
        }
    }
};

int main()
{
    int n,k;
    cin>>n>>k;
    vector<pair<double,double>> pointSet(n);
    for (auto& pair:pointSet)
    {
        cin>>pair.first>>pair.second;
    }
    solution s;
    s.kmeans(pointSet,k);
    return 0;
}
