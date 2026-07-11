class Solution {
public:
    void backtrack(int idx, vector<int> temp,  vector<int>& nums, vector<vector<int>>& res) {
        if(idx>=nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        backtrack(idx+1, temp, nums, res);
        temp.pop_back();
        backtrack(idx+1, temp, nums, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }

        vector<vector<int>> res;
        vector<int> temp;
        backtrack(0,temp, nums, res);

        return res;
    }
};
