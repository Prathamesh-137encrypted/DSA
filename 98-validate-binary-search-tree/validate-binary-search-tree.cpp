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
    long ans;
    bool BST(TreeNode * root){
        bool Ans1 = true, Ans2 = true;
        if(root->left)Ans1 = BST(root->left);
        bool Ans = root->val <=  ans ? false : true;
        ans = root->val;
        if(root->right)Ans2 = BST(root->right);
        return Ans1 && Ans && Ans2;
    }
    bool isValidBST(TreeNode* root) {
        ans = LLONG_MIN;
        return BST(root);
    }
};