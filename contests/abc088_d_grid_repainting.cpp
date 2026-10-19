//
// Created by A on 2026/10/19.
//
//我看到题目后最初的想法就是把问题转化为求最短路径，这样能涂黑的就最多
//我现在递归掌握的其实并不好，所以写起来磕磕绊绊的
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class solution
{
public:
    int grid_repainting(vector<vector<char>>& grid)
    {
        int h=grid.size(),w=grid[0].size();
        vector<vector<int>> dist(h,vector<int>(w,-1));//标记未访问-1
        queue<pair<int,int>> q;
        q.push({0,0});
        dist[0][0]=0;
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int count=0;
        for (int i=0;i<h;i++)
        {
            for (int j=0;j<w;j++)
            {
                if (grid[i][j]=='#') count++;
            }
        }

        while (!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            if (x==h-1&&y==w-1) return h*w-dist[x][y]-1-count;
            for (int i=0;i<4;i++)
            {
                int nx=x+dx[i];
                int ny=y+dy[i];
                if (nx>=0&ny>=0&&nx<h&&ny<w)
                {
                    if (grid[nx][ny]=='.'&&dist[nx][ny]==-1)
                    {
                        dist[nx][ny]=dist[x][y]+1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    int H,W;
    cin>>H>>W;
    vector<vector<char>> grid(H,vector<char>(W));
    for (int i=0;i<H;i++)
    {
        for (int j=0;j<W;j++)
        {
            cin>>grid[i][j];
        }
    }
    solution s;
    cout<<s.grid_repainting(grid);
    return 0;
}