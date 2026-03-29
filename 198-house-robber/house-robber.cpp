class Solution {
public:
    // int house(vector<int>& nums, int rob, int profit, int idx) {
    //     cout << "flag1 " << profit << endl;
    //     if(idx == nums.size()) return profit;
    //     if(rob == 1) return house(nums, 0, profit, idx + 1);
    //     else return max(house(nums, 1, profit + nums[idx], idx + 1), house(nums, 0, profit, idx + 1));
    // }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        for(int i = nums.size() - 1; i >= 0; i--) {
            for(int rob = 0; rob < 2; rob++) {
                if(rob == 0) {
                    dp[i][rob] = max(dp[i + 1][1] + nums[i], dp[i + 1][0]);
                }
                else
                    dp[i][rob] = dp[i + 1][0];
            }
        }
        return max(dp[0][0], dp[0][1]);
    }
};