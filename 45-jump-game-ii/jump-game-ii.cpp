class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 1e9);
        dp[0] = 0;
        for(int i = 0; i < nums.size();i++){
            for(int j = i + 1; j <= min(i + nums[i], (int)nums.size() - 1);j++){
                dp[j] = min(dp[j], dp[i] + 1);
            }
        }
        return dp[nums.size() - 1];
    }
};