class Solution {
public:
    const int mod=1e9+7;
    int peopleAwareOfSecret(int totalDays, int delay, int forget) {
        vector<long long> peopleAware(totalDays, 0);
        long long totalPeopleAware = 0;
        peopleAware[0] = 1;
        for(auto i = 0; i < totalDays; i++){
            for(auto k = delay; k < forget && i + k < totalDays; k++){
                peopleAware[i + k] = (peopleAware[i + k] + peopleAware[i]) % mod;
            }
            totalPeopleAware = (totalPeopleAware + peopleAware[i]) % mod;
            if(i >= forget){
                totalPeopleAware = (totalPeopleAware - peopleAware[i - forget] + mod) % mod;
            }
        }
        return totalPeopleAware;
    }
};

/*
      Time Complexity : O(n^2)
      Space Complexity : O(n)
*/      
