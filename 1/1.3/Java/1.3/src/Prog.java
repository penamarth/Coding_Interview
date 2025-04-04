public class Prog {
    public static String URIWhitespace(String s){
        return s.strip().replace(" ", "%20");
    }

    public static void main(String[] args) {
        System.out.println(URIWhitespace("NoSpace"));
        System.out.println(URIWhitespace("With Space"));
        System.out.println(URIWhitespace("Many Spaces In Line"));
        System.out.println(URIWhitespace(" StartWithSpace"));
        System.out.println(URIWhitespace("EndWithSpace "));
        System.out.println(URIWhitespace(" Start With Space And Multiple Spaces"));
        System.out.println(URIWhitespace("End With Space And Multiple Spaces "));
        System.out.println(URIWhitespace(" All In Spaces "));
    }
}
