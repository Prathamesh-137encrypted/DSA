class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int i = 0, j = 1, k = n - 1;
        while(i < n - 2) {
            j = i + 1;
            k = n - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j+1 < n && nums[j] == nums[j+1])j++;
                    while(k-1 > 0 && nums[k] == nums[k-1])k--;
                   
                }
                if(nums[i] + nums[j] + nums[k] > 0)k--;
                else j++;
            }
            while(i + 1 < n && nums[i] == nums[i + 1])i++;
            i++;
        }
        return ans;
    }
    
};