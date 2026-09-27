class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto x:nums)
            st.insert(x);
        int ans=0;
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                int consec=0;
                while(st.find(x)!=st.end()){
                    consec++;
                    x++;
                }
                ans=max(ans,consec);
            }
        }

        return ans;
    }
};