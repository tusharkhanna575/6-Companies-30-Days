class Solution:
    def distinctEchoSubstrings(self, text: str) -> int:
        count=0
        dic=dict()
        for i in range(len(text)):
            a=i
            b=a+1
            for j in range(len(text[i:])):
                if text[a:b]==text[b:len(text[a:b])+b]:
                    if not text[a:b] in dic:
                        count+=1
                    dic[text[a:b]]=0
                b+=1
        
        return count 
      
      
"""
    Time Complexity : O(n^3)
    Space Complexity : O(n^2)
"""    
