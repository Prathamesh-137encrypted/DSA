class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 1, size = s.size();
        if(size == 0)return 0;
        if(size == 1)return 1;
        unordered_set<char> Set;
        Set.insert(s[0]);
        int maxLength = 1, Max = 1;
        while(right < size){
            if(Set.find(s[right]) == Set.end()){
                Set.insert(s[right]);
                right++;
                Max = right - left;
            }
            else{
                maxLength = max(maxLength,Max);
                Set.erase(s[left]);
                left++;
            }
        }
        return max(maxLength,Max);
    }
};