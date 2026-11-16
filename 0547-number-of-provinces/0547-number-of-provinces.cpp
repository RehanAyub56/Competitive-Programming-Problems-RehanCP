class Solution {
public:
    void dfs(map<int,vector<int>>mp,vector<bool>&visited,int i){
        if(visited[i]){
            return ;
        }

        visited[i]=true;

        for(int j=0;j<mp[i].size();j++){
            if(!visited[mp[i][j]])
            dfs(mp,visited,mp[i][j]);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] && i!=j){
                    mp[i].push_back(j);
                }
            }
        }

        vector<bool>visited(n,false);

        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(mp,visited,i);
                ans++;
            }
        }

        return ans;
    }
};