class Solution {
public:
    bool canJump(vector<int>& nums) {
        int Max = 0;
        int i = 0;
        for(i = 0; i < nums.size(); i++){
            if(Max > nums[i])Max--;
            else{
                Max = nums[i];
            }
            if(Max == 0)break;
        }
        if(i >= nums.size() - 1)return true;
        
        else return false;
    }
};