class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int Max = 0;
        for(int i = 0; i < nums.size(); i++){
            Max = Max < nums[i] ?  nums[i] : Max;
        }
        cout<<Max;
        int high = Max, low = 1, divisor = Max;
        while(low <= high){
            int mid = (low + high)/2;
            int dividendSum = 0;
            for(int i = 0; i < nums.size(); i++){
                if(nums[i] % mid == 0)dividendSum += (nums[i] / mid);
                else dividendSum += (nums[i] / mid) + 1;
            }
            if(dividendSum <= threshold){
                divisor = mid;
                high = mid - 1;
            }
            else low = mid + 1;

        }
        return divisor;
    }
};