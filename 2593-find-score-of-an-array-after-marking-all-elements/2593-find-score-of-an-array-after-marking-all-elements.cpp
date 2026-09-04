class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        vector<bool>b(nums.size(),false);
        long long int ans=0;
        while(!pq.empty()){
            int val=pq.top().first;
            int idx=pq.top().second;
            
            if(!b[idx]){
                b[idx]=true;
                if(idx>0)b[idx-1]=true;
                if(idx<n-1)b[idx+1]=true;
                ans+=val;
            }

            pq.pop();
        }

        return ans;

    }
};