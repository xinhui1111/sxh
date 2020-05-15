/*
题目描述：
    在给定的网格中，每个单元格可以有以下三个值之一：

    值 0 代表空单元格；
    值 1 代表新鲜橘子；
    值 2 代表腐烂的橘子。
    每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。

    返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
*/
#include <iostream>
#include <vector>
#include <queue>
#include<cstring>
using namespace std;

/*
    总思想：
        入队的是坐标而不是坐标以及对应的值，因为之后值可以从数组中提取
        出队
*/
int orangesRotting(vector<vector<int>> &grid)
{
    int cnt;//用于统计未腐烂的橘子有多少个
    int dis[10][10];//表示层数
    //x、y表示上下左右四个位置的值
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
    queue<pair<int, int>> Q;
    memset(dis, -1, sizeof(dis));
    cnt = 0;
    int n = (int)grid.size(), m = (int)grid[0].size(), ans = 0;
    /*
        入队初始化，层数计算初始化，非腐烂个数总计
    */
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (grid[i][j] == 2)
            {
                Q.push(make_pair(i, j));
                dis[i][j] = 0;//腐烂就是没有层数
            }
            else if (grid[i][j] == 1)
                cnt += 1;
        }
    }

    /*
        入队--->相应操作
        出队--->相应操作
    */
    while (!Q.empty())
    {
        pair<int, int> x = Q.front();
        Q.pop();
        //前后左右四个位置进行循环计算
        for (int i = 0; i < 4; ++i)
        {
            int tx = x.first + dir_x[i];
            int ty = x.second + dir_y[i];
            //~dis[tx][ty]能将处理之后的反向邻continue过去
            if (tx < 0 || tx >= n || ty < 0 || ty >= m || (~dis[tx][ty]) || !grid[tx][ty])
                continue;
            dis[tx][ty] = dis[x.first][x.second] + 1;
            Q.push(make_pair(tx, ty));
            if (grid[tx][ty] == 1)
            {
                cnt -= 1;
                ans = dis[tx][ty];
                if (!cnt)
                    break;
            }
        }
    }
    return cnt ? -1 : ans;
}


int main()
{
    int m{-1};
    cout<<~m<<endl;
    vector<vector<int>>grid{{1,1,2},{1,0,0},{1,2,1}};
    cout<<orangesRotting(grid)<<endl;
    system("pause");
    return 0;
}