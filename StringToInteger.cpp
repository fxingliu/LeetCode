class Solution {
public:
    int myAtoi(string str) {
        const int len = str.size();
        int i=0;
        while (i<len && str[i]==' ') 
            i++;
        
        int sign = 1;
        int sum = 0;
        
        if (str[i]=='+')
            i++;
        else if (str[i]=='-') {
            sign = -1;
            i++;
        }
        
        for (; i<len; i++) {
            int num = str[i]-'0';
            if (num<0 || num>9) 
                break;
            if (sum > INT_MAX / 10 || sum == INT_MAX / 10 && num > INT_MAX % 10)
                return (sign==1) ? INT_MAX : INT_MIN;
            sum = sum * 10 + num;
        }
        
        return sign * sum;
    }
};
