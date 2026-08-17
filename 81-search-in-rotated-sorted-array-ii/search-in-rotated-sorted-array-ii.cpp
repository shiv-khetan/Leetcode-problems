class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (nums[m] == target)
                return true;

            // Cannot determine which side is sorted
            if (nums[l] == nums[m] && nums[m] == nums[h]) {
                l++;
                h--;
                continue;
            }

            // Left half is sorted
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }

            // Right half is sorted
            else {
                if (nums[m] < target && target <= nums[h]) {
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
        }

        return false;
    }
};