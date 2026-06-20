#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    queue<int> q;
    
    for (int i = 0; i < n + 1; i++) {
        int num;
        cin >> num;
        
        if (q.size() < static_cast<size_t>(n)) {
            q.push(num);
        } else {
            cout << "错误：队列已满。" << endl;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << q.front() << endl;
        q.pop();
    }
    
    cout << "错误：队列为空。" << endl;
    cout << -1 << endl;
    cout << "错误：队列为空。" << endl;
    
    return 0;
}