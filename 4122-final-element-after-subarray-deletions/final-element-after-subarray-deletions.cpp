class Solution {
public:
    
    int finalElement(vector<int>& v) {
        return max(v[0],v[v.size() -1]);
    }
};