class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int Sum = 0, Max = 0;
        for(int i = 0; i < weights.size(); i++){
            Sum += weights[i];
            Max = Max < weights[i] ? weights[i] : Max; 
        }

        int high = Sum, low = Max, load = Sum;
        while(low <= high){
            int mid = (low + high)/2;
            int weightCount = 0, day = 1;
            for(int i = 0; i < weights.size(); i++){
                weightCount += weights[i];
                if(weightCount > mid){
                    weightCount = weights[i];
                    day++;
                }
            }
            if(day <= days){
                high = mid - 1;
                load = mid;
            }
            else low = mid + 1;
        }
        return load;
    }
};