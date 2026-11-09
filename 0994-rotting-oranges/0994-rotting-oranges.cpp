class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;
        int minutes = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty() && fresh > 0) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto [r, c] = q.front();
                q.pop();

                for(int d = 0; d < 4; d++) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                        continue;

                    if(grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }
        if(fresh > 0)
            return -1;
        return minutes;
    }
};