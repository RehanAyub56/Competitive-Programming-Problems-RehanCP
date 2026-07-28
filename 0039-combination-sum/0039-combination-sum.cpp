class Solution {
public:
vector<vector<int>>v;
vector<int>path;
    void SUM(vector<int>&candidates,int target,int i,int sum,vector<int>path){
        if(sum>target || i>=candidates.size()){
            return;
        }
        else if(sum==target){
            v.push_back(path);
            return;
        }

        SUM(candidates,target,i+1,sum,path);


        path.push_back(candidates[i]);
        
        SUM(candidates,target,i,sum+candidates[i],path);
        path.pop_back();

        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        int i=0,sum=0;
        SUM(candidates,target,i,sum,path);

        return v;
    }
};