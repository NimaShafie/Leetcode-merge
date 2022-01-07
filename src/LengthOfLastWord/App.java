package LengthOfLastWord;

import java.util.Scanner;

public class App {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String userInput = sc.nextLine();
        LengthOfLastWord solObj = new LengthOfLastWord();
        int lengthWord = solObj.lengthOfLastWord(userInput);
        System.out.println("Length is = " + lengthWord);
        sc.close();
    }
}