class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
       int m = grid.size();
    int n = grid[0].size();

    set<int, greater<int>> sums;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            // size 0 rhombus (single cell)
            sums.insert(grid[i][j]);

            for (int k = 1; ; k++) {

                int r1 = i + k;
                int r2 = i + 2 * k;
                int c1 = j - k;
                int c2 = j + k;

                if (r2 >= m || c1 < 0 || c2 >= n) break;

                int sum = 0;

                int x = i, y = j;

                // top -> right
                for (int t = 0; t < k; t++)
                    sum += grid[x + t][y + t];

                // right -> bottom
                for (int t = 0; t < k; t++)
                    sum += grid[x + k + t][y + k - t];

                // bottom -> left
                for (int t = 0; t < k; t++)
                    sum += grid[x + 2 * k - t][y - t];

                // left -> top
                for (int t = 0; t < k; t++)
                    sum += grid[x + k - t][y - k + t];

                sums.insert(sum);
            }
        }
    }

    vector<int> ans;
    for (auto x : sums) {
        ans.push_back(x);
        if (ans.size() == 3) break;
    }

    return ans;
    }
};