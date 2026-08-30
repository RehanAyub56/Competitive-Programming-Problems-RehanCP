class Solution {
public:

    string Lexicograph(string s,string r){
        if(s.empty() || s.length()>r.length()){
            return r;
        }
        else if(s.length()==r.length()){
            for(int i=0;i<s.length();i++){
                if(s[i]!=r[i]){
                    if(r[i]=='0')
                        return r;
                    else
                        return s;
                }
            }
        }

        return s;
    }

    string shortestBeautifulSubstring(string s, int k) {
        int l=0,r=0;
        int cnt=0;
        int n=s.length();
        string ans="";
        
        vector<int>a;
        for(int i=0;i<n;i++){
            if(s[i]=='1')a.push_back(i);
        }

        while(r<a.size()){
            int range=r-l+1;
            if(range<k)r++;
            if(range==k){
                string temp=s.substr(a[l],a[r]-a[l]+1);
                ans=Lexicograph(ans,temp);
                l++;
                r++;
            }
            
        }
        
        return ans;

    }
};