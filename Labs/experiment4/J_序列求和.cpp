/**
 * J - 序列求和
 *
 * 题意：给定长度为 n 的序列，以及 k 个已知子段和的信息 (l, r)，
 *       表示你知道 sum[l..r]（从 l 到 r 的元素和）。
 *       问在这 k 条信息下，一共能计算出多少种不同的子段和。
 *
 * 思路：将前缀和看作节点，已知 sum[l..r] 等价于知道 sum[r] - sum[l-1]，
 *       即 l-1 和 r 在同一个并查集中。最终，对每个连通块，
 *       其内部任意两个不同节点之间的差值都能被计算出来。
 *       答案 = Σ(cnt[i] * (cnt[i] - 1) / 2)，其中 cnt[i] 是每个连通块的大小。
 */

#include <iostream>
using namespace std;

const int MAXN = 1000005;

int n, k;
int root[MAXN];
long long ans = 0;
int cnt[MAXN];

int fd(int x) {
    if (root[x] == x) return x;
    root[x] = fd(root[x]);
    return root[x];
}

void hb(int x, int y) {
    root[fd(x)] = fd(y);
}

int main() {
    cin >> n >> k;

    // 并查集初始化：节点 0..n
    for (int i = 0; i <= n; i++) {
        root[i] = i;
    }

    // 合并已知子段和对应的前缀节点
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        hb(l - 1, r);
    }

    // 统计每个连通块的大小
    for (int i = 0; i <= n; i++) {
        root[i] = fd(i);
        cnt[root[i]]++;
    }

    // 每个连通块内，任意两个节点可算出一个不同的子段和
    for (int i = 0; i <= n; i++) {
        ans += (cnt[i] - 1);  // cnt[i] 个节点贡献 C(cnt[i],2) 到总和
    }

    cout << ans / 2 << endl;

    return 0;
}
