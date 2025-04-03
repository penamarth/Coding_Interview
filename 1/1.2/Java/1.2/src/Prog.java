public class Prog {
    public static boolean isAnagram(String string1, String string2)
    {
        if (string1.length() != string2.length())
        {
            return false;
        }

        for(char c : string1.toCharArray())
        {
            if (string1.chars().filter(x -> x == c).count() != string2.chars().filter(x -> x == c).count())
            return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println(isAnagram("hello", "hell"));
        System.out.println(isAnagram("hello", "ehllo"));
    }
}
