package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Liangsh
 * @description 组合总和II
 * @date 2022/7/5 8:55
 */
public class LC216_CombinationSum3 {
    List<List<Integer>> result = new ArrayList<>();
    LinkedList<Integer> path = new LinkedList<>();

    public static void main(String[] args) {
        System.out.println(new LC216_CombinationSum3().combinationSum3(3, 7));
    }

    public List<List<Integer>> combinationSum3(int k, int n) {
        backTracking(n, k, 0, 1);
        return result;
    }

    private void backTracking(int target, int k, int sum, int start) {
        // 减枝
        if (sum > target) {
            return;
        }
        if (path.size() == k) {
            if (target == sum) {
                result.add(new ArrayList<>(path));
            }
            return;
        }

        // 遍历找出符合条件的组合
        for (int i = start; i <= 9; i++) {
            sum += i;
            path.add(i);
            backTracking(target, k, sum, i + 1);
            // 回溯
            sum -= i;
            path.removeLast();
        }

    }
}
