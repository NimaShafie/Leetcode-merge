package MedianOfTwoSortedArrays;

public class App {

    public static void main(String[] args) {
        int[] nums1 = {1, 3};
        int[] nums2 = {2};

        MedianOfTwoSortedArrays solObj = new MedianOfTwoSortedArrays();
        Double medianSol = solObj.findMedianSortedArrays(nums1, nums2);
        System.out.println("Median is = " + medianSol);
    }
}