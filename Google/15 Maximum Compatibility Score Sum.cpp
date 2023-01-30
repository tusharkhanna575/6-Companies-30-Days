class Solution {
public:
 int f(int ind,vector<vector<int>>& students, vector<vector<int>>& mentors,vector<int>&vis){
      
      int n= students.size();
      int m= students[0].size();
      if(ind==n) return 0;
      int ans=0;
      for(int i=0;i<n;i++){
          if(!vis[i]){
              int d=0;
              vis[i]=1;
              for(int j=0;j<m;j++) if((students[ind][j]^mentors[i][j])==0) d++;
         ans= max(ans,d+f(ind+1,students,mentors,vis));
         vis[i]=0;
          }
      }
      return ans;
 }


    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
       int n= students.size();
       int m= students[0].size();
       vector<int>vis(n);
    return f(0,students,mentors,vis);
    }
};


/*
     Time Complexity : O(2^n)
     Space Complexity : O(n)
*/
