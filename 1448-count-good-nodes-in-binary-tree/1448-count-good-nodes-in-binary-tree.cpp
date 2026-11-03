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
    int ans;
    int preorder(TreeNode* root,int x){
        if(root==NULL)return 0;
        if(root->val>=x){
            x=root->val;
            ans++;
        }

        int left = preorder(root->left,x);
        int right= preorder(root->right,x);

        return 0;
    }
    int goodNodes(TreeNode* root) {
        ans=0;
        preorder(root,INT_MIN);

        return ans;
    }
};