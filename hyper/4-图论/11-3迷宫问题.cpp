#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x, y, step;
};

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> maze(n, vector<int>(m));
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;
    
    // 读入迷宫并找到起点和终点
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 3) {
                startX = i;
                startY = j;
            }
            if (maze[i][j] == 4) {
                endX = i;
                endY = j;
            }
        }
    }
    
    // 方向数组：上下左右
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    // BFS
    queue<Point> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    q.push({startX, startY, 0});
    visited[startX][startY] = true;
    
    int result = -1;
    
    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        
        // 到达终点
        if (cur.x == endX && cur.y == endY) {
            result = cur.step;
            break;
        }
        
        // 四个方向尝试移动
        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            
            // 边界检查
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 障碍物检查
            if (maze[nx][ny] == 1) continue;
            // 已访问检查
            if (visited[nx][ny]) continue;
            
            visited[nx][ny] = true;
            q.push({nx, ny, cur.step + 1});
        }
    }
    
    if (result == -1) {
        cout << "unreachable" << endl;
    } else {
        cout << result << endl;
    }
    
    return 0;
}