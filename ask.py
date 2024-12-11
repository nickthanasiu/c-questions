import sys

questions = sys.argv[1:]
qnas = []

for q in questions:
    qnas.append((q, input(q + ' ')))

print("")
for q, a in qnas:
    print(f'Q: {q}')
    print(f'A: {a}')
    print("----")
