class Solution {
public:
vector<vector<int>>ans;
set<vector<int>>st;
    void Sum(vector<int>& nums,vector<int>a, int target,int i){

        int n=nums.size();

        if(target==0){
            sort(a.begin(),a.end());
            st.insert(a);
            return ;
        }
        if(target<0 || i>=n){
            return ;
        }
        
        a.push_back(nums[i]);
        Sum(nums,a,target-nums[i],i+1);
        a.pop_back();
        while(i<n-1 && nums[i]==nums[i+1]){
            i++;
        }
        Sum(nums,a,target,i+1);


        return;

    }


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
        Sum(candidates,{},target,0);
        for(auto it:st){
            ans.push_back(it);
        }

    return ans;

    }
};