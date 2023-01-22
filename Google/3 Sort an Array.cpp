class Solution {
private:
    void heapify(vector<int> &nums, int n, int i) {
        int largest=i, l=2*i+1, r=2*i+2;
        if(l<n && nums[l]>nums[largest]) {
            largest=l;
        }
        if(r<n && nums[r]>nums[largest]) {
            largest=r;
        }
        if(largest!=i) {
            swap(nums[i], nums[largest]);
            heapify(nums, n, largest);
        }
    }
    void buildHeap(vector<int>& nums, int n) {
        for(int i=n/2-1; i>=0; i--) {
            heapify(nums, n, i);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        buildHeap(nums, n);
        for(int i=n-1; i>=0; i--) {
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums;
    }
};

/*
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
*/
