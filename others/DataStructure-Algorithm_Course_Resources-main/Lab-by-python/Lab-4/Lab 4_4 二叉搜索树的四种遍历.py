from collections import deque


class Node:
    """Binary search tree node."""
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(root, value):
    """Insert a new value into the BST."""
    if root is None:
        return Node(value)
    if value < root.data:
        root.left = insert(root.left, value)
    else:
        root.right = insert(root.right, value)
    return root


def preorder(root, result):
    """Preorder traversal: root -> left -> right."""
    if root is None:
        return
    result.append(str(root.data))
    preorder(root.left, result)
    preorder(root.right, result)


def inorder(root, result):
    """Inorder traversal: left -> root -> right."""
    if root is None:
        return
    inorder(root.left, result)
    result.append(str(root.data))
    inorder(root.right, result)


def postorder(root, result):
    """Postorder traversal: left -> right -> root."""
    if root is None:
        return
    postorder(root.left, result)
    postorder(root.right, result)
    result.append(str(root.data))


def levelorder(root, result):
    """Level order traversal using a queue."""
    if root is None:
        return
    q = deque([root])
    while q:
        current = q.popleft()
        result.append(str(current.data))
        if current.left is not None:
            q.append(current.left)
        if current.right is not None:
            q.append(current.right)


def main():
    n = int(input().strip())
    values = list(map(int, input().strip().split()))

    root = None
    for value in values:
        root = insert(root, value)

    result_pre = []
    preorder(root, result_pre)
    print(" ".join(result_pre))

    result_in = []
    inorder(root, result_in)
    print(" ".join(result_in))

    result_post = []
    postorder(root, result_post)
    print(" ".join(result_post))

    result_level = []
    levelorder(root, result_level)
    print(" ".join(result_level))


if __name__ == "__main__":
    main()
