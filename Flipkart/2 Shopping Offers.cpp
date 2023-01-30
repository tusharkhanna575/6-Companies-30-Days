class Solution {
    int n;
public:
    int f(int ind, vector<int>&price, vector<vector<int>>& special, vector<int> &needs, map <pair<int, vector<int>>, int> &dp) {
        if(dp.find({ind, needs}) != dp.end()) return dp[{ind, needs}];
        if(ind == special.size()) {
            for(int i = 0; i < n; i++) {
                if(needs[i] < 0) return 1e9;
            }
            int sum = 0;
            for(int i = 0; i < n; i++) sum += needs[i]*price[i];
            return sum;
        }
        for(int i = 0; i < n; i++) {
            if(needs[i] < 0) return 1e9;
        }
        int flg = 0;
        for(int i = 0; i < special.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(needs[j] >= special[i][j]) cnt++;
            }
            if(cnt == n) {
                flg = 1;
                break;
            }
        }
        if(!flg) {
            int sum = 0;
            for(int i = 0; i < n; i++) sum += needs[i]*price[i];
            return sum;
        }
        vector <int> v = needs;
        for(int i = 0; i < n; i++) v[i] -= special[ind][i];
        int take = special[ind][n] + f(ind, price, special, v, dp);
        int notTake = f(ind + 1, price, special, needs, dp);
        return dp[{ind, needs}] = min(take, notTake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        map <pair<int, vector<int>>, int> dp;
        return f(0, price, special, needs, dp);
    }
};class Solution {
    int n;
public:
    int f(int ind, vector<int>&price, vector<vector<int>>& special, vector<int> &needs, map <pair<int, vector<int>>, int> &dp) {
        if(dp.find({ind, needs}) != dp.end()) return dp[{ind, needs}];
        if(ind == special.size()) {
            for(int i = 0; i < n; i++) {
                if(needs[i] < 0) return 1e9;
            }
            int sum = 0;
            for(int i = 0; i < n; i++) sum += needs[i]*price[i];
            return sum;
        }
        for(int i = 0; i < n; i++) {
            if(needs[i] < 0) return 1e9;
        }
        int flg = 0;
        for(int i = 0; i < special.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(needs[j] >= special[i][j]) cnt++;
            }
            if(cnt == n) {
                flg = 1;
                break;
            }
        }
        if(!flg) {
            int sum = 0;
            for(int i = 0; i < n; i++) sum += needs[i]*price[i];
            return sum;
        }
        vector <int> v = needs;
        for(int i = 0; i < n; i++) v[i] -= special[ind][i];
        int take = special[ind][n] + f(ind, price, special, v, dp);
        int notTake = f(ind + 1, price, special, needs, dp);
        return dp[{ind, needs}] = min(take, notTake);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = price.size();
        map <pair<int, vector<int>>, int> dp;
        return f(0, price, special, needs, dp);
    }
};


/*
    Time Complexity : O(n^2 * 2^n)
    Space Complexity : O(n^2)
*/    
