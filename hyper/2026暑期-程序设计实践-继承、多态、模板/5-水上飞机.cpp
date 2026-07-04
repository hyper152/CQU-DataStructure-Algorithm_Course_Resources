#include <iostream>
using namespace std;

/* 你提交的代码将被嵌在这里 */
// CRAFT 航行器类（基类）
class CRAFT {
protected:
    double speed;
    
public:
    // 构造函数
    CRAFT(double s) : speed(s) {
        cout << "创建航行器(速度: " << speed << ")" << endl;
    }
    
    // 析构函数
    virtual ~CRAFT() {
        cout << "销毁航行器(速度: " << speed << ")" << endl;
    }
    
    // Show函数
    virtual void Show() {
        cout << "航行(速度: " << speed << ")";
    }
};

// PLANE 飞机类（继承CRAFT）
class PLANE : virtual public CRAFT {
protected:
    double width;  // 翼展
    
public:
    // 构造函数
    PLANE(double s, double w) : CRAFT(s), width(w) {
        cout << "创建飞机(翼展: " << width << ")" << endl;
    }
    
    // 析构函数
    virtual ~PLANE() {
        cout << "销毁飞机(翼展: " << width << ")" << endl;
    }
    
    // Show函数
    virtual void Show() override {
        CRAFT::Show();
        cout << ", 翼展: " << width;
    }
};

// SHIP 船类（继承CRAFT）
class SHIP : virtual public CRAFT {
protected:
    double depth;  // 吃水深度
    
public:
    // 构造函数
    SHIP(double s, double d) : CRAFT(s), depth(d) {
        cout << "创建船(吃水: " << depth << ")" << endl;
    }
    
    // 析构函数
    virtual ~SHIP() {
        cout << "销毁船(吃水: " << depth << ")" << endl;
    }
    
    // Show函数
    virtual void Show() override {
        CRAFT::Show();
        cout << ", 吃水: " << depth;
    }
};

// SEAPLANE 水上飞机类（多重继承PLANE和SHIP）
class SEAPLANE : public PLANE, public SHIP {
public:
    // 构造函数
    SEAPLANE(double s, double w, double d) 
        : CRAFT(s), PLANE(s, w), SHIP(s, d) {
        cout << "创建水上飞机" << endl;
    }
    
    // 析构函数
    ~SEAPLANE() {
        cout << "销毁水上飞机" << endl;
    }
    
    // Show函数
    void Show() override {
        cout << "航行(速度: " << speed << ", 翼展: " << width << ", 吃水: " << depth << ")";
    }
};
/* 你提交的代码将被嵌在这里 */

int main()
{
    double s, w, d;
    CRAFT *p;
    cin >> s >> w >> d;
    p = new SEAPLANE(s, w, d);
    p->Show();
    delete p;
    return 0;
}