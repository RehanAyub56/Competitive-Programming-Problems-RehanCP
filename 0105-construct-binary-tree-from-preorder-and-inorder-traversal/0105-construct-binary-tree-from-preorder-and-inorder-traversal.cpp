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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp.insert({inorder[i],i});
        }

        TreeNode*root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            stack<TreeNode*>st;
            st.push(root);

            while(!st.empty()){
            TreeNode*newNode=st.top();
            st.pop();
            if(mp[newNode->val]>mp[preorder[i]]){
                if(newNode->left==NULL){
                TreeNode*Node=new TreeNode(preorder[i]);
                newNode->left=Node; 
                break;                 
                }
                else{
                st.push(newNode->left);
                }
            }
            else if(mp[newNode->val]<mp[preorder[i]]){
                if(newNode->right==NULL){
                TreeNode*Node=new TreeNode(preorder[i]);
                newNode->right=Node; 
                break;                 
                }
                else{
                st.push(newNode->right);
                }
            }

            }
        }

        return root;

    }
};