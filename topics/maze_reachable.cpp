// 迷宫可达格数：递归 DFS 练习（自命题）
// 输入 H W，随后 H 行迷宫，1 <= H,W <= 20。
// S 恰有一个，表示起点；. 是空地，# 是墙。
// 每次只能上下左右移动，输出从 S 能到达的不同格子数，包含 S。
// 样例输入：
// 3 3
// S..
// .##
// ..#
// 样例输出：6

#include <iostream>
#include <limits>
#include <string>
#include <vector>
using namespace std;

int h, w;
vector<string> grid;
vector<vector<int>> visited;
int reachable = 0;

void dfs(int x, int y) {
    // TODO：只实现这里。grid、visited、reachable 由各层共用。
    visited[x][y]=1;
    reachable++;
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    for (int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if (nx>=0&&ny>=0&&nx<h&&ny<w)//越界检测
        {
            if (grid[nx][ny]!='#'&&visited[nx][ny]==0)
            {
                dfs(nx,ny);
            }
        }
    }
}

int main() {
    cin >> h >> w;
    grid.resize(h);
    visited.assign(h, vector<int>(w, 0));
    for (auto& row : grid) cin >> row;

    for (int x = 0; x < h; ++x) {
        for (int y = 0; y < w; ++y) {
            if (grid[x][y] == 'S') dfs(x, y);
        }
    }
    cout << reachable << '\n';
}
