
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                if(dfs(neighbor, adj, visited, pathVisited)) {
                    return true;
                }
            }
            else if(pathVisited[neighbor]) {
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites) {
            int course = it[0];
            int prerequisite = it[1];
            adj[prerequisite].push_back(course);
        }

        vector<int> visited(numCourses, 0);
        vector<int> pathVisited(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {

            if(!visited[i]) {

                if(dfs(i, adj, visited, pathVisited)) {
                    return false;
                }
            }
        }

        return true;
    }
};
