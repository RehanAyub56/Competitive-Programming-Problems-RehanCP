class Solution {
public:

    bool Words(vector<vector<char>>&board,vector<vector<bool>>&visited,string &word,int i,int j,int k){
        int n=board.size();
        int m=board[0].size();
        if(k==word.length()){
            return true;
        }
        if(i>=n || i<0 || j>=m || j<0 || word[k]!=board[i][j] ||  visited[i][j]){
            return false;
        }
        
        
        visited[i][j]=true;

    bool ans=Words(board,visited,word,i+1,j,k+1) || Words(board,visited,word,i,j+1,k+1) || Words(board,visited,word,i-1,j,k+1) || Words(board,visited,word,i,j-1,k+1);
    

    visited[i][j] = false;

    return ans;
        
    }
    bool Rows(vector<vector<char>>board,string word,int i,int j){
        if(i>=board.size()){
            return false;
        }
        else if(j>=board[0].size()){
            return Rows(board,word,i+1,0);
        }
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));      
        bool ans=Words(board,visited,word,i,j,0);
        if(ans){
            return true;
        }
        return Rows(board,word,i,j+1);
    }
    bool exist(vector<vector<char>>& board, string word) {

        return Rows(board,word,0,0);
        
    }
};