class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree() : root(nullptr) {}

    bool insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        Node *temp = root;

        while (true)
        {
            if (newNode->value == temp->value)
            {
                return false;
            }

            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                // Move to the left child and continue searching
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {

                    temp->right = newNode;
                    return true;
                }

                // Move to the right child and continue searching
                temp = temp->right;
            }
        }
    }
};
