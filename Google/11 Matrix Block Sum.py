class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        ans = [[0 for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                for q in range(max(0, i-k), min(m, i+k+1)):
                    ans[i][j]+=sum(mat[q][max(0, j-k): min(n, j+k+1)])
        return ans
      
      
"""
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
"""    
