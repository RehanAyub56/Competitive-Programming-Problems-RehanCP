class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int j=0;
        vector<string>ans;
        stack<int>st;
        for(int i=1;i<=n && j<target.size();i++){
            if(i==target[j]){
                while(!st.empty()){
                    ans.push_back("Pop");
                    st.pop();
                }
                ans.push_back("Push");
                j++;
            }
            else if(i<target[j]){
                st.push(i);
                ans.push_back("Push");
            }
        }


        return ans;
    }
};