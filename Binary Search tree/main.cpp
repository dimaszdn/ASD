#include <iostream>
#include<BinarySearchTree.h>
#include<vector>

using namespace asd;

int main()
{
    setlocale(LC_ALL, "Rus");
    std::string strTree = "8(3(1,6(4,7)),10(,14(13,20)))";
    BinarySearchTree tree(strTree);
    tree.erase(tree.getRoot(), 3);
    tree.printTree(tree.getRoot());

    return 0;
}