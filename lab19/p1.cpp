#include <iostream>
#include <memory>
class Node {
public:
int index;
std::shared_ptr<Node> next;
};
using NodePtr = std::shared_ptr<Node>;
void printList(const NodePtr root) {
auto n = root;
while (n->next != nullptr && n->next != root) {
std::cout << n->index << "->";
n = n->next;
}
std::cout << n->index << std::endl;
}
NodePtr reverseList(NodePtr root) {
    NodePtr prev = nullptr;
    NodePtr current = root;
    NodePtr next = nullptr;

    while (current != nullptr) {
        next = current->next;  // store the next node
        current->next = prev;  // reverse the current node's pointer
        prev = current;        // move prev to the current node
        current = next;        // move to the next node
    }

    return prev; // new head of the reversed list
}
int main() {
auto root = std::make_shared<Node>(Node{});
root->index = 0;
auto n = root;
for (int i = 1; i < 10; ++i) {
n->next = std::make_shared<Node>(Node{});
n->next->index = i;
n = n->next;
}
printList(root);
root = reverseList(root);
printList(root);
}
