#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX / 2;  // 定义一个足够大的数表示无穷大，避免整数溢出

// 边的结构体，表示图中的一条有向边
struct Edge {
    int to;          // 目标节点编号
    int length;      // 道路长度（距离），单位千米
    int time;        // 通过该道路所需时间，单位分钟
};

// 节点的结构体，表示图中的一个顶点
struct Node {
    vector<Edge> edges;  // 从该节点出发的所有有向边
};

/**
 * 打印路径函数
 * @param path 路径向量，按顺序存储节点编号
 * @param start 起点编号（用于显示）
 * @param end 终点编号（用于显示，实际未使用）
 */
void printPath(const vector<int>& path, int start, int end) {
    cout << start;  // 打印起点
    // 从第1个节点开始打印（第0个是起点），用"=>"连接
    for (int i = 1; i < path.size(); i++) {
        cout << " => " << path[i];
    }
}

/**
 * 从父节点数组还原完整路径
 * @param parent 父节点数组，parent[i]表示节点i的前驱节点
 * @param start 起点编号
 * @param end 终点编号
 * @return 从起点到终点的完整路径向量
 */
vector<int> getPath(const vector<int>& parent, int start, int end) {
    vector<int> path;
    int cur = end;
    // 从终点开始，通过parent数组向前追溯直到起点
    while (cur != -1) {  // -1表示没有前驱节点（即起点）
        path.push_back(cur);
        cur = parent[cur];
    }
    // 由于是从后向前追溯，需要反转得到正确顺序
    reverse(path.begin(), path.end());
    return path;
}

/**
 * 比较两条路径是否完全相同
 * @param path1 第一条路径
 * @param path2 第二条路径
 * @return 如果路径完全相同返回true，否则返回false
 */
bool isSamePath(const vector<int>& path1, const vector<int>& path2) {
    if (path1.size() != path2.size()) return false;  // 长度不同肯定不同
    for (int i = 0; i < path1.size(); i++) {
        if (path1[i] != path2[i]) return false;  // 有任何节点不同则不同
    }
    return true;
}

/**
 * 使用Dijkstra算法求最快到达路线（时间优先，距离次之）
 * @param n 节点总数
 * @param start 起点编号
 * @param end 终点编号
 * @param graph 图的邻接表表示
 * @return pair<路径向量, 总时间>
 */
pair<vector<int>, int> dijkstraTime(int n, int start, int end, const vector<Node>& graph) {
    vector<int> distTime(n, INF);    // 从起点到各节点的最短时间
    vector<int> distLen(n, INF);     // 在最短时间条件下的最短距离（用于打破平局）
    vector<int> parent(n, -1);       // 记录每个节点的前驱节点，用于还原路径
    vector<bool> visited(n, false);  // 标记节点是否已确定最短路径
    
    distTime[start] = 0;  // 起点到自身的时间为0
    distLen[start] = 0;   // 起点到自身的距离为0
    
    // 主循环：每次选出一个未被访问且距离最小的节点
    for (int i = 0; i < n; i++) {
        // 选择时间最小的未访问节点
        int u = -1;
        int minTime = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distTime[j] < minTime) {
                minTime = distTime[j];
                u = j;
            }
        }
        
        if (u == -1) break;  // 所有节点都已访问或不可达
        visited[u] = true;
        if (u == end) break;  // 已到达终点，可以提前结束
        
        // 松弛操作：更新节点u的所有邻居
        for (const Edge& e : graph[u].edges) {
            int v = e.to;
            if (!visited[v]) {
                // 条件1: 找到更短的时间
                // 条件2: 时间相同但距离更短（打破平局）
                if (distTime[u] + e.time < distTime[v] ||
                    (distTime[u] + e.time == distTime[v] && 
                     distLen[u] + e.length < distLen[v])) {
                    distTime[v] = distTime[u] + e.time;
                    distLen[v] = distLen[u] + e.length;
                    parent[v] = u;  // 更新前驱节点
                }
            }
        }
    }
    
    return {getPath(parent, start, end), distTime[end]};
}

/**
 * 使用Dijkstra算法求最短距离路线（距离优先，节点数次之）
 * @param n 节点总数
 * @param start 起点编号
 * @param end 终点编号
 * @param graph 图的邻接表表示
 * @return pair<路径向量, 总距离>
 */
pair<vector<int>, int> dijkstraDistance(int n, int start, int end, const vector<Node>& graph) {
    vector<int> distLen(n, INF);    // 从起点到各节点的最短距离
    vector<int> distNode(n, INF);   // 在最短距离条件下的节点数（用于打破平局）
    vector<int> parent(n, -1);      // 记录每个节点的前驱节点
    vector<bool> visited(n, false); // 标记节点是否已确定最短路径
    
    distLen[start] = 0;   // 起点到自身的距离为0
    distNode[start] = 1;  // 起点到自身的路径包含1个节点（起点自身）
    
    // 主循环：每次选出一个未被访问且距离最小的节点
    for (int i = 0; i < n; i++) {
        // 选择距离最小的未访问节点
        int u = -1;
        int minLen = INF;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distLen[j] < minLen) {
                minLen = distLen[j];
                u = j;
            }
        }
        
        if (u == -1) break;  // 所有节点都已访问或不可达
        visited[u] = true;
        if (u == end) break;  // 已到达终点，可以提前结束
        
        // 松弛操作：更新节点u的所有邻居
        for (const Edge& e : graph[u].edges) {
            int v = e.to;
            if (!visited[v]) {
                // 条件1: 找到更短的距离
                // 条件2: 距离相同但经过的节点数更少（打破平局）
                if (distLen[u] + e.length < distLen[v] ||
                    (distLen[u] + e.length == distLen[v] && 
                     distNode[u] + 1 < distNode[v])) {
                    distLen[v] = distLen[u] + e.length;
                    distNode[v] = distNode[u] + 1;  // 新路径节点数 = 前驱节点路径节点数 + 1
                    parent[v] = u;  // 更新前驱节点
                }
            }
        }
    }
    
    return {getPath(parent, start, end), distLen[end]};
}

int main() {
    int n, m;  // n: 节点数, m: 边数
    cin >> n >> m;
    
    vector<Node> graph(n);  // 创建图的邻接表，n个节点
    
    // 读入m条边
    for (int i = 0; i < m; i++) {
        int v1, v2, oneway, length, time;
        cin >> v1 >> v2 >> oneway >> length >> time;
        
        // v1 -> v2 的正向边
        Edge e1;
        e1.to = v2;
        e1.length = length;
        e1.time = time;
        graph[v1].edges.push_back(e1);
        
        // 如果oneway == 0，表示双向路，添加反向边 v2 -> v1
        if (oneway == 0) {
            Edge e2;
            e2.to = v1;
            e2.length = length;
            e2.time = time;
            graph[v2].edges.push_back(e2);
        }
        // 如果oneway == 1，表示单行道，只添加正向边
    }
    
    int start, end;  // 起点和终点
    cin >> start >> end;
    
    // 计算最快到达路线（时间优先）
    auto [timePath, totalTime] = dijkstraTime(n, start, end, graph);
    
    // 计算最短距离路线（距离优先）
    auto [distPath, totalDist] = dijkstraDistance(n, start, end, graph);
    
    // 判断两条路线是否相同，根据要求输出不同格式
    if (isSamePath(timePath, distPath)) {
        // 如果两条路线相同，合并输出一行
        cout << "Time = " << totalTime << "; Distance = " << totalDist << ": ";
        printPath(timePath, start, end);
        cout << endl;
    } else {
        // 如果两条路线不同，分行输出
        cout << "Time = " << totalTime << ": ";
        printPath(timePath, start, end);
        cout << endl;
        
        cout << "Distance = " << totalDist << ": ";
        printPath(distPath, start, end);
        cout << endl;
    }
    
    return 0;
}