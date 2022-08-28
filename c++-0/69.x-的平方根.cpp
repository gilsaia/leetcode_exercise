/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        long long left = 0, right = x, mid;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (mid * mid == x)
            {
                return mid;
            }
            if (mid * mid > x)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (left * left > x)
        {
            left -= 1;
        }
        return left;
    }
};
// @lc code=end
