class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>> &ans,vector<int>& temp, int idx){
        if(idx == nums.size()){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[idx]);
        dfs(nums,ans,temp,idx+1);

        //not take
        temp.pop_back();
        dfs(nums,ans,temp,idx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;

        dfs(nums,ans,temp,0);

        return ans;
    }
};