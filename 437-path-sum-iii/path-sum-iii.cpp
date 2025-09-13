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
    int target;
    int count;
    void path(TreeNode* temp, vector<long> v){
        for(auto &x : v){
            x += temp->val;
            if(x == target)count++;
        }
        if(temp->val == target)count++;
        v.push_back(temp->val);
        if(temp->left)path(temp->left,v);
        if(temp->right)path(temp->right, v);
        return;
    }
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        count = 0;
        if(root == nullptr)return 0;
        path(root, {});
        return count;
    }
};