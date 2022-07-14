package cn.hxy.easy;

import java.util.ArrayList;
import java.util.List;

/**
 * 202. 快乐数
 *
 * 编写一个算法来判断一个数 n 是不是快乐数。
 *
 * 「快乐数」 定义为：
 *
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
 * 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
 * 如果这个过程 结果为 1，那么这个数就是快乐数。
 * 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：n = 19
 * 输出：true
 * 解释：
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 * 示例 2：
 *
 * 输入：n = 2
 * 输出：false
 *  
 *
 * 提示：
 *
 * 1 <= n <= 231 - 1
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/happy-number
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/7/14 16:26
 */
public class LC0202 {
	public static void main(String[] args) {

	}

	public boolean isHappy(int n) {
		List<Integer> in = new ArrayList<>();
		return piHappy(n, in);
	}

	public boolean piHappy(int n, List<Integer> con) {
		con.add(n);
		int res = 0;
		while (n != 0){
			res += (n % 10) * (n % 10);
			n = n / 10;
		}
		if (res == 1) {
			return true;
		} else {
			if (con.contains(res)) return false;
			try {
				return piHappy(res, con);
			} catch (StackOverflowError e) {
				return false;
			}
		}
	}

}
