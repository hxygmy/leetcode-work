package cn.hxy.easy;

/**
 * 14. 最长公共前缀
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *  
 *
 * 示例 1：
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 示例 2：
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *  
 *
 * 提示：
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] 仅由小写英文字母组成
 *
 * 来源：力扣（LeetCode）
 * 链接：<a href="https://leetcode.cn/problems/longest-common-prefix">链接</a>
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author 何晓宇
 * 2022/6/4 18:27
 */
public class LC0014 {

	public static void main(String[] args) {

	}

	public String longestCommonPrefix(String[] strs) {
		StringBuilder sb = new StringBuilder();
		String s = strs[0];
		boolean flag = true;
		for (int i = 0; i < s.length(); i++) {
			for (int j = 1; j < strs.length; j++) {
				String str = strs[j];
				if(i == str.length() || s.charAt(i) != str.charAt(i)){
					flag = false;
					break;
				}
			}
			if(!flag){
				break;
			} else {
				sb.append(s.charAt(i));
			}
		}

		return sb.toString();
	}

	/*
	 * 执行用时：
	 * 1 ms
	 * , 在所有 Java 提交中击败了
	 * 69.16%
	 * 的用户
	 * 内存消耗：
	 * 39.2 MB
	 * , 在所有 Java 提交中击败了
	 * 66.85%
	 * 的用户
	 */
}
