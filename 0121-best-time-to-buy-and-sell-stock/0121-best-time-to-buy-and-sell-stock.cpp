class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        stack<int>st;
        int mx=0;
        int ans=-1;
        for(int i=0;i<prices.size();i++){
            st.push(prices[i]);
        }
        bool found=false;
        while(!st.empty()){
            mx=max(st.top(),mx);
            st.pop(); 
            if(!st.empty() && st.top()<mx){
                ans=max(ans,mx-st.top());
                found=true;
            }
        }

        if(found){
            return ans;
        }
        else{
            return 0;
        }

    }
};