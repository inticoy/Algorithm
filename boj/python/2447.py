def star(N):
    if N == 3:
        print("***\n* *\n***")
    else:
        for i in range(3):
            star(N / 3)
        star(N / 3)
        print('   \n   \n   ')
        star(N / 3)
        for i in range(3):
            star(N / 3)


star(9)
