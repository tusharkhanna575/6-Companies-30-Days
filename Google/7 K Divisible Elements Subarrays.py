class Solution:
    def countDistinct(self, nums: List[int], k: int, p: int) -> int:
        res=set()
        for i in range(len(nums)):
            if nums[i]%p==0:
                nums[i]=str(nums[i])+'x'
            else:
                nums[i]=str(nums[i])
        for i in range(len(nums)):
            c=0
            x=[]
            for j in range(i,len(nums)):
                x.append(nums[j])
                if x[-1][-1]=='x':
                    c+=1
                if c>k:
                    break
                else:
                    res.add(tuple(x))
        return len(res)
      
      
"""
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)
"""    
