class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
      this->data = data;
      left = right = nullptr;
    }
};