def evaluate(tokens):
    st = []
    for tok in tokens:
        if tok in "+-*/":
            b = st.pop()
            a = st.pop()
            if tok == '+': st.append(a + b)
            elif tok == '-': st.append(a - b)
            elif tok == '*': st.append(a * b)
            elif tok == '/': st.append(a // b)
        else:
            st.append(int(tok))
    return st[0]

if __name__ == "__main__":
    tokens = input().strip().split()
    print(evaluate(tokens))
