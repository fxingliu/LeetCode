class Solution {
public:
    bool isNumber(string s) {
        enum s_type {
            INVALID,
            SPACE,
            SIGN,
            DIGIT,
            DOT,
            EXP,
            NUM_TYPE
        };
        
        const int transition[][NUM_TYPE] = {
            -1, 0, 3, 1, 2, -1,
            -1, 8, -1, 1, 4, 5,
            -1, -1, -1, 4, -1, -1,
            -1, -1, -1, 1, 2, -1,
            -1, 8, -1, 4, -1, 5,
            -1, -1, 6, 7, -1, -1,
            -1, -1, -1, 7, -1, -1,
            -1, 8, -1, 7, -1, -1,
            -1, 8, -1, -1, -1, -1,
        };
        
        int state = 0;
        for (char& c : s) {
            s_type type = INVALID;
            
            if (isspace(c)) type = SPACE;
            else if (c == '+' || c == '-') type = SIGN;
            else if (isdigit(c)) type = DIGIT;
            else if (c == '.') type = DOT;
            else if (c == 'E' || c == 'e') type = EXP;
            
            state = transition[state][type];
            if (state==-1) 
                return false;
        }
        
        if (state==1 || state==4 || state==7 || state==8)
            return true;
        return false;
    }
};
