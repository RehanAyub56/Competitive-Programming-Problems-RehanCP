class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int>b;
        b=nums;
        sort(b.begin(),b.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(int i=0;i<nums.size();i++){
            
        }
        for(int i=0;i<b.size();i++){
            int x=count(nums.begin(),nums.end(),b[i]);
            pq.push({x,b[i]});
        }
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }


        return ans;
    }
};
