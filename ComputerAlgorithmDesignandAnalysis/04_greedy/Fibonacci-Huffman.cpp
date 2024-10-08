#include <bits/stdc++.h>
using namespace std;

#define FLENGTH 8
int F[FLENGTH];

typedef struct node
{
    char character;
    int frequence;
    node *right;
    node *left;
} node;

vector<node> nodes(10);

// 生成斐波那契数列
void generateFibonacci()
{
    F[0] = 1;
    F[1] = 1;
    for (int i = 2; i < FLENGTH; i++)
        F[i] = F[i - 1] + F[i - 2];
}

// 初始化节点
void generateNodes()
{
    char now = 'a';
    for (int i = 0; i < FLENGTH; i++)
    {
        node *n = (node *)malloc(sizeof(node));
        n[i].character = now++;
        n[i].frequence = F[i];
        n[i].left = NULL;
        n[i].right = NULL;
        nodes.push_back(&n);
    }
}

// 构建huffman树
node *BuildHuffmanTree()
{
    for (int i = 0; i < FLENGTH;)
    {
        node *father = (node *)malloc(sizeof(node));
        father->left = &nodes[i];
        father->right = &nodes[i + 1];
        father->frequence = nodes[i].frequence + nodes[i + 1].frequence;
        father->character = ' ';
    }
}

int main()
{
    generateFibonacci();
    generateNodes();

    node *root = BuildHuffmanTree();
    return 0;
}
