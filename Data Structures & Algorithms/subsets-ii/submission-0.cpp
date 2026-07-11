class Solution {
public:
    void backtrack(int idx, vector<int> temp, vector<int> &nums, vector<vector<int>> &res) {
        if (idx>=nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[idx]);
        backtrack(idx+1, temp, nums, res);
        temp.pop_back();
        while(idx+1 <nums.size() && nums[idx] == nums[idx+1]) idx++;
        backtrack(idx+1, temp, nums, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        backtrack(0,temp,nums, res);
        return res;
    }
};
