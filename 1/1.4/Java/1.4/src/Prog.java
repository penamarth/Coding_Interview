import java.util.*;

public class Prog {
    public static List < String > generatePermutations(String str) {
        List < String > permutations = new ArrayList < > ();
        generatePermutationsHelper(str, "", permutations);
        return permutations;
    }

    private static void generatePermutationsHelper(String str, String current, List < String > permutations) {
        if (str.isEmpty()) {
            permutations.add(current);
            return;
        }

        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            String remaining = str.substring(0, i) + str.substring(i + 1);
            generatePermutationsHelper(remaining, current + ch, permutations);
        }
    }

    static boolean isPalindrome(String s){
        for( int i = 0; i < s.length() / 2; i++) {
            if(s.toCharArray()[i] != s.toCharArray()[s.length() - 1 - i])
                return false;
        }
        return true;
    }

    static boolean isPalindromeAnagram(String s)
    {
        s = s.replace(" ", "");

        for (String permutation : generatePermutations(s)) {
            if (isPalindrome(permutation)) {
                System.out.println("Palindrome found: " + permutation);
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println(isPalindromeAnagram("ar"));
        System.out.println(isPalindromeAnagram("ara"));
        System.out.println(isPalindromeAnagram("raa"));
        System.out.println(isPalindromeAnagram("ar "));
        System.out.println(isPalindromeAnagram("a ra"));
        System.out.println(isPalindromeAnagram("r aa"));
        System.out.println(isPalindromeAnagram("r ara"));
    }
}
