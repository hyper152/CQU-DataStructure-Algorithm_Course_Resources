#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Student {
    string name, id;
    int score[11] = {0};
    int total = 0;
} a[100005];

bool cmp(Student &s1, Student &s2) {
    if (s1.total == s2.total) return s1.id > s2.id;
    return s1.total > s2.total;
}

int main() {
    int n, m, tot = 0;
    cin >> n >> m;
    map<string, int> D;
    for (int i = 0; i < n; i++) {
        string tname, tid;
        cin >> tname >> tid;
        int tsc, tscore;
        cin >> tsc >> tscore;
        int tt1, tt2;
        scanf("%02d:%02d", &tt1, &tt2);
        if (tt1 < 3) {
            if (!D.count(tid)) {
                D[tid] = ++tot;
                a[tot].name = tname;
                a[tot].id = tid;
            }
            int p = D[tid];
            a[p].total -= a[p].score[tsc];
            a[p].score[tsc] = max(a[p].score[tsc], tscore);
            a[p].total += a[p].score[tsc];
        }
    }
    sort(a + 1, a + tot + 1, cmp);
    for (int i = 1; i <= m; i++) {
        cout << a[i].name << " " << a[i].id << " " << a[i].total << "\n";
    }
    return 0;
}
