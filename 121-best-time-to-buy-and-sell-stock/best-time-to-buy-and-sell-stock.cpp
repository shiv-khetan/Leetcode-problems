class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0, mini=INT_MAX;
        for(int it: prices){
            mini = min(mini,it);
            ans = max(ans,it-mini);
        }
        return ans;
    }
};