# pow function

# 2的n次方
def pow2(n):
    return 1 << n



if __name__ == '__main__':
    intput = int(input())
    
    for i in range(intput):
        n = int(i)
        print(pow2(n)%998244353)