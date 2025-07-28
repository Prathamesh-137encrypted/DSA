class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int high = nums.size() - 1, low = 0, mid = high / 2;
        while(low <= high){
            mid = low + (high - low)/2;
            if(target == nums[mid])return true;
            if(nums[mid] == nums[high]){
                while(high >= 0 && nums[high] == nums[mid])high--;
                if(high < 0)return false;
            }
            if(nums[low] == nums[mid]){
                while(low < nums.size() && nums[low] == nums[mid])low++;
                if(low >= nums.size())return false;
            }
            if(nums[high] == target || nums[low] == target)return true;
            if(nums[low] <= nums[mid]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else 
                    low = mid + 1;
            }
            else {
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else 
                    high = mid - 1;
            }
        }
        return false;
    }
};