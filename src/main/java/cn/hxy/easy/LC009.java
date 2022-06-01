package cn.hxy.easy;

/**
 * 第9题 回文数
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 *
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 *
 * 例如，121 是回文，而 123 不是。
 *
 *
 * 示例 1：
 *
 * 输入：x = 121
 * 输出：true
 * 示例2：
 *
 * 输入：x = -121
 * 输出：false
 * 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 示例 3：
 *
 * 输入：x = 10
 * 输出：false
 * 解释：从右向左读, 为 01 。因此它不是一个回文数。
 *
 *
 * 提示：
 *
 * -231<= x <= 231- 1
 *
 *
 * 进阶：你能不将整数转为字符串来解决这个问题吗？
 *
 * @author 何晓宇
 * 2022/5/31 14:57
 */
public class LC009 {
	public static void main(String[] args) {

	}

	public boolean isPalindrome(int x) {
		char[] chars = String.valueOf(x).toCharArray();
		int len = chars.length;
		boolean flag = true;
		for (int i = 0; i < len / 2; i++){
			if(chars[i] != chars[len - i - 1]){
				flag = false;
				break;
			}
		}
		return flag;
	}
}
