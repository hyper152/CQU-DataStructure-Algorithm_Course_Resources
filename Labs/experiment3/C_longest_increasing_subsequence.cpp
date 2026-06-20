#include<iostream>
#include<set>
using namespace std;

int main() {
    int n, num;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto it = s.lower_bound(num);
        if (it != s.end()) s.erase(it);
        s.insert(num);
    }
    cout << s.size() << endl;
    return 0;
}
