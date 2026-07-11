class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> um;
        for(auto i: nums) {
            if(um.contains(i)) return true;
            um.insert(i);
        }
        return false;
    }
};