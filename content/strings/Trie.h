#pragma once

struct TrieNode
{
    int next[26];
    bool leaf = false;
    TrieNode() { fill(begin(next), end(next), -1); }
};
struct Trie
{
    int siz;
    vector<TrieNode> tr;
    Trie() : siz(0), tr(vector<TrieNode>(1)) {}
    TrieNode &operator[](int u) { return tr[u]; }
    int size() { return siz; }
    void addstring(const string &s)
    {
        int v = 0;
        for (char ch : s)
        {
            int c = ch - 'a';
            if (tr[v].next[c] == -1)
            {
                tr[v].next[c] = tr.size();
                tr.emplace_back();
            }
            v = tr[v].next[c];
        }
        if (!tr[v].leaf)
            siz++;
        tr[v].leaf = true;
    }
    template <class F>
    void dfs(int u, F f)
    {
        forn(i, 0, 26)
        {
            if (tr[u].next[i] != -1)
            {
                dfs(tr[u].next[i]);
            }
        }
    }
};
