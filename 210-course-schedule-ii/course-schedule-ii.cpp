class Solution {
public:
    bool has_cycle(int start, vector<bool>& visited, vector<vector<int>>& adj,
                   vector<bool>& curr_path, stack<int> &st) {
        visited[start] = true;
        curr_path[start] = true;

        for (int node : adj[start]) {
            if (!visited[node]) {
                if (has_cycle(node, visited, adj, curr_path,st))
                    return true;
            } else if (curr_path[node]) {
                return true;
            }
        }

        curr_path[start] = false;
        st.push(start);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> curr_path(numCourses, false);
        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (has_cycle(i, visited, adj, curr_path,st))
                    return {};
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
