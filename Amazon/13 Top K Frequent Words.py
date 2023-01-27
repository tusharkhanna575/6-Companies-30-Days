class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        c = Counter(words) 
        ans = sorted(c, key = lambda x: (-c[x],x))
        return ans[:k]
    
"""
    Time Complexity : O(n*logn)
    Space Complexity : O(n)
"""
