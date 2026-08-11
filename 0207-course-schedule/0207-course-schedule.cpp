class Solution {
public:
/*
Discussion:
make the Map of Every Course Pointed to the vector represented All of his 
Prerequisites 
Example prerequisites=[[0,1],[0,2],[1,3],[1,4],[3,4]]

            0 -> [1,2]
            1 -> [3,4]
            2 -> []
            3 -> [4]
            4 -> []

            if every one is the prerequisite of other Impossbible answer 
            but we Start from empty list Which is not the prerequisite of any other Like ( 2 -> [] )


*/
        bool dfs(map<int, vector<int>>& mp,vector<bool>& visited,int i) {
            if(visited[i]){
                return false;
            }
            if(mp[i].empty()){
                return true;
            }

            visited[i]=true;
            bool ans=true;

            for(int j=0;j<mp[i].size();j++){
                if(!dfs(mp,visited,mp[i][j])){
                    return false;
                }
            }

            visited[i]=false;
            mp[i].clear();

            return true;
             
        }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {



        map<int,vector<int>>mp;
        for(int i=0;i<numCourses;i++){
            vector<int>a;
            mp[i]=a;
        }
        for(int i=0;i<prerequisites.size();i++){
            mp[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<bool>visited(numCourses,false);        
        
        for(int i=0;i<numCourses;i++){
            if(!dfs(mp,visited,i)){
                return false;
            }
        }

        return true;
    }
};