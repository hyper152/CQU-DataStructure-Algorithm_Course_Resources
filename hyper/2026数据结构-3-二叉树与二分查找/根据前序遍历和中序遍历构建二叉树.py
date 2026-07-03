from collections import deque

class TreeNode:
    """二叉树节点类"""
    def __init__(self, x):
        self.val = x      # 节点值
        self.left = None  # 左子节点
        self.right = None # 右子节点

def buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd):
    """
    根据前序遍历和中序遍历构建二叉树
    
    参数:
        preorder: 前序遍历序列列表
        preStart: 当前子树在前序序列中的起始索引
        preEnd: 当前子树在前序序列中的结束索引
        inorder: 中序遍历序列列表
        inStart: 当前子树在中序序列中的起始索引
        inEnd: 当前子树在中序序列中的结束索引
    
    返回:
        构建的子树的根节点
    
    核心思想：
        前序遍历：根 -> 左子树 -> 右子树（第一个节点是根）
        中序遍历：左子树 -> 根 -> 右子树（根节点在中间）
    """
    # 递归终止条件：前序序列的起始索引大于结束索引，说明没有节点需要处理
    if preStart > preEnd:
        return None
    
    # 前序遍历的第一个节点是当前子树的根节点
    # 这是与前序+后序重建的关键区别：前序的第一个是根，后序的最后一个是根
    rootVal = preorder[preStart]
    root = TreeNode(rootVal)  # 创建根节点
    
    # 在中序遍历序列中找到根节点的位置
    # 中序遍历中，根节点左边的元素属于左子树，右边的元素属于右子树
    inRoot = inStart
    while inorder[inRoot] != rootVal:
        inRoot += 1
    
    # 计算左子树的节点数量
    # 这个值用于在前序序列中分割左右子树的范围
    leftSize = inRoot - inStart
    
    # 递归构建左子树
    # 左子树的前序序列范围：[preStart + 1, preStart + leftSize]
    # 解释：跳过根节点(preStart)，取接下来的 leftSize 个节点
    # 左子树的中序序列范围：[inStart, inRoot - 1]
    # 解释：中序遍历中根节点左边的所有节点
    root.left = buildTree(preorder, preStart + 1, preStart + leftSize, 
                          inorder, inStart, inRoot - 1)
    
    # 递归构建右子树
    # 右子树的前序序列范围：[preStart + leftSize + 1, preEnd]
    # 解释：跳过根节点和左子树的所有节点
    # 右子树的中序序列范围：[inRoot + 1, inEnd]
    # 解释：中序遍历中根节点右边的所有节点
    root.right = buildTree(preorder, preStart + leftSize + 1, preEnd, 
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
    
    # 读取前序遍历序列（一行用空格分隔的整数）
    preorder = list(map(int, input().split()))
    
    # 读取中序遍历序列（一行用空格分隔的整数）
    inorder = list(map(int, input().split()))
    
    # 根据前序和中序遍历构建二叉树
    # 初始时，前序序列的范围是 [0, N-1]，中序序列的范围也是 [0, N-1]
    root = buildTree(preorder, 0, N-1, inorder, 0, N-1)
    
    # 对构建的二叉树进行层序遍历并输出结果
    levelOrder(root)
    print()  # 输出换行

# Python程序的入口点
if __name__ == "__main__":
    main()