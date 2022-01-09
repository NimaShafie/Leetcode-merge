package RemoveNthNodeFromEndOfList;

import java.util.Scanner;
import java.util.*;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

public class App {

  public class ListNode {
      int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
    
    public static void main(String[] args) {
        //RemoveNthNodeFromEndOfList obj = new RemoveNthNodeFromEndOfList();
        //ListNode Node = new ListNode(1);
        LinkedList<Integer> linkList = new LinkedList<>();
        linkList.add(1);
        linkList.add(2);
        linkList.add(3);
        //for(LinkedList<Integer> list : linkList) System.out.println()
        linkList.get(0);

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter value to remove: ");
        int removeVal = sc.nextInt();

        //int sol = obj.removeElement(nums, val);
        //RemoveNthNodeFromEndOfList Solution = new RemoveNthNodeFromEndOfList();

        sc.close();
        //System.out.println("\nReturn value == " + Solution);
    }
}