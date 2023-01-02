class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int f=0, maxi, n=nums.size(), sum=0;
        if(n==0) {
            return 0;
        }
        for(int i: nums) {
            sum+=i;
        }
        for(int i=0;i<n;i++) {
            f+=(i*nums[i]);
        }
        maxi=f;
        for(int k=1;k<n;k++) {
            f+=(sum-n*nums[n-k]);
            maxi=max(maxi,f);
        }
        return maxi;
    }
};

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
*/
