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

    int average(TreeNode* root){  
        if(root==NULL){
            return 0;
        }
        return root->val+average(root->left)+average(root->right);
    }
    int Nodes(TreeNode* root){
        if(root==NULL)return 0;
        return 1+Nodes(root->left)+Nodes(root->right);
    }

    int Traverse(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int aver=(root->val + average(root->left) + average(root->right))/Nodes(root);
        if(aver==root->val){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        return  Traverse(root) + averageOfSubtree(root->left) + averageOfSubtree(root->right);
        
    }
};