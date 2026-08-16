class Solution {
public:
    void dfs(vector<int>& nums, int idx,vector<int>& temp,vector<vector<int>>& ans) {

        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);

            dfs(nums, i + 1, temp, ans);

            temp.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(nums, 0, temp, ans);

        return ans;
    }
};