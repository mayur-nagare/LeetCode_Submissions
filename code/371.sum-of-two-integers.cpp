class Solution {
public:
    int getSum(int a, int b) {
        
        double val = pow(2, a) * pow(2, b);
        return log(val) / log(2);
    }
};