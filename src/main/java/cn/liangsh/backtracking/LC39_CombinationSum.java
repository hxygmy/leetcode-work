package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Liangsh
 * @description 组合总和
 * @date 2022/7/11 14:11
 */
public class LC39_CombinationSum {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {

        // 先排序后大于target的值自动返回
        Arrays.sort(candidates);
        backtracking(candidates, target, 0, 0);

        return result;
    }

    private void backtracking(int[] candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            // 不new会将path引用传入，最后修改为空列表
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = startIndex; i < candidates.length && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.add(candidates[i]);
            backtracking(candidates, target, sum, i);
            // 回溯
            sum -= candidates[i];
            path.remove(path.size() - 1);
        }

    }
}
