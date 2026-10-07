class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> s;

        for(int i = 0; i<nums.size(); i++){
            s[nums[i]]++;
        }

        for(auto i : s){
            if(i.second > nums.size()/2){
                return i.first;
            }
        }

        return -1;
    }
};