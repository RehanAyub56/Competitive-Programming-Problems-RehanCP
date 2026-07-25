/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return " ";
        }
        string s="";
        queue<TreeNode*>st;
        st.push(root);
        s+=(to_string(root->val));
        s.push_back(' ');

        while(!st.empty()){
            TreeNode*newNode=st.front();
            st.pop();
            if(newNode->left!=NULL){
                st.push(newNode->left);
                s+=(to_string(newNode->left->val));
                s.push_back(' ');
            }
            else{
                s+=("-10000 ");               
            }

            if(newNode->right!=NULL){
                st.push(newNode->right);
                s+=(to_string(newNode->right->val));
                s.push_back(' ');
            }
            else{
                s+=("-10000 ");               
            }

        }
     
        cout<<s<<endl;

        return s;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if(data==" "){
            TreeNode*newNode=NULL;
            return newNode;
        }
        vector<int>a;
        int l=0;
        int idx=0;

        for(int i=0;i<data.length();i++){
            if(data[i]==' '){
                string ss=data.substr(idx,l);
                
                int m=stoi(ss);
                a.push_back(m);
                idx=i+1;
                l=0;
            }
            else{
                l++;
            }
        }

        

        
        TreeNode*root=new TreeNode(a[0]);
        

        bool left=true,right=false;
        queue<TreeNode*>pq;
        pq.push(root);
        
        for(int i=1;i<a.size();i+=2){

           
                TreeNode*newNode=pq.front();
                pq.pop();
            
                int val=a[i];
                

                
                    if(val==-10000){
                        newNode->left=NULL;
                    }
                    else{
                    TreeNode*newnode=new TreeNode(val);
                    newNode->left=newnode;
                    pq.push(newnode);
                    }

                val=a[i+1];

                    if(val==-10000){
                        newNode->right=NULL;
                    }
                    else{
                    TreeNode*newnode=new TreeNode(val);
                    newNode->right=newnode;
                    pq.push(newnode);

                    }
               
            
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));