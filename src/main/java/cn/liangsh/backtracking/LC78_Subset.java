package cn.liangsh.backtracking;

import java.util.ArrayList;
import java.util.List;

/**
 * @author Liangsh
 * @description 子集
 * @date 2022/7/19 8:55
 */
public class LC78_Subset {

    List<List<Integer>> result = new ArrayList<>();
    List<Integer> path = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums) {

        backtracking(nums, 0);

        return result;
    }

    private void backtracking(int[] nums, int startIndex) {
        // 起始位置大于数组长度时，终止递归
        // 遍历这个树的时候，把所有节点都记录下来，就是要求的子集集合
        result.add(new ArrayList<>(path));
        if (startIndex >= nums.length) {
            return;
        }

        for (int i = startIndex; i < nums.length; i++) {
            path.add(nums[i]);
            backtracking(nums, i + 1);
            path.remove(path.size() - 1);
        }
    }
}
