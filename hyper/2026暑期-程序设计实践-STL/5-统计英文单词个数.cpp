#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        
        map<string, int> wordCount;
        
        // 读取并统计每个单词
        for (int i = 0; i < n; i++) {
            string word;
            cin >> word;
            wordCount[word]++;
        }
        
        // 按字典序输出
        for (const auto& pair : wordCount) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    
    return 0;
}