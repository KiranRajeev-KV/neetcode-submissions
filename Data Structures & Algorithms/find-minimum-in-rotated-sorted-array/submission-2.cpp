class Solution {
public:
    int findMin(vector<int> &nums) {
        int l =0;
        int r = nums.size() -1;
        int minimum = INT_MAX;
        while(l<=r) {
            int mid = (l+r)/2;

            // optimization for already sorted arrays
            if(nums[l] <= nums[r]) {
                minimum = min(nums[l],minimum);
                break;
            }

            if(nums[l] <= nums[mid]) {
                minimum = min(nums[l],minimum);
                l = mid +1;
            } else {
                minimum = min(nums[mid],minimum);
                r = mid - 1;
            }
        }
        return minimum;
    }
};
