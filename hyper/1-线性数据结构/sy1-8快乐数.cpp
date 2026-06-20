#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2)
        if (n % i == 0) return false;
    return true;
}

int f(int n){
    vector<int> arr;
    int t=0;
    while (n>0){
        arr.push_back(n%10);
        n=n/10;
    }
    for (int i : arr){
        t += i*i;
    }
    return t;
}

void isHappy(int n, bool& b, int& m, unordered_set<int>& ll) {
    int t = n;
    unordered_set<int> arr;
    while (true){
        t = f(t);
        m++;
        if (arr.count(t)) {
            b = false;
            return;
        }
        arr.insert(t);
        if (t == 1) {
            b = true;
            for (int x : arr) ll.insert(x);
            return;
        }
    }
}

int main(){
    int l, r;
    unordered_set<int> ll;
    bool found = false;
    vector<vector<int>> list;

    cin >> l >> r;

    for (int i = l; i <= r; i++){
        if (ll.count(i)) continue;

        bool b;
        int m=0;
        isHappy(i, b, m, ll);

        if (b) {
            int independence = m;
            if (isPrime(i)) independence *= 2;
            list.push_back({i, independence});
            found = true;
        }
    }
    if (!found) {
        cout << "SAD";
    } else {
        for (int i = 0; i < list.size(); i++){
            if (!ll.count(list[i][0])) cout << list[i][0] << " " << list[i][1] << endl;
        }
    }
}