class Solution {

private:
    vector<int> array;
    vector<int> original;

public:
    Solution(vector<int>& nums) {
        for(int i: nums) {
            array.push_back(i);
            original.push_back(i);
        }
    }
    
    vector<int> reset() {
        return array;
    }
    
    vector<int> shuffle() {
        for(int i=array.size()-1; i>0; i--) {
            int j=rand()%(i+1);
            swap(original[i], original[j]);
        }
        return original;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */


/*
    Time Complexity : O(n)
    Space Complexity : O(n)
*/
