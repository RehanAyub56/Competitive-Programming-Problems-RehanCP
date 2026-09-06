class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=speed.size();
        
        vector<int>p,s;
    
        for(int i=0;i<n-1;i++){
            if(position[i+1]-position[i]>distance){
                p.push_back(position[i]);
                s.push_back(speed[i]);
            }
        }
        p.push_back(position[n-1]);
        s.push_back(speed[n-1]);        
        int ans=0;
        stack<int>st;
        for(int i=0;i<p.size();i++){

            while(!st.empty() && s[i]<s[st.top()]){
                ans++;
                st.pop();
            }

            st.push(i);
        }


        return p.size()-ans;
        
        
    }
};