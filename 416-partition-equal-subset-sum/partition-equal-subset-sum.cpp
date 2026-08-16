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

        vector<int> prev(target + 1, false);

        prev[0] = true;

        for (int i = 1; i < n + 1; i++) {
            vector<int> curr(target + 1, false);
            for (int s = 1; s < target + 1; s++) {
                curr[s] = prev[s];

                if (s >= nums[i - 1]) {
                    curr[s] = curr[s] || prev[s - nums[i - 1]];
                }
            }
            prev=curr;
        }

        return prev[target];
    }
};