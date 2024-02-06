import java.util.*;
// import java.util.Collections;


class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] sorted = new int[nums1.length + nums2.length];
        int i, j;
        int medIdx;
        double median;

        for(i = 0; i < nums1.length; i++) {
            sorted[i] = nums1[i];
        }

        for(j = nums1.length; j < nums1.length+nums2.length; j++) {
            sorted[j] = nums2[j - i];
        }

        List<Integer> arr = Arrays.stream(sorted).boxed().collect(Collectors.toList());

        Collections.sort(arr);

        if (sorted.length % 2 != 0) {
            medIdx = arr.size()/2;
            median = arr.get(medIdx);
        } else {
            medIdx = arr.size()/2;
            double a = Double.valueOf(arr.get(medIdx-1));
            double b = Double.valueOf(arr.get(medIdx));
            median = (a+b)/2;
            System.out.println("CHK1: Median of merged array is: " + median + " medIdx " + medIdx);
        }

        return median;
    }
}