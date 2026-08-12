class Solution {
public:
/*
Discussion :-

Use of DFS And Topological Sort 
Topological Sort is due to the Acyclic Directed Graph and someTime for some Courses the Ordering not matter More then one answer can exist

We can also use Both cycle Detection and making order simultanously But I done it using the dfs for cycle and TOPOLOGY SORT for the constuction like that It will wok

*/
vector<int>v;
    bool Topologic(map<int,vector<int>>&mp,vector<bool>&visit,int i){
        
        if(visit[i]){
            return true;
        }
        visit[i]=true;

        for(int j=0;j<mp[i].size();j++){
            Topologic(mp,visit,mp[i][j]);    
        }

        v.push_back(i);
        return true;
    }
    bool dfs(map<int,vector<int>>&mp,vector<bool>&visited,int i){
        if(visited[i]){
            return false;
        }
        if(mp[i].empty()){
            return true;
        }
        visited[i]=true;

        for(int j=0;j<mp[i].size();j++){
            if(!dfs(mp,visited,mp[i][j])){
                return false;
            }
        }

        visited[i]=false;
        mp[i].clear();
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>mp;
        for(int i=0;i<numCourses;i++)mp[i]={};
        for(int i=0;i<prerequisites.size();i++)
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);

        map<int,vector<int>>mp2=mp;
        vector<bool>visited(numCourses,false),visit(numCourses,false);

        for(int i=0;i<numCourses;i++){
            if(!dfs(mp,visited,i)){
                return {};
            }
        }

        
        for(int i=0;i<visit.size();i++){
            if(!visit[i]){
                Topologic(mp2,visit,i);
            }
        }
        reverse(v.begin(),v.end());
        return v;
        
    }
};