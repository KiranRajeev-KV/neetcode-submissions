class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int product = 1;
    int zeroCount = 0;

    for (int x : nums) {
        if (x == 0) {
            zeroCount++;
        } else {
            product *= x;
        }
    }

    vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        if (zeroCount > 1) {
            res[i] = 0;
        } 
        else if (zeroCount == 1) {
            res[i] = (nums[i] == 0) ? product : 0;
        } 
        else {
            res[i] = product / nums[i];
        }
    }

    return res;
}
};
