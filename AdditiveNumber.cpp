class Solution {
public:
    bool isAdditiveNumber(string num) {
        // check every possible partition of the first two numbers
        for (int i=1; i<=num.size()/2; i++)
            for (int j=1; j<=(num.size()-i)/2; j++) 
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i+j))) 
                    return true;
        return false;
    }
    
private:
    bool check(string a, string b, string c) {
        // check leading zeros
        if (a.size()>1 && a[0]=='0' || b.size()>1 && b[0]=='0') return false;
        string sum = add(a, b);
        if (sum == c) return true;
        if (sum.size() >= c.size() || c.substr(0, sum.size()) != sum) return false;
        // check the following sequence
        return check(b, sum, c.substr(sum.size()));
    }
    
    string add(string& a, string& b) {
        if (a.size() > b.size()) return add(b, a);
        string ret;
        int i = a.size()-1, j = b.size()-1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = (i >= 0 ? a[i--]-'0' : 0) + (j >= 0 ? b[j--]-'0' : 0) + carry;
            ret.push_back(sum%10 + '0');
            carry = sum / 10;
        }
        if (carry) ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
