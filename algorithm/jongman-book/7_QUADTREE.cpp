#include <iostream>
#include <string>
#include <utility>
#include <vector>
#define FOR(i, n) for (int i = 0; i < n; ++i)

using namespace std;

struct Node
{
    string type;
    vector<Node> children;
};

pair<Node, int> makeTree(string quadtree)
{
    Node tree;

    if (!quadtree.size())
        return make_pair(tree, 0);

    int len = 1;
    tree.type = quadtree[0];
    if (tree.type == "x")
    {
        FOR(i, 4)
        {
            pair<Node, int> temp = makeTree(quadtree.substr(len));
            tree.children.push_back(temp.first);
            len += temp.second;
        }
    }

    return make_pair(tree, len);
}

void reverseTree(Node &tree)
{
    if (tree.type == "x")
    {
        tree.children.push_back(*tree.children.begin());
        tree.children.erase(tree.children.begin());
        tree.children.push_back(*tree.children.begin());
        tree.children.erase(tree.children.begin());
        FOR(i, 4) { reverseTree(tree.children[i]); }
    }
}

string treeToStr(Node &tree)
{
    string ret;

    if (!tree.type.size())
        return ret;

    ret += tree.type;
    if (tree.type == "x")
    {
        FOR(i, 4) { ret += treeToStr(tree.children[i]); }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testcase = 0;
    cin >> testcase;

    string quadtree;

    FOR(i, testcase)
    {
        cin >> quadtree;
        pair<Node, int> tree = makeTree(quadtree);
        reverseTree(tree.first);
        string str = treeToStr(tree.first);
        cout << str << endl;
    }

    return 0;
}