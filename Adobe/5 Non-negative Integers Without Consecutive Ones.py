class Solution:
    @cache
    def findIntegers(self, n: int) -> int:
        if n <= 1: return n + 1
        k = int(log2(n))            
        return self.findIntegers(2**k - 1) + self.findIntegers(min(n - 2**k, 2**(k-1) - 1))
      
      
"""
    Time Complexity : O(2^n)
    Space Complexity : O(n)
"""    
