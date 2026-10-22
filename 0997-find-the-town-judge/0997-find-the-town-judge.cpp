class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.empty() && n>1)return -1;
        map<int,vector<int>>mp;
        vector<int>in(n+1,0),out(n+1,0);
        for(int i=0;i<trust.size();i++){
            in[trust[i][1]]++;
            out[trust[i][0]]++;
        }

        for(int i=1;i<=n;i++){
            if(out[i]==0 && in[i]==n-1){
                return i;
            }
        }
        
        
        return -1;


    }
};