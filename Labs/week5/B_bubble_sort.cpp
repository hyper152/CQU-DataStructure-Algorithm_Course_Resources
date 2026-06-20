#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lst(n + 1);
    for (int i = 1; i <= n; i++) cin >> lst[i];

    for (int i = 1; i <= 3; i++) {
        for (int j = n; j > i; j--) {
            if (lst[j] < lst[j - 1]) {
                swap(lst[j], lst[j - 1]);
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << lst[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
