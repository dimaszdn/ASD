#pragma once
#include<iostream>
#include<stack>
#include<string>

namespace asd
{
    struct Node
    {
        int mValue;
        Node* mLeft;
        Node* mRight;

        explicit Node(int value, Node* left = nullptr, Node* right = nullptr) : mValue(value),
            mLeft(left), mRight(right)
        {}
    };

    class BinaryTree
    {
    private:
        Node* mRoot;

    public:
        explicit BinaryTree(const std::string& strTree) : mRoot(nullptr)
        {
            std::string number;
            for (auto sym : strTree)
            {
                if (sym == '(' || sym == ')' || sym == ',')
                {
                    if (!number.empty())
                    {
                        this->insert(std::stoi(number));
                        number.clear();
                    }
                }
                else
                    number += sym;
            }
        }

        BinaryTree() : mRoot(nullptr) {}

        ~BinaryTree()
        {
            destroyTree();
        }

        //вставляем значение
        void insert(int value)
        {
            if (mRoot == nullptr)
                mRoot = new Node(value);
            else
                this->insert(value, mRoot);
        }

        //Центральный обход(обход узлов в отсортированном порядке)
        void inOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                this->inOrderPrint(node->mLeft);
                std::cout << node->mValue << " ";
                this->inOrderPrint(node->mRight);
            }
        }

        //Прямой порядок(корень, левое поддерево, правое)
        void preOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                std::cout << node->mValue << " ";
                this->preOrderPrint(node->mLeft);
                this->preOrderPrint(node->mRight);
            }
        }

        //Обратный порядок(левое, начиная с детей; правое, начиная с детей; корень)
        void postOrderPrint(Node* node)
        {
            if (node != nullptr)
            {
                this->postOrderPrint(node->mLeft);
                this->postOrderPrint(node->mRight);
                std::cout << node->mValue << " ";
            }
        }

        void iterativePreOrderPrint(Node* node)
        {
            std::stack<Node*> nodeStack;
            nodeStack.push(node);
            Node* tmp;
            while (!nodeStack.empty())
            {
                tmp = nodeStack.top();
                std::cout << tmp->mValue << " ";
                nodeStack.pop();

                if (tmp->mRight)
                    nodeStack.push(tmp->mRight);
                if (tmp->mLeft)
                    nodeStack.push(tmp->mLeft);
            }
        }

        void destroyTree()
        {
            destroySubTree(mRoot);
            mRoot = nullptr;
        }

        void destroySubTree(Node* node)
        {
            if (node != nullptr)
            {
                destroySubTree(node->mLeft);
                destroySubTree(node->mRight);
                delete node;
            }
        }

        Node* getRoot()
        {
            return mRoot;
        }

    private:
        //вставляем значение, начиная с некоторого узла
        void insert(int value, Node* node)
        {
            if (value == node->mValue)
            {
                throw std::logic_error("The tree contains a node with this value!");
            }

            if (value < node->mValue)
            {
                if (node->mLeft == nullptr)
                    node->mLeft = new Node(value);
                else
                    this->insert(value, node->mLeft);
            }
            else
            {
                if (node->mRight == nullptr)
                    node->mRight = new Node(value);
                else
                    this->insert(value, node->mRight);
            }
        }

    };
}