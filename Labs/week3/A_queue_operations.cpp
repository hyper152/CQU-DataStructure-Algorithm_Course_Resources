#include <iostream>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    cout << "错误：队列已满。" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cout << x << endl;
    }
    cout << "错误：队列为空。" << endl;
    cout << -1 << endl;
    cout << "错误：队列为空。" << endl;
    return 0;
}
