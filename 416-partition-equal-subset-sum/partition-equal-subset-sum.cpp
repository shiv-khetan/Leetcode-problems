class Solution {
public:
    bool dfs(vector<int>& nums, int idx, int sum, vector<vector<int>>& dp) {
        if (sum == 0) return true;
        if (idx == nums.size() || sum < 0) return false;

        if (dp[idx][sum] != -1)
            return dp[idx][sum];

        bool take = dfs(nums, idx + 1, sum - nums[idx], dp);
        bool notTake = dfs(nums, idx + 1, sum, dp);

        return dp[idx][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2)
            return false;

        int target = total / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return dfs(nums, 0, target, dp);
    }
};