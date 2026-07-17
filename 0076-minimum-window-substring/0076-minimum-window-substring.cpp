class Solution {
public:

    string minWindow(string s, string t) {

        map<char,int> mpt;
        map<char,int> mps;
        
        for(int i=0;i<t.length();i++){
            mpt[t[i]]++;
        }
        string s_ans = "";
        int ans = INT_MAX;

        int l = 0;
        int need=0,have=0;
string r = t;
sort(r.begin(), r.end());
r.erase(unique(r.begin(), r.end()), r.end());
int mx=0,mn=0;
need = r.length();

for(int r = 0; r < s.length(); r++){

    if(mpt.count(s[r])){
        mps[s[r]]++;


        if(mps[s[r]] == mpt[s[r]]){
            have++;
        }
    }

 
    while(have == need){

        int len = r - l + 1;

        if(len < ans){
            ans = len;

            mx=len;
            mn=l;
  
        }

        if(mpt.count(s[l])){


            if(mps[s[l]] == mpt[s[l]]){
                have--;
            }

            mps[s[l]]--;
        }

        l++;

        while(l < s.length() && mpt.count(s[l]) == 0){
            l++;
        }
    }
}

          s_ans = s.substr(mn, mx);

        return s_ans;
    }
};
