class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort(reverse=True)
        l, r = 0, len(piles) - 1
        ans = 0
        while l + 1 < r:
            ans += piles[l + 1]
            l += 2
            r -= 1
        return ans
      
      
"""
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
"""    
