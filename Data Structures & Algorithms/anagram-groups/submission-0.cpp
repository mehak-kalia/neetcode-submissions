class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string,vector<string>> abc;
        vector<vector<string>> ans;

        for(int i = 0; i< strs.size(); i++){
            string value = strs[i];
            sort(value.begin(), value.end());
            abc[value].push_back(strs[i]);

        }

        for(auto& pair :abc){
            ans.push_back(pair.second);
        }


        return ans;
        
    }
};
