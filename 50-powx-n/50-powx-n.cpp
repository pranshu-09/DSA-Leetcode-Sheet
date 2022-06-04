class Solution {
public:
    
    double myPow(double x, int n) {
     
        if(n==1) return x;
        if(n==-1) return 1/x;
        if(n==0) return 1.0;
        
        double h = myPow(x, n/2);
        
        if(n&1){
            if(n<0) return 1/x*h*h;
            else return x*h*h;
        }
        else{
            return h*h;
        }
    }
};