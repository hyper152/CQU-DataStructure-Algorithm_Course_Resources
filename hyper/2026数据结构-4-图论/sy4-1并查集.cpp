#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>  // 用于格式化输出 setw, setfill, setprecision
#include <set>

using namespace std;

const int MAXN = 10000; // 编号范围 0000-9999，共10000个可能编号

int parent[MAXN];
bool exist[MAXN];

void init(){
    for (int i=0;i<MAXN;i++){
        parent[i]=i;
        exist[i]=false;
    }
}

int find(int id){
    if (parent[id]!=id){
        parent[id]=find(parent[id]);
    }
    return parent[id]
}

void unite(int a, int b) {
    if (a == -1 || b == -1) return;
    int ia=find(a);
    int ib=find(b);
    exist[a] = true;
    exist[b] = true;
    if (ia != ib) {
        parent[ia] = ib;
    }
}

struct family{
    int id;
    int population;
    int min;
    int house_num;
    int area;

    family(){
        min=MAXN;
        population=0;
        house_num=0;
        area=0;
        id=-1;
    }
};

struct Person {
    int id;         // 个人编号
    int house_num;  // 该人名下的房产套数
    int area;       // 该人名下的房产总面积
};

int main(){
    int N;
    cin>>N;
    
    vector<Person> persons;
    
    for (int i=0;i<N;i++){
        int id;
        int fid;
        int mid;
        int k;
        cin>>id>>fid>>mid>>k;
        if (fid!=-1) unite(id,fid);
        if (mid!=-1) unite(id,mid);
        for (int i=0;i<k;i++){
            int cid;
            cin>>cid;
            unite(id,cid);
        }
        
        int num;
        int area;

        cin>>num>>area;

        Person p;
        p.house_num=num;
        p.area=area;
        p.id=id;

        persons.push_back(p);
        
    }
    for (int i = 0; i < MAXN; i++) {
        if (exist[i]) {
            find(i);  // 调用 find 会进行路径压缩
        }
    }

    vector<family> familys(MAXN);

    for (const Person& p : persons){
        int root=find(p.id);
        familys[root].house_num += p.house_num;  // 累加房产套数
        familys[root].area += p.area;            // 累加房产面积
    }
    for (int i = 0; i < MAXN; i++) {
        if (exist[i]) {                 // 如果这个人出现过
            int root = find(i);          // 找到他所在家庭的根节点
            familys[root].population++; // 家庭人口数加1
            
            // 更新家庭的最小编号
            if (i < familys[root].min_id) {
                familys[root].min_id = i;
            }
        }
    }
    vector<Family> valid_families;
    for (int i = 0; i < MAXN; i++) {
        if (familys[i].population > 0) {
            valid_families.push_back(families[i]);
        }
    }
    
    sort(valid_families.begin(),valid_families.end(),
    [](const family& a,const family& b){
        double avg_a = (double)a.area / a.population;
        double avg_b = (double)b.area / b.population;
        if (avg_a != avg_b) return avg_a > avg_b;
        return a.min_id < b.min_id;
    });

    cout << valid_families.size() << endl;

        for (const Family& f : valid_families) {
        // 输出最小编号（4位，前导补0）
    cout << setw(4) << setfill('0') << f.min_id << " "
             // 输出家庭人口数
             << f.population << " "
             // 输出人均房产套数（保留3位小数）
             << fixed << setprecision(3) 
             << (double)f.house_num / f.population << " "
             // 输出人均房产面积（保留3位小数）
             << (double)f.area / f.population << endl;
    }
    
    return 0;
}