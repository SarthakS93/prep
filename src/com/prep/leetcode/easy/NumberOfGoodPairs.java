package com.prep.leetcode.easy;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class NumberOfGoodPairs {

    int arr[] = {1,2,3};

    public int numIdenticalPairsSolve() {
        return numIdenticalPairs(arr);
    };

    private int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> mymap = new HashMap<>();
        Integer result = 0;

        for (int i = 0; i < nums.length; i++) {
            if (mymap.containsKey(nums[i])) {
                Integer count = mymap.get(nums[i]);
                result += count;
                mymap.put(nums[i], count + 1);
            }
            else {
                mymap.put(nums[i], 1);
            }
        }

        return result;
    }

}
