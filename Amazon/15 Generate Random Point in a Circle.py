class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        radius = sqrt(random.random()) * self.radius
        x_center = random.uniform(0, 2 * pi)
        return [self.x_center + radius * math.cos(x_center), self.y_center + radius * math.sin(x_center)]

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()


"""
    Time Complexity : O(1)
    Space Complexity : O(1)
"""
