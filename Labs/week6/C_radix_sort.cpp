#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getDigit(int num, int d) {
    for (int i = 0; i < d; ++i) num /= 10;
    return num % 10;
}

void radixSort(vector<int>& arr, int maxDigits) {
    vector<int> tmp(arr.size());
    for (int d = 0; d < maxDigits; ++d) {
        int cnt[10] = {0};
        for (int x : arr) cnt[getDigit(x, d)]++;
        for (int i = 1; i < 10; ++i) cnt[i] += cnt[i - 1];
        for (int i = (int)arr.size() - 1; i >= 0; --i) {
            int digit = getDigit(arr[i], d);
            tmp[--cnt[digit]] = arr[i];
        }
        arr = tmp;
        for (size_t i = 0; i < arr.size(); ++i) cout << arr[i] << " ";
        cout << endl;
        if (d == 2) break;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxVal = 0;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
    }
    int maxDigits = 0;
    while (maxVal > 0) {
        maxDigits++;
        maxVal /= 10;
    }
    radixSort(arr, maxDigits);
    return 0;
}
