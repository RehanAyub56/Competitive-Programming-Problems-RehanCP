class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=true;
                    bool level=false;
                    while(!q.empty()){
                        level=true;
                        pair<int,int>node=q.front();
                        q.pop();

                        vector<int>dx={1,-1,0,0};
                        vector<int>dy={0,0,1,-1};
                        int r=node.first;
                        int c=node.second;
                        for(int k=0;k<4;k++){
                            int dr=r+dx[k];
                            int dc=c+dy[k];

       if(dr>=0 && dr<n && dc>=0 && dc<m && !visited[dr][dc] && grid[dr][dc]=='1'){
                            visited[dr][dc]=true;
                            q.push({dr,dc});
        }

                        }

                    }

                    if(level){
                        ans++;
                    }

                }
            }
        }



        return ans;
    }
};