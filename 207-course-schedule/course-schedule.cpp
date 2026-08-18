class Solution {
public:
    bool has_cycle(int start, vector<bool> &visited, vector<vector<int>> &adj, vector<bool> & curr_path){
        visited[start]=true;
        curr_path[start]=true;

        for(int node: adj[start]){
            if(!visited[node]){
                if(has_cycle(node,visited,adj,curr_path))return true;
            }
            else if(curr_path[node]){
                return true;
            }
        }

        curr_path[start]=false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<bool> visited(numCourses,false);
        vector<bool> curr_path(numCourses,false);

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(has_cycle(i,visited,adj,curr_path))return false;
            }
        }
        return true;
    }
};