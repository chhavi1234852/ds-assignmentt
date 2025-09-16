#include <iostream>
#include <queue>
using namespace std;
class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return q.front();
    }
 bool empty() {
        return q.empty();
    }
};
int main() {
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    cout << st.top() << endl; 
    st.pop();
    cout << st.top() << endl;
    return 0;
}
