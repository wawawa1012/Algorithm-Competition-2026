//
// Created by A on 2026/10/17.
//
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
    int max_meeting_num(vector<pair<int,int>>& meetings)
    {
        sort(meetings.begin(),meetings.end(),
            [](const pair<int,int>& a,const pair<int,int>& b)
            {
                return a.second<b.second;
            });
        int maxMeetingNum=1;
        int currTime=meetings[0].second;
        for (int i=1;i<meetings.size();i++)
        {
            if (currTime<=meetings[i].first)
            {
                maxMeetingNum++;
                currTime=meetings[i].second;
            }
        }
        return maxMeetingNum;
    }
};

int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>> meetings(n);
    for (auto& meeting:meetings)
    {
        cin>>meeting.first>>meeting.second;
    }
    solution s;
    cout<<s.max_meeting_num(meetings);
    return 0;
}