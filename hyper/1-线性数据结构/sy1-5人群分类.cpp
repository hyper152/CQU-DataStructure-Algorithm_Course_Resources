#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int mid = n / 2;
    long long sum_left = accumulate(a.begin(), a.begin() + mid, 0LL);
    long long sum_right = accumulate(a.begin() + mid, a.end(), 0LL);

    cout << "Outgoing #: " << n - mid << '\n';
    cout << "Introverted #: " << mid << '\n';
    cout << "Diff = " << sum_right - sum_left << '\n';

    return 0;
}