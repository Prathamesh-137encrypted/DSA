/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> v;
    int target;
    void path(TreeNode* temp, int sum, vector<int> p){
        sum += temp->val;
        p.push_back(temp->val);
        if(!temp->left && !temp->right && target == sum){
            v.push_back(p);
        }
        if(temp->left)path(temp->left, sum, p);
        if(temp->right)path(temp->right, sum, p);
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        v.clear();
        target = targetSum;
        if(root == nullptr)return {};
        path(root, 0, {});
        return v;
    }
};