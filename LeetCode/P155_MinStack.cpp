class MinStack {
public:
    /** initialize your data structure here. */
    vector <int> v;
    vector <int> minval;
  
    MinStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        if(minval.empty()) minval.push_back(x);
        else if(x <= minval[minval.size()-1]) minval.push_back(x);
        
    }
    
    void pop() {
        if (v[v.size()-1] == minval[minval.size()-1]){
            minval.pop_back();
        }
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return minval[minval.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */