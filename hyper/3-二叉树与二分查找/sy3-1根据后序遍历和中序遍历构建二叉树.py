from collections import deque

class TreeNode:
    """二叉树节点类"""
    def __init__(self, x):
        self.val = x      # 节点值
        self.left = None  # 左子节点
        self.right = None # 右子节点

def buildTree(postorder, postStart, postEnd, inorder, inStart, inEnd):
    """
    根据后序遍历和中序遍历构建二叉树
    
    参数:
        postorder: 后序遍历序列列表
        postStart: 当前子树在后序序列中的起始索引
        postEnd: 当前子树在后序序列中的结束索引
        inorder: 中序遍历序列列表
        inStart: 当前子树在中序序列中的起始索引
        inEnd: 当前子树在中序序列中的结束索引
    
    返回:
        构建的子树的根节点
    """
    # 递归终止条件：后序序列的起始索引大于结束索引，说明没有节点需要处理
    if postStart > postEnd:
        return None
    
    # 后序遍历的最后一个节点是当前子树的根节点
    rootVal = postorder[postEnd]
    root = TreeNode(rootVal)  # 创建根节点
    
    # 在中序遍历序列中找到根节点的位置
    # 根节点左边的元素属于左子树，右边的元素属于右子树
    inRoot = inStart
    while inorder[inRoot] != rootVal:
        inRoot += 1
    
    # 计算左子树的节点数量
    leftSize = inRoot - inStart
    
    # 递归构建左子树
    # 左子树的后序序列范围：[postStart, postStart + leftSize - 1]
    # 左子树的中序序列范围：[inStart, inRoot - 1]
    root.left = buildTree(postorder, postStart, postStart + leftSize - 1, 
                          inorder, inStart, inRoot - 1)
    
    # 递归构建右子树
    # 右子树的后序序列范围：[postStart + leftSize, postEnd - 1]
    # 右子树的中序序列范围：[inRoot + 1, inEnd]
    root.right = buildTree(postorder, postStart + leftSize, postEnd - 1, 
                           inorder, inRoot + 1, inEnd)
    
    return root

def levelOrder(root):
    """
    二叉树的层序遍历（广度优先搜索）
    使用队列实现，逐层访问节点
    
    参数:
        root: 二叉树的根节点
    """
    # 如果树为空，直接返回
    if not root:
        return
    
    # 使用双端队列作为队列，初始时将根节点入队
    q = deque([root])
    result = []  # 存储遍历结果的列表
    
    # 当队列不为空时，继续遍历
    while q:
        # 从队列头部取出一个节点（先进先出）
        node = q.popleft()
        # 将节点值转换为字符串并添加到结果列表
        result.append(str(node.val))
        
        # 如果当前节点有左子节点，将左子节点入队
        if node.left:
            q.append(node.left)
        # 如果当前节点有右子节点，将右子节点入队
        if node.right:
            q.append(node.right)
    
    # 打印结果，节点值之间用空格分隔
    print(' '.join(result))

def main():
    """主函数：处理输入输出"""
    # 读取树的节点数量
    N = int(input())
    
    # 读取后序遍历序列（一行用空格分隔的整数）
    postorder = list(map(int, input().split()))
    
    # 读取中序遍历序列（一行用空格分隔的整数）
    inorder = list(map(int, input().split()))
    
    # 根据后序和中序遍历构建二叉树
    # 初始时，后序序列的范围是 [0, N-1]，中序序列的范围也是 [0, N-1]
    root = buildTree(postorder, 0, N-1, inorder, 0, N-1)
    
    # 对构建的二叉树进行层序遍历并输出结果
    levelOrder(root)

# Python程序的入口点
if __name__ == "__main__":
    main()