public class Prog {
    public static void main(String[] arg)
    {

        List L = new LinkedList();
        L.insert(3, 0);
        L.insert(5, L.end());
        L.insert(8, L.end());
        L.insert(5, L.end());
        L.insert(10, L.end());
        L.insert(2, L.end());
        L.insert(1, L.end());

        L.print();

        ((LinkedList)L).sortAround(5);

        L.print();
    }
}
