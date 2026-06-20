#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 定义结点：存储 数据 + 下一个地址
struct Node {
    int data;
    string next;
};

int main() {
    string head;
    int n;
    cin >> head >> n;

    // 核心：用【地址】作为唯一键，存储结点（正确！）
    map<string, Node> nodeMap;

    // 1. 读取所有结点
    for (int i = 0; i < n; i++) {
        string addr, next;
        int data;
        cin >> addr >> data >> next;
        nodeMap[addr].data = data;
        nodeMap[addr].next = next;
    }

    // 2. 遍历原始链表，把地址按顺序存入vector
    vector<string> list;
    string p = head;
    while (p != "-1") {
        list.push_back(p);
        p = nodeMap[p].next;
    }

    // 3. 双指针重排：Ln → L1 → Ln-1 → L2 ...（核心！）
    vector<string> res;
    int left = 0, right = list.size() - 1;
    bool flag = true; // 先取右边

    while (left <= right) {
        if (flag) {
            res.push_back(list[right--]);
        } else {
            res.push_back(list[left++]);
        }
        flag = !flag;
    }

    // 4. 按格式输出（补5位地址 + 空格 + 正确next）
    for (int i = 0; i < res.size(); i++) {
        string cur = res[i];
        // 输出当前地址、数据
        cout << cur << " " << nodeMap[cur].data << " ";
        // 输出next：最后一个为-1，否则为下一个地址
        if (i == res.size() - 1) {
            cout << "-1" << endl;
        } else {
            cout << res[i + 1] << endl;
        }
    }

    return 0;
}