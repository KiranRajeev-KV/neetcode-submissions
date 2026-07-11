class Solution {
public:
    int rec(int n, vector<int>& dp) {
        if(dp[n]!=-1) {
            return dp[n];
        }
        dp[n] = rec(n-1,dp) + rec(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        return rec(n,dp);
    }
};