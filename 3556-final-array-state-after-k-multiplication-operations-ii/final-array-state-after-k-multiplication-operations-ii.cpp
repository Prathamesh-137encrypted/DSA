class Solution {
public:
    long long mod = 1000000007;
    long long powMod(long long m, int p){
        long long result  = 1LL;
        while(p > 0){
            if(1 & p) result = (result * m) % mod;
            m = (m * m) % mod;
            p /= 2;
        }
        return result;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        
        if(multiplier == 1) return nums;
        priority_queue<pair<long long,int>, vector<pair<long long, int>> , greater<pair<long long, int>>> pq;

        vector<long long> v(nums.size());
        for(int i = 0; i < nums.size(); i++){
            pq.push({1LL * nums[i], i});
        }

        int mx = *max_element(nums.begin(), nums.end());
        int op = 0;
        while(op < k){
            pair<long long, int> p = pq.top();
            pq.pop();
            if(p.first * multiplier <= mx){
                p.first *= multiplier;
                pq.push(p);
            }
            else{
                pq.push(p);
                break;
            }
            

            op++;
        }
        k -= op;
        int yash = k / nums.size();
        int rem = k % nums.size();

        while(rem){
            pair<long long, int> p = pq.top();
            pq.pop();
            p.first *= multiplier;
            pq.push(p);

            rem--;
        }
        while(!pq.empty()) {
            pair<long long, int> p = pq.top();
            pq.pop();
            p.first %= mod;
            p.first *= powMod(multiplier, yash);
            p.first %= mod;
            v[p.second] = p.first;
        }



        // for(int i = 0; i < nums.size(); i++) {
        //     pq.push({nums[i], i});
        // }
        vector <int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
           
            ans[i] = static_cast<int>(v[i]);
        }
        return ans;
    }
};