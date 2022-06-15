package cn.hxy.medium;

/**
 * 6. Z字形变换
 * <a href="https://leetcode.cn/problems/zigzag-conversion">题目链接</a>
 * 将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行Z 字形排列。
 *
 * 比如输入字符串为 "PAYPALISHIRING"行数为 3 时，排列如下：
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
 *
 * 请你实现这个将字符串进行指定行数变换的函数：
 *
 * string convert(string s, int numRows);
 *
 *
 * 示例 1：
 *
 * 输入：s = "PAYPALISHIRING", numRows = 3
 * 输出："PAHNAPLSIIGYIR"
 * 示例 2：
 * 输入：s = "PAYPALISHIRING", numRows = 4
 * 输出："PINALSIGYAHRPI"
 * 解释：
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 示例 3：
 *
 * 输入：s = "A", numRows = 1
 * 输出："A"
 *
 *
 * 提示：
 *
 * 1 <= s.length <= 1000
 * s 由英文字母（小写和大写）、',' 和 '.' 组成
 * 1 <= numRows <= 1000
 *
 * @author 何晓宇
 * 2022/5/28 13:29
 */
public class LC0006 {

	public static void main(String[] args) {
		System.out.println(convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers.", 3));
	}

	/**
	 * Z字形变换
	 *
	 * 这里采用了完全符合题目描述的解法，把字符串直接写入二维数组中，再顺序读取
	 * 时间复杂度O(n)
	 * 空间复杂度O(n^2)
	 *
	 * @param s			待排字符串
	 * @param numRows	Z字形行数
	 * @return			返回重排后的字符串
	 */
	public static String convert(String s, int numRows) {
		int len = s.length();
		if(numRows < 2 || len < 3) return s;
		if (numRows == 2) {
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < len; i = i + 2) {
				sb.append(s.charAt(i));
			}
			for (int i = 1; i < len; i = i + 2) {
				sb.append(s.charAt(i));
			}
			return sb.toString();
		}
		int row = ((len / (2 * numRows - 2)) + 1) * (numRows - 1);
		char[][] matrix = new char[numRows][row];
		boolean dir = true;
		int k = 0;
		for (int i = 0, j = -1; i < len; i++) {
			if(dir){
				matrix[++j][k] = s.charAt(i);
				if(j + 1 == numRows) {
					dir = false;
				}
			} else {
				matrix[--j][++k] = s.charAt(i);
				if(j == 0) dir = true;
			}
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < numRows; i++) {
			for (int j = 0; j <= k; j++) {
				if(matrix[i][j] != '\0'){
					sb.append(matrix[i][j]);
				}
			}
		}
		return sb.toString();
	}

}
