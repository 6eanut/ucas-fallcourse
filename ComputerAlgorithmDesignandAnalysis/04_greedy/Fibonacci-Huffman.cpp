#include <bits/stdc++.h>
using namespace std;

#define FLENGTH 8

typedef struct Node
{
    char character;
    int frequency;
    string code;
    Node *right;
    Node *left;
} Node;

// 生成斐波那契数列
void generateFibonacci(int *F)
{
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < FLENGTH; i++)
        F[i] = F[i - 1] + F[i - 2];
}

// 生成节点
vector<Node> *generateNodes(int *F)
{
    auto *nodes = new vector<Node>();
    char ch = 'a';
    for (int i = 0; i < FLENGTH; ++i)
    {
        Node node;
        node.character = ch + i;
        node.frequency = F[i];
        node.code.assign("");
        node.right = NULL;
        node.left = NULL;
        nodes->push_back(node);
    }
    return nodes;
}

// 生成huffman树
Node *generateHuffman(vector<Node> *nodes)
{
    while (nodes->size() != 1)
    {
        Node *father = new Node();
        Node left = nodes->front();
        nodes->erase(nodes->begin());
        Node right = nodes->front();
        nodes->erase(nodes->begin());
        father->left = new Node(left);
        father->right = new Node(right);
        father->frequency = left.frequency + right.frequency;
        father->code.assign("");
        nodes->insert(nodes->begin(), *father);
    }
    return new Node(nodes->front());
}

// 遍历二叉树
void TestHuffman(Node *node)
{
    if (node)
    {
        cout << "character: " << node->character << ", frequency: " << node->frequency << ", code: " << node->code << endl;
        TestHuffman(node->left);
        TestHuffman(node->right);
    }
}

// 生成Huffman-code
void generateCodes(Node *node, string fatherCode, int left)
{
    if (node)
    {
        node->code.append(fatherCode);
        if (left == 1)
        {
            node->code.append("1");
        }
        else if (left == 2)
        {
            node->code.append("0");
        }
        generateCodes(node->left, node->code, 1);
        generateCodes(node->right, node->code, 2);
    }
}

int main()
{
    int Fibonacci[FLENGTH];
    generateFibonacci(Fibonacci);
    for (int i = 0; i < FLENGTH; ++i)
    {
        cout << Fibonacci[i] << " ";
    }

    vector<Node> *nodes = generateNodes(Fibonacci);
    // for (auto it = nodes->begin(); it != nodes->end(); it++)
    // {
    //     Node node = *it;
    //     cout << node.character << " " << node.frequency << " " << endl;
    // }

    Node *root = generateHuffman(nodes);
    // TestHuffman(root);

    generateCodes(root, "", 0);
    // TestHuffman(root);
    return 0;
}
