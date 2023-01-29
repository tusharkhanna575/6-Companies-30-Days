class Solution:
    def mostPopularCreator(self, cts: List[str], ids: List[str], views: List[int]) -> List[List[str]]:
        d = {}
        n = len(ids)
        max_v = 0
        for i in range(n):
            if cts[i] not in d :
                d[cts[i]] = [views[i] , ids[i] , views[i]]
            
            else:
                d[cts[i]][0] += views[i]
                if views[i] > d[cts[i]][2] :
                    d[cts[i]][2] = views[i]
                    d[cts[i]][1] = ids[i]
                elif views[i] == d[cts[i]][2] :
                    d[cts[i]][1] = min(d[cts[i]][1] , ids[i])

            if d[cts[i]][0] > max_v:
                max_v = d[cts[i]][0]

        ans = []
        for c in d:
            if d[c][0] == max_v:
                ans.append([c , d[c][1]])
        return ans
        
        
        
"""
    Time Complexity : O(n)
    Space Complexity : O(n)
"""    
