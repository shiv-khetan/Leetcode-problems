class Solution {
public:

    int stepCount(int n,vector<int> &dp){
        if(dp[n]!=-1)return dp[n];
        return dp[n] = stepCount(n-1,dp) + stepCount(n-2,dp);
    }
    int climbStairs(int n) {
        if(n<2)return 1;
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        return stepCount(n,dp);
    }
};