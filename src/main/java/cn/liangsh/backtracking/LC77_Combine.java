package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Liangsh
 * @description 组合
 * @date 2022/6/30 11:18
 */
public class LC77_Combine {
    List<List<Integer>> result = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();


    public List<List<Integer>> combine(int n, int k) {
        // 第一次从1开始取值，判断1 - n的数据
        backtracking(n, k, 1);
        return result;
    }

    private void backtracking(int n, int k, int start) {
        // 终止条件，当path中的元素达到k时返回
        if (path.size() == k) {
            result.add(new ArrayList<>(path));
            return;
        }

        // 单层逻辑，从start开始遍历数组，for循环做横向遍历，递归做纵向遍历
        for (int i = start; i <= n; i++) {
            // 横向遍历，从start -- n 区间依次取值
            path.add(i);
            // 纵向遍历，找出 i 往下的所有可能组合
            backtracking(n, k, i + 1);
            path.removeLast();
        }

    }
}
