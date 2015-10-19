class Solution {
public:
    void reverseWords(string &s) {
        stack<char> word;
        stack<char> sentence;
        
        for (int i=0; i<=s.size(); i++) {
            if (isspace(s[i]) || i==s.size()) {
                if (!sentence.empty() && !word.empty()) 
                    sentence.push(' ');
                while (!word.empty()) {
                    sentence.push(word.top());
                    word.pop();
                }
            }
            else
                word.push(s[i]);
        }
        s.clear();
        while (!sentence.empty()) {
            s.push_back(sentence.top());
            sentence.pop();
        }
    }
};