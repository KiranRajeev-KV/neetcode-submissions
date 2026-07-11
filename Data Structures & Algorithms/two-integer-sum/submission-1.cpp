class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++) {
            int wanted = target - nums[i];
            vector<int> result = {i};
            
            auto it = find(nums.begin() + i + 1, nums.end(), wanted);

            if (it != nums.end() && (it - nums.begin()) != i) {
                return {i, int(it - nums.begin())};
            }
        }
    }
};
