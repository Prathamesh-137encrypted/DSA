class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        dq.push_back(0);
        vector<int> ans;
        for(int i = 1; i < k; i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        for(int i = k; i < nums.size(); i++){
            while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
            if(dq.front() <= i - k)dq.pop_front();
            ans.push_back(nums[dq.front()]);
            
        }
        return ans;
    } 
};