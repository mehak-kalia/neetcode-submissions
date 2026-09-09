class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> ans;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int a = ans.top(); ans.pop();
                int b = ans.top(); ans.pop();
                ans.push(b);        // restore b
                ans.push(a);        // restore a
                ans.push(a + b);    // push the new sum
            }
            else if (operations[i] == "C") {
                ans.pop();
            }
            else if (operations[i] == "D") {
                int a = ans.top();
                ans.push(2 * a);
            }
            else {
                ans.push(stoi(operations[i]));
            }
        }

        int total = 0;
        stack<int> temp = ans;
        while (!temp.empty()) {
            total += temp.top();
            temp.pop();
        }
        return total;
    }
};