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
    int dfs(TreeNode* root ,int maxi){
        if(root == nullptr) return 0;
        int cnt=0;
        if(root->val >= maxi){
            cnt=1;
        }
        maxi=max(root->val,maxi);
        cnt+=dfs(root->left,maxi);
        cnt+=dfs(root->right,maxi);
        return cnt;
    }
public:
    int goodNodes(TreeNode* root) {
        int maxi = root->val;
        int result = dfs(root, root->val);
        return result;
    }
};