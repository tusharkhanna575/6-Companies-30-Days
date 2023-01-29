class Solution:
    def maximumGood(self, statements: List[List[int]]) -> int:
        n = len(statements)

        def contradicts(goodPeople):
            goodPeople = set(goodPeople)
            couldBeGood = set(goodPeople)

            for i in goodPeople:
                for j in range(n):
                    if statements[i][j] == 0 and j in goodPeople:
                        return True
                    if statements[i][j] == 1 and j not in goodPeople:
                        couldBeGood.add(j)
            
            for i in couldBeGood:
                for j in range(n):
                    if statements[i][j] == 0 and j in couldBeGood:
                        return True
                    if statements[i][j] == 1 and j not in couldBeGood:
                        return True
            
            M = len(couldBeGood)
            return False
        
        def isValid(size):
            for goodPeople in combinations(range(n), size):
                if not contradicts(goodPeople):
                    return True
            
            return False 
        
        L = 0; R = n
        while L < R:
            M = (L+R+1)//2
            if not isValid(M):
                R = M-1
            else:
                L = M
        
        return L
      
      
"""
    Time Complexity : O(n^4)
    Space Complexity : O(n^2)
"""
    
