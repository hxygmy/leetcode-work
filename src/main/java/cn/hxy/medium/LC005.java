package cn.hxy.medium;

/**
 * 5. 最长回文子串
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 *
 *
 *
 * 示例 1：
 *
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 示例 2：
 *
 * 输入：s = "cbbd"
 * 输出："bb"
 *
 *
 * 提示：
 *
 * 1 <= s.length <= 1000
 * s 仅由数字和英文字母组成
 *
 * 链接：<a href="https://leetcode.cn/problems/longest-palindromic-substring">...</a>
 *
 * @author 何晓宇
 * 2022/5/27 19:56
 */
public class LC005 {
	public static void main(String[] args) {
		System.out.println(longestPalindrome("cbbd"));
	}


	/**
	 * 最长回文子串，该题存在线性级别的算法
	 *
	 * 此处为自己的题解
	 * 后期有空加入动态规划和中心发散的方法
	 *
	 * @param s		待查字符串
	 * @return		返回最长回文子串
	 */
	public static String longestPalindrome(String s) {
		int len = s.length();
		if (len == 1) return s;

		int length = 0;
		int begin = 0;
		boolean flag = false;
		for (int i = 0; i < len; i++) {
			for (int j = len - 1; j > i; j--) {
				if(s.charAt(i) == s.charAt(j)){
					for (int k = i; k <= (j + i) / 2; k++) {
						if(s.charAt(k) != s.charAt(i + j - k)){
							flag = false;
							break;
						} else {
							flag = true;
						}
					}
					if (flag){
						if((j - i + 1) > length){
							length = j - i + 1;
							begin = i;
						}

					}
				}
			}
			if (length >= len - i - 1){
				break;
			}
		}
		if (length == 0) return s.substring(0,1);
		return s.substring(begin, begin + length);
	}

}
