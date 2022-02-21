package utils;

import java.util.Arrays;

/**
 * 辅助 debug
 */
public class OutputUtil {
    private OutputUtil() {} // ban new this class
    public static final String ONE_SPACE = "";
    /**
     * print int[] type arrays
     * @param nums
     * @return
     */
    public static void printIntArray(int[] nums) {
        System.out.println(Arrays.asList(nums));
    }

}
