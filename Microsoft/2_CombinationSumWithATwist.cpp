class Solution {
private: 
    void help(int index, int sum, int n, vector<int>&combination, vector<vector<int>>&ans, int k) {
        if(sum==n && k==0) {
            ans.push_back(combination);
            return;
        }
        if(sum>n) {
            return;
        }
        for(int i=index;i<=9;i++) {
            if(i>n) {
                break;
            }
            combination.push_back(i);
            help(i+1,sum+i,n,combination,ans,k-1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> combination;
        help(1,0,n,combination,ans,k);
        return ans;
    }
};

/*
    Time Complexity : O(n**2)
    Space Complexity : O(n**2)
*/