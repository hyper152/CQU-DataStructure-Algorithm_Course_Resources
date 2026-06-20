class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    return root

def find_node(root, val):
    if root is None:
        return None
    if root.val == val:
        return root
    if val < root.val:
        return find_node(root.left, val)
    else:
        return find_node(root.right, val)

def find_parent(root, val, parent=None):
    """返回值为 val 的结点的父结点，不存在或为根则返回 None"""
    if root is None:
        return None
    if root.val == val:
        return parent
    if val < root.val:
        return find_parent(root.left, val, root)
    else:
        return find_parent(root.right, val, root)

def find_depth(root, val, depth=0):
    if root is None:
        return -1
    if root.val == val:
        return depth
    if val < root.val:
        return find_depth(root.left, val, depth + 1)
    else:
        return find_depth(root.right, val, depth + 1)

def main():
    root = None
    n = int(input())
    values = list(map(int, input().split()))
    for val in values:
        root = insert(root, val)

    m = int(input())
    for _ in range(m):
        line = input().strip()
        if "is the root" in line:
            a = int(line.split()[0])
            print("Yes" if root and root.val == a else "No")
        elif "are siblings" in line:
            parts = line.split()
            a, b = int(parts[0]), int(parts[2])
            pa = find_parent(root, a)
            pb = find_parent(root, b)
            print("Yes" if pa and pb and pa == pb else "No")
        elif "is the parent of" in line:
            parts = line.split()
            a, b = int(parts[0]), int(parts[5])
            pb = find_parent(root, b)
            print("Yes" if pb and pb.val == a else "No")
        elif "is the left child of" in line:
            parts = line.split()
            a, b = int(parts[0]), int(parts[6])
            node_b = find_node(root, b)
            print("Yes" if node_b and node_b.left and node_b.left.val == a else "No")
        elif "is the right child of" in line:
            parts = line.split()
            a, b = int(parts[0]), int(parts[6])
            node_b = find_node(root, b)
            print("Yes" if node_b and node_b.right and node_b.right.val == a else "No")
        elif "are on the same level" in line:
            parts = line.split()
            a, b = int(parts[0]), int(parts[2])
            da = find_depth(root, a)
            db = find_depth(root, b)
            print("Yes" if da != -1 and da == db else "No")

if __name__ == "__main__":
    main()
