class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for(auto query : queries) {
            priority_queue<pair<string,int>> trimmedNumbers;
            for(int i=0;i<nums.size();i++) {
                int start = nums[i].length() - query[1];
                string trimmedNum = nums[i].substr(start, query[1]);
                if(trimmedNumbers.size() < query[0]) {
                    trimmedNumbers.push({trimmedNum,i});
                }
                else {
                    if(trimmedNumbers.top().first > trimmedNum) {
                        trimmedNumbers.pop();
                        trimmedNumbers.push({trimmedNum,i});
                    }
                }
            }
            int index = trimmedNumbers.top().second;
            res.push_back(index);
        }
        return res;
    }
};


/*
    Time Complexity : O(n^2 * logn)
    Space Complexity : O(n^2)
*/
