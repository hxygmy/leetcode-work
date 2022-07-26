package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 全排列
 * @date 2022/7/21 8:41
 */
public class LC46_Permute {
    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();


    public List<List<Integer>> permute(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }

        // 记录使用过的元素
        boolean[] used = new boolean[nums.length];
        backtracking(nums, used);
        return result;
    }

    private void backtracking(int[] nums, boolean[] used) {
        if (path.size() == nums.length) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = 0; i < nums.length; i++) {
            // 同一排列中使用过的元素不再使用
            if (used[i]) {
                continue;
            }

            used[i] = true;
            path.add(nums[i]);
            backtracking(nums, used);
            // 回溯
            used[i] = false;
            path.remove(path.size() - 1);
        }
    }
}
