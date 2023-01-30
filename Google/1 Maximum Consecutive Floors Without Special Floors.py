class Solution:
    def maxConsecutive(self, bottom: int, top: int, special: List[int]) -> int:
        special.sort()
        special = [bottom-1] + special + [top+1]
        ans = 0
        for i in range(1,len(special)):
            d = (special[i]-1)-special[i-1]
            ans = max(ans,d)
        return ans
      
      
"""
    Time Complexity : O(nlogn)
    Space Complexity : O(n)
"""    
