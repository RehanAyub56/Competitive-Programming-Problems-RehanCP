class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        #define P pair<int,int>
        int sum=0;
        int ans=INT_MAX;
        int n=nums.size();
        priority_queue<P,vector<P>,greater<P>>pq;
        for(int r=0;r<n;r++){
            sum+=nums[r];
           
           if(sum>=k){
            ans=min(ans,r+1);
           }

           while(!pq.empty() && sum-pq.top().first>=k){
            int val=pq.top().first;
            int idx=pq.top().second;
            ans=min(ans,r-idx);
            pq.pop();
           }

           pq.push({sum,r});

           

        }


        if(ans==INT_MAX)return -1;

        return ans;
    }
};