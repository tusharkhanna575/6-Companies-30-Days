class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            dist[u][v] = dist[v][u] = w;
        }
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int res = 0, mn = n;
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                cnt += (dist[i][j] <= distanceThreshold);
            if (cnt <= mn) {
                mn = cnt;
                res = i;
            }
        }
        return res;
    }
};


/*
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
*/    
