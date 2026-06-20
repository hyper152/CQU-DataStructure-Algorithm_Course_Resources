class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def build(preorder, inorder, preL, preR, inL, inR):
    if preL > preR:
        return None
    rootVal = preorder[preL]
    root = TreeNode(rootVal)
    k = inL
    while k <= inR and inorder[k] != rootVal:
        k += 1
    leftSize = k - inL
    root.left = build(preorder, inorder, preL + 1, preL + leftSize, inL, k - 1)
    root.right = build(preorder, inorder, preL + leftSize + 1, preR, k + 1, inR)
    return root

def postorder(root):
    if not root:
        return
    postorder(root.left)
    postorder(root.right)
    print(root.val, end=" ")

n = int(input())
preorder = list(map(int, input().split()))
inorder = list(map(int, input().split()))
root = build(preorder, inorder, 0, n - 1, 0, n - 1)
postorder(root)
print()
