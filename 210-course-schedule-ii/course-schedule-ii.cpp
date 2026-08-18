class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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

        vector<int> ans;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            ans.push_back(t);

            for (int i : adj[t]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                    v--;
                }
            }
        }

        if(v!=0)return {};
        return ans;
    }
};
