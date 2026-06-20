#include <iostream>
using namespace std;

long long gcd(long long x, long long y) {
    if (y == 0) return x;
    return gcd(y, x % y);
}

int main() {
    long long n, m;
    cin >> n >> m;
    long long g = gcd(n, m);
    cout << g << " " << n / g * m << endl;
    return 0;
}
