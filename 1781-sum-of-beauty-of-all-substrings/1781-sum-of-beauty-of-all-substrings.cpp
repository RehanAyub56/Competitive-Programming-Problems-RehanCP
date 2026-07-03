class Solution {
public:

    int MaxCount(vector<int>a){
        int mx=INT_MIN;
        for(int i=0;i<a.size();i++){
            mx=max(mx,a[i]);
        }
        return mx;
    }
    int MinCount(vector<int>a){
        int mn=INT_MAX;
        for(int i=0;i<a.size();i++){
            if(a[i]>0)
            mn=min(mn,a[i]);
        }

        return mn;
    }
    int beautySum(string s) {
        vector<int>mp(26,0);
        int ans=0;
        int mx;
        int mn;
        for(int l=0;l<s.length()-1;l++){


            fill(mp.begin(), mp.end(), 0);
            for(int r=l;r<s.length();r++){
                mp[s[r]-'a']++;

                    mx=MaxCount(mp);
                    mn=MinCount(mp);
                
                ans+=(mx-mn);
            }
                mx=INT_MIN;
                mn=INT_MAX;
          

        }

        return ans;
    }
};