#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int N, k, M;
    cin >> N >> k >> M;

    vector<double> final_scores;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        int max_score = -1;
        int min_score = 101;

        for (int j = 0; j < k; j++) {
            int score;
            cin >> score;
            sum += score;
            if (score > max_score) max_score = score;
            if (score < min_score) min_score = score;
        }

        // 去掉最高分和最低分，求平均
        double avg = (sum - max_score - min_score) * 1.0 / (k - 2);
        final_scores.push_back(avg);
    }

    // 排序（非递减顺序，即从小到大）
    sort(final_scores.begin(), final_scores.end());

    // 输出最后（最高）的 M 个成绩
    // 设置输出格式：保留3位小数
    cout << fixed << setprecision(3);
    for (int i = N - M; i < N; i++) {
        if (i != N - M) cout << " ";
        cout << final_scores[i];
    }

    return 0;
}