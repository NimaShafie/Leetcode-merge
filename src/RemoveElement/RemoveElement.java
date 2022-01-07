package RemoveElement;

public class RemoveElement {
    
    public int removeElement(int[] nums, int val) {
        System.out.print("Original nums[] = ");
        for(int i = 0; i < nums.length; i++) System.out.print(nums[i] + " ");

        // scan the array, when we find our target value, we must mark it to be moved to the end of the user input array
        // [1, 0, 4, 6, 4, 2, 1] remove 4
        // [1, 0, 6, 2, 1, _, _] return new size of array (minus the removed values) return size = 5

        // base case for only 1 input
        if(nums.length == 1) {
            //if the only argument that was passed is the value we want to remove then return 0
            if(nums[0] == val) return 0;
            else return 1;
        }

        int swapLength = (nums.length - 1);   // used to determine how many elements to look at
        for(int j = 0; j < swapLength; j++) {
            // we've found the target int to remove
            // int will be swap with next position until it reaches the end of the array and will be replaced by -1
            int indexCheck = j;
            while((nums[j] == val) && (indexCheck < nums.length)) {
            if(nums[j] == val) {
                int temp = nums[j];
                for(int k = j; k < swapLength; k++) {      // k will be the index starting from position of value to remove
                    nums[k] = nums[k + 1];
                    nums[k + 1] = temp;
                }
            }
            indexCheck++;
            }
        }
        System.out.print("\nNew nums[] == ");
        for(int i = 0; i < nums.length; i++) System.out.print(nums[i] + " ");
        System.out.println("\n");

        int retValue = nums.length; // will return the original length if no removed elements are found
        for(int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
            if(nums[i] == val) {
                retValue = i;
                return retValue;
            }
        }
        return retValue;
    }
}