class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (string word: strs) {
            string key = word;
            sort(key.begin(),key.end());
            if (map.find(key) == map.end()) {
                map[key].push_back(word);
            } else {
                map[key].push_back(word);
            }
        }
        vector<vector<string>> results;
        for(pair<string, vector<string>> p: map) {
            results.push_back(p.second);
        }
        return results;
    }
};
