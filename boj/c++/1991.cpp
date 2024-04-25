#include <iostream>
#include <map>
#include <string>

using namespace std;

void preorder(map<string, string> &tree, const string &node)
{
    if (node == ".")
        return;

    cout << node;
    preorder(tree, (*tree.find(node)).second.substr(0, 1));
    preorder(tree, (*tree.find(node)).second.substr(1, 1));
}

void inorder(map<string, string> &tree, const string &node)
{
    if (node == ".")
        return;

    inorder(tree, (*tree.find(node)).second.substr(0, 1));
    cout << node;
    inorder(tree, (*tree.find(node)).second.substr(1, 1));
}

void postorder(map<string, string> &tree, const string &node)
{
    if (node == ".")
        return;

    postorder(tree, (*tree.find(node)).second.substr(0, 1));
    postorder(tree, (*tree.find(node)).second.substr(1, 1));
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false); // use cpp buffer only
    cin.tie(NULL);                    // untie std::cin && std::cout

    int n;
    string node, left, right;
    map<string, string> tree;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> node >> left >> right;
        tree.insert(make_pair(node, left + right));
    }

    preorder(tree, "A");
    cout << "\n";
    inorder(tree, "A");
    cout << "\n";
    postorder(tree, "A");
    cout << "\n";

    return 0;
}