class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        ans = 0
        n = len(s)
        def solve(index,current,vis):
            nonlocal ans,n
            if(index == n):
                ans = max(ans,current)
                return
            for i in range(index,n):
                if(s[index:i+1] not in vis):
                    solve(i+1,current+1,vis+(s[index:i+1],))
        solve(0,0,())
        return ans
      
"""
    Time Complexity : O(2^n)
    Space Complexity : O(n)
"""
