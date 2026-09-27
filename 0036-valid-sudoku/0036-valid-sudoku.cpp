class Solution {
public:

    bool SubMatrix(vector<vector<char>>&board,int r,int c){
        map<char,int>mp;
        int row=r+3,col=c+3;
        for(;r<row;r++){
            for(int cc=c;cc<col;cc++){
                if(board[r][cc]!='.'){
                    mp[board[r][cc]]++;
                    if(mp[board[r][cc]]>1){
                        return false;
                    }
                }
            }
        }


        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=0;j<n;j++){
                if(board[i][j]!='.'){
                    mp[board[i][j]]++;
                    if(mp[board[i][j]]>1){
                        return false;
                    }
                }
            }
            mp.clear();

            for(int j=0;j<n;j++){
                if(board[j][i]!='.'){
                    mp[board[j][i]]++;
                    if(mp[board[j][i]]>1){
                        return false;
                    }
                }
            }
        }

        mp.clear();
        int r=-3,c=-3;
        for(int i=0;i<n;i++){
            if(i%3==0){
                r+=3;
                c=0;
            }
            else{
                c+=3;
            }
            cout<<r<<" "<<c;
            if(!SubMatrix(board,r,c))return false;

        }



        return true;
    }
};