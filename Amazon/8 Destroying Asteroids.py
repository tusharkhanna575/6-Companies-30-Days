class Solution:
    def asteroidsDestroyed(self, mass: int, asteroids: List[int]) -> bool:
        asteroids.sort()
        for a in asteroids:
            if a>mass:
                return False
            mass+=a
        return True
      
"""
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
"""    
