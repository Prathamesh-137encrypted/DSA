class Solution {
public:
    bool subset(vector<int> num, int sum, int n) {
        vector<vector<bool>> dp(num.size() + 1, vector<bool>(sum + 1, false));
        for(int i = 0; i <= n; i++) 
            dp[i][0] = true;

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(num[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num[i - 1]];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto x : nums) sum += x;

        if(sum % 2 != 0) return false;

        return subset(nums, sum / 2, nums.size());
    }
};