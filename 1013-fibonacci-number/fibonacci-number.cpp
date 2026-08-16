class Solution {
public:
    int dfs(int n, vector<int> &dp) {
        if(dp[n]!=-1)return dp[n];
        return dfs(n - 1,dp) + dfs(n - 2,dp);
    }
    int fib(int n) { 
        if(n<2)return n;
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        dp[1] = 1;
        return dfs(n,dp); 
    }
};