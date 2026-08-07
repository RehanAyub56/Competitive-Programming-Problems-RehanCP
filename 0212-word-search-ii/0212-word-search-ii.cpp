class TrieNode{
    public:
    TrieNode*Node[26];
    bool isEnd;

    TrieNode(){
        for(int i=0;i<26;i++){
            Node[i]=NULL;
        }
        isEnd=false;
    }
};
class Solution {
public:
vector<string>ans;
TrieNode*root;

void Tree(vector<string>& words){


    for(int i=0;i<words.size();i++){
            TrieNode*curr=root;
        for(int j=0;j<words[i].length();j++){
            int idx=words[i][j]-'a';
            if(curr->Node[idx]==NULL){
                TrieNode*newNode=new TrieNode();
                curr->Node[idx]=newNode;
            }
            curr=curr->Node[idx];
        }
        curr->isEnd=true;
    }

}

    bool Find(vector<vector<char>>&board,TrieNode*curr,vector<vector<bool>>&visited,string word,int i,int j){
        int n=board.size();
        int m=board[0].size();


        if(i>=n || j>=m || i<0 || j<0  || visited[i][j]){
            return false;
        }
        int idx=board[i][j]-'a';
        if(curr->Node[idx]==NULL){
            return false;
        }
        curr = curr->Node[idx];

        word += board[i][j];

        if(curr->isEnd){
            ans.push_back(word);
            curr->isEnd=false;
        }

            visited[i][j] = true;

        bool ans=(Find(board,curr,visited,word,i+1,j) ||
                  Find(board,curr,visited,word,i,j+1) ||
                  Find(board,curr,visited,word,i-1,j) ||
                  Find(board,curr,visited,word,i,j-1));

        visited[i][j]=false;

        return ans;
    }
    void Traverse(vector<vector<char>>&board,int i,int j){
        int n=board.size();
        int m=board[0].size();
        
        if(i>=n){
            return;
        }
        if(j>=m){
            Traverse(board,i+1,0);
            return;
        }
        vector<vector<bool>>b(n,vector<bool>(m,false));
        Find(board,root,b,"",i,j);
        Traverse(board,i,j+1);

    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();
        Tree(words);
        Traverse(board,0,0);

        return ans;
    }
};