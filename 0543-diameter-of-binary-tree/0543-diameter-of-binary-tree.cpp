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
int diameter;

int dia(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int leftH =dia(root->left);
    int rightH=dia(root->right);
    diameter=max(diameter,leftH+rightH);
    return 1+max(leftH,rightH);
}

    int diameterOfBinaryTree(TreeNode* root) {
        dia(root);
        return diameter;
    }
};