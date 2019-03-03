#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
const int ALPHABET_SIZE = 26;
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};
struct TrieNode *getNode()
{
    struct TrieNode *pNode = new TrieNode();
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->children[index]==NULL)
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (pCrawl->children[index]==NULL)
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl != NULL && pCrawl->isEndOfWord);
}
int main()
{
    int n;
    cin>>n;
    string keys[n];
    for(int i=0;i<n;i++)
    {
        cin>>keys[i];
    }
    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    if (search(root, "rana") == true)
        printf("found");
    else
        printf("not found!!!");

    return 0;
}
