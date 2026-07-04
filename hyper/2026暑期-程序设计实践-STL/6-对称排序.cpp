#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    int caseNum = 1;
    
    while (cin >> n && n != 0) {
        vector<string> names(n);
        
        for (int i = 0; i < n; i++) {
            cin >> names[i];
        }
        
        vector<string> result(n);
        int left = 0, right = n - 1;
        
        // 每次取两个元素
        for (int i = 0; i < n; i += 2) {
            result[left++] = names[i];      // 偶数索引放前面
            if (i + 1 < n) {
                result[right--] = names[i + 1]; // 奇数索引放后面
            }
        }
        
        cout << "SET " << caseNum++ << endl;
        for (int i = 0; i < n; i++) {
            cout << result[i] << endl;
        }
    }
    
    return 0;
}