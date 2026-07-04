/* 请在这里填写答案 */
#include <iostream>
using namespace std;

class Point {
private:
    int x, y;  // 私有成员变量

public:
    // 构造函数
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 获取坐标值（用于友元函数访问）
    int getX() const { return x; }
    int getY() const { return y; }
    
    // 成员函数方式重载 += 运算符
    Point& operator+=(const Point& other) {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    
    // 成员函数方式重载 == 运算符（同时提供友元方式）
    bool operator==(const Point& other) const {
        return (this->x == other.x && this->y == other.y);
    }
    
    // 友元函数声明
    friend Point operator+(const Point& p1, const Point& p2);
    friend Point operator-(const Point& p1, const Point& p2);
    friend ostream& operator<<(ostream& out, const Point& p);
};

// 友元函数方式重载 + 运算符
Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.x + p2.x, p1.y + p2.y);
}

// 友元函数方式重载 - 运算符
Point operator-(const Point& p1, const Point& p2) {
    return Point(p1.x - p2.x, p1.y - p2.y);
}

// 友元函数方式重载 << 运算符
ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << "," << p.y;
    return out;
}
/* 请在这里填写答案 */



int main(int argc, char const *argv[])
{
    Point p1(2,3);
    cout<<p1<<endl;
    Point p2(4,5);
    cout<<p2<<endl;
    Point p3 = p1+p2;    
    cout<<p3<<endl;
    p3 = p2-p1;
    cout<<p3<<endl;
    p1 += p2;
    cout<<p1<<endl;
    cout<<(p1==p2)<<endl;
    return 0;
}
