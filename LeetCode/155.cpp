/*******************************************************************************
	> File Name: 155.cpp
	> Author: sillyplus 
	> Mail: oi_boy@sina.cn 
	> Created Time: Sun Mar  6 11:02:19 2016
*******************************************************************************/

class MinStack {
private:    
    stack<int> allStack;
    stack<int> minStack;
    
public:
    void push(int x) {  
        if (minStack.empty()) {
            minStack.push(x);
        } else if (x <= minStack.top()) {
            minStack.push(x);
        }
        allStack.push(x);
    }

    void pop() {
        if (allStack.top() == minStack.top()) {
            minStack.pop();
        }
        allStack.pop();
    }

    int top() {
        return allStack.top();
    }

    int getMin() {
        return minStack.top();
    }
};
