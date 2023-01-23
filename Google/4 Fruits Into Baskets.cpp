class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        if(n<=1) {
            return 1;
        }
        if(n==2) {
            return n;
        }
        unordered_map<int, int> mp;
        int i=0, j=0, ans=INT_MIN;
        while(j<fruits.size()) {
            mp[fruits[j]]++;
            if(mp.size()<=2) {
                ans=max(ans, j-i+1);
                j++;
            }
            else if(mp.size()>2) {
                while(mp.size()>2) {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0) {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                if(mp.size()==2) {
                    ans=max(ans, j-i+1);
                }
                j++;
            }
        }
        return ans;
    }
};

/*
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/
