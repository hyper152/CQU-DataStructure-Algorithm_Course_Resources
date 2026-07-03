#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int w, p;
    cin >> w >> p;

    double g = 9.8;
    double total = 20000000.0 / (w * g * p);

    cout << fixed << setprecision(3) << total << endl;
    return 0;
}