#include <iostream>
#include <cmath> 
using namespace std;

class shape {// 形状类
public:
 double getArea()  // 求面积
 {return -1;}
 double getPerimeter() // 求周长
 {return -1;}
};
/* 请在这里填写答案 */
//Your code will be embed-ed here.
class RegularPolygon : public shape {
private:
    int n;
    double s;
    
public:
    RegularPolygon(int n, double s) : n(n), s(s) {}
    
    double getArea() {
        const double PI = 3.1415926;
        return n * s * s / (4 * tan(PI / n));
    }
    
    double getPerimeter() {
        return n * s;
    }
};
/* 请在这里填写答案 */
//Your code will be embed-ed here.

int main()
{
    int n; 
    double s;
    
    cin>>n>>s;
    RegularPolygon p(n,s);
    cout<<p.getArea()<<endl;

    cout<<p.getPerimeter()<<endl;

    return 0;
}