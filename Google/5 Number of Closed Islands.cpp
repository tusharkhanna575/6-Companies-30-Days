class Solution {
public:
    bool flag;
    int n, m;
    vector<vector<bool>> seen;
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        seen = vector<vector<bool>>(n, vector<bool>(m, false));
        int count = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!seen[i][j] and !grid[i][j]) {
                    flag = true;
                    DFS(i, j, grid);
                    if(flag)
                        count++;
                }
            }
        }
        return count;
    }
    void DFS(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 or j < 0 or i >= n or j >= m) {
            flag = false; // If edge of the island is wall, it is not counted!
            return;
        }
        if(seen[i][j])
            return;
        if(grid[i][j] == 1)
            return;
        seen[i][j] = true;
        DFS(i+1, j, grid);
        DFS(i, j+1, grid);
        DFS(i-1, j, grid);
        DFS(i, j-1, grid);
    }
};


/*
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)
*/    
