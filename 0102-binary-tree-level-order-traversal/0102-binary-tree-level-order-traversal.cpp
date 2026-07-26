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
vector<vector<int>> levelOrder(TreeNode* root) {
    
vector<vector<int>> v;
queue<TreeNode*> pq;

if (root == NULL) {
    return v;   
}

pq.push(root);

while (!pq.empty()) {          
    int levelSize = pq.size(); 
    vector<int> vv;

    for (int i = 0; i < levelSize; i++) {
        TreeNode* newNode = pq.front();
        pq.pop();
        vv.push_back(newNode->val);

        if (newNode->left != NULL) {
            pq.push(newNode->left);
        }
        if (newNode->right != NULL) {
            pq.push(newNode->right);
        }
    }

    v.push_back(vv);
}

return v;

}


};