class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        n = len(grid)
        def neighbors(i, j):
            for x, y in [(i-1, j), (i+1, j), (i, j-1), (i, j+1)]:
                if 0 <= x < n and 0 <= y < n:
                    yield x, y
                    
        heap = [(grid[0][0], 0, 0)]
        visited = set([(0, 0)])
        while heap:
            height, i, j = heapq.heappop(heap)
            if (i, j) == (n-1, n-1):
                return height
            for x, y in neighbors(i, j):
                if (x, y) not in visited:
                    visited.add((x, y))
                    heapq.heappush(heap, (max(height, grid[x][y]), x, y))
                    
                    
                    
"""
    Time Complexity : O(n^2 log n^2)
    Space Complexity : O(n^2)
"""    
