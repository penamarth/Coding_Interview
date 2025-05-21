public class Prog {

    public static boolean isSubstring(String string, String substring) {
        return string.contains(substring);
    }

    public static boolean isCiclicShift(String s1, String s2) {
        if( s1.length() != s2.length()) {
            return false;
        }
        return isSubstring(s2 + s2, s1);
    }

    public static void main(String[] args) {
        System.out.println("waterbottle " + "erbottlewat " + isCiclicShift("waterbottle", "erbottlewat"));
        System.out.println("Hello " + "oHell " + isCiclicShift("Hello", "oHell"));
        System.out.println("Hello " + "Helloo " + isCiclicShift("Hello", "Helloo"));
        System.out.println("Hello " + "Hoell " + isCiclicShift("Hello", "Hoell"));

    }
}
