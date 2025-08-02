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
    unordered_set<int> s;
    bool ft(TreeNode* root, int k){
        if(s.find(k - root->val) != s.end())return true;
        else s.insert(root->val);
        bool temp1 = false, temp2 = false;
        if(root->left)temp1 = ft(root->left, k);
        if(root->right)temp2 = ft(root->right,k);
        return temp1 || temp2;
        
    }
    bool findTarget(TreeNode* root, int k) {
        s.clear();
        return ft(root,k);
    }
};