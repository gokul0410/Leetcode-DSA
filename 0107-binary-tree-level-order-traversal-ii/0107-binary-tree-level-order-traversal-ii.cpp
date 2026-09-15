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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>result;
        if(root == nullptr) return result;
        queue<TreeNode*>q;  q.push(root);
        result.push_back({root->val});
        while(!q.empty()){
            int sz = q.size();
            vector<int>temp;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push(node->left);
                    temp.push_back(node->left->val);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                    temp.push_back(node->right->val);
                }
            }
            if(!temp.empty())
                result.push_back(temp);
        }
            reverse(result.begin(),result.end());
            return result; 
    }
};