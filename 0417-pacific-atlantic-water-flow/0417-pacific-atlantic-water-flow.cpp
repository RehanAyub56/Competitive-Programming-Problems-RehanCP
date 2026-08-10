class Solution {
public:
    vector<vector<int>>v;

    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<bool>>& visited){
        int n=grid.size();
        int m=grid[0].size();

        visited[r][c]=true;

        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        
        for(int i=0;i<4;i++){
            int nr=dx[i]+r;
            int nc=dy[i]+c;
            if(nr>=n || nc>=m || nr<0 || nc<0 ){
                continue;
            }

            if(visited[nr][nc]){
                continue;
            }
            if(grid[nr][nc]>=grid[r][c]){
                dfs(nr,nc,grid,visited);
            }
            
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>visitedP(n,vector<bool>(m,false));
        vector<vector<bool>>visitedA(n,vector<bool>(m,false));
        
        for(int i=0;i<m;i++){
            dfs(0,i,heights,visitedP);
        }
        for(int i=0;i<n;i++){
            dfs(i,0,heights,visitedP);
        }

        for(int i=0;i<m;i++){
            dfs(n-1,i,heights,visitedA);
        }
        for(int i=0;i<n;i++){
            dfs(i,m-1,heights,visitedA);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visitedP[i][j] && visitedA[i][j]){
                    v.push_back({i,j});
                }
            }
        }
    
        return v;
    }
};