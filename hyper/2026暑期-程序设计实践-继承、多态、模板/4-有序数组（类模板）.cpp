#include <iostream>
using namespace std;

/* 请在这里填写答案 */
template <class T>
class MyArray {
private:
    T* data;
    int size;
    
public:
    MyArray(int size) {
        this->size = size;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            cin >> data[i];
        }
    }
    
    ~MyArray();
    
    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (data[j] > data[j + 1]) {
                    T temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }
    
    bool check();
    
    void display() {
        for (int i = 0; i < size; i++) {
            if (i > 0) cout << " ";
            cout << data[i];
        }
        cout << endl;
    }
};
/* 请在这里填写答案 */

template<class T>
MyArray<T>::~MyArray(){ delete[] data;}

template<class T>
bool MyArray<T>::check(){
    int i;
    for(i=0;i<size-1;i++)
        if(data[i]>data[i+1]) { cout<<"ERROR!"<<endl;return false;}
    return true;
}
int main( )
{
    MyArray<int> *pI;
    MyArray<float> *pF;
    MyArray<char> *pC;
    int ty, size;
    cin>>ty;
    while(ty>0){
        cin>>size;
        switch(ty){
            case 1: pI = new MyArray<int>(size);   pI->sort(); pI->check(); pI->display(); delete pI; break;
            case 2: pF = new MyArray<float>(size); pF->sort(); pF->check(); pF->display(); delete pF; break;
            case 3: pC = new MyArray<char>(size);  pC->sort(); pC->check(); pC->display(); delete pC; break;
        }
        cin>>ty;
    }
    return 0;
}

