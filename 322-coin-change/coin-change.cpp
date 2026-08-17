class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, INT_MAX);
        prev[0] = 0;

        for (int amt = 1; amt < amount + 1; amt++){
            if(amt%coins[0]==0){
                prev[amt]=amt/coins[0];
            }
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, INT_MAX);
            curr[0] = 0;
            for (int amt = 1; amt < amount + 1; amt++) {
                curr[amt] = prev[amt];
                if (amt >= coins[i] && curr[amt - coins[i]] != INT_MAX)
                    curr[amt] = min(curr[amt], 1 + curr[amt - coins[i]]);
            }
            prev=curr;
        }
        return prev[amount]==INT_MAX?-1:prev[amount];
    }
};