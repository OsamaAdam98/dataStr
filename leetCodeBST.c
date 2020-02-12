#include <stdio.h>

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *smallestInRight(TreeNode *root);

TreeNode *deleteNode(struct TreeNode *root, int key) {
  if (root == NULL)
    return root;
  else if (key < root->val)
    root->left = deleteNode(root->left, key);
  else if (key > root->val)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    } else if (root->left == NULL) {
      TreeNode *temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      TreeNode *temp = root;
      root = root->left;
      free(temp);
    } else {
      TreeNode *temp = smallestInRight(root);
      root->val = temp->val;
      root->right = deleteNode(root->right, temp->val);
    }
  }
  return root;
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
