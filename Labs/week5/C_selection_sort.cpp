#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lst(n + 1);
    for (int i = 1; i <= n; i++) cin >> lst[i];

    for (int i = n; i > n - 3; i--) {
        int mx = lst[i], mxid = i;
        for (int j = 1; j <= i; j++) {
            if (lst[j] > mx) {
                mx = lst[j];
                mxid = j;
            }
        }
        swap(lst[i], lst[mxid]);
        for (int j = 1; j <= n; j++) {
            cout << lst[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
