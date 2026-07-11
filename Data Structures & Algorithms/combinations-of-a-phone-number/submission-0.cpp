class Solution {
public:
    vector<string> mapping = {
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    void backtrack(int idx, const string& digits, string& temp, vector<string>& res) {
        if (idx == digits.size()) {
            res.push_back(temp);
            return;
        }

        string letters = mapping[digits[idx] - '2'];

        for (char ch : letters) {
            temp.push_back(ch);
            backtrack(idx + 1, digits, temp, res);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;

        if (digits.empty()) {
            return res;
        }

        string temp;
        backtrack(0, digits, temp, res);
        return res;
    }
};