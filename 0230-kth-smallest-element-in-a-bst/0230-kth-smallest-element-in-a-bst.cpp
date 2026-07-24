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
    int kthSmallest(TreeNode* root, int k) {

        stack<TreeNode*>st;
        st.push(root);
        int s=0;
        TreeNode*newNode=st.top();
        while(!st.empty() || newNode!=NULL){

            while(newNode!=NULL){
                st.push(newNode);
                newNode=newNode->left;
            }
            newNode=st.top();
            st.pop();

            s++;
            if(s==k){
                return newNode->val;
            }

         newNode = newNode->right;            
        }

        

        return 0;

    }
};