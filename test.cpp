// Program to Test BST
// EE312 Fall 2018
// Sean Wang
// szw87
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {
  BST_312<int> bst;

  srand(0);
  int bstSize = 10;

  cout << "test countNodes(), insertItem()" << endl;
  for(int i = 0; i < bstSize; i++) {
    int num = static_cast<int>((rand() % (bstSize*2)) - bstSize);
    cout << "BST size: " << bst.countNodes() << ", inserting " << num << endl;
    bst.insertItem(num);
  }
  cout << "BST final size: " << bst.countNodes() << endl;

  // bst.insertItem(23);
  // bst.insertItem(20);
  // bst.insertItem(26);
  // bst.insertItem(16);
  // bst.insertItem(21);
  // bst.insertItem(14);
  // bst.insertItem(17);
  // bst.insertItem(25);
  // bst.insertItem(34);
  // bst.insertItem(31);
  // bst.insertItem(37);
  // bst.insertItem(36);

  cout << endl;

  cout << "test copy constructor, deleteItem(), isItemInTree()" << endl;
  BST_312<int> bstCopy(bst);
  cout << "deleting 3 from bstCopy ... " << (bst.isItemInTree(3) ? "exists in bstCopy, removed" : "doesn't exist in bstCopy") << endl;
  cout << "deleting 40 from bstCopy ... " << (bst.isItemInTree(40) ? "exists in bstCopy, removed" : "doesn't exist in bstCopy") << endl;
  bstCopy.deleteItem(3);
  bstCopy.deleteItem(40);
  cout << "bstCopy size after delete: " << bstCopy.countNodes() << endl;
  cout << "original BST size: " << bst.countNodes() << endl;

  cout << endl;
  cout << "use bstCopy to test makeEmpty(), isEmpty()" << endl;
  bstCopy.makeEmpty();
  cout << "bstCopy empty: " << (bstCopy.isEmpty() ? "true" : "false") << endl;
  cout << "original bst empty: " << (bst.isEmpty() ? "true" : "false") << endl;
  cout << "original bst full: " << (bst.isFull() ? "true" : "false") << endl;
  bstCopy.~BST_312();
  cout << "hi" << endl;
  cout << endl;
  
  cout << "test pre, in, post order traversals" << endl;
  vector<int> pre = bst.preOrderTraversal();
  vector<int> in = bst.inOrderTraversal();
  vector<int> post = bst.postOrderTraversal();
  cout << "pre\tin\tpost" << endl;
  for(int i = 0; i < bst.countNodes(); i++) {
    cout << pre.at(i) << "\t" << in.at(i) << "\t" << post.at(i) << endl;
  }
}