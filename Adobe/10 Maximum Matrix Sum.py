class Solution:
    def maxMatrixSum(self, mat: List[List[int]]) -> int:
        neg = sum(x<1 for r in mat for x in r)%2
        m = min(abs(x) for r in mat for x in r) if neg else 0
        return sum(abs(x) for r in mat for x in r)-2*m
      
      
"""
    Time Complexity : O(n^2)
    Space Complexity : O(1)
"""    
