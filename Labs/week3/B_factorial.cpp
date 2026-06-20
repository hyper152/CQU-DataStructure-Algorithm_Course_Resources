#include <iostream>
using namespace std;

long long fac(int x) {
    if (x == 0) return 1;
    return x * fac(x - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << fac(n) << endl;
    return 0;
}
