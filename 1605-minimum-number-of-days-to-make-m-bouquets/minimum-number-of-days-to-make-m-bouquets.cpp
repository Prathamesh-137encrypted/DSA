class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {

        int size = bloomDay.size(), Max = 0;
        if(m > size || k > size || (INT_MAX / m) / k < 1 || size < m * k)return -1;

        for(int i = 0; i < size; i++){
            Max = bloomDay[i] > Max ? bloomDay[i] : Max;
        }

        int low = 0, high = Max, day = Max;
        while(low <= high){
            int mid = (low + high)/2, count1 = 0, count2 = 0;
            for(int i = 0; i < size; i++){
                if(bloomDay[i] <= mid)count1++;
                else count1 = 0;
                if(count1 == k){
                    count1 = 0;
                    count2++;
                }
                
            }
            if(count2 >= m  && count2 < day){
                day = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return day;
    }
};