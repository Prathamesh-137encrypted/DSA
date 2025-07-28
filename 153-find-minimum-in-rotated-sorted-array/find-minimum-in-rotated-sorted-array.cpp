class Solution {
public:
    int findMin(vector<int>& nums) {
        int size =  nums.size();
        if(size == 1)return nums[0];
        int high = size - 1, low = 0;
        int target = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target)target = nums[mid];
            if(nums[low] <= nums[mid] && nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return target;
    }
};