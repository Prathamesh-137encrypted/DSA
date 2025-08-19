class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1;
        vector<int> v2;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0)v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        for(int i = 0; i < nums.size(); i++){
            if(i % 2 == 0)nums[i] = v1[i/2];
            else nums[i] = v2[(i/2)];
        }
        return nums;
    }
};