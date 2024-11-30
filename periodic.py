from chempy.util import periodic

n=int(input("Enter number to see the table: "))
print("Atomic No.\tName\t\tSymbol\t\tMass")

for i in range(1,n+1):
    print(i,end="\t\t")
    if len(periodic.names[i])>7:
        print(periodic.names[i],end="\t")
    else:
        print(periodic.names[i],end="\t\t")
    print(periodic.symbols[i], end="\t\t")
    print(periodic.relative_atomic_masses[i])
