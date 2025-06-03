public class Prog {
    public static void main(String[] arg)
    {

        List L = new LinkedList();
        L.insert(1, 0);
        L.insert(2, L.end());
        L.insert(2, L.end());
        L.insert(3, L.end());

        L.print();
        ((LinkedList)L).purge();

        L.print();

        L = new LinkedList();
        L.insert(1, 0);
        L.insert(1, L.end());
        L.insert(2, L.end());
        L.insert(3, L.end());

        L.print();
        ((LinkedList)L).purge();

        L.print();

        L = new LinkedList();
        L.insert(1, 0);
        L.insert(2, L.end());
        L.insert(3, L.end());
        L.insert(3, L.end());

        L.print();
        ((LinkedList)L).purge();

        L.print();

    }
}
