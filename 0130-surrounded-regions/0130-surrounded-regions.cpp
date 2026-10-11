class Solution {
public:
    bool dfs(vector<vector<char>>&grid,vector<vector<bool>>&visited,int r,int c,queue<pair<int,int>>&q){

        int n=grid.size();
        int m=grid[0].size(); 

        if(grid[r][c]=='X'){
            return true;
        }
        if(r==0 || r==n-1 || c==0 || c==m-1){
            return false;
        }
        visited[r][c]=true;
        q.push({r,c});

        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};
        bool ways=true;
        for(int i=0;i<4;i++){
            int nr=r+dx[i];
            int nc=c+dy[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc]){
                ways&=dfs(grid,visited,nr,nc,q);
            }       
        }

   
    return ways;


    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && board[i][j]=='O'){
                    queue<pair<int,int>>q;
                    if(dfs(board,visited,i,j,q)){
                        while(!q.empty()){
                            int x=q.front().first;
                            int y=q.front().second;
                            board[x][y]='X';
                            q.pop();
                        }
                    }
                }
            }
        }

    }
};