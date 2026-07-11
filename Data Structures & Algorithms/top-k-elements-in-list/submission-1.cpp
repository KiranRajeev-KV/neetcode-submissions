class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);

        for (auto& p : freq) {
            int num = p.first;
            int count = p.second;

            buckets[count].push_back(num);
        }

        vector<int> result;

        for (int count = nums.size(); count >= 1; count--) {
            for (int num : buckets[count]) {
                result.push_back(num);

                if (result.size() == k) {
                    return result;
                }
            }
        }

        return result;
    }
};