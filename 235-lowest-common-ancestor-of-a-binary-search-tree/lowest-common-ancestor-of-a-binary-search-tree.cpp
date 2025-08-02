/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p)return p;
        if(root == q)return q;
        TreeNode* temp1 = NULL;
        TreeNode* temp2 = NULL;
        if(root->left && root->val > p->val && root->val > q->val)temp1 = lowestCommonAncestor(root->left, p, q);
        else if(root->right && root->val < p->val && root->val < q->val)temp2 = lowestCommonAncestor(root->right, p, q);
        else return root;
        if(temp1)return temp1;
        else return temp2;
    }
};