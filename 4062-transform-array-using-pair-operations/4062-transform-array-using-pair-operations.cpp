class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long int a=0,b=0;
        for(int i=0;i<source.size();i++){
            a+=source[i];
            b+=target[i];
        }

        return a==b;
    }
};