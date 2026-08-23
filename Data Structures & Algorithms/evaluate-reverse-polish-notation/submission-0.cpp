class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;

        for (int i = 0; i < tokens.size(); i++) {
            string& t = tokens[i];
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                int a2 = ans.top(); ans.pop();
                int a1 = ans.top(); ans.pop();

                if (t == "+") ans.push(a1 + a2);
                else if (t == "-") ans.push(a1 - a2);
                else if (t == "*") ans.push(a1 * a2);
                else ans.push(a1 / a2);
            } else {
                ans.push(stoi(t));
            }
        }

        return ans.top();
    }
};