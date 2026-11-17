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
    vector<int>pre,post;
    void preorder(TreeNode*root){
        if(!root) {pre.push_back(-1);return;}
        pre.push_back(root->val);
        preorder(root->left);
        preorder(root->right);

        return;
    }
    void postorder(TreeNode*root){
        if(!root){post.push_back(-1);return;}
        postorder(root->left);
        postorder(root->right);
        post.push_back(root->val);

        return;
    }
    bool isSymmetric(TreeNode* root) {
        preorder(root->left);
        postorder(root->right);

        for(int i=0;i<pre.size();i++){
            cout<<pre[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<post.size();i++){
            cout<<post[i]<<" ";
        }
        cout<<endl;
        if(pre.size()!=post.size()){
            return false;
        }
        int n=pre.size();
        
        for(int i=0;i<pre.size();i++){
            if(pre[i]!=post[n-i-1]){
                return false;
            }
        }

        return true;
    }
};