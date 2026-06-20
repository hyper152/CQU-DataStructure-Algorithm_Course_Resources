/**
 * B - Captain-G's "Die Hard"
 *
 * 题意：给定两个容量分别为 X 和 Y 的杯子，可以进行装满、倒空、相互倒水等操作。
 *       对于 K 次询问，每次给定 w，判断是否能量出恰好 w 体积的水（在第一个杯子中）。
 *
 * 性质：w 能被量出当且仅当 w ≤ X 且 w 是 gcd(X, Y) 的倍数。
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int K;
    cin >> K;

    int g = __gcd(X, Y);

    for (int i = 0; i < K; i++) {
        int w;
        cin >> w;
        if (w <= X && w % g == 0) {
            cout << 1 << " ";
        } else {
            cout << 0 << " ";
        }
    }
    cout << endl;

    return 0;
}
