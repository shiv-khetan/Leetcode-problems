class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        int v = numCourses;

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                v--;
            }
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();

            for (int i : adj[t]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                    v--;
                }
            }
        }

        return v==0;
    }
};