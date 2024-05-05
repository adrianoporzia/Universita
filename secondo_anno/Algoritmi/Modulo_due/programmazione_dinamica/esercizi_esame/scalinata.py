class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = []

def generate_combinations_helper(node, n, path, result):
    if node.value == n:
        result.append(path[:])
        return

    if node.value + 1 <= n:
        child1 = TreeNode(node.value + 1)
        node.children.append(child1)
        generate_combinations_helper(child1, n, path + [1], result)

    if node.value + 2 <= n:
        child2 = TreeNode(node.value + 2)
        node.children.append(child2)
        generate_combinations_helper(child2, n, path + [2], result)

def generate_combinations(n):
    if n == 0:
        return []

    root = TreeNode(0)
    result = []
    generate_combinations_helper(root, n, [], result)
    return result

# Esempio di utilizzo:
n = 8
combinations = generate_combinations(n)
print("Combinazioni possibili per raggiungere", n, "scegliendo 1 o 2:")
for combination in combinations:
    print(combination)

