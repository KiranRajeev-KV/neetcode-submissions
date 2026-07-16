class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        unordered_set<int> st;
        for(int i =0; i<nums.size();i++) {
            st.insert(nums[i]);
        }

        int maxV = -1;
        
        for(int i =0; i<nums.size();i++) {
            if(st.contains(nums[i]-1)) {
                continue;
            }
            int len = 1;
            while(st.find(nums[i] + len) != st.end()) {
                len++;
            }
            maxV = max(len, maxV);
        }
        return maxV;
    }   
};
