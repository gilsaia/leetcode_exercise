/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long left = 0, right = num, mid;
        right += 1;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (mid * mid == num)
            {
                return true;
            }
            if (mid * mid > num)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end
