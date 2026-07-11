class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i<j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void backtrack(int idx, vector<string> temp, string s, vector<vector<string>> &res) {
        if(idx == s.size()) {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i< s.size(); i++) {
            if (isPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                backtrack(i + 1, temp, s, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        backtrack(0, temp, s, res);
        return res;
    }
};
