package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 划分回文子串
 * @date 2022/7/12 8:49
 */
public class LC131_Partition {

    List<List<String>> result = new ArrayList<>();
    List<String> path = new ArrayList<>();

    public List<List<String>> partition(String s) {

        backtracking(s, 0);

        return result;
    }

    private void backtracking(String s, int startIndex) {
        if (startIndex >= s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }

        // 从startIndex开始计算往后的回文子串
        for (int i = startIndex; i < s.length(); i++) {
            // 判断到i是否为回文子串,闭区间
            if (isPalindrome(s, startIndex, i)) {
                path.add(s.substring(startIndex, i + 1));
            } else {
                continue;
            }

            // 递归,从i + 1开始，不做重复计算
            backtracking(s, i + 1);
            // 回溯
            path.remove(path.size() - 1);
        }

    }

    private boolean isPalindrome(String s, int startIndex, int i) {
        // 双指针遍历
        char[] chars = s.toCharArray();
        for (int j = startIndex, k = i; j < k; j++, k--) {
            if (chars[j] != chars[k]) {
                return false;
            }
        }


        return true;
    }
}
