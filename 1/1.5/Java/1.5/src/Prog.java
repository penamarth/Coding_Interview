public class Prog {
    static boolean areOneStepAway(String s1, String s2)
    {
        if (s1 == s2)
            return true;

        if (s1.length() == s2.length())
        {
            int count = 0;

            for (int i = 0; i < s1.length(); i++)
            {
                if (s1.toCharArray()[i] != s2.toCharArray()[i])
                {
                    count += 1;
                }
            }
            if (count == 1)
                return true;
            else
                return false;
        }
        else if (s1.length() - s2.length() == 1)
        {
            for (char c : s2.toCharArray())
            {
                if (!s1.contains("" + c))
                    return false;
            }
            return true;
        }
        else if (s2.length() - s1.length() == 1)
        {
            for (char c : s1.toCharArray())
            {
                if (!s2.contains("" + c))
                    return false;
            }
            return true;
        }
        return false;
    }

    public static void main(String[] args) {

        System.out.println(areOneStepAway("hello", "hello"));
        System.out.println(areOneStepAway("hello", "hell"));
        System.out.println(areOneStepAway("hello", "help"));
        System.out.println(areOneStepAway("hellu", "hello"));
        System.out.println(areOneStepAway("helloo", "hello"));
        System.out.println(areOneStepAway("hellooo", "hello"));
    }
}
