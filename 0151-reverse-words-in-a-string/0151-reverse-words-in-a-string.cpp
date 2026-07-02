class Solution {
public:
    string reverseWords(string s) {

        while(s.back()==' '){
            s.pop_back();
            
        }

        reverse(s.begin(),s.end());
        while(s.back()==' '){
            s.pop_back();
        }
        reverse(s.begin(),s.end());

        vector<string>rr;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                rr.push_back(temp);
                temp="";
                while(s[i]==' '){
                    i++;
                }
                i--;
            }
            else{
                temp.push_back(s[i]);
            }
        }

        rr.push_back(temp);
        string ans="";
        for(int i=rr.size()-1;i>=0;i--){
            ans+=rr[i];
            if(i>0)
            ans.push_back(' ');
        }




        return ans;

    }
};