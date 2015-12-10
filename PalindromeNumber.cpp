class Solution {
public:
    bool isPalindrome(int x) {
        int rev = 0;
        for (int xx=x; xx>0; xx/=10)
            rev = rev*10+xx%10;
        if (rev == x) return true;
        return false;
    }
};
