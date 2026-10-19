// 空地区域数量（自命题）
// 输入 H W，随后 H 行地图，1 <= H,W <= 20。
// . 表示空地，# 表示墙；没有 S。
// 上下左右相邻的空地属于同一区域，斜向相邻不算。
// 输出整张图的空地区域数量。没有空地时输出 0。
// 样例输入：
// 3 4
// ..##
// #.##
// ##..
// 样例输出：2

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int h,w;
vector<vector<char>> grid;
vector<vector<int>> visited;
int island_count=0;
constexpr int dx[4]={1,-1,0,0};
constexpr int dy[4]={0,0,1,-1};
void dfs_island_count(int x,int y)
{
    visited[x][y]=1;
    for (int i=0;i<4;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if (nx>=0&&ny>=0&&nx<h&&ny<w)
        {
            if (visited[nx][ny]==0&&grid[nx][ny]=='.')
            {
                dfs_island_count(nx,ny);
            }
        }
    }
}

int main() {
    // TODO：可以复用自己在 maze_reachable.cpp 中写的 DFS。
    cin>>h>>w;
    grid.assign(h,vector<char>(w));
    visited.assign(h,vector<int>(w,0));
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            cin>>grid[i][j];
        }
    }
    for (int i=0;i<h;i++)
    {
        for (int j=0;j<w;j++)
        {
            if (grid[i][j]=='.'&&visited[i][j]==0)
            {
                dfs_island_count(i,j);
                island_count++;
            }
        }
    }
    cout<<island_count;
}

