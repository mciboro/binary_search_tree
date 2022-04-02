#include "node.h"

int main()
{
    std::shared_ptr<Node> root = initRoot(2023);
    addElement(2020, root);
    addElement(2022, root);
    addElement(2025, root);
    addElement(2026, root);
    addElement(2027, root);
    addElement(2019, root);
    addElement(2021, root);
    addElement(2029, root);
    checkIfPresent(2026, root);
    removeElement(2026, root);
    checkIfPresent(2026, root);
    printAllElements(root);
    removeTree(root);
    return 0;
}