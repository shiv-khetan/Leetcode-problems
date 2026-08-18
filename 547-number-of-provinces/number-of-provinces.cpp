class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool> &visited){
        int n=isConnected.size();

        visited[i]=true;

        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(isConnected[i][j] && !visited[j]){
                dfs(isConnected,j,visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n,false);
        int count=0;

        for(int i=0; i<n;i++){
            if(!visited[i]){
                dfs(isConnected,i,visited);
                count++;
            }
        }
        return count;
    }
};