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
    int num,ans;
    void order(TreeNode*root){
        if(root->left)order(root->left);
        num--;
        if(num == 0)ans = root->val;
        if(root->right)order(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        num = k;
        order(root);
        return ans;
    }
};