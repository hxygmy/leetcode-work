package cn.hxy.medium;

/**
 * 3 无重复最长子串
 * <a href = "https://leetcode.cn/problems/longest-substring-without-repeating-characters/">原题链接</a>
 * 给定一个字符串 s ，请你找出其中不含有重复字符的最长子串的长度。
 *
 *
 *
 * 示例1:
 *
 * 输入: s = "abcabcbb"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 * 示例 2:
 *
 * 输入: s = "bbbbb"
 * 输出: 1
 * 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
 * 示例 3:
 *
 * 输入: s = "pwwkew"
 * 输出: 3
 * 解释: 因为无重复字符的最长子串是"wke"，所以其长度为 3。
 *     请注意，你的答案必须是 子串 的长度，"pwke"是一个子序列，不是子串。
 *
 *
 * 提示：
 *
 * 0 <= s.length <= 5 * 104
 * s由英文字母、数字、符号和空格组成
 *
 * @author 何晓宇
 * 2022/5/25 19:13
 */
public class LC003 {

	public static void main(String[] args) {

	}

	/**
	 * 指定数组中遍历的开始和结束位置，以结束位置为基准，遍历指定截取的数组是否存在与该位置相同的元素
	 * 1. 指定一个指针 end， 从前向后遍历数组
	 * 2. 指定一个数组下标begin和一个指针i，i从begin到end进行遍历，确定此区间的最长无重复子串
	 * 3. 指定当前记录的最长子串的长度flag，对遍历结果进行监督，如果存在更大的值则进行覆盖
	 *
	 * @param s		待遍历字符串
	 * @return		无重复最长子串的长度
	 */
	public int lengthOfLongestSubstring(String s) {
		char[] chars = s.toCharArray();
		int begin = 0;
		int flag = 0;
		for (int end = 0; end < chars.length ; end++) {

			for (int i = begin; i < end; i++) {
				if(chars[i] == chars[end]){
					begin = i + 1;
					break;
				}
			}
			if(end - begin + 1 > flag){
				flag = end - begin + 1;
			}
		}
		return flag;
	}
}
