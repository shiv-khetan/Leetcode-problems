class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ch(26,0);
        for(char c: word){
            ch[c-'a']++;
        }
        int ans=0;
        sort(ch.begin(),ch.end(),greater<int>());
        for(int i=0;i<26;i++){
            ans+=(ch[i]*((i+8)/8));
        }
        return ans;
    }
};