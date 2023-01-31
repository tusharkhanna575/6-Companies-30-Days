class Solution:
    def customSortString(self, order: str, s: str) -> str:
        order = {c: i for i, c in enumerate(order)}
        s = list(s)
        s.sort(key=lambda x: order.get(x, 26))
        return "".join(s)
      
      
"""
    Time Complexity : O(nlogn)
    Space Complexity : O(n)
"""    
