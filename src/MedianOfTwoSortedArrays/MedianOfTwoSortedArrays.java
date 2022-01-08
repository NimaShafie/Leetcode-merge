package MedianOfTwoSortedArrays;

import java.lang.Math;

class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        int[] testNums = {2, 4, 6, 8};
        double testAnswer = calcMedian(testNums);

        return testAnswer;
    }

    double calcMedian(int[] combNums) {
        double median;
        double floorMean, cielMean;
        // odd -> divde by 2, round up
        // [2, 4, 6, 8, 9] 5/2 == 3, answer is 6
        if(combNums.length % 2 != 0) {
            System.out.println("Enter odds\n");
            median = Math.ceil(combNums.length / 2);
        }

        // even -> divide by 2, average number in that position with next higher number
        // [2, 4, 6, 8]
        // [4, 6]
        else {
            int meanLength = combNums.length / 2;
            System.out.println("Enter evens\n");
            floorMean = combNums[meanLength - 1]; // 4
            cielMean = combNums[(meanLength / 2) + 1]; // 6
            System.out.println("Floor Mean = " + floorMean + ", cielMean = " + cielMean);
            median = ((floorMean + cielMean) / 2);
        }

        return median;
    }
}