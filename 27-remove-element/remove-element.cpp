class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] == val ? 51 : nums[i];
        }
        sort(nums.begin(), nums.end());
        int ct = nums.size(), ind = nums.size() - 1;
        while(ind >= 0 && nums[ind] == 51){
            ct--;
            ind--;
        }
        return ct;
    }
};