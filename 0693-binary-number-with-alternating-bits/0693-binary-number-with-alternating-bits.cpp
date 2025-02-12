class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cnt = 0;
        int c = n;
        while(n > 0){
            int rem = n % 2;
            if(c % 2 == 0){
                if(rem == 0 && cnt % 2 == 0){
                    cnt++;
                }
                else if(rem == 1 && cnt % 2 == 1){
                    cnt++;
                }
                else{
                    return false;
                }
            }
            else{
                if(rem == 1 && cnt % 2 == 0){
                    cnt++;
                }
                else if(rem == 0 && cnt % 2 == 1){
                    cnt++;
                }
                else{
                    return false;
                }
            }
            n /= 2;
        }
            return true;
        }
        
};