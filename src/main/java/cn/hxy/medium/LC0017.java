package cn.hxy.medium;

import java.util.ArrayList;
import java.util.List;

/**
 * 17. 电话号码的字母组合
 *
 * 给定一个仅包含数字2-9的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 *
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 *
 *
 *
 * 
 *
 * 示例 1：
 *
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 示例 2：
 *
 * 输入：digits = ""
 * 输出：[]
 * 示例 3：
 *
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 *
 * 提示：
 *
 * 0 <= digits.length <= 4
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 *
 * 来源：力扣（LeetCode）
 * 链接：https://leetcode.cn/problems/letter-combinations-of-a-phone-number
 * 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * @author Applewald
 * 2022/6/7 12:42
 */
public class LC0017 {
	public static void main(String[] args) {

	}

	public List<String> letterCombinations(String digits) {
//		if (digits.length() == 0) return new ArrayList<>();
//		Map<Character, char[]> map = new HashMap<>();
//		map.put('2', new char[]{'a', 'b', 'c'});
//		map.put('3', new char[]{'d', 'e', 'f'});
//		map.put('4', new char[]{'g', 'h', 'i'});
//		map.put('5', new char[]{'j', 'k', 'l'});
//		map.put('6', new char[]{'m', 'n', 'o'});
//		map.put('7', new char[]{'p', 'q', 'r', 's'});
//		map.put('8', new char[]{'t', 'u', 'v'});
//		map.put('9', new char[]{'w', 'x', 'y', 'z'});
//		char[][] res = new char[digits.length()][];
//		int len = 1;
//		for (int i = 0; i < digits.length(); i++){
//			char[] chars = map.get(digits.charAt(i));
//			len *= chars.length;
//			res[i] = chars;
//		}
//		List<StringBuilder> result = new ArrayList<>(len);



		// 广度优先遍历？
		if (digits == null || digits.length() == 0) {
			return new ArrayList<String>();
		}
		String[] map = {" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		List<String> res = new ArrayList<>();

		res.add("");
		for (int i = 0; i < digits.length(); i++) {
			String letters = map[digits.charAt(i) - '0'];
			int levelSize = res.size();
			for (int j = 0; j < levelSize; j++) {
				String tmp = res.remove(0);
				for (int k = 0; k < letters.length(); k++) {
					res.add(tmp + letters.charAt(k));
				}
			}
		}
		return res;
	}


}
