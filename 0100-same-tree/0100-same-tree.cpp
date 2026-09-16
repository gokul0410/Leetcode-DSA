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
    vector<vector<int>> check(TreeNode* root){
        vector<vector<int>>result;
        if(root == nullptr) return result;
        queue<TreeNode*>q;
        q.push(root);
        result.push_back({root->val});
        while(!q.empty()){
        int sz = q.size();
        vector<int>temp;
        while(sz--){
            TreeNode* node = q.front();
            q.pop();
            TreeNode* l = node->left;
            TreeNode* r = node->right;
            if(l!= nullptr){
                temp.push_back(l->val);
                q.push(l);
            }else temp.push_back(INT_MIN);
            if(r!=nullptr){
                temp.push_back(r->val);
                q.push(r);
            }else temp.push_back(INT_MIN);
        }
        if(temp.size()>0)
        result.push_back(temp);
       }
       return result;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<vector<int>> r1 = check(p);
        vector<vector<int>> r2 = check(q);
        return r1==r2;
    }
};