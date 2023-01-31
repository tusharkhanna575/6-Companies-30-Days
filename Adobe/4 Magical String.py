class Solution:
    def magicalString(self, n: int) -> int:
        S = [1, 2, 2]
        i = 2
        while len(S) < n:
            S += S[i] * [3 - S[-1]]
            i += 1
        return S[:n].count(1)
      
      
"""
    Time Complexity : O(n)
    Space Complexity : O(1)
"""    
