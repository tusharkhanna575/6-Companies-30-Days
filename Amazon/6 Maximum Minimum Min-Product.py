class Solution:
    def maxSumMinProduct(self, nums: List[int]) -> int:
        st, best = [], 0
        nums.append(0)
        for num in nums:
            summ = 0
            while len(st) > 0 and num <= st[-1][0]:
                (poppedVal, poppedSum) = st.pop()
                best = max(best, poppedVal * (poppedSum + summ))
                summ += poppedSum
            st.append((num, summ + num))
        return best % (10**9 + 7)
      

"""
    Time Complexity : O(n)
    Space Complexity : O(n)
"""
