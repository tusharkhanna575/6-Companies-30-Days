class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int ans=INT_MAX;
        for(int i=0;i<cards.size();i++) {
            if(mp.count(cards[i])>0) {
                ans=min(ans,i-mp[cards[i]]+1);
                mp[cards[i]]=i;
            }
            else {
                mp[cards[i]]=i;
            }
        }
        if(ans==INT_MAX) {
            return -1;
        }
        return ans;
    }
};

/*
    Time Complexity : O(n^2)
    Space Complexity : O(n)
*/    
