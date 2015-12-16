class MinStack {
public:
    void push(int x) {
        if (s.empty()) {
            s.push(0);
            min = x;
        }
        else {
            s.push(x-min);
            if (x < min) min = x;
        }
    }

    void pop() {
        if (s.top() < 0) min -= s.top();
        s.pop();
    }

    int top() {
        if (s.top() < 0) return min;
        return (int)(min + s.top());
    }

    int getMin() {
        return (int)min;
    }
    
private:
    // the difference with current min
    // use long since the difference may overflow the int range
    stack<long> s;
    long min;
};
