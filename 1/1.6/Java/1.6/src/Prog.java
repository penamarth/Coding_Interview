public class Prog {

    static String compressString(String s) {
        String compressed = "";
        int counter = 1;
        String prev_c = "";
        for (char c : s.toCharArray()) {
            if (("" + c).equals(prev_c))
                counter += 1;
            else {
                compressed += prev_c + counter;
                counter = 1;
                prev_c = "" + c;
            }
        }
        compressed +=  s.substring(s.length() - 1) + counter;
        compressed = compressed.substring(1);

        if (compressed.length() >= s.length())
            return s;
        else
            return compressed;
    }

    public static void main(String[] args) {
        System.out.println(compressString("abc"));
        System.out.println(compressString("aabc"));
        System.out.println(compressString("Aabc"));
        System.out.println(compressString("aaaabbbcc"));
        System.out.println(compressString("aaAabbBcc"));
        System.out.println(compressString("aaAabbbBcc"));
        System.out.println(compressString("aaAabbbbBcc"));
        System.out.println(compressString("aaAabbbbbBcc"));
        System.out.println(compressString("aaAabbbbbbBcc"));
    }
}
