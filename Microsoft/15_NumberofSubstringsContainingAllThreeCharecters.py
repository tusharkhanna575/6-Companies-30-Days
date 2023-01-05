class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        counts = [0, 0, 0]
        left = 0
        right = 0
        result = 0
        while right < len(s):
            counts[ord(s[right]) - ord('a')] += 1
            
            while all(counts):
                counts[ord(s[left]) - ord('a')] -= 1
                left += 1
            
            result += left
            right += 1
        
        return result
"""
  Time Complexity : O(n)
  Space Complexity : O(1)
"""
