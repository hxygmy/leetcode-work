package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @author Liangsh
 * @description 全排列II
 * @date 2022/7/21 8:55
 */
public class LC47_PermuteII {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();


    public List<List<Integer>> permuteUnique(int[] nums) {
        if (nums.length == 0) {
            return new ArrayList<>();
        }

        Arrays.sort(nums);
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
            // used[i - 1] == true，说明同⼀树⽀nums[i - 1]使⽤过
            // used[i - 1] == false，说明同⼀树层nums[i - 1]使⽤过
            // 如果同⼀树层nums[i - 1]使⽤过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            if (!used[i]) {
                used[i] = true;
                path.add(nums[i]);
                backtracking(nums, used);
                // 回溯
                used[i] = false;
                path.remove(path.size() - 1);
            }

        }
    }
}
