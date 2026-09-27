class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string>mp;
        for(int i=0;i<knowledge.size();i++){
            mp[knowledge[i][0]]=knowledge[i][1];
        }
        string ans="";

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                i++;
                string r="";
                for(;i<s.size();i++){
                    if(s[i]==')'){
                        if(mp.find(r)!=mp.end()){
                            ans+=mp[r];
                            r="";
                        }
                        else{
                            ans.push_back('?');
                            r="";
                        }
                        break;
                    }
                    else{
                        r.push_back(s[i]);
                    }
                }
            }
            else{
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};