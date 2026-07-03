#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int parent[MAXN], cnt[MAXN];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra != rb) parent[ra] = rb;
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) parent[i] = i;

    int first[MAXN] = {0};   // first[兴趣] = 第一个拥有该兴趣的人

    for (int i = 1; i <= n; ++i) {
        int k;
        char colon;
        cin >> k >> colon;   // 读取 "k:" 中的冒号
        for (int j = 0; j < k; ++j) {
            int h;
            cin >> h;
            if (first[h] == 0) {
                first[h] = i;
            } else {
                unite(i, first[h]);
            }
        }
    }

    // 统计每个根的人数
    for (int i = 1; i <= n; ++i) {
        cnt[find(i)]++;
    }

    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] > 0) ans.push_back(cnt[i]);
    }

    sort(ans.begin(), ans.end(), greater<int>());

    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;

    return 0;
}