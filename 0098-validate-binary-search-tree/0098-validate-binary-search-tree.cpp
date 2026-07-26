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
long long int ValidMIN(TreeNode* root, long long int minVal){
     if(root==NULL){
        return minVal;
     }
        minVal=max(minVal,(long long)root->val);
    
    minVal= ValidMIN(root->left ,minVal);
    minVal= ValidMIN(root->right,minVal);   


    return minVal;

}
long long int ValidMAX(TreeNode* root, long long int maxVal){
     if(root==NULL){
        return maxVal;
     }     
        maxVal=min(maxVal,(long long)root->val);
    
    maxVal = ValidMAX(root->left ,maxVal);
    maxVal = ValidMAX(root->right,maxVal); 

    return maxVal;
}
bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }
        else{
            long  minVal=LLONG_MIN;
            long  maxVal=LLONG_MAX;
        
            long long int num1=ValidMIN(root->left,minVal);
            long long int num2= ValidMAX(root->right,maxVal);
        if(!(num2>root->val && num1<root->val)){
                return false;
        }
        else{
            return isValidBST(root->left) && isValidBST(root->right);
        }

        }

        return true;
    }
};