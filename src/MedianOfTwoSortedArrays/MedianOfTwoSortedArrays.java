package MedianOfTwoSortedArrays;

import java.util.Collections;
import java.util.ArrayList;

class MedianOfTwoSortedArrays {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {

        //int[] testNums = {2, 4, 6, 8};
        ArrayList<Integer> combNums = combArrays(nums1, nums2);
        System.out.print("combNums == ");
        for(int i = 0; i < combNums.size(); i++) System.out.print(combNums.get(i) + ", ");
        double answer = calcMedian(combNums);

        return answer;
    }

    ArrayList<Integer> combArrays(int[] nums1, int[] nums2) {
        int nums1Length = nums1.length;
        int nums2Length = nums2.length;

        // initalize the arrayList capacity in advance for better performance
        ArrayList<Integer> newNums = new ArrayList<>((nums1Length + nums2Length)); 
        // only add to the combined array if the original array has data in it
        if(nums1Length != 0) for(int i = 0; i < nums1Length; i++) newNums.add(nums1[i]);    
        if(nums2Length != 0) for(int i = 0; i < nums2Length; i++) newNums.add(nums2[i]);
        if(nums1Length == 0 && nums2Length == 0) return newNums;
        Collections.sort(newNums);
        return newNums;
    }

    double calcMedian(ArrayList<Integer> combNums) {
        int medianPos;
        double median;
        double floorMean, cielMean;
        if(combNums.size() == 1) return combNums.get(0);
        // odd -> divde by 2, round up
        // [2, 4, 6, 8, 9] 5/2 == 3, answer is 6
        if(combNums.size() % 2 != 0) {
            System.out.println("\nEnter odds\n");
            medianPos = combNums.size() / 2;
            median = combNums.get(medianPos);
            return median;
        }

        // even -> divide by 2, average number in that position with next higher number
        // [2, 4, 6, 8]
        // [4, 6]
        else {
            int meanLength = combNums.size() / 2;
            System.out.println("\nEnter evens\n");
            floorMean = combNums.get(meanLength - 1); // 4
            cielMean = combNums.get(meanLength); // 6
            System.out.println("Floor Mean == " + floorMean + "\nCiel Mean == " + cielMean);
            System.out.println("Floor Mean = " + floorMean + ", cielMean = " + cielMean);
            median = ((floorMean + cielMean) / 2);
        }
        return median;
    }
}

// [1, 2, 3, 4]
//  0  1  2  3
// meanLength = size / 2 == (4/2) = 2
// lowerBound == (meanLength - 1)
// higherBound == (meanLength)

// [1, 2, 3, 4, 5, 6, 7, 8]
//  0  1  2  3  4  5  6  7
// meanLength = size / 2 == (8/2) = 4
// lowerBound == (meanLength - 1)
// higherBound == (meanLength)