class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        long long sum = 0, max = -1, size = piles.size();
        for(int i = 0; i < size; i++){
            max = max > piles[i] ? max : piles[i];
        }

        int low = 1, high = max,k = max;
        while(low <= high){
            int mid = (low + high)/2;
            long long count = 0;
            for(int i = 0; i < size; i++){
                if(piles[i] % mid == 0)count += (piles[i]/mid);
                else count += (piles[i]/mid + 1);
            }
            
            if(count > h)low = mid + 1;
            else{
                k = min(k,mid);
                high = mid - 1;
            }
        }
        return k;
    }
};