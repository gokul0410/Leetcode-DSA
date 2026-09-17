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
    bool check(TreeNode* p , TreeNode* q){
        if(p == nullptr && q == nullptr) return true;
        if(p== nullptr && q != nullptr) return false;
        if(p != nullptr && q == nullptr) return false;
        if(p->val != q->val) return false;
        return check(p->left,q->right)&& check(p->right,q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root ->left == nullptr && root->right == nullptr) return true;
        if(root->left == nullptr && root ->right !=nullptr) return false;
        if(root->left != nullptr && root->right == nullptr ) return false;
        return check(root->left , root->right);
    }
};