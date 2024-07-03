
/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "Tree.hpp"
#include "complex.hpp"

using namespace std;

int main()
{
    cout << "\n-------first tree: binary---------\n";
    Node<double>* root_node = new Node<double>(1.1);
    Tree<double> tree1; // Binary tree that contains doubles.
    tree1.add_root(root_node);
    Node<double>* n1 = new Node(1.2);
    Node<double>* n2 = new Node(1.3);
    Node<double>* n3 = new Node(1.4);
    Node<double>* n4 = new Node(1.5);
    Node<double>* n5 = new Node(1.6);

    tree1.add_sub_node(root_node, n1);
    tree1.add_sub_node(root_node, n2);
    tree1.add_sub_node(n1, n3);
    tree1.add_sub_node(n1, n4);
    tree1.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "\n******* line 40 - Test pre order:\n";

    for (auto node = tree1.begin_pre_order(); node != tree1.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << tree1.end_pre_order()->get_value();
    cout << "\nline above should be: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6 \n";

    cout << "\n******* line 49 - Test post order:\n";

    for (auto node = tree1.begin_post_order(); node != tree1.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout << tree1.end_post_order()->get_value();
    cout << "\nline above sould be: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1, \n";


    cout << "\n******** line 59 - Test in order:\n";

    for (auto node = tree1.begin_in_order(); node != tree1.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout << tree1.end_in_order()->get_value();
    cout << "\nline above should be: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3, \n";


    cout << "\n****** line 69 - Test bfs scan:\n";

    for (auto node = tree1.begin_bfs_scan(); node != tree1.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout << tree1.end_bfs_scan()->get_value();
    cout << "\nline above should be: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6\n";

    cout << "\n****** line 78 - Test bfs scan but begin()-end()\n";

    for (auto& node : tree1)
    {
        cout << node.get_value() << ", ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout << tree1.end()->get_value();
    cout << "\nline above should be: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6\n";

    //cout << tree; // Should print the graph using GUI.

    cout << "\n---------second tree: children = 3 -----------\n";
    Tree<double> three_ary_tree(3); // 3-ary tree.
    three_ary_tree.add_root(1.1);
    three_ary_tree.add_sub_node(1.1, 1.2);
    three_ary_tree.add_sub_node(1.1, 1.3);
    three_ary_tree.add_sub_node(1.1, 1.4);
    three_ary_tree.add_sub_node(1.2, 1.5);
    three_ary_tree.add_sub_node(1.3, 1.6);

     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    

    cout << "\n***** line 108 - Test In-Order in case dfs:\n";
    for (auto it = three_ary_tree.begin_in_order(); it != three_ary_tree.end_in_order(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.5, 1.2, 1.6, 1.3, 1.4, 1.1
    cout << three_ary_tree.end_in_order()->get_value(); 
    cout << "\nline above should be: 1.5, 1.2, 1.6, 1.3, 1.4, 1.1\n";

    cout << "\n**** line 114 - Test BFS:" << endl;
    for (auto it = three_ary_tree.begin_bfs_scan(); it != three_ary_tree.end_bfs_scan(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 
    cout << three_ary_tree.end_bfs_scan()->get_value();
    cout << "\nline above should be: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, \n";

    cout << "\n**** line 120 - Test DFS:" << endl;
    for (auto it = three_ary_tree.begin_dfs_scan(); it != three_ary_tree.end_dfs_scan(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.5, 1.2, 1.6, 1.3, 1.4, 1.1 
    cout << three_ary_tree.end_dfs_scan()->get_value();
    cout << "\nline above should be: 1.5, 1.2, 1.6, 1.3, 1.4, 1.1\n";

    
    cout << "\n---------third tree: binary -----------\n";

    Tree<double> tree3; // Binary tree that contains doubles.
    tree3.add_root(1.1);
    tree3.add_sub_node(1.1, 1.2);
    tree3.add_sub_node(1.1, 1.3);
    tree3.add_sub_node(1.2, 1.4);
    tree3.add_sub_node(1.2, 1.5);
    tree3.add_sub_node(1.3, 1.6);

    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */

    cout << "\n**** line 146 - Test Pre-Order:\n";
    for (auto it = tree3.begin_pre_order(); it != tree3.end_pre_order(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.1, 1.2, 1.4, 1.5, 1.3, 1.6,
    cout << tree3.end_pre_order()->get_value(); 
    cout << "\nline above should be: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6, \n";

    cout << "\n***** line 152 - Test Post-Order:\n";
    for (auto it = tree3.begin_post_order(); it != tree3.end_post_order(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.4, 1.5, 1.2, 1.6, 1.3, 1.1, 
    cout << tree3.end_post_order()->get_value();
    cout << "\nline above should be: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1\n";


    cout << "\n***** line 160 - Test In-Order:\n";
    for (auto it = tree3.begin_in_order(); it != tree3.end_in_order(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.4, 1.2, 1.5, 1.1, 1.6, 1.3, 
    cout << tree3.end_in_order()->get_value();
    cout << "\nline above should be: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3\n";

    cout << "\n**** line 166 - Test BFS:" << endl;
    for (auto it = tree3.begin_bfs_scan(); it != tree3.end_bfs_scan(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.1, 1.2, 1.4, 1.5, 1.3, 1.6, 
    cout << tree3.end_bfs_scan()->get_value();
    cout << "\nline above should be: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6, \n";

    cout << "\n**** line 172 - Test DFS:" << endl;
    for (auto it = tree3.begin_dfs_scan(); it != tree3.end_dfs_scan(); ++it) {
        cout << it->get_value() << ", ";
    } // 1.4, 1.5, 1.2, 1.6, 1.3, 1.1, 
    cout << tree3.end_dfs_scan()->get_value();
    cout << "\nline above should be: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1\n";



    cout << "\n--------four tree: complex binary-----------\n";

    Tree<Complex> complex_tree(2); // Binary tree that contains Complex numbers.
    complex_tree.add_root(Complex(41, 1));
    complex_tree.add_root(Complex(9, 1)); // should not add (have root)
    complex_tree.add_sub_node(Complex(41, 1), Complex(2.2, 2));
    complex_tree.add_sub_node(Complex(41, 1), Complex(3, 3.5));
    complex_tree.add_sub_node(Complex(41, 1), Complex(-4, 4)); // should not add (too many children)
    complex_tree.add_sub_node(Complex(2.2, 2), Complex(5, 5));
    complex_tree.add_sub_node(Complex(5, 5), Complex(16, 6));
    complex_tree.add_sub_node(Complex(0, 1), Complex(8, 3)); // sould not add (no parent)
    complex_tree.add_sub_node(new Node<Complex>(Complex(3, 3.5)), new Node<Complex>(Complex(6, 4)));

    /*
                root=(41,1i)
                /      \ 
            (2.2,2i)    (3,3.5i)
            /              /
           (5,5i)         (6,4i)
           /
        (16,6i) 
    */


    
    cout << "\n******* line 205 - Test pre order:\n";

    for (auto node = complex_tree.begin_pre_order(); node != complex_tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: (41,1i), (2.2,2i), (5,5i), (16,6i), (3,3.5i), (6,4i) 
    cout << complex_tree.end_pre_order()->get_value();
    cout << "\nline above should be: (41,1i), (2.2,2i), (5,5i), (16,6i), (3,3.5i), (6,4i)  \n";

    cout << "\n******* line 214 - Test post order:\n";

    for (auto node = complex_tree.begin_post_order(); node != complex_tree.end_post_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints:(16,6i), (5,5), (2.2,2), (6,4), (3,3.5), (41,1), 
    cout << complex_tree.end_post_order()->get_value();
    cout << "\nline above sould be: (16,6i), (5,5i), (2.2,2i), (6,4i), (3,3.5i), (41,1i), \n";


    cout << "\n******** line 224 - Test in order:\n";

    for (auto node = complex_tree.begin_in_order(); node != complex_tree.end_in_order(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: (5,5), (2.2,2), (41,1), (6,4), (3,3.5), 
    cout << complex_tree.end_in_order()->get_value();
    cout << "\nline above should be: (16,6i), (5,5i), (2.2,2i), (41,1i), (6,4i), (3,3.5i),  \n";


    cout << "\n****** line 234 - Test bfs scan:\n";

    for (auto node = complex_tree.begin_bfs_scan(); node != complex_tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << ", ";
    } // prints: (41,1), (2.2,2), (5,5), (16,6), (3,3.5), 
    cout << complex_tree.end_bfs_scan()->get_value();
    cout << "\nline above should be: (41,1i), (2.2,2i), (5,5i), (16,6i), (3,3.5i), (6,4i) \n";

    cout << "\n****** line 243 - Test bfs scan but begin()-end()\n";

    for (auto& node : complex_tree)
    {
        cout << node.get_value() << ", ";
    } // prints: (41,1), (2.2,2), (5,5), (16,6), (3,3.5), 
    cout << complex_tree.end()->get_value();
    cout << "\nline above should be: (41,1i), (2.2,2i), (5,5i), (16,6i), (3,3.5i), (6,4i) \n";

    cout << "\n-------complex tree : binary---------\n";
    Complex* c1 = new Complex(1, -1);
    Complex* c2 = new Complex(0, 1);
    Complex* c3 = new Complex(9, 9);
    Complex* c4 = new Complex(10, 3);
    Complex* c5 = new Complex(11, 1);


    Node<Complex> *root_node1 = new Node<Complex>(*c1);
    Tree<Complex> tree4; 
    tree4.add_root(root_node1);
    Node<Complex>* n10 = new Node(*c2);
    Node<Complex>* n20 = new Node(*c3);
    Node<Complex>* n30 = new Node(*c4);
    Node<Complex>* n40 = new Node(*c5);
    Node<Complex>* n50 = new Node(Complex(100,15));

    tree4.add_sub_node(root_node1, n10);
    tree4.add_sub_node(root_node1, n20);
    tree4.add_sub_node(root_node1, n30); // should not work

    tree4.add_sub_node(n10, n30);
    tree4.add_sub_node(n10, n40);
    tree4.add_sub_node(n20, n50);
    tree4.add_sub_node(*c3, Complex(9,19));

    /*
            complex tree:

            root=(1,-1)
             /         \
            (0,1)      (9,9)
           /    \          /     \
         (10,3)  (11,1) (100,15) (9,19)    
    
    */

    cout << "\n**** line 295 - Test Pre-Order:\n";
    for (auto it = tree4.begin_pre_order(); it != tree4.end_pre_order(); ++it) {
        cout << it->get_value() << ", ";
    } // (1,-1), (0,1), (10,3), (11,1), (9,9), (100,15), (9,19)
    cout << tree4.end_pre_order()->get_value(); 
    cout << "\nline above should be: (1,-1), (0,1), (10,3), (11,1), (9,9), (100,15), (9,19)\n";

    cout << "\n***** line 302 - Test Post-Order:\n";
    for (auto it = tree4.begin_post_order(); it != tree4.end_post_order(); ++it) {
        cout << it->get_value() << ", ";
    } // (10,3), (11,1), (0,1), (100,15), (9,19), (9,9), (1,-1) 
    cout << tree4.end_post_order()->get_value();
    cout << "\nline above should be: (10,3), (11,1), (0,1), (100,15), (9,19), (9,9), (1,-1)\n";


    cout << "\n***** line 310 - Test In-Order:\n";
    for (auto it = tree4.begin_in_order(); it != tree4.end_in_order(); ++it) {
        cout << it->get_value() << ", ";
    } // (10,3), (0,1), (11,1), (1,-1), (100,15), (9,9), (9,19) 
    cout << tree4.end_in_order()->get_value();
    cout << "\nline above should be: (10,3), (0,1), (11,1), (1,-1), (100,15), (9,9), (9,19)\n";



    cout << "\n-------- tree: double binary-----------\n";
    Tree<double> tree5;
    tree5.add_root(1.5);
    tree5.add_root(9.1);

    tree5.add_sub_node(1.5, 7.8);
    tree5.add_sub_node(1.5, 8.6);
    tree5.add_sub_node(8.6, 5.5);
    tree5.add_sub_node(8.6, 3.2);
    tree5.add_sub_node(3.2, 2.2);
    tree5.add_sub_node(7.8, 99);
    tree5.add_sub_node(7.8, 6);
    tree5.add_sub_node(6, 6.6);
    tree5.add_sub_node(99, 1);

    /*

    befor heap:
                    root=1.5
                    /      \
                   7.8      8.6
                  /   \      /   \ 
                99    6     5.5  3.2
                /     /          /
                1    6.6      2.2
    
    after heap:

            1
        /     \
       1.5    2.2
      / \     /  \
     3.2 5.5  6   7.8
     / \     /
   99  8.6  6.6

    
    */


    cout << "\n***** line 358 - Test In-Order in case dfs:\n";
    for (auto it = tree5.begin_in_order(); it != tree5.end_in_order(); ++it) {
        cout << it->get_value() << ", ";
    } // 1, 99, 7.8, 6.6, 6, 1.5, 5.5, 8.6, 2.2, 3.2
    cout << tree5.end_in_order()->get_value(); 
    cout << "\nline above should be: 1, 99, 7.8, 6.6, 6, 1.5, 5.5, 8.6, 2.2, 3.2\n";

    cout << "\n**** line 366 - Test Heap:" << endl;
    for (auto it = tree5.beagin_Heap(); it != tree5.end_Heap(); ++it) {
        cout << it->get_value() << ", ";
    } // 1, 1.5, 3.2, 99, 8.6, 5.5, 2.2, 6, 6.6, 7.8 
    cout << tree5.end_Heap()->get_value();
    cout << "\nline above should be: 1, 1.5, 3.2, 99, 8.6, 5.5, 2.2, 6, 6.6, 7.8\n";

    cout << "\n**** line 373 - Test DFS:" << endl;
    for (auto it = tree5.begin_dfs_scan(); it != tree5.end_dfs_scan(); ++it) {
        cout << it->get_value() << ", ";
    } // 99, 8.6, 3.2, 5.5, 1.5, 6.6, 6, 7.8, 2.2, 1 
    cout << tree5.end_dfs_scan()->get_value();
    cout << "\nline above should be: 99, 8.6, 3.2, 5.5, 1.5, 6.6, 6, 7.8, 2.2, 1\n";


    return 0;

}