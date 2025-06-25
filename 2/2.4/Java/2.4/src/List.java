public interface List {
    boolean isEmpty();
    void insert(int value, int position);
    int locate(int value);
    int retrieve(int position);
    void print();
    void del(int position);
    int end();
    int getCurrentPosition();
}
