class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0)
            return 0;
        
        if(x == 1) return 1;
        
        if(x == 2) return 1;
        
        long i = 1, j = x;
        long long mid, square;
        
        while(i< j){
            mid = (i + j)/2;
            
            square = mid * mid;
            
            if(square == x)
                return mid;
            else if(square > x){
                j = mid;
            }
            else if(square < x){
                i = mid + 1;
            }
        }
        return i - 1;
    }
};