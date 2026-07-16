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
        
        for (int num : st) {
            if (st.contains(num - 1))
                continue;

            int len = 1;
            while (st.contains(num + len))
                len++;

            maxV = max(maxV, len);
        }
        return maxV;
    }   
};
