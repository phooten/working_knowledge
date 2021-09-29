#ifndef BSTREE_H
#define BSTREE_H

class BsTree{
    public:
        int data;
        BsTree *right;
        BsTree *left;

        BsTree();
        BsTree(int num);

        BsTree *Insert(int num, BsTree *root);
        void Print(BsTree *root);
    private:    

};

#endif  // BSTREE_H