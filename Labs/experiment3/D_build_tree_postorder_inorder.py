import sys

class Node:
    def __init__(self, val: int):
        self.val = val
        self.lchild: Node | None = None
        self.rchild: Node | None = None


def make(lin: int, rin: int, lpost: int, rpost: int,
         post: list[int], in_arr: list[int]) -> Node:
    nd = Node(post[rpost])
    k = 0
    while in_arr[lin + k] != post[rpost]:
        k += 1
    if k > 0:
        nd.lchild = make(lin, lin + k - 1, lpost, lpost + k - 1, post, in_arr)
    if lin + k < rin:
        nd.rchild = make(lin + k + 1, rin, lpost + k, rpost - 1, post, in_arr)
    return nd


def preorder(nd: Node | None, out: list[str]) -> None:
    if nd is None:
        return
    out.append(str(nd.val))
    preorder(nd.lchild, out)
    preorder(nd.rchild, out)


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    post = [0] * (n + 1)
    in_arr = [0] * (n + 1)
    for i in range(1, n + 1):
        post[i] = int(next(it))
    for i in range(1, n + 1):
        in_arr[i] = int(next(it))

    root = make(1, n, 1, n, post, in_arr)
    out: list[str] = []
    preorder(root, out)
    sys.stdout.write(" ".join(out))


if __name__ == "__main__":
    main()
