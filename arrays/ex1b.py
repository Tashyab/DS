heros=['spider man','thor','hulk','iron man','captain america']
heros.append("black panther")
heros.pop()

for i, he in enumerate(heros):
    if he=='hulk':
        ind=i

heros.insert(ind+1, "black panther")
heros[1:3]=['doctor strange']
print(heros)
heros.sort()
print(heros)

