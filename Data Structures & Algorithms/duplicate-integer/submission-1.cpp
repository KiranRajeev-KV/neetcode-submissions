class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> um;
        for(auto i: nums) {
            if(um.contains(i)) return true;
            um.insert({i, 1});
        }
        return false;
    }
};