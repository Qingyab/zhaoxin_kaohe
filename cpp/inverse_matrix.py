def menu():
    n = int(input('请输入方针的阶数\n'))
    #初始化方阵
    a = List(n)
    #判断是否为非奇异矩阵
    #print(strange(a))
    if strange(a):
        #求出矩阵的逆
        Reverse(a)
    else:
        print('矩阵不可逆')
#判断是否为非奇异矩阵
def List(k):
    a = []  # 创建一个空列表
    for i in range(k):  # 创建一个k行的列表（行）
        a.append([])  # 在空的列表中添加空的列表
        for j in range(k):  # 循环每一行的每一个元素（列）
            x = float(input())
            a[i].append(x)  # 为内层列表添加元素
    s = []  # 创建一个空列表
    for i in range(k):  # 创建一个k行的列表（行）
        s.append([])  # 在空的列表中添加空的列表
        for j in range(2 * k):  # 循环每一行的每一个元素（列）
            if j < k:
                x = a[i][j]
            elif j - k == i:
                x = 1.0
            else:
                x = 0.0
            s[i].append(x)  # 为内层列表添加元素
    return s
def strange(a):
    n1 = len(a)
    for m in range(n1-1):  #从第0列开始计算
        k = float(a[m+1][m]/a[m][m])    #
        for m1 in range(1,n1-m):   #从第m1行开始将对应位置的数据变为0
            for n in range(m,2*n1):    #更新每一行的数据
                a[m1][n] = float(a[m1][n] - k*a[m1-1][n])
    for m in range(n1):
        if a[m][m] == 0:
            return False
    return True

#求矩阵的逆
def Reverse(a):
    #回代
    l = len(a)  #l实际为矩阵的行数
    n = l - 1
    while(n>=0):   #最后一行开始遍历，除主元以外都化为0
        for i in range(n+1,l):   #主元往后数l-n个数据，都要进行化简，需要进行l-n次行变换
            k = float(a[n][i]/a[i][i])
            for j in range(n+1,2*l):   #每一次行变换都从主元开始，到每一行的最后一个元素结束
                a[n][j] = a[n][j] - k * a[i][j]
        n = n -1
    #主元化为1
    for i in range(l):
        k = float(1/a[i][i])
        for j in range(i,2*l):
            a[i][j] = k*a[i][j]
    #输出
    for m in range(l):
        for n in range(2*l):
            print(a[m][n],end=' ')
        print('\n')

menu()
