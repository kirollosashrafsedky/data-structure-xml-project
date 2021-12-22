#include "XmlCompression.h"

char strToChar(const std::string& str, int index) {
    char parsed = 0;

    for (int i = 0; i < 8; i++) {
        if (index + i < str.size())
        {
            if (str[index + i] == '1') {
                parsed |= 1 << (7 - i);
            }
        }
    }
    return parsed;
}

std::string toBinary(unsigned char n)
{
    std::string r;
    int i = 0;
    std::stack<char> s;
    while (i < 8) {
        s.push(n % 2 == 0 ? '0' : '1');
        n /= 2;
        i++;
    }
    while (!s.empty())
    {
        r += s.top();
        s.pop();
    }
    return r;
}

Node* getNode(char ch, int freq, Node* left, Node* right)
{
    Node* node = new Node();

    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;

    return node;
}

void encode(Node* root, std::string str, std::map<char, std::string>& huffmanCode)
{
    if (root == nullptr)
        return;
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

std::string compressXml(std::string text)
{
    std::map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }
    std::priority_queue<Node*, std::vector<Node*>, comp> pq;
    for (auto pair : freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top();	pq.pop();
        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }
    Node* root = pq.top();
    std::map<char, std::string> huffmanCode;
    encode(root, "", huffmanCode);
    std::string huffmanCodeStr = "";

    //cout << "ff" << endl;
    //for (auto ch : huffmanCode)
        //cout << ch.first << " " << ch.second << endl;

    for (auto ch : huffmanCode) {

        huffmanCodeStr += toBinary(static_cast<unsigned char>(ch.first));
        huffmanCodeStr += toBinary(static_cast<unsigned char>(ch.second.size()));
        //huffmanCodeStr += fillZeros(ch.second);
        huffmanCodeStr += ch.second;
    }
    std::string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    std::string encodedStr = huffmanCodeStr + "0010011000100110" + str;
    std::string finalSavedEncodedStr = "";
    finalSavedEncodedStr.resize(ceil(encodedStr.size() / 8.0));
    int i, j;
    for (i = 0, j = 0; j < encodedStr.size(); i++, j += 8)
    {
        finalSavedEncodedStr[i] = strToChar(encodedStr, j);
    }
    int extraBits = 8 - (encodedStr.size() % 8);
    if (extraBits == 8) extraBits = 0;
    finalSavedEncodedStr += (extraBits + 48);
    return finalSavedEncodedStr;
}

std::string decompressXml(std::string text)
{
    std::string semiDecodedStr = "";
   
    for (int i = 0; i < text.length() - 1; ++i) {
        semiDecodedStr += toBinary(static_cast<unsigned char>(text[i]));
    }
    int charsToBeDeleted = text[text.size() - 1] - 48;
    for (int i = 0; i < charsToBeDeleted; i++)
    {
        semiDecodedStr.pop_back();
    }
    //text = semiDecodedStr;
    int i = 0;
    char charFromStr;
    std::string huffmanCodeStr;
    std::map<std::string, char> huffmanCode;
    while (strToChar(semiDecodedStr, i) != '&' || strToChar(semiDecodedStr, i + 8) != '&')
    {
        huffmanCodeStr = "";
        charFromStr = strToChar(semiDecodedStr, i);
        i += 8;
        std::string StrBitsStr = "";
        for (int j = 0; j < 8; j++)
        {
            StrBitsStr += semiDecodedStr[i];
            i++;
        }
        char StrBits = std::stoull(StrBitsStr, 0, 2);
        for (char j = 0; j < StrBits; j++)
        {
            huffmanCodeStr += semiDecodedStr[i];
            i++;
        }
        huffmanCode[huffmanCodeStr] = charFromStr;
    }
    i += 16;
    std::string encodedStr = semiDecodedStr.substr(i, semiDecodedStr.size() - i);
    std::string out = "", temp = "";
    for (int i = 0; i < encodedStr.size(); i++)
    {
        temp += encodedStr[i];
        char charTemp = huffmanCode[temp];
        if (charTemp != '\0')
        {
            out += charTemp;
            temp = "";
        }
    }
    return out;
}
