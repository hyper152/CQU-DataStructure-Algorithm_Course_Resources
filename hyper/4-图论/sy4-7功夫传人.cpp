#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct person{
    vector<int> apprentices;
    int multiplier = 1;  // 得道者的放大倍数，默认为1
    bool isDao = false;  // 是否得道者
};

int main(){
    int n;
    double z,r;
    cin>>n>>z>>r;
    vector<person> persons(n);
    
    double decay = (100 - r) / 100.0;
    
    for (int i=0;i<n;i++){
        int t;
        cin>>t;
        if (t==0) {
            int mul;
            cin>>mul;
            persons[i].multiplier = mul;
            persons[i].isDao = true;  // 标记为得道者
        } 
        else {
            for (int j=0;j<t;j++){
                int a;
                cin >> a;
                persons[i].apprentices.push_back(a);
            }
        }
    }
    
    // BFS遍历，记录每个节点的功力值
    queue<pair<int, double>> q;  // <节点编号, 功力值>
    q.push({0, z});
    double sum = 0;
    
    while (!q.empty()){
        auto [id, power] = q.front();
        q.pop();
        
        // 如果是得道者，累加功力值
        if (persons[id].isDao) {
            sum += power * persons[id].multiplier;
        }
        
        // 传递功力给徒弟
        for (int child : persons[id].apprentices){
            q.push({child, power * decay});
        }
    }
    
    cout << (int)sum << endl;  // 只保留整数部分
    return 0;
}