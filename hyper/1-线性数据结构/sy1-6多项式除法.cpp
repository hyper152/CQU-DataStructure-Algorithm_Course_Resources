#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

// 清理掉系数接近0（四舍五入后为0.0）的项
void clean_poly(map<int, double>& poly) {
    auto it = poly.begin();
    while (it != poly.end()) {
        if (fabs(it->second) < 0.05) {
            it = poly.erase(it);
        } else {
            ++it;
        }
    }
}

// 输出多项式
void print_poly(map<int, double>& poly) {
    clean_poly(poly);
    if (poly.empty()) {
        cout << "0 0 0.0" << endl;
        return;
    }
    cout << poly.size();
    // 从高次到低次输出
    for (auto iter = poly.rbegin(); iter != poly.rend(); ++iter) {
        cout << " " << iter->first << " " 
             << fixed << setprecision(1) << iter->second;
    }
    cout << endl;
}

int main() {
    // 读取多项式 A
    int nA;
    cin >> nA;
    map<int, double> A;
    for (int i = 0; i < nA; ++i) {
        int e; double c;
        cin >> e >> c;
        A[e] = c;
    }

    // 读取多项式 B
    int nB;
    cin >> nB;
    map<int, double> B;
    int max_e_B = -1;
    double max_c_B = 0.0;
    for (int i = 0; i < nB; ++i) {
        int e; double c;
        cin >> e >> c;
        B[e] = c;
        if (e > max_e_B) {
            max_e_B = e;
            max_c_B = c;
        }
    }

    map<int, double> Q;  // 商
    map<int, double> R = A;  // 余数初始为A

    while (true) {
        // 找当前余数最高次项
        int max_e_R = -1;
        double max_c_R = 0.0;
        for (auto& p : R) {
            if (p.first > max_e_R && fabs(p.second) >= 0.05) {
                max_e_R = p.first;
                max_c_R = p.second;
            }
        }
        // 余数次数小于除数次数，结束
        if (max_e_R < max_e_B) break;

        // 商的一项
        int q_e = max_e_R - max_e_B;
        double q_c = max_c_R / max_c_B;
        Q[q_e] += q_c;

        // 用 B * 该项 去减 R
        for (auto& p : B) {
            int e = p.first + q_e;
            double c = p.second * q_c;
            R[e] -= c;
        }
    }

    // 输出商和余数
    print_poly(Q);
    print_poly(R);

    return 0;
}