#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    istringstream iss(line);
    stack<long long> st;
    string token;
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            long long b = st.top(); st.pop();
            long long a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoll(token));
        }
    }
    cout << st.top() << endl;
    return 0;
}
