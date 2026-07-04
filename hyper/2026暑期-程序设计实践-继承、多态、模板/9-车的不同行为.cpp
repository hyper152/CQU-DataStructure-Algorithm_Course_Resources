
/* 请在这里填写答案 */
#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void Run() {
        cout << "Vehicle run" << endl;
    }
    virtual void Stop() {
        cout << "Vehicle stop" << endl;
    }
};

class Bicycle : public Vehicle {
public:
    void Run() {
        cout << "Bicycle run" << endl;
    }
    void Stop() {
        cout << "Bicycle stop" << endl;
    }
};

class Motorcar : public Vehicle {
public:
    void Run() {
        cout << "Motorcar run" << endl;
    }
    void Stop() {
        cout << "Motorcar stop" << endl;
    }
};

void run(Vehicle &v) {
    v.Run();
}
/* 请在这里填写答案 */
int main(int argc, char const *argv[])
{
    Vehicle veh;
    Bicycle bic;
    Motorcar mot;
    run(veh);
    run(bic);
    run(mot);
    return 0;
}

