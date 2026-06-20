class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build(seq, idx):
    if idx[0] >= len(seq) or seq[idx[0]] == "#":
        idx[0] += 1
        return None
    node = TreeNode(int(seq[idx[0]]))
    idx[0] += 1
    node.left = build(seq, idx)
    node.right = build(seq, idx)
    return node

def preorder(root):
    if not root:
        return
    print(root.val)
    preorder(root.left)
    preorder(root.right)

n = int(input())
seq = input().strip().split()
root = build(seq, [0])
preorder(root)
