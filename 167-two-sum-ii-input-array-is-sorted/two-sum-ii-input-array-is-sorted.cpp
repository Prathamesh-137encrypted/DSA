class Solution {
public:
    int binary_search(vector<int> &v, int l, int target){
        int r = v.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(v[mid] == target) return mid;
            else if(v[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++) {
                int idx = binary_search(numbers, i + 1, target - numbers[i]);
                if(idx != -1) return {i + 1, idx + 1};
        }
        return {-1,-1};
    }
};