class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2)
            return false;

        int target = total / 2;
        int n = nums.size();

        vector<int> dp(target + 1, false);

        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int s = target; s >= nums[i]; s--) {
                dp[s] = dp[s] || dp[s - nums[i]];
            }
        }

        return dp[target];
    }
};