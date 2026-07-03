#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_set<string> follows;
    for (int i = 0; i < N; i++) {
        string id;
        cin >> id;
        follows.insert(id);
    }
    
    int M;
    cin >> M;
    
    vector<pair<string, int>> likes(M);
    long long sum = 0;
    
    for (int i = 0; i < M; i++) {
        cin >> likes[i].first >> likes[i].second;
        sum += likes[i].second;
    }
    
    double avg = (double)sum / M;
    
    vector<string> result;
    for (auto& p : likes) {
        if (p.second > avg && follows.find(p.first) == follows.end()) {
            result.push_back(p.first);
        }
    }
    
    if (result.empty()) {
        cout << "Bing Mei You" << endl;
    } else {
        sort(result.begin(), result.end());
        for (auto& id : result) {
            cout << id << endl;
        }
    }
    
    return 0;
}