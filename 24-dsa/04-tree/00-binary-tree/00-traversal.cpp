#include<bits/stdc++.h>
#include "node.h"
using namespace std;

#define printa(x,n) for(int i=0;i<n;i++) cerr<<x[i]<<" "; cerr<<endl;
#define DEBUG(x) cerr<<">>> "<<#x<<" : "<<x<<endl;

void preorder_rec(Node* node) {
  if (node == nullptr) {
    return;
  } else {
    printf("%d ", node->data);
    preorder_rec(node->left);
    preorder_rec(node->right);
  }
}

void preorder_ite(Node* node) {
  stack<Node*> s;

  s.push(node);

  while(!s.empty()) {
    Node* n = s.top(); s.pop();

    // push right and then left in stack
    if(n->right != nullptr) s.push(n->right);
    if(n->left != nullptr) s.push(n->left);

    printf("%d ", n->data);
  }
}

void inorder_rec(Node* node) {
  if (node == nullptr) {
    return;
  } else {
    inorder_rec(node->left);
    printf("%d ", node->data);
    inorder_rec(node->right);
  }
}

void inorder_ite(Node* root) {
  stack<Node*> s;

  // push left to stack
  while(root != nullptr) {
    s.push(root);
    root = root->left;
  }

  while(!s.empty()) {
    Node* node = s.top(); s.pop();
    printf("%d ", node->data);

    // push right and all lefties
    node = node->right;
    while(node != nullptr) {
      s.push(node);
      node = node->left;
    }
  }
}

void postorder_rec(Node* node) {
  if (node == nullptr) {
    return;
  } else {
    postorder_rec(node->left);
    postorder_rec(node->right);
    printf("%d ", node->data);
  }
}

void bfs(Node* node) {
  Node* ptr;
  queue<Node*> q;
  q.push(node);

  while(!q.empty()) {
    ptr = q.front();
    q.pop();

    printf("%d ", ptr->data);
    if (ptr->left != nullptr)
      q.push(ptr->left);
    if (ptr->right != nullptr)
      q.push(ptr->right);
  }
}

int depth_height(Node* node) {
  if (node == nullptr) {
    return 0;
  }
  int left = depth_height(node->left);
  int right = depth_height(node->right);
  return max(left, right) + 1;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  freopen("input.txt", "r", stdin);

  // read integers from file and create binary tree
  int n, tmp;
  Node *top;
  Node *root;
  Node* node;

  cin >> n;

  queue<Node*> s;

  for (int i=0; i<n; i++) {
    cin >> tmp;
    node = new Node(tmp);
    if (s.empty()) {
      root = node;
      s.push(node);
      continue;
    }

    top = s.front();

    if (top->left == nullptr) {
      s.push(node);
      top->left = node;
    } else if (top->right == nullptr) {
      top->right = node;
      s.pop();
      s.push(node);
    }
  }

  printf("Preorder Recursive: ");
  preorder_rec(root);
  printf("\nPreorder Iterative: ");
  preorder_ite(root);
  printf("\nInorder Recursive: ");
  inorder_rec(root);
  printf("\nInorder Iterative: ");
  inorder_ite(root);
  printf("\nPostorder Recursive: ");
  postorder_rec(root);
  printf("\nBFS: ");
  bfs(root);
  printf("\n");
  printf("height of tree: %d\n", depth_height(root));

  return 0;
}