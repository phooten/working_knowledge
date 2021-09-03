

class Node{
    public:
        int data;
        int *head;
        int *tail;

        Node();
        Node(int num);

        bool insert(int num);
        bool remove(int num);
        int seach(int num);

    private:
        int position;
};