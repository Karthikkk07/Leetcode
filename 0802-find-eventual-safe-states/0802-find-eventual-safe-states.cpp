
class Solution {
public:

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {

            if(vis[i] == 0) {
                dfs(i, graph, vis);
            }

            if(vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
    bool dfs(int node, vector<vector<int>>& graph,
             vector<int>& vis) {

        vis[node] = 1;

        for(int neighbour : graph[node]) {

            if(vis[neighbour] == 1) {
                return false;
            }

            if(vis[neighbour] == 0) {
                if(!dfs(neighbour, graph, vis)) {
                    return false;
                }
            }
        }

        vis[node] = 2;
        return true;
    }
};
