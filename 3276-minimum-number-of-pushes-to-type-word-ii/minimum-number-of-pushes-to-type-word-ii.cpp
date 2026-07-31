class Solution {
public:
    int minimumPushes(string word) {
        vector<int> ch(26,0);
        for(char c: word){
            ch[c-'a']++;
        }
        int ans=0;
        sort(ch.begin(),ch.end());
        for(int i=0;i<2;i++){
            ans+=(ch[i]*4);
        }
        for(int i=2;i<10;i++){
            ans+=(ch[i]*3);
        }
        for(int i=10;i<18;i++){
            ans+=(ch[i]*2);
        }
        for(int i=18;i<26;i++){
            ans+=(ch[i]*1);
        }
        return ans;
    }
};