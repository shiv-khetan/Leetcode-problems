class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        int fresh = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();

            int row = temp[0];
            int col = temp[1];
            int time = temp[2];

            ans = max(ans, time);

            for (int k = 0; k < 4; k++) {
                int nr = row + drow[k];
                int nc = col + dcol[k];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    grid[nr][nc] == 1) {

                    grid[nr][nc] = 2;
                    fresh--;

                    q.push({nr, nc, time + 1});
                }
            }
        }

        if (fresh > 0)
            return -1;

        return ans;
    }
};