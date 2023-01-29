class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        c=0
        d={}
        
        for i in nums:
            if i-int(str(i)[::-1]) in d:
                d[i-int(str(i)[::-1])]+=1
            else:
                d[i-int(str(i)[::-1])]=1
                
        for i,j in d.items():
            c+=(j*(j-1)//2)
            
        return c%(10**9+7)
      
"""
    Time Complexity : O(n)
    Space Complexity : O(n)
"""
