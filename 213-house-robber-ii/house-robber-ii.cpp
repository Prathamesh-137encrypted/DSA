class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<vector<int>> dp1(nums.size(), vector<int>(2, 0));
        for(int i = nums.size() - 2; i >= 0; i--) {
            for(int rob = 0; rob < 2; rob++) {
                if(rob == 0) {
                    dp1[i][rob] = max(dp1[i + 1][1] + nums[i], dp1[i + 1][0]);
                }
                else
                    dp1[i][rob] = dp1[i + 1][0];
            }
        }
        vector<vector<int>> dp2(nums.size() + 1, vector<int>(2, 0));
        int case1 = max(dp1[0][0], dp1[0][1]);
        for(int i = nums.size() - 1; i >= 1; i--) {
            for(int rob = 0; rob < 2; rob++) {
                if(rob == 0) {
                    dp2[i][rob] = max(dp2[i + 1][1] + nums[i], dp2[i + 1][0]);
                }
                else
                    dp2[i][rob] = dp2[i + 1][0];
            }
        }
        int case2 = max(dp2[1][0], dp2[1][1]);
        return max(case1, case2);
    }
};