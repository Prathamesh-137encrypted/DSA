class Solution {
public:
    int minOperations(string s) {
        int even1 = 0;
        int even0 = 0;
        int odd0 = 0;
        int odd1 = 0;

        for(int i = 0; i < s.size(); i += 2) {
            if(s[i] == '0')even0++;
            else even1++;
        }
        for(int i = 1; i < s.size(); i += 2) {
            if(s[i] == '0')odd0++;
            else odd1++;
        }

        int min1 = s.size() - (even1 + odd0);
        int min2 = s.size() - (even0 + odd1);

        if(min1 < min2){
            return min1;
        }
        else return min2;
    }
};