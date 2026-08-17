class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, h=nums.size()-1,ans=nums.size();

        while(l<=h){
            int m = l+ (h-l)/2;
            if(nums[m]>=target){
                ans = m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};