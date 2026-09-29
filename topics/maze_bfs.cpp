//
// Created by A on 2026/9/28.
//
#include <iostream>
#include <vector>
#include  <queue>
using namespace std;
class solution
{
public:
    int bfs(const vector<string>& grid,const pair<int,int>& start)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));  // -1=没访问；否则=从 S 走的步数
        queue<pair<int,int>> q;

        q.push(start);
        dist[start.first][start.second] = 0;

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            if (grid[x][y] == 'E') return dist[x][y];

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];
                // TODO 1: 越界检查
                if (nx>=0&&ny>=0&&nx<n&&ny<m)
                {
                    // TODO 2: 可走判断（'.' 或 'E'）且 dist[nx][ny] == -1（没访问过）
                    if ((grid[nx][ny]=='.'||grid[nx][ny]=='E')&&dist[nx][ny]==-1)
                    {
                        // TODO 3: dist[nx][ny] = dist[x][y] + 1; 然后 q.push({nx, ny});
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
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for (auto& row:grid)
    {
        cin>>row;
    }
    solution s;
    int res=0;
    pair<int,int> start={0,0};
    for (int i=0;i<grid.size();i++)
    {
        for (int j=0;j<grid[0].size();j++)
        {
            if (grid[i][j]=='S')    start={i,j};
        }
    }
    cout<<s.bfs(grid,start);
}