class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, m=INT_MIN;
        for(int it:nums){
            sum+=it;
            m = max(m,sum);
            if(sum<0)sum=0;
        }
        return m;
    }
};