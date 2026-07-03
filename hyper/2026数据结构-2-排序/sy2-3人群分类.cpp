#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> act(N);
    
    for (int i = 0; i < N; i++) {
        cin >> act[i];
    }
    
    sort(act.begin(), act.end());
    
    int half = N / 2;
    // 内向型：前 half 个，外向型：后 N - half 个
    long long sum_intro = accumulate(act.begin(), act.begin() + half, 0LL);
    long long sum_out = accumulate(act.begin() + half, act.end(), 0LL);
    
    cout << "Outgoing #: " << N - half << endl;
    cout << "Introverted #: " << half << endl;
    cout << "Diff = " << sum_out - sum_intro << endl;
    
    return 0;
}