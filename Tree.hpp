
// Tree.hpp

#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <memory>
#include <sstream>

using namespace std;

enum TraversalType { PRE_ORDER_BFS, POST_ORDER_DFS, IN_ORDER };


template<typename T>
class Tree {

public:
    class Iterator;

private:
    Node<T>* root = nullptr;
    int k;

    Node<T>* find_node(Node<T>* node_start, Node<T>* node_to_find) {
        if (!node_start || !node_to_find) {return nullptr;}
        if (node_start->get_value() == node_to_find->get_value()) {return node_start;}
        for (size_t i=0; i<node_start->children.size(); i++) {
            Node<T>* child = node_start->children[i];
            cout << "Checking child at index " << i << " with value " << child->get_value() << endl;
            auto result = find_node(child, node_to_find);
            if (result) return result;
        }
        return nullptr;
    }

    Node<T>* find_node_value(Node<T>* node_start, T node_value_to_find) {
        if (!node_start) return nullptr;
        if (node_start->get_value() == node_value_to_find) return node_start;
        for (auto& child : node_start->children) {
            auto result = find_node_value(child, node_value_to_find);
            if (result) return result;
        }
        return nullptr;
    }


    // Helper function to perform heapify in-place
    void heapify(Node<T>* node) {
        if (!node) return;

        // Recursively heapify each subtree
        for (auto& child : node->children) {
            heapify(child);
        }

        // Perform heapify operation
        if (!node->children.empty()) {
            // Find minimum among root and children
            Node<T>* min_node = node;
            for (auto& child : node->children) {
                if (child->get_value() < min_node->get_value()) {
                    min_node = child;
                }
            }

            // Swap values if necessary
            if (min_node != node) {
                T temp = node->get_value();
                node->set_value(min_node->get_value());
                min_node->set_value(temp);
            }
        }
    }

public:
    Tree(int k=2) {this->k=k;}

     ~Tree() {
        delete root;
    }

    void add_root(Node<T>* r) {
        if(!root) {
            root = r;
        }
    }

    void add_root(T value) {
        if(!root) {
            root = new Node<T>(value);
        }
    }

    void add_sub_node(Node<T>* parent, Node<T>* child) {
        Node<T>* found_parent = find_node(root, parent);
        if (found_parent != nullptr && found_parent->children.size() < k) {
            found_parent->add_child(child);
        }
    }

    bool add_sub_node(T parent_value, T child_value) {
        auto parent = find_node_value(root, parent_value);
        if (parent && parent->children.size() < k) {
            parent->add_child(new Node<T> (child_value));
            return true;
        }
        return false;
    }

    ostringstream& printTreeBaseoNumber(ostringstream& ans,int number) {
        Iterator start;
        Iterator end;
        switch (number) {
        case 0 :
            start = this->begin();
            end = this->end();
            break;
        case 1 :
            start = this->begin_bfs_scan();
            end = this->end_bfs_scan();
            break;
        case 2 :
            start = this->begin_dfs_scan();
            end = this->end_dfs_scan();
            break;
        case 3 :
            start = this->begin_in_order();
            end = this->end_in_order();
            break;
        case 4 :
            start = this->begin_pre_order();
            end = this->end_pre_order();
            break;
        case 5 :
            start = this->begin_post_order();
            end = this->end_post_order();
            break;
        case 6 :
            start = this->beagin_Heap();
            end = this->end_Heap();
            break;
        default:
            ans << "Error: input print number is not good";
            return ans;
        }
        while(start!=end) {
            ans << start->get_value() << ", ";
            ++start;
        }
        ans << end->get_value();
        return ans;
    }


    Iterator begin() {
        return Iterator(root, PRE_ORDER_BFS, false);
    }

    Iterator end() {
        return Iterator(root, PRE_ORDER_BFS, true);
    }

    Iterator begin_pre_order() {
        if(k==2) {
            return Iterator(root, PRE_ORDER_BFS, false);
        }
        else {
            return Iterator(root, POST_ORDER_DFS, false);
        }
    }

    Iterator end_pre_order() {
        if(k==2) {
            return Iterator(root, PRE_ORDER_BFS, true);
        }
        else {
            return Iterator(root, POST_ORDER_DFS, true);
        }    
    }

    Iterator begin_post_order() {
        return Iterator(root, POST_ORDER_DFS, false);
    }

    Iterator end_post_order() {
        return Iterator(root, POST_ORDER_DFS, true);
    }

    Iterator begin_in_order() {
        if(k==2) {
            return Iterator(root, IN_ORDER, false);
        }
        else {
            return Iterator(root, POST_ORDER_DFS, false);
        }    
    }

    Iterator end_in_order() {
        if(k==2) {
            return Iterator(root, IN_ORDER, true);
        }
        else {
            return Iterator(root, POST_ORDER_DFS, true);
        }    
    }

    Iterator begin_bfs_scan() {
        return Iterator(root, PRE_ORDER_BFS, false);
    }

    Iterator end_bfs_scan() {
        return Iterator(root, PRE_ORDER_BFS, true);
    }

    Iterator begin_dfs_scan() {
        return Iterator(root, POST_ORDER_DFS, false);
    }

    Iterator end_dfs_scan() {
        return Iterator(root, POST_ORDER_DFS, true);
    }

    Iterator beagin_Heap() {
        if(k==2) {
            this->heapify(root);
        }
        return Iterator(root, PRE_ORDER_BFS, false);
    }

    Iterator end_Heap() {
        return Iterator(root, PRE_ORDER_BFS, true);
    }


    class Iterator {
    private:
        Node<T>* root;
        Node<T>* current;
        TraversalType type;
        bool is_end;

        void pre_order_traversal_and_bfs(Node<T>* node, vector<Node<T>*>& nodes) {
            if (!node) return;
            nodes.push_back(node);
            for (size_t i=0; i<node->children.size(); i++) {
                pre_order_traversal_and_bfs(node->children[i], nodes);
            }
        }

        void post_order_traversal_and_dfs(Node<T>* node, vector<Node<T>*>& nodes) {
            if (!node) return;
            for (size_t i=0; i<node->children.size(); i++) {
                post_order_traversal_and_dfs(node->children[i], nodes);
            }
            nodes.push_back(node);
        }

        void in_order_traversal(Node<T>* node, vector<Node<T>*>& nodes) {
            if (!node) return;
            if (!node->children.empty()) {
                in_order_traversal(node->children[0], nodes);
            }
            nodes.push_back(node);
            for (size_t i = 1; i < node->children.size(); ++i) {
                in_order_traversal(node->children[i], nodes);
            }
        }

    public:
        Iterator() : root(nullptr), current(nullptr), type(TraversalType::PRE_ORDER_BFS), is_end(true) {}

        Iterator(Node<T>* root, TraversalType traversal_type, bool is_end)
            : root(root), current(nullptr), type(traversal_type), is_end(is_end) {
            if (root) {
                vector<Node<T>*> nodes;
                switch (type) {
                    case TraversalType::PRE_ORDER_BFS:
                        pre_order_traversal_and_bfs(root, nodes);
                        break;
                    case TraversalType::POST_ORDER_DFS:
                        post_order_traversal_and_dfs(root, nodes);
                        break;
                    case TraversalType::IN_ORDER:
                        in_order_traversal(root, nodes);
                        break;
                    default:
                        break;
                }
                if (!nodes.empty()) {
                    if (is_end) {
                        current = nodes.back();
                    } else {
                        current = nodes[0];
                    }
                }
            }
        }

        Iterator& operator++() {
            if (current) {
                vector<Node<T>*> nodes;
                switch (type) {
                    case TraversalType::PRE_ORDER_BFS:
                        pre_order_traversal_and_bfs(root, nodes);
                        break;
                    case TraversalType::POST_ORDER_DFS:
                        post_order_traversal_and_dfs(root, nodes);
                        break;
                    case TraversalType::IN_ORDER:
                        in_order_traversal(root, nodes);
                        break;
                    default:
                        break;
                }
                for (size_t t = 0; t < nodes.size(); t++) {
                    if (nodes[t] == current && t + 1 < nodes.size()) 
                    { 
                        current = nodes[t + 1]; 
                        break;
                    }
                    if(t+1==nodes.size()) {current = nullptr;}
                }
            }
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        Node<T>& operator*() const {
            return *current;
        }

        Node<T>* operator->() const {
            return current;
        }
    };
};

#endif // TREE_HPP
