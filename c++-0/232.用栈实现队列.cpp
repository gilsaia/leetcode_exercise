/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>
using namespace std;
// @lc code=start
class MyQueue {
public:
  MyQueue() {}

  void push(int x) { front.push(x); }

  int pop() {
    int tmp = this->peek();
    back.pop();
    return tmp;
  }

  int peek() {
    if (back.empty()) {
      while (!front.empty()) {
        back.push(front.top());
        front.pop();
      }
    }
    return back.top();
  }

  bool empty() { return front.empty() && back.empty(); }

private:
  stack<int> front, back;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
