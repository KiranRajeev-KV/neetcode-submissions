class Solution {
   public:
    void backtrack(int idx, vector<int> temp, int target, vector<int>& nums,
                   vector<vector<int>>& res) {
                    if(idx >= nums.size()) {
                        if (target == 0) {
                            res.push_back(temp);
                            return;
                        }
                        return;
                    }

                    if(target - nums[idx] >= 0) {
                        temp.push_back(nums[idx]);
                        target -= nums[idx];
                        backtrack(idx, temp, target, nums, res);
                        temp.pop_back();
                        target += nums[idx];
                    }
                    backtrack(idx+1, temp, target, nums, res);
                   }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        if(nums.empty()) {
            return {};
        }
        vector<int>temp;
    vector<vector<int>> res;

    backtrack(0,temp,target,nums,res);
    return res;

    }
};
