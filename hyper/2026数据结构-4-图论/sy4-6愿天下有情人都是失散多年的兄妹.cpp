#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
using namespace std;

struct Person {
    char sex;
    int mom = -1;
    int dad = -1;
};

// 获取某个人五代以内的所有祖先（包括自己）
void getAncestors(int id, int generation, map<int, Person>& people, unordered_set<int>& ancestors) {
    if (id == -1 || generation > 4) return; // 只查4代（高祖父母）
    if (ancestors.count(id)) return; // 防止重复
    
    ancestors.insert(id);
    
    // 如果此人信息不存在于map中，则无法继续往上查
    if (people.find(id) != people.end()) {
        getAncestors(people[id].dad, generation + 1, people, ancestors);
        getAncestors(people[id].mom, generation + 1, people, ancestors);
    }
}

int main() {
    int n;
    cin >> n;
    map<int, Person> people; // 用map存储，ID可能是5位数
    
    for (int i = 0; i < n; i++) {
        int id, mom, dad;
        char sex;
        cin >> id >> sex >> mom >> dad;
        people[id].sex = sex;
        people[id].mom = mom;
        people[id].dad = dad;
        
        // 重要：题目可能给出父母ID，但父母本人可能不在N行中。
        // 为了能通过父母ID找到他们的性别，也需要标记父母的性别（如果父母ID后来出现在输入中会覆盖）
        // 但如果父母不在输入中，我们无法知道其性别，但可以通过其孩子推断。
        // 更好的做法是：如果父母ID不为-1且尚未记录，先创建一个占位记录。
        if (mom != -1 && people.find(mom) == people.end()) {
            people[mom].sex = 'F'; // 母亲一定是女性
        }
        if (dad != -1 && people.find(dad) == people.end()) {
            people[dad].sex = 'M'; // 父亲一定是男性
        }
    }
    
    int k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        int id1, id2;
        cin >> id1 >> id2;
        
        // 同性直接输出
        if (people[id1].sex == people[id2].sex) {
            cout << "Never Mind" << endl;
            continue;
        }
        
        // 分别获取两人的五代以内祖先
        unordered_set<int> ancestors1, ancestors2;
        getAncestors(id1, 0, people, ancestors1);
        getAncestors(id2, 0, people, ancestors2);
        
        // 检查是否有共同祖先
        bool hasCommon = false;
        for (int id : ancestors1) {
            if (ancestors2.count(id)) {
                hasCommon = true;
                break;
            }
        }
        
        if (hasCommon) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}