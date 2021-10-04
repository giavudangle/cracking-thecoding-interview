#include <iostream>
#include <stack>


template<class T>
class Node {
public:
    T data;
    Node* left;
    Node* right;
    Node<T>(T data) {
        this->data = data;
        left = right = NULL;
    }

    // InOrder Traversal -> LNR
    void InOrderTraversal(Node* root) {
        if (root == NULL) {
            return ;
        }
        InOrderTraversal(root->left);
        std::cout << root->data << " ";
        InOrderTraversal(root->right);
    }

    // PreOrder Traversal -> NLR
    void PreOrderTraversal(Node* root) {
        if (root == NULL) {
            return;
        } 
        std::cout << root->data << " ";
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
    }

    // PostOrderTraversal -> LRN
    void PostOrderTraversal(Node* root) {
        if (root == NULL) {
            return;

        }
        PreOrderTraversal(root->left);
        PreOrderTraversal(root->right);
        std::cout << root->data << " ";

    }

    // Function to check if BST contains a Node with d
    bool isContainsNode(Node* root, T d) {
        if (root == NULL) {
            return false;
        }
        bool flag = root->data == d ? true : false;
        return flag | isContainsNode(root->left, d) | isContainsNode(root->right, d);
    }

    // Function to insert a node 
    Node* insertNode(Node* root, T d) {
        if (root == NULL) {
            Node<T>* tmp = new Node<T>(d);
            return tmp;
        }

        // Consider node with data d is less than current root
        if (d < root->data) {
            root->left = insertNode(root->left, d);
            return root;
        } 
        // Consider node with data d is less than current root
        else if (d > root->data) {
            root->right = insertNode(root->right, d);
            return root;
        }

    }

    Node* minValueNode(Node* root) {
        Node<T>* current = root;
        while (current && current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* maxValueNode(Node* root) {
        Node<T>* current = root;
        while (current && current->right != NULL) {
            current = current->right;
        }
        return current;
    }

    Node* deleteNode(Node* root, T d) {
        if (root == NULL) {
            return root;
        }

        if (d < root->data) {
            root->left = deleteNode(root->left, d);
        }
        else if (d > root->data) {
            root->right = deleteNode(root->right, d);
        }
        else {
            if (root->left == NULL && root->right == NULL) {
                return NULL;
            }
            else if (root->left == NULL) {
                Node<T>* tmp = root->right;
                return tmp;
            }
            else if (root->right == NULL) {
                Node<T>* tmp = root->left;
                return tmp;
            }

            Node* tmp = minValueNode(root->right);
            root->data = tmp->data;
            root->right = deleteNode(root->right, tmp->data);
        }
        return root;
    }

};

template<class T>
class MySet {
public:
    Node<T>* root;
    int size;

    MySet<T>() {
        root = NULL;
        size = 0;
    }

    MySet<T>(const MySet& s) {
        this->root = s.root;
        this->size = s.size;
    }

    // Function to add an element into the set
    void add(const T data) {
        if (!root->isContainsNode(root, data)) {
            root = root->insertNode(root, data);
            size++;
        }
    }

    // Function to union another with this to new set
    MySet<T> unionSet(MySet& s) {
        MySet<T> res;

        if (root == NULL) {
            return res;
        }

        if (s.root == NULL) {
            return *this;
        }

        std::stack<Node<T>*> stackOfNodes;
        stackOfNodes.push(root);
        while (!stackOfNodes.empty()) {
            Node<T>* node;
            node = stackOfNodes.top();
            stackOfNodes.pop();
            res.add(node->data);
            if (node->right) {
                stackOfNodes.push(node->right);
            }
            if (node->left) {
                stackOfNodes.push(node->left);
            }
        }

        std::stack<Node<T>*> stackOfNodesTemp;
        stackOfNodesTemp.push(s.root);
        while (!stackOfNodesTemp.empty()) {
            Node<T>* node;
            node = stackOfNodesTemp.top();
            stackOfNodesTemp.pop();
            res.add(node->data);
            if (node->right) {
                stackOfNodesTemp.push(node->right);
            }
            if (node->left) {
                stackOfNodesTemp.push(node->left);
            }
        }

        return res;
    }

    // Function to intersection another one
    MySet<T> intersectionSet(MySet& s) {
        MySet<T> res;
        std::stack<Node<T>*> stackOfNodes;
        stackOfNodes.push(root);

        while (!stackOfNodes.empty()) {
            Node<T>* node;
            node = stackOfNodes.top();
            stackOfNodes.pop();
            if (s.isContains(node->data)) {
                res.add(node->data);
            }
            if (node->right) {
                stackOfNodes.push(node->right);
            }
            if (node->left) {
                stackOfNodes.push(node->left);
            }
        }
        return res;
    }

    // Function to compute the complement of the set
    MySet<T> complementSet(MySet<T>& U) {
        return U - *this;
    }

    // Operator
    MySet<T> operator-(MySet<T>& s) {
        MySet<T> res;
        std::stack<Node<T>*> stackOfNodes;
        stackOfNodes.push(root);
        while (!stackOfNodes.empty()) {
            Node<T>* node;
            node = stackOfNodes.top();
            stackOfNodes.pop();
            if (!s.isContains(node->data)) {
                res.add(node->data);
            }
            if (node->right) {
                stackOfNodes.push(node->right);
            }
            if (node->left) {
                stackOfNodes.push(node->left);
            }
        }
        return res;
    }

    bool operator ==(MySet<T>& s) {
        if (s.size != size) {
            return false;
        }
        std::stack<Node<T>*> stackOfNodes;
        stackOfNodes.push(this->root);
        while (!stackOfNodes.empty()) {
            Node<T>* node;
            node = stackOfNodes.top();
            stackOfNodes.pop();
            if (!s.isContains(node->data)) {
                return false;
            }
            if (node->right) {
                stackOfNodes.push(node->right);
            }
            if (node->left) {
                stackOfNodes.push(node->left);
            }
        }
        return true;
    }

    bool isContains(T data) {
        return root->isContainsNode(root, data) ? true : false;
    }

    T* toArray() {
        T* arr = new T[size];
        int i = 0;
        std::stack<Node<T>*> stackOfNodes;
        stackOfNodes.push(this->root);
        while (!stackOfNodes.empty()) {
            Node<T>* node;
            node = stackOfNodes.top();
            stackOfNodes.pop();
            arr[i++] = node->data;
            if (node->right) {
                stackOfNodes.push(node->right);
            }
            if (node->left) {
                stackOfNodes.push(node->left);
            }
        }
        return arr;
    }
  
    void displayProduct(MySet& s)
    {
        int i, j, n2 = s.size;
        T* A = toArray();
        T* B = s.toArray();

        i = 0;

        std::cout << "{ ";
        for (i = 0; i < size; i++) {
            for (j = 0; j < n2; j++) {
                std::cout << "{ " << A[i] << " " << B[j] << " } ";
            }
        }
        std::cout << "}" << std::endl;
    }
    void displayPowerSet()
    {
        int n = std::pow(2, size);
        T* A = toArray();
        int i;
        while (n-- > 0) {
            std::cout << "{ ";
            for (int i = 0; i < size; i++) {
                if ((n & (1 << i)) == 0) {
                    std::cout << A[i] << " ";
                }
            }
            std::cout << "}" << std::endl;
        }
    }
    void displaySet()
    {
        std::cout << "{ ";
        root->InOrderTraversal(root);
        std::cout << "}" << std::endl;
    }

    Node<T>* deleteNodeInSet(T d) {
        return root->deleteNode(root, d);
    }
};


int main()
{
    //Node<int>* r = new Node<int>(9);
    //r->insertNode(r,2);
    //r->insertNode(r, 6);
    //r->insertNode(r, 7);
    //r->insertNode(r, 10);
    //r->insertNode(r, 12);
    //r->insertNode(r, 8);

    //r->InOrderTraversal(r);
    //std::cout << "\n";
    //r->PreOrderTraversal(r);
    //std::cout << "\n";
    //r->PostOrderTraversal(r);
    //std::cout << "\n";


    // Create Set A
    MySet<int> A;

    // Add elements to Set A
    A.add(1);
    A.add(2);
    A.add(3);
    A.add(2);
    A.displaySet();
    A.deleteNodeInSet(2);
    A.displaySet();

  //  std::cout << "A = ";
  //  A.displaySet();
  //  std::cout << "P(A) = " << std::endl;
  //  A.displayPowerSet();


  //  // Check if Set A contains some elements
  //  std::cout << "A " << (A.isContains(3) ? "contains"
  //      : "does not contain")
  //      << " 3" << std::endl;
  //  std::cout << "A " << (A.isContains(4) ? "contains"
  //      : "does not contain")
  //      << " 4" << std::endl;
  //  std::cout << std::endl;

  //  // Create Set B
  //  MySet<int> B;

  //  // Insert elements to Set B
  //  B.add(1);
  //  B.add(2);
  //  B.add(4);

  //  // Display the contents of Set B
  //  std::cout << "B = ";
  //  B.displaySet();
  //  std::cout << "P(B) = " << std::endl;
  //  B.displayPowerSet();
  //  std::cout << std::endl;

  //  // Create Set C
  //  MySet<int> C;
  //  C.add(1);
  //  C.add(2);
  //  C.add(4);

  //  // Display the contents of Set C
  //  std::cout << "C = ";
  //  C.displaySet();
  //  std::cout << std::endl;

  //  // Set F contains the difference
  //  // of the Sets A and B
  //  MySet<int> F = A - B;
  //  std::cout << "A - B = ";
  //  F.displaySet();
  //  std::cout << std::endl;


  //  // Set D contains the union
  //// of the Sets A and B
  //  MySet<int> D = A.unionSet(B);
  //  std::cout << "A union B = ";
  //  D.displaySet();
  //  std::cout << std::endl;


  //  // Set E contains the intersection
  //  // of the Sets A and B
  //  MySet<int> E = A.intersectionSet(B);
  //  std::cout << "A intersection B = ";
  //  E.displaySet();
  //  std::cout << std::endl;

  //  // Display the product
  //  std::cout << "A x B = ";
  //  A.displayProduct(B);
  //  std::cout << std::endl;

  //  // Equality tests
  //  std::cout << "Equality of Sets:" << std::endl;

  //  std::cout << "A "
  //      << ((A == B) ? "" : "!") << "= B"
  //      << std::endl;
  //  std::cout << "B "
  //      << ((B == C) ? "" : "!") << "= C"
  //      << std::endl;
  //  std::cout << "A "
  //      << ((A == C) ? "" : "!") << "= C"
  //      << std::endl;
  //  std::cout << std::endl;

  //  MySet<int> U;
  //  U.add(1);
  //  U.add(2);
  //  U.add(3);
  //  U.add(4);
  //  U.add(5);
  //  U.add(6);
  //  U.add(7);

  //  // Complements of the respective Sets
  //  MySet<int> A1 = A.complementSet(U);
  //  MySet<int> B1 = B.complementSet(U);
  //  MySet<int> C1 = C.complementSet(U);

  //  std::cout << "A' = ";
  //  A1.displaySet();
  //  std::cout << "B' = ";
  //  B1.displaySet();
  //  std::cout << "C' = ";
  //  C1.displaySet();


    return 0;
}

