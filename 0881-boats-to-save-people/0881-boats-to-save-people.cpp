class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            int x=people[l]+people[r];
            if(x<=limit){
                ans++;
                l++;
                r--;
            }
            else if(x>limit){
                if(people[r]<=limit)ans++;
                r--;
            }
        }


        return ans;
    }
};