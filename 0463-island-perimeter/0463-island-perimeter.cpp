class Solution {
public:
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                vector<int>dx={0,0,1,-1},dy={1,-1,0,0};
                int ways=0;
                for(int k=0;k<4;k++){
                    int nr=dx[k]+i;
                    int nc=dy[k]+j;
                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                        ways++;
                    }
                }
                     if(ways==0)ans+=4;
                else if(ways==1)ans+=3;
                else if(ways==2)ans+=2;
                else if(ways==3)ans+=1;

                }

            }
        }

        return ans;
    }
};