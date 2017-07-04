import cls

print("** test started **")

p = cls.Person("pohe")
assert(p.greet() == "My name is pohe")

p = cls.Person("fuga", 1)
assert(p.age == 1)
p.age = 10
assert(p.age == 10)
p.grow()
assert(p.age == 11)

p.height = 150
assert(p.height == 150)

assert(p.weight == 50)
# p.weight = 100

p += 10
p -= 5
p = 5 + p
assert(p.age == 21)

assert(p.__str__() == "fuga")

for s in p.name_string():
    print(s)

print("** test passed **")
