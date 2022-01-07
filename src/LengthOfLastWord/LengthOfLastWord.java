package LengthOfLastWord;
public class LengthOfLastWord {

    // returns the length of the last word in the string (delimited by space chars)
    public int lengthOfLastWord(String s) {
        // split the words of a string delimited by a space char
        String[] tokens = s.split(" ");

        // output the results to see what we're working with
        /*
        for(int i = 0; i < tokens.length; i++) {
            System.out.println(tokens[i]);
        }
        */

        String targetWord = tokens[(tokens.length) - 1];
        return (targetWord.length());
    }
}