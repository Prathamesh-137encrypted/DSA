class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0] = 1;
        int cnt = 0;
        int num = 0;
        for(int i = 0; i < nums.size(); i++){
            num += nums[i];
            cnt += (prefix[num -k]);
            prefix[num]++;
        }
        return cnt;
    }
};