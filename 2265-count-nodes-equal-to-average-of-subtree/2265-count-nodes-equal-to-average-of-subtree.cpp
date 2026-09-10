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
    pair<int,int> postorder(TreeNode* root , int &count){
        if(root == nullptr) return {0,0};
        auto [ls,lc] = postorder(root->left,count);
        auto [rs,rc] = postorder(root->right,count);
        int sum = ls+rs+root->val;
        int cnt = lc+rc+1;
        if(sum/cnt == root->val) count++;
        return {sum,cnt};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0 ;
        postorder(root , result);
        return result;
    }
};