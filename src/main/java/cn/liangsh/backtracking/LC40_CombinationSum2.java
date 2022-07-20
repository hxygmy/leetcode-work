package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Liangsh
 * @description 组合总和II
 * @date 2022/7/19 10:00
 */
public class LC40_CombinationSum2 {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {

        // 排序后去重
        Arrays.sort(candidates);
        backtracking(candidates, target, 0, 0);
        return result;
    }

    private void backtracking(int[] candidates, int target, int startIndex, int sum) {
        if (sum == target) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = startIndex; i < candidates.length && sum + candidates[i] <= target; i++) {
            // 去重，同一层的元素不重复使用
            if (i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }

            path.add(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, i + 1, sum);
            // 回溯
            path.remove(path.size() - 1);
            sum -= candidates[i];
        }

    }
}
