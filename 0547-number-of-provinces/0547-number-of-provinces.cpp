class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected,
             vector<int>& visited) {

        visited[node] = 1;

        for(int i = 0; i < isConnected.size(); i++) {

            if(isConnected[node][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        vector<int> visited(n, 0);

        int provinces = 0;

        for(int i = 0; i < n; i++) {

            if(!visited[i]) {
                provinces++;

                dfs(i, isConnected, visited);
            }
        }

        return provinces;
    }
};