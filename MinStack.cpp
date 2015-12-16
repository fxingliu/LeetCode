class MinStack {
public:
    void push(int x) {
        main_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top())
            min_stack.push(x);
    }

    void pop() {
        int ret = main_stack.top();
        main_stack.pop();
        if (ret == min_stack.top())
            min_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
    
private:
    stack<int> main_stack;
    stack<int> min_stack;
};
