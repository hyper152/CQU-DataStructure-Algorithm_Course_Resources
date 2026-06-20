#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Student {
    int id;
    int score;
};

bool cmp(Student a, Student b) {
    if (a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

int main() {
    int n, m;
    cin >> n >> m;
    Student lst[5005];
    for (int i = 1; i <= n; i++) {
        cin >> lst[i].id >> lst[i].score;
    }
    sort(lst + 1, lst + n + 1, cmp);

    int ans = floor(m * 1.5);
    cout << lst[ans].score << " ";
    for (int i = ans + 1; i <= n; i++) {
        if (lst[i].score == lst[ans].score) ans++;
        else break;
    }
    cout << ans << endl;
    for (int i = 1; i <= ans; i++) {
        cout << lst[i].id << " " << lst[i].score << endl;
    }
    return 0;
}
