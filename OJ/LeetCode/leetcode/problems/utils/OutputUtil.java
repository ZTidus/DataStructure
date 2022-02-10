package utils;

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
        String res = "";
        for (int i = 0; i < nums.length; i++) {
            if (i == 0) res += "[";
            res += nums[i];
            if (i != nums.length - 1) {
                res += ",";
            }
            res += ONE_SPACE;
            if (i == nums.length - 1) {
                res += "]";
            }
        }
        System.out.println(res);
    }

}
