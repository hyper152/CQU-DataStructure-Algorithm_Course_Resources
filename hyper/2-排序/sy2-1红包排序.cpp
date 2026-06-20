#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>  // 用于 setprecision
using namespace std;

struct Person {
    int id;
    int money;  // 净收入（分）
    int cnt;    // 红包个数
};

bool cmp(const Person &a, const Person &b) {
    if (a.money != b.money)
        return a.money > b.money;
    if (a.cnt != b.cnt)
        return a.cnt > b.cnt;
    return a.id < b.id;
}

int main() {
    int n;
    cin >> n;

    vector<int> get(n, 0);
    vector<int> cnt(n, 0);
    vector<int> out(n, 0);

    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int id, money;
            cin >> id >> money;
            get[id - 1] += money;
            cnt[id - 1]++;
            out[i - 1] += money;
        }
    }

    vector<Person> p(n);
    for (int i = 0; i < n; ++i) {
        p[i].id = i + 1;
        p[i].money = get[i] - out[i];
        p[i].cnt = cnt[i];
    }

    sort(p.begin(), p.end(), cmp);

    // cout 输出，保留两位小数
    for (auto &x : p) {
        cout << x.id << " " 
             << fixed << setprecision(2) 
             << x.money / 100.0 << endl;
    }

    return 0;
}