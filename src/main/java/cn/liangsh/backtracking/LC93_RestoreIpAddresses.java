package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 复原IP地址
 * @date 2022/7/12 9:06
 */
public class LC93_RestoreIpAddresses {


    public static void main(String[] args) {
        System.out.println(new LC93_RestoreIpAddresses().restoreIpAddresses("25525511135"));
    }

    List<String> result = new ArrayList<>();

    public List<String> restoreIpAddresses(String s) {

        backtracking(s, 0, 0);

        return result;
    }

    private void backtracking(String s, int startIndex, int pointCount) {
        // 到第三个分割点时判断最后一段字符串是否合法
        if (pointCount == 3) {
            // 判断字符串是否合法
            if (isVlaid(s, startIndex, s.length() - 1)) {
                result.add(s);
            }
            return;
        }

        // 横向遍历字符串s并判断是否符合ip地址条件
        for (int i = startIndex; i < s.length(); i++) {
            if (isVlaid(s, startIndex, i)) {
                s = s.substring(0, i + 1) + "." + s.substring(i + 1);
                pointCount++;
                backtracking(s, i + 2, pointCount);
                // 回溯
                pointCount--;
                s = s.substring(0, i + 1) + s.substring(i + 2);

            } else {
                break;
            }

        }

    }

    private boolean isVlaid(String str, int start, int end) {
        if (start > end) {
            return false;
        }

        if (str.charAt(start) == '0' && start != end) {
            // 不能以0开头
            return false;
        }

        int num = 0;
        for (int i = start; i <= end; i++) {
            if (str.charAt(i) > '9' || str.charAt(i) < '0') {
                // 必须为0-9的数字
                return false;
            }

            num = num * 10 + (str.charAt(i) - '0');

            if (num > 255) {
                return false;
            }
        }

        return true;
    }
}

