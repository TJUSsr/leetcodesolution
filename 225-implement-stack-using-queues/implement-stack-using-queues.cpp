// Implement the following operations of a stack using queues.
//
//
// 	push(x) -- Push element x onto stack.
// 	pop() -- Removes the element on top of the stack.
// 	top() -- Get the top element.
// 	empty() -- Return whether the stack is empty.
//
//
// Example:
//
//
// MyStack stack = new MyStack();
//
// stack.push(1);
// stack.push(2);  
// stack.top();   // returns 2
// stack.pop();   // returns 2
// stack.empty(); // returns false
//
// Notes:
//
//
// 	You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// 	Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// 	You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
//
//


static const auto _=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        size=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(size==0)
            q1.push(x);
        else if(q2.empty())
            q1.push(x);
        else
            q2.push(x);
        ++size;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if(q1.empty()){
            for(int i=1;i<size;++i){
                q1.push(q2.front());
                q2.pop();
            }
            res=q2.front();
            q2.pop();
        }else{
            for(int i=1;i<size;++i){
                q2.push(q1.front());
                q1.pop();
            }
            res=q1.front();
            q1.pop();
        }
        --size;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        int res;
        if(q1.empty()){
            for(int i=1;i<size;++i){
                q1.push(q2.front());
                q2.pop();
            }
            res=q2.front();
            q1.push(res);
            q2.pop();
        }else{
            for(int i=1;i<size;++i){
                q2.push(q1.front());
                q1.pop();
            }
            res=q1.front();
            q2.push(res);
            q1.pop();
        }
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return size==0;
    }
private:
    int size;
    queue<int> q1;
    queue<int> q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
