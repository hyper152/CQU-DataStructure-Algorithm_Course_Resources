#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lst(n + 1);
    for (int i = 1; i <= n; i++) cin >> lst[i];

    for (int i = 2; i <= n; i++) {
        int p = i, q = i - 1;
        while (q >= 1 && lst[p] <= lst[q]) {
            swap(lst[p], lst[q]);
            p = q;
            q--;
        }
        for (int j = 1; j <= n; j++) {
            cout << lst[j];
            if (j < n) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
