package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @author Liangsh
 * @description 电话号码的字母组合
 * @date 2022/7/11 8:50
 */
public class LC17_LetterCombinations {
    private final Map<Character, String> letterMap = new HashMap<Character, String>() {
        {
            put('0', "");
            put('1', "");
            put('2', "abc");
            put('3', "def");
            put('4', "ghi");
            put('5', "jkl");
            put('6', "mno");
            put('7', "pqrs");
            put('8', "tuv");
            put('9', "wxyz");
        }
    };

    private List<String> result = new ArrayList<>();
    StringBuilder s = new StringBuilder();

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0) {
            return result;
        }

        backtracking(digits, 0);

        return result;
    }

    private void backtracking(String digits, int index) {
        if (index == digits.length()) {
            result.add(s.toString());
            return;
        }

        String str = letterMap.get(digits.charAt(index));

        for (int i = 0; i < str.length(); i++) {
            // 横向遍历获取当前层的字符组合
            s.append(str.charAt(i));
            backtracking(digits, index + 1);
            s.deleteCharAt(s.length() - 1);
        }

    }
}
