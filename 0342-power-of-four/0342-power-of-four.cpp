class Solution {
public:
    bool isPowerOfFour(int n) {
       long long num=n,count=0;
       if(n<=0){
        return false;
       }

if((n&(n-1))==0){
   
    while(num!=1){
       
    num=num/2;
    count++;
    
}
}
else {
   
    return false;
}
 


if(count%2==0){
    

    return true;
}
else
{
    
  
    return false;
}
    }
};