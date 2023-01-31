class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts:
            return 1.0
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        maxPts_sum = 1.0
        for i in range(1, n + 1):
            dp[i] = maxPts_sum / maxPts
            if i < k:
                maxPts_sum += dp[i]
            if i - maxPts >= 0:
                maxPts_sum -= dp[i - maxPts]
        return sum(dp[k:n + 1])

"""
    Time Complexity : O(n)
    Space Complexity : O(n)
"""    
