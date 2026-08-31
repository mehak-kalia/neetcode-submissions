#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> values;
    stack<int> mins;

public:
    MinStack() {
        // Member stacks are automatically initialized.
    }

    void push(int val) {
        values.push(val);

        if (mins.empty() || val <= mins.top()) {
            mins.push(val);
        }
    }

    void pop() {
        if (values.top() == mins.top()) {
            mins.pop();
        }

        values.pop();
    }

    int top() {
        return values.top();
    }

    int getMin() {
        return mins.top();
    }
};