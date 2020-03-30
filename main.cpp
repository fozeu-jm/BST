#include <iostream>
#include "Nodes.h"
#include <glutWindow.h>
#include "BST.h"
#include "GUI.h"

int main(int argc,char **argv) {
    BST tree(new Node(16));

    tree.place(new Node(8),tree.getRoot());
    tree.place(new Node(7),tree.getRoot());
    tree.place(new Node(11),tree.getRoot());
    tree.place(new Node(9),tree.getRoot());
    tree.place(new Node(14),tree.getRoot());
    tree.place(new Node(25),tree.getRoot());
    tree.place(new Node(21),tree.getRoot());
    tree.place(new Node(31),tree.getRoot());
    tree.place(new Node(46),tree.getRoot());


    cout<< ( ( tree.find(11) != nullptr ) ? "Matching key found in the tree \n" : "No match found in the tree\n" );

    cout<< ( ( tree.insert(65) ) ? "Node was successfully added to the tree \n" : "A node with a similar key already exist ! \n" );

    int tab[]={16, 8, 11, 7, 9, 21, 30, 25, 30, 46, 14};

    BST tree2;
    tree2.inserts(tab);



    tree.placingNodes();
    GUI window(&tree,argc,argv);
    window.start();

    return 0;
}