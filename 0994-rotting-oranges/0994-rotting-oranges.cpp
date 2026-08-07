class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int ans=0;
        vector<int>dx={-1,1,0,0};
        vector<int>dy={0,0,-1,1};
        while(!q.empty()){
            vector<pair<int,int>>v;
            bool fnd=false;
            int size=q.size();
        for(int i=0;i<size;i++){
            pair<int,int>node=q.front();
            q.pop();

            int r=node.first;
            int c=node.second;
            
            for(int j=0;j<4;j++){
                int dr=r+dx[j];
                int dc=c+dy[j];

           if(dr<n && dc<m && dr>=0 && dc>=0 && grid[dr][dc]==1 ){
                    grid[dr][dc]=2;
                    v.push_back({dr,dc});

                    if(!fnd){
                        ans++;
                        fnd=true;
                    }
                }

            }
            


        }
            cout<<endl;

        while(!v.empty()){
            q.push(v.back());
            v.pop_back();
        }


        }



        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }


        return ans;


    }
};