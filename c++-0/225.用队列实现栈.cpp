/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>
using namespace std;
// @lc code=start
class MyStack {
public:
  MyStack() {}

  void push(int x) {
    int siz = que.size();
    que.push(x);
    while (siz) {
      que.push(que.front());
      que.pop();
      --siz;
    }
  }

  int pop() {
    int tmp = que.front();
    que.pop();
    return tmp;
  }

  int top() { return que.front(); }

  bool empty() { return que.empty(); }

private:
  queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
