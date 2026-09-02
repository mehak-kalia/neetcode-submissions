class Solution {
public:

    string encode(vector<string>& strs) {

        string ans;

        for(int i = 0; i<strs.size(); i++){
            ans += strs[i];
            ans += "~";

        }
        return ans;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        string v = "";                    // declared OUTSIDE the loop

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '~') {            // single quotes for char comparison
                ans.push_back(v);
                v = "";                   // reset only when delimiter found
            } else {
                v.push_back(s[i]);
            }
        }

        return ans;
    }
};
