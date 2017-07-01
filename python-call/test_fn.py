import fn

print("** test started **")

for i in range(100):
    assert(fn.mult2(i) == i * 2)

assert(fn.sum(2) == 2)
assert(fn.sum(2, 3) == 5)

assert(fn.sub(3) == 3)
assert(fn.sub(3, 4) == -1)

assert(fn.sub(1.0) == 1.0)
assert(fn.sub(1.0, 2.0) == -1.0)

print("** test passed **")
