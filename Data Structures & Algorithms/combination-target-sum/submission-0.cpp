class Solution {
public:
    void backtrack(vector<vector<int>> &res, vector<int> nums, int idx, vector<int> &temp, int sum, int target) {
        if (idx >= nums.size()) {
            if (target ==sum) {
                res.push_back(temp);
                // return;
            }
            return;
        }



        if (nums[idx]+sum <= target) {
            temp.push_back(nums[idx]);
            sum += nums[idx];
            // cout<<sum<<" "<<target<<endl;
            backtrack(res, nums, idx, temp, sum, target);
            sum -= nums[idx];
            temp.pop_back();
        }
        // cout<<"notpicked: "<<sum<<" "<<target<<endl;
        backtrack(res, nums, idx+1, temp, sum, target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(res, nums, 0, temp, 0, target);
        return res;

    }
};
