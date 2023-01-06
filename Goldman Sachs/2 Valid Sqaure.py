class Solution:
    def dist (self, p1, p2):
        return math.sqrt((p1[0]-p2[0]) ** 2 + (p1[1]-p2[1]) ** 2)

    def validSquare(self, p1: List[int], p2: List[int], p3: List[int], p4: List[int]) -> bool:
        vertices = [p1, p2, p3, p4]
        dists = []
        for v in vertices:
            for w in vertices:
                if v != w:
                    dists.append(self.dist(v,w))

        comps = len(dists)
        distSet= set(dists)
        return comps == 12 and len(distSet) == 2   

"""
	Time Complexity : O(n)
	Space Complexity : O(1)
"""
