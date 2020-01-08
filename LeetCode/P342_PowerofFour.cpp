class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        if (num == 1 || num == 4) return true;
        
        long long f = 4;
        
        while(f < num){
            f = f<<2;
            if (f == num) return true;
        }
        
        return false;
    }
};