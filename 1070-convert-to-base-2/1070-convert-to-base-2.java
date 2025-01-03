class Solution {
    public String baseNeg2(int n) {
        if (n == 0) return "0";
        
        String result = "";
        
        while (n != 0) {
            int r = n % -2;
            n = n / -2;
            
            if (r < 0) {
                r += 2;
                n += 1;
            }
            
            result = r + result;
        }
        
        return result;
    }
}
