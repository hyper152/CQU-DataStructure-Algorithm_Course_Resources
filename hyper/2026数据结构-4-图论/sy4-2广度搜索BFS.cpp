#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M, N, L, T;
vector<vector<vector<int>>> matrix;
vector<vector<vector<bool>>> visited;

// 6个方向
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Point {
    int x, y, z;
    Point(int x_, int y_, int z_) : x(x_), y(y_), z(z_) {}
};

int bfs(int x, int y, int z) {
    queue<Point> q;
    q.push(Point(x, y, z));
    visited[x][y][z] = true;
    int volume = 1;
    
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        
        for (int i = 0; i < 6; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            int nz = p.z + dz[i];
            
            // 边界检查
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || nz < 0 || nz >= L) {
                continue;
            }
            
            // 肿瘤且未访问
            if (matrix[nx][ny][nz] == 1 && !visited[nx][ny][nz]) {
                visited[nx][ny][nz] = true;
                q.push(Point(nx, ny, nz));
                volume++;
            }
        }
    }
    
    return volume;
}

int main() {
    cin >> M >> N >> L >> T;
    
    // 初始化三维数组
    matrix.resize(M, vector<vector<int>>(N, vector<int>(L)));
    visited.resize(M, vector<vector<bool>>(N, vector<bool>(L, false)));
    
    // 读入数据
    for (int z = 0; z < L; z++) {
        for (int x = 0; x < M; x++) {
            for (int y = 0; y < N; y++) {
                cin >> matrix[x][y][z];
            }
        }
    }
    
    int total = 0;
    
    // 遍历所有点
    for (int x = 0; x < M; x++) {
        for (int y = 0; y < N; y++) {
            for (int z = 0; z < L; z++) {
                if (matrix[x][y][z] == 1 && !visited[x][y][z]) {
                    int volume = bfs(x, y, z);
                    if (volume >= T) {
                        total += volume;
                    }
                }
            }
        }
    }
    
    cout << total << endl;
    
    return 0;
}