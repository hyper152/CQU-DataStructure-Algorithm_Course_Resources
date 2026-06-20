#include <iostream>
#include <vector>
#include <numeric>   // std::accumulate, std::gcd
#include <algorithm> // std::min_element
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    long long min_val =arr[0];
    
    for (int i = 1; i < n; ++i) {
        min_val= gcd(arr[i], min_val);
    }
    cout <<min_val*n<< endl;
    
    return 0;
}