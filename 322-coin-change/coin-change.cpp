class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        // Base case: only coins[0]
        for (int amt = 1; amt <= amount; amt++) {
            if (amt % coins[0] == 0) {
                dp[amt] = amt / coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            for (int amt = 1; amt <= amount; amt++) {
                // take
                if (amt >= coins[i] &&
                    dp[amt - coins[i]] != INT_MAX) {

                    dp[amt] = min(dp[amt],1 + dp[amt - coins[i]]);
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};