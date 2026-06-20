#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 使用 deque 作为底层容器，方便查看容量
    queue<int> q;
    
    // 读取 n+1 个整数
    int* arr = new int[n + 1];
    for (int i = 0; i < n + 1; i++) {
        cin >> arr[i];
    }
    
    // 执行 n+1 次入队操作
    for (int i = 0; i < n + 1; i++) {
        if (q.size() == n) {
            cout << "错误：队列已满。" << endl;
        } else {
            q.push(arr[i]);
        }
    }
    
    // 执行 n+1 次取队首并出队操作
    for (int i = 0; i < n + 1; i++) {
        if (q.empty()) {
            cout << "错误：队列为空。" << endl;
            cout << -1 << endl;
        } else {
            cout << q.front() << endl;
            q.pop();
        }
    }
    
    delete[] arr;
    return 0;
}