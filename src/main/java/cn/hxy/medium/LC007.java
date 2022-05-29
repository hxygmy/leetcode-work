package cn.hxy.medium;

/**
 * 7. 整数反转
 * <a href="https://leetcode.cn/problems/reverse-integer">题目链接</a>
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 *
 * 如果反转后整数超过 32 位的有符号整数的范围[−231, 231− 1] ，就返回 0。
 *
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 *
 *
 * 示例 1：
 *
 * 输入：x = 123
 * 输出：321
 * 示例 2：
 *
 * 输入：x = -123
 * 输出：-321
 * 示例 3：
 *
 * 输入：x = 120
 * 输出：21
 * 示例 4：
 *
 * 输入：x = 0
 * 输出：0
 *
 *
 * 提示：
 *
 * -231 <= x <= 231 - 1
 *
 * @author 何晓宇
 * 2022/5/29 20:05
 */
public class LC007 {
	public static void main(String[] args) {

	}

	/**
	 * 整数反转
	 * 一步步取余得到数字，然后再一步步乘上去，构思巧妙，又很容易理解的题目
	 * 需要注意边界问题，这里使用了long类型变换，实际上并不是最好的方法
	 * 在第11题中有相似的解法
	 * <a href="https://leetcode.cn/problems/string-to-integer-atoi">第8题链接</a>
	 *
	 * @param x    待处理整数
	 * @return 反转后的整数
	 */
	public int reverse(int x) {
		if (x == 0) { return 0; }

		int result = 0;

		while (x / 10 != 0) {
			result = result * 10 + x % 10;
			x = x / 10;
		}

		long res = result * 10L + x % 10;

		return (int)res == res ? (int)res : 0;
	}
}
