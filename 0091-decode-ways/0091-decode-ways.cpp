class Solution {
public:
    vector<int>dp;
    int Decode(string s,string r,int i){
        int n=s.size();

        if((i&& r.empty()) || (!r.empty() && (r[0]=='0' || stoi(r)>26))){
            return 0;
        }

        if(i>=n){
            return 1;
        }
        if(dp[i]==-1){
            string r1="",r2="";
            if(i<n)r1+=s[i];
            if(i<n-1){r2+=s[i],r2+=s[i+1];}
            return dp[i]=Decode(s,r1,i+1)+ Decode(s,r2,i+2);
        }
        return dp[i];
    }
    int numDecodings(string s) {
        for(int i=0;i<101;i++)dp.push_back(-1);
    
        int ans=Decode(s,"",0);

        return ans; 
    }
};