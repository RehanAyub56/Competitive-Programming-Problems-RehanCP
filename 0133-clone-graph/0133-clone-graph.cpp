/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node){
            return NULL;
        }

        unordered_map<Node*,Node*>copies;
        
        Node*copy=new Node(node->val,{});
        copies[node]=copy;
        queue<Node*>q;
        q.push(node);

        while(!q.empty()){
            Node* curr=q.front();
            q.pop();

            for(int i=0;i<curr->neighbors.size();i++){
                Node*x=curr->neighbors[i];
                if(copies.find(x)==copies.end()){
                    copies[x]=new Node(x->val,{});
                    q.push(x);
                }

                copies[curr]->neighbors.push_back(copies[x]);
            }

        }
    
        
        return copies[node];

    }
};