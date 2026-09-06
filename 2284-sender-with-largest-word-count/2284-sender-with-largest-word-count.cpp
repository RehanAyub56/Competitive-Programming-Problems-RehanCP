class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string,int>mp;

        for(int i=0;i<messages.size();i++){
            int val=count(messages[i].begin(),messages[i].end(),' ')+1;
            mp[senders[i]]+=val;
        }

        priority_queue<pair<int,string>>pq;

        for(auto it:mp){
            pq.push({it.second,it.first});
        }

        return pq.top().second;
    }
};