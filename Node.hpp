
// Node.hpp

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

using namespace std;

template<typename T>
class Node {
public:
    T value; // Holding the value of the node
    vector<Node<T>*> children; // Children of this node

    // Constructor to initialize the node with a value
    Node(T value) : value(value) {}

    // Destructor to delete all child nodes
    ~Node() {
        for (auto child : children) {
            delete child;
        }
    }

    // Get the value of the node
    T get_value() { return this->value; }

    void set_value(T value) {this->value = value;}


    // Add a child to this node
    void add_child(Node<T>* child) {
        this->children.push_back(child);
    }
};

#endif // NODE_HPP
