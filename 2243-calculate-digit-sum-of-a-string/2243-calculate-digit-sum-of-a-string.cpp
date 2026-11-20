class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){            
            string temp="";
            int num=0;
            for(int i=0;i<s.length();i++){

                num+=(s[i]-'0');
                if((i+1)%k==0){ 
                    temp+=(to_string(num));
                    cout<<num<<endl;
                    num=0;
                }
                
            }
            if(s.length()%k!=0)
            temp+=(to_string(num));
            s=temp;
        }
        return s;
    }
};