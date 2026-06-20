import sys

class Node:
    def __init__(self, val: int):
        self.val = val
        self.lchild: Node | None = None
        self.rchild: Node | None = None


def insert(root: Node, v: int) -> None:
    tmp = root
    add = Node(v)
    while tmp is not None:
        if v == tmp.val:
            return
        if v > tmp.val:
            if tmp.rchild is None:
                tmp.rchild = add
                return
            tmp = tmp.rchild
        else:
            if tmp.lchild is None:
                tmp.lchild = add
                return
            tmp = tmp.lchild


def preorder(nd: Node | None, out: list[str]) -> None:
    if nd is None:
        out.append("0")
        return
    out.append(str(nd.val))
    preorder(nd.lchild, out)
    preorder(nd.rchild, out)


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    x = int(data[1])
    root = Node(x)
    for i in range(2, n + 1):
        x = int(data[i])
        insert(root, x)

    out: list[str] = []
    preorder(root, out)
    sys.stdout.write(" ".join(out))


if __name__ == "__main__":
    main()
