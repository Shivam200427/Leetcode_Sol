class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int dr[] = {0, 0, -1, 1};
            int dc[] = {-1, 1, 0, 0};

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    ans[nr][nc] == -1) {
                    q.push({nr, nc});
                    ans[nr][nc] = ans[r][c] + 1;
                }
            }
        }
        return ans;
    }
};