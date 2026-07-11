class Solution {
   public:
    void backtrack(int idx, vector<int> temp, int target, vector<int>& candidates,
                   vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i - 1] == candidates[i]) continue;
            if (target < candidates[i]) break;
            temp.push_back(candidates[i]);
            target -= candidates[i];
            backtrack(i + 1, temp, target, candidates, res);
            temp.pop_back();
            target += candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        backtrack(0, temp, target, candidates, res);
        return res;
    }
};
