class Solution {
public:
    void bfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        int n = isConnected.size();

        queue<int> q;
        q.push(i);

        visited[i] = true;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (t == j)
                    continue;
                if (isConnected[t][j] && !visited[j]) {
                    q.push(j);
                    visited[j]=true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};