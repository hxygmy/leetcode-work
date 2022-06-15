package cn.hxy.medium;

/**
 * 12. 整数转罗马数字
 *
 * 罗马数字包含以下七种字符：I，V，X，L，C，D和M。
 *
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 例如， 罗马数字 2 写做II，即为两个并列的 1。12 写做XII，即为X+II。 27 写做XXVII, 即为XX+V+II。
 *
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做IIII，而是IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为IX。这个特殊的规则只适用于以下六种情况：
 *
 * I可以放在V(5) 和X(10) 的左边，来表示 4 和 9。
 * X可以放在L(50) 和C(100) 的左边，来表示 40 和90。
 * C可以放在D(500) 和M(1000) 的左边，来表示400 和900。
 * 给你一个整数，将其转为罗马数字。
 *
 * 
 *
 * 示例1:
 *
 * 输入:num = 3
 * 输出: "III"
 * 示例2:
 *
 * 输入:num = 4
 * 输出: "IV"
 * 示例3:
 *
 * 输入:num = 9
 * 输出: "IX"
 * 示例4:
 *
 * 输入:num = 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 * 示例5:
 *
 * 输入:num = 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 *
 * 提示：
 *
 * 1 <= num <= 3999
 *
 * 来源：力扣（LeetCode）
 * 链接：<a href="https://leetcode.cn/problems/integer-to-roman">...</a>
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author 何晓宇
 * 2022/6/2 13:23
 */
public class LC0012 {
	public static void main(String[] args) {
		System.out.println(intToRoman(3));
	}

	public static String intToRoman(int num) {
		String[] k = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
		int[] v = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		int i;
		int j = 12;
		StringBuilder sb = new StringBuilder();
		while (num > 0){
			for (i = j; i >= 0; i--) {
				if (v[i] <= num) {
					num -= v[i];
					j = i;
					break;
				}
			}
			sb.append(k[i]);
		}
		return sb.toString();
	}

	/*
	 * 执行用时：
	 * 3 ms
	 * , 在所有 Java 提交中击败了
	 * 95.80%
	 * 的用户
	 * 内存消耗：
	 * 40.8 MB
	 * , 在所有 Java 提交中击败了
	 * 81.80%
	 * 的用户
	 * 通过测试用例：
	 * 3999 / 3999
	 */

}
