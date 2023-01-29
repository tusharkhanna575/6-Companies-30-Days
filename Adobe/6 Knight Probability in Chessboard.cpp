class Solution {
public:
    double knightProbability(int n, int K, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        vector<int> dr = {2, 2, -2, -2, 1, 1, -1, -1};
        vector<int> dc = {1, -1, 1, -1, 2, -2, 2, -2};
        for (int k = 0; k < K; k++) {
            vector<vector<double>> dp2(n, vector<double>(n, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int m = 0; m < 8; m++) {
                        int newR = i + dr[m];
                        int newC = j + dc[m];
                        if (newR >= 0 && newR < n && newC >= 0 && newC < n) {
                            dp2[newR][newC] += dp[i][j] / 8.0;
                        }
                    }
                }
            }
            dp = dp2;
        }
        double result = 0;
        for (auto& row : dp) {
            for (auto& val : row) {
                result += val;
            }
        }
        return result;
    }
};

/*
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/
