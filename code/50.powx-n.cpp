class Solution {
public:
    double myPow(double x, int nn) {
        double ans = 1;
        
        long long n = nn;
        
        if(x == 1) return 1.000;
        
        bool flag = false;
        
        if(n < 0){
            n = abs(nn);
        }
        
        while(n){
            if(n % 2){
                ans *= x;
                n = n - 1;
            }else{
                n = n/2;
                x = x * x;
            }
        }
        
        return (nn < 0)? 1.0/ans : ans; 
    }
};