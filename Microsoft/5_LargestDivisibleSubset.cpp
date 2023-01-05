class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) {
            return {};
        }
        sort(nums.begin(),nums.end());
        pair<int,int> dp[nums.size()];
        dp[0] = {1,-1};
        int m = 1; 
        int k = 0;
        for(int i = 1;i<nums.size();i++) {
            int pre = -1; 
            int t = 1;
            for(int j = i-1;j>=0;j--) {
                if(nums[i] % nums[j] == 0 && dp[j].first + 1 > t) {
                    t = dp[j].first + 1;
                    pre = j;
                }
            }
            dp[i] = {t,pre};
            if(t > m) {
                m = t; 
                k = i;
            }
        }
        vector<int> ret; 
        while(k != -1) {
            ret.push_back(nums[k]);
            k = dp[k].second;
        }
        return ret; 
    }
};

/*
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/
