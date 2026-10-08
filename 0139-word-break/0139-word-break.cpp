class Solution {
public:

    bool word(string s,vector<string>& wordDict,vector<int>&dp,int i){
        if(i>=s.length()){
            return true;
        }

        if(dp[i]!=-1){
            return dp[i];
        }

    for(int k=0;k<wordDict.size();k++){
        bool fnd=true;
        int l=i;

        for(int j=0;j<wordDict[k].size();j++,l++){
            if(l >= s.length() || s[l]!=wordDict[k][j]){
                fnd=false;
                break;
            }            
        }
        if(fnd){
           if(word(s,wordDict,dp,i+wordDict[k].size())){
            return dp[i]=true;
           }
        }

        

    }

    return dp[i]=false;

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        return word(s,wordDict,dp,0);

    }
};