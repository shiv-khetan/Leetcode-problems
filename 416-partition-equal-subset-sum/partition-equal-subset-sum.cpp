class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;

        for (int x : nums)
            total += x;

        if (total % 2)
            return false;

        int target = total / 2;
        int n=nums.size();

        vector<vector<int>> dp(
            n+1,
            vector<int>(target + 1, false)
        );

        for(int i=0;i<n+1;i++){
            dp[i][0]=true;
        }

        for(int i=1;i<n+1;i++){
            for(int s=1;s<target+1;s++){
                dp[i][s] = dp[i-1][s];

                if(s>=nums[i-1]){
                    dp[i][s]=dp[i][s] || dp[i-1][s-nums[i-1]];
                }
            }
        }

        return dp[n][target];
    }
};