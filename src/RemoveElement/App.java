package RemoveElement;
import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        RemoveElement obj = new RemoveElement();
        //RemoveElement obj = new RemoveElement();
        int[] nums = {3, 3};

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter value to remove: ");
        int val = sc.nextInt();

        int sol = obj.removeElement(nums, val);
        sc.close();
        System.out.println("\nReturn value == " + sol);
    }
}