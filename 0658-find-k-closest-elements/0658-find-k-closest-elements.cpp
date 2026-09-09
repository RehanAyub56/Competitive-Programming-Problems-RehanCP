class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        #define P pair<int,int>

        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({abs(arr[i]-x),arr[i]});
        }
        vector<int>v;

        while(k && !pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
            k--;
        }


        sort(v.begin(),v.end());

        return v;

    }
};