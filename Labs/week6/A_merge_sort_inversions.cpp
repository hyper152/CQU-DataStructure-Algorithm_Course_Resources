#include <iostream>
using namespace std;

int q[105], temp[105], cnt = 0;

void merge_sort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2, i = l, j = mid + 1, k = 0;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) temp[k++] = q[i++];
        else temp[k++] = q[j++], cnt += mid - i + 1;
    }
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];
    for (i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    merge_sort(0, n - 1);
    cout << "count = " << cnt << endl;
    for (int i = 0; i < n; i++) cout << q[i] << " ";
    cout << endl;
    return 0;
}
