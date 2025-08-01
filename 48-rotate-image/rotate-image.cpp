class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j < size; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        for(int i = 0; i < size; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};