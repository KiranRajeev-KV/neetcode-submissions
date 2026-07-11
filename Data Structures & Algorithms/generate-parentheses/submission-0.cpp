class Solution {
public:
    void backtrack(string temp , vector<string> &res, int n, int open, int close) {
        if(open == n && close == n) {
            res.push_back(temp);
            return;
        }

        if(close<open) {
            temp.push_back(')');
            backtrack(temp, res, n, open, close+1);
            temp.pop_back();
        }
        
        if(open<n) {
            temp.push_back('(');
            backtrack(temp, res, n, open+1, close);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack("(", res, n, 1, 0);
        return res;
    }
};
