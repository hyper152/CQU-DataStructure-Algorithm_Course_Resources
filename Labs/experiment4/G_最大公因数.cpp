/**
 * G - 最大公因数
 *
 * 题意：给定两个正整数 a, b。每次操作可以选择其中一个数，将它减去当前两个数的 gcd。
 *       问最少需要多少次操作才能使两个数都变成 0。
 *
 * 思路：搜索剪枝。可以证明最优解不超过 26 步。
 *       使用 DFS 枚举每一步的操作（减去 a 或减去 b 的 gcd）。
 */

#include <iostream>
#include <algorithm>
using namespace std;

int ans;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

void dfs(int a, int b, int k) {
    if (k >= ans) return;  // 剪枝
    if (!a && !b) {
        ans = k;
        return;
    }

    int g = gcd(a, b);

    // 选择 a 减去 gcd
    if (a >= g) dfs(a - g, b, k + 1);
    // 选择 b 减去 gcd
    if (b >= g) dfs(a, b - g, k + 1);
}

void solve() {
    int a, b;
    cin >> a >> b;

    ans = 26;  // 上界
    dfs(a, b, 0);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) solve();

    return 0;
}
