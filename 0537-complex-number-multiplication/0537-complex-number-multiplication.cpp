class Solution {
public:
    pair<int,int>RI(string s){
        string as="",bs="";
        as.push_back(s[0]);
        int i=1;
        while(s[i]!='+' && s[i]!='-'){
            as.push_back(s[i]);
            i++;
        }
        if(s[i]=='+')i++;
        int a=stoi(as);

        while(s[i]!='i'){
            bs.push_back(s[i]);
            i++;
        }
        int b=stoi(bs);

        return {a,b};

    }
    string complexNumberMultiply(string num1, string num2) {

        pair<int,int>n1=RI(num1),n2=RI(num2);
        int a=n1.first;
        int b=n1.second;
        int c=n2.first;
        int d=n2.second;

        int R=a*c-b*d;
        int I=a*d+b*c;

        string Rs=to_string(R),Is=to_string(I);
        string ans="";
        ans+=Rs;
        ans.push_back('+');
        ans+=Is;
        ans.push_back('i');

        return ans;

    }
};