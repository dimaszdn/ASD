#include <iostream>
#include<BinaryTree.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    std::string strTree = "8(3(1,6(4,7)),10(,14(13,)))";

    try
    {
        asd::BinaryTree tree(strTree);
        std::cout << "�����������: "; tree.inOrderPrint(tree.getRoot()); std::cout << "\n";
        std::cout << "������: "; tree.preOrderPrint(tree.getRoot()); std::cout << "\n";
        std::cout << "������ �� �����������: "; tree.iterativePreOrderPrint(tree.getRoot()); std::cout << "\n";
        std::cout << "��������: "; tree.postOrderPrint(tree.getRoot()); std::cout << "\n";
    }
    catch (const std::exception& ex) { std::cout << ex.what(); }


    return 0;
}