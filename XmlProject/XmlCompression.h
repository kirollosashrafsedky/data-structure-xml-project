#ifndef _XML_COMPRESSION_
#define _XML_COMPRESSION_

#include <string>
#include <queue>
#include <map>
#include <stack>
#include <vector>

struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};

struct comp
{
    bool operator()(Node* l, Node* r)
    {
        return l->freq > r->freq;
    }
};

char strToChar(const std::string& str, int index);

std::string toBinary(unsigned char n);

Node* getNode(char ch, int freq, Node* left, Node* right);

void encode(Node* root, std::string str, std::map<char, std::string>& huffmanCode);

std::string compressXml(std::string text);

std::string decompressXml(std::string text);

#endif /* _XML_COMPRESSION_ */
