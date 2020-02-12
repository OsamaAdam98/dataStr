#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
};

TreeNode *newNode(int nodeVal);
void insertNode(TreeNode *root, int data);
void deleteNode(TreeNode *root, int key);
void searchNodeParent(TreeNode *root, int key, TreeNode **returnNode);
TreeNode *searchNode(TreeNode *root, int key);
TreeNode *smallestInRight(TreeNode *root);
void printTree(TreeNode *root);
void recursion(TreeNode *root);

int main() {
  TreeNode *head = newNode(1);
  insertNode(head, 2);
  insertNode(head, 3);

  // printTree(head);

  deleteNode(head, 2);

  cout << "After deletion" << endl;
  printTree(head);
}

TreeNode *newNode(int nodeVal) {
  TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
  node->val = nodeVal;
  return node;
}

void insertNode(TreeNode *root, int data) {
  if (root->right == NULL && data > root->val) {
    TreeNode *node = newNode(data);
    root->right = node;
  } else if (root->left == NULL && data <= root->val) {
    TreeNode *node = newNode(data);
    root->left = node;
  } else if (data > root->val) {
    insertNode(root->right, data);
  } else {
    insertNode(root->left, data);
  }
}

void searchNodeParent(TreeNode *root, int key, TreeNode **returnNode) {
  if (root) {
    if (root->left && root->left->val == key ||
        root->right && root->right->val == key) {
      *returnNode = root;
    } else if (key >= root->val && root->right != NULL) {
      searchNodeParent(root->right, key, returnNode);
    } else if (key < root->val && root->left != NULL) {
      searchNodeParent(root->left, key, returnNode);
    } else {
      returnNode = NULL;
    }
  } else {
    returnNode = NULL;
  }
}

void deleteNode(TreeNode *root, int key) {
  TreeNode *parent;
  searchNodeParent(root, key, &parent);
  TreeNode *target;

  if (parent) {
    if (parent->val < key && parent->right != NULL) {
      target = parent->right;
    } else if (parent->val > key && parent->left != NULL) {
      target = parent->left;
    } else {
      target = NULL;
    }
  } else {
    target = searchNode(root, key);
  }

  if (target) {
    if (target->left == NULL && target->right == NULL) {
      if (parent->val < key) {
        parent->right = NULL;
      } else {
        parent->left = NULL;
      }
    } else if (target->right == NULL) {
      if (parent->val < key) {
        parent->right = target->left;
      } else {
        parent->left = target->left;
      }
      free(target);
    } else if (target->left == NULL) {
      if (parent->val < key) {
        parent->right = target->right;
      } else {
        parent->left = target->right;
      }
      free(target);
    } else {
      TreeNode *tempNode = smallestInRight(target);
      if (parent) {
        if (parent->val < key) {
          parent->right = tempNode;
          tempNode->right = target->right;
          tempNode->left = target->left;
        } else {
          parent->left = tempNode;
          tempNode->right = target->right;
          tempNode->left = target->left;
        }
        tempNode->right = target->right == tempNode ? NULL : target->right;
        tempNode->left = target->left == tempNode ? NULL : target->left;
        free(target);
      } else {
        tempNode->left = root->left;
        free(root);
        *root = *tempNode;
      }
    }
  } else {
    cout << "Node doesn't exist" << endl;
  }
}

TreeNode *smallestInRight(TreeNode *root) {
  TreeNode *tempNode;
  if (root->right) {
    tempNode = root->right;
    while (tempNode->left) {
      tempNode = tempNode->left;
    }
  } else {
    tempNode = root;
  }
  return tempNode;
}

void printTree(TreeNode *root) {
  cout << "---root---" << endl;
  cout << root->val << endl;
  recursion(root);
}

void recursion(TreeNode *root) {
  if (root) {
    if (root->right) {
      cout << "---right---" << endl;
      cout << root->right->val << endl;
      recursion(root->right);
    }
    if (root->left) {
      cout << "---left---" << endl;
      cout << root->left->val << endl;
      recursion(root->left);
    }
  } else {
    return;
  }
}

// void printTree(TreeNode *root) {
//   if (root) {
//     cout << "---root---" << endl;
//     cout << root->val << endl;
//     TreeNode *temp = NULL;
//     if (!root->left && !root->right) {
//       return;
//     } else {
//       if (root->left) {
//         temp = root->left;
//         cout << "---left---" << endl;
//         while (temp) {
//           cout << temp->val << endl;
//           if (temp->left) {
//             temp = temp->left;
//           } else {
//             break;
//           }
//         }
//       }
//       if (root->right) {
//         temp = root->right;
//         cout << "---right---" << endl;
//         while (temp) {
//           cout << temp->val << endl;
//           if (temp->right) {
//             temp = temp->right;
//           } else {
//             break;
//           }
//         }
//       }
//     }
//   }
//   if (root->left->right) {
//     printTree(root->left->right);
//   } else if (root->right->left) {
//     printTree(root->right->left);
//   } else {
//     return;
//   }
// }

TreeNode *searchNode(TreeNode *root, int key) {
  if (root->val == key) {
    return (root);
  } else if (key > root->val && root->right != NULL) {
    searchNode(root->right, key);
  } else if (key < root->val && root->left != NULL) {
    searchNode(root->left, key);
  } else {
    cout << "Node doesn't exist in the tree!" << endl;
    return NULL;
  }
}