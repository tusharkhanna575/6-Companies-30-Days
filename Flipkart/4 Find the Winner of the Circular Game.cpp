class Solution {
private:
    int solve(int n,int k){
         if(n==1)
            return 0;
        else 
            return (solve(n-1,k)+k)%n;
    }
public:
    int findTheWinner(int n, int k) {
       return solve(n,k)+1;
    }
};


/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/    
