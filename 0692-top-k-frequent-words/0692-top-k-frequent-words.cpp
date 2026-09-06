struct compare{

bool operator()(const pair<int,string>&a,const pair<int,string>&b){
    if(a.first!=b.first){
        return a.first<b.first;
    }

    return a.second>b.second;
}

};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        #define P pair<int,string>

        for(auto word:words){
            mp[word]++;
        }
    
        priority_queue<P,vector<P>,compare>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        vector<string>ans;

        while(!pq.empty() && k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }


        return ans;

    }
};