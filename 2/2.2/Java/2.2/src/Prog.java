public class Prog {
    public static void main(String[] arg)
    {

        List L = new LinkedList();
        L.insert(1, 0);
        L.insert(2, L.end());

        L.insert(3, L.end());
        L.insert(4, L.end());
        L.insert(5, L.end());
        L.insert(6, L.end());
        L.insert(7, L.end());

        L.print();


        System.out.println(((LinkedList)L).retrieveFromEnd(0));
        System.out.println(((LinkedList)L).retrieveFromEnd(1));
        System.out.println(((LinkedList)L).retrieveFromEnd(2));
        System.out.println(((LinkedList)L).retrieveFromEnd(3));
        System.out.println(((LinkedList)L).retrieveFromEnd(4));
        System.out.println(((LinkedList)L).retrieveFromEnd(5));
        System.out.println(((LinkedList)L).retrieveFromEnd(6));
        System.out.println(((LinkedList)L).retrieveFromEnd(7));


    }
}
