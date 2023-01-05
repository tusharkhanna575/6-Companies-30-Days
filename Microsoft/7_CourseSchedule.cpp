class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<set<int>> g(numCourses);
        vector<int> in(numCourses);
        
        for(auto x: prerequisites) {
            g[x[0]].insert(x[1]);
            in[x[1]]++;
        }
        
        queue<int> q; 
        for(int i = 0;i<numCourses;i++) {
            if(in[i] == 0) {
                q.push(i);
            }
        }
        
        int vis = 0;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            vis++;
            for(int i : g[x]) {
                in[i]--;
                if(in[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        return (vis == numCourses);
    }
};

/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
