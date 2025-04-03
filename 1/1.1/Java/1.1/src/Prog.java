public class Prog {
    public static boolean isCharsOccurOnce(String str){
        for(char c : str.toCharArray()){
            if (str.chars().filter(x -> x == c).count() > 1)
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        System.out.println(isCharsOccurOnce("abc"));
        System.out.println(isCharsOccurOnce("aabbcc"));
    }
}
