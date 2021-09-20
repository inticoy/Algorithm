import time

num = 10 ** 5

start = time.time()
list_comprehension = [i for i in range(num)]
end = time.time()
print("[for i in] :\t", (end - start))

start = time.time()
list_append = []
for i in range(num):
    list_append.append(i)
end = time.time()
print("[].append() :\t", (end - start))


start = time.time()
list_add = []
for i in range(num):
    list_add += [i]
end = time.time()
print("[] + [] :\t", (end - start))

start = time.time()
list_initialize = [0] * num
for i in range(num):
    list_initialize[i] = i
end = time.time()
print("[0,... 0] :\t", (end - start))

start = time.time()
list_range = list(range(num))
end = time.time()
print("list(range()) :\t", end - start)


start = time.time()
list_range = [0] * num
end = time.time()
print("list(range()) :\t", end - start)


start = time.time()
for i in range(num):
    pass
end = time.time()
print(end - start)
