class Solution {
public:
    int trailingZeroes(int n) {
        int x=5,zero=0;
        while((n/x)>0){
            zero+=(n/x);
            x*=5;
        }
        return(zero);
    }
};

/*
    Time Complexity : O(logn)
    Space Complexity : O(1)
*/
