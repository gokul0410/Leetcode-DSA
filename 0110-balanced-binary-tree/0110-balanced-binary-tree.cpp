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
private:
    int solve(TreeNode* root){
        if(root==nullptr) return 0;
        int lt = solve(root->left);
        int rt = solve(root->right);
        return 1+max(lt,rt);
    }
    bool result(TreeNode* root){
        if(root==nullptr) return true;
        if(abs(solve(root->left)-solve(root->right))>1){
            return false;
        }
        bool lt=result(root->left); 
        bool rt=result(root->right);
        if(!lt||!rt) return false;
        return true;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        bool val=result(root);
        return val;
    }
};