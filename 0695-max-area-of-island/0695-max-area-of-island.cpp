class Solution {
public:

int dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int r,int c,int sum){

    int n=grid.size();
    int m=grid[0].size();

    visited[r][c]=true;
    sum++;
    
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,-1,1};

    for(int i=0;i<4;i++){
        int nr=r+dx[i],nc=c+dy[i];

      if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]){
            sum=dfs(grid,visited,nr,nc,sum);
       }

    }
    return sum;
}

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int Area=0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    Area=max(Area,dfs(grid,visited,i,j,0));
                }
            }
        }

        
        return Area;

    }
};