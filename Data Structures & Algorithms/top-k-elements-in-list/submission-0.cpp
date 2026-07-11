class Solution {
   public:
    static bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;

        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> freq;

        for (auto& p : counts) {
            freq.push_back({p.first, p.second});
        }

        sort(freq.begin(), freq.end(), cmp);

        vector<int> result;

        for (int i = 0; i < k; i++) {
            result.push_back(freq[i].first);
        }

        return result;
    }
};