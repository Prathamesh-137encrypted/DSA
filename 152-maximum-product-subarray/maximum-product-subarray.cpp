class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0];
        int Max = nums[0];
        int Min = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int temp = Max;
            Max = max({nums[i], Max * nums[i], Min * nums[i]});
            Min = min({nums[i], temp * nums[i], Min * nums[i]});

            ans = max(ans, Max);
        }

        return ans;
    }
};