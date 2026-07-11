class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> um;
        for(auto i: s) {
            if (um.contains(i)) {
                um[i]++;
            }
            um.insert({i,1});
        }

        for(auto j: t) {
            if (um.contains(j) && um[j]>=1) {
                um[j]--;
            } else {
                return false;
            }
        }

        return true;
    }
};
