class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 1, size = nums.size();
        //edge cases
        if(nums[0] == 0 && k == 0 && size == 1)return 0;
        if((nums[0] == 1 && size == 1) ||  (nums[0] == 0 && k > 0 && size == 1))return 1;
        //For 1st element
        int Max = 0, zeroCount = 0, oneCount = 0;
        if(nums[0] == 0 && k > 0){
            zeroCount++;
            oneCount++;
            Max++;
        }
        else if(nums[0] == 1){
            oneCount++;
            Max++;
        }

        while(right < size){
            if(nums[right] == 1){
                oneCount++;
                right++;
            }
            else{
                if(k == 0){
                    Max = max(Max, oneCount);
                    right++;
                    left = right;
                    oneCount = 0;
                }
                else if(zeroCount + 1 > k){
                    Max = max(Max, oneCount);
                    if(nums[left] == 0){
                        zeroCount--;
                    } 
                    oneCount--;
                    left++;
                }
                else{
                    oneCount++;
                    right++;
                    zeroCount++;
                }
            }
            
        }
        Max = max(Max, oneCount);
        return Max;
    }
};