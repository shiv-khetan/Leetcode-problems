class Solution {
public:
    int dfs(vector<int>& coins, int idx, int amt, vector<vector<int>>& dp) {
        if (amt == 0)
            return 0;

        if (idx == coins.size() || amt < 0)
            return INT_MAX;

        if (dp[idx][amt] != -1)
            return dp[idx][amt];

        // take current coin
        int take = dfs(coins, idx, amt - coins[idx], dp);

        if (take != INT_MAX)
            take = 1 + take;

        // skip current coin
        int skip = dfs(coins, idx + 1, amt, dp);

        return dp[idx][amt] = min(take, skip);
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = dfs(coins, 0, amount, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};