class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        if k == 1:
            return 1
        k -= 1
        cur = 1
        while k > 0:
            steps = self.getSteps(n, cur, cur+1)
            if steps <= k:
                cur += 1
                k -= steps
            else:
                cur *= 10
                k -= 1
        return cur

    def getSteps(self, n, n1, n2):
        steps = 0
        while n1 <= n:
            steps += min(n+1, n2) - n1
            n1 *= 10
            n2 *= 10
        return steps
      
      
"""
    Time Complexity : O(logn)
    Space Complexity : O(1)
"""    
