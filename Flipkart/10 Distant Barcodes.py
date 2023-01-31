class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        n = len(barcodes)
        c = Counter(barcodes)
        barcodes_freq = [(val, key) for key, val in c.items()]
        barcodes_freq.sort(reverse=True)
        res = [0] * n
        idx = 0
        for freq, code in barcodes_freq:
            for _ in range(freq):
                if idx >= n:
                    idx = 1
                res[idx] = code
                idx += 2
        return res
      
      
"""
    Time Complexity : O(nlogn)
    Space Complexity : O(n)
"""    
