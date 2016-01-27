class Solution {
public:
    string countAndSay(int n) {
        string num = "1", tmp;
        int cnt;
        while (--n) {
            swap(num, tmp);
            num.erase();
            for (int j=0; j<tmp.size(); ) {
                cnt = 0;
                do {
                    j++;
                    cnt++;
                }
                while (j<tmp.size() && tmp[j]==tmp[j-1]);
                num += to_string(cnt) + tmp[j-1];
            }
        }
        return num;   
    }
};
