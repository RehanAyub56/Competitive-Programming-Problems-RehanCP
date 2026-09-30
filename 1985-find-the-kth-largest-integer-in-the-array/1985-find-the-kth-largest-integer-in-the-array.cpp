class Solution {
public:
struct compare{
    bool operator()(string a,string b){
        if(a.length()==b.length()){
            return a<b;
        }
        else if(a.length()<b.length()){
            return true;
        }
        else{
            return false;
        }
    }
};
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,compare>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        k--;
        while(k){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};