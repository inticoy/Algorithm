M = int(input())
place = input().split()

if M % 2 == 1:
    print("koosaga")
else:
    if place.count('1') % 2 == 1:
        print("koosaga")
    else:
        print("cubelover")
