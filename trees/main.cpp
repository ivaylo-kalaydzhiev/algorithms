#include <iostream>

class Node {
public:
    int key;
    Node *l, *r;

    Node(int key)
            : key(key), l(nullptr), r(nullptr) {}
};

/// Implementation does not follow good practices, is for "quick & dirty" algorithmic purposes only
class BST {
private:
    Node *root;

    Node *insert(int key, Node *node) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key < node->key) {
            node->l = insert(key, node->l);
        } else if (key > node->key) {
            node->r = insert(key, node->r);
        }

        return node;
    }

    Node *minKey(Node *node) {
        Node *tmp = node;
        while (tmp->l != nullptr) {
            tmp = tmp->l;
        }
        return tmp;
    }

    Node *remove(int key, Node *node) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->l = remove(key, node->l);
        } else if (key > node->key) {
            node->r = remove(key, node->r);
        } else {
            // This is the node we need to delete

            // Leaf, or single child cases
            if (node->l == nullptr) {
                return node->r;
            } else if (node->r == nullptr) {
                return node->l;
            } else {
                // Handle case where it has 2 children

                // Take the new root
                Node *newRoot = minKey(node->r);

                // Replace this root with the new root
                node->key = newRoot->key;

                // Delete the new root original in the right tree
                node->r = remove(newRoot->key, node->r);
            }
        }

        return node;
    }

    void inorder(Node *node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->l);
        std::cout << node->key << ' ';
        inorder(node->r);
    }

    bool search(int key, Node *node) {
        if (node == nullptr) {
            return false;
        }

        if (key < node->key) {
            return search(key, node->l);
        } else if (key > node->key) {
            return search(key, node->r);
        } else {
            // This is the node we are looking for
            return true;
        }
    }


public:
    BST() : root(nullptr) {}

    void insert(int key) {
        root = insert(key, root);
    }

    void remove(int key) {
        root = remove(key, root);
    }

    void print() {
        inorder(root);
    }

    bool contains(int key) {
        return search(key, root);
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
