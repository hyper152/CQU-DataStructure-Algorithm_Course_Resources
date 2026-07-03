#冰雹猜想的内容是：任何一个大于1的整数n，按照n为偶数则除等2，n为奇数则乘3后再加1的规则不断变化，最终都可以变化为1。
#例如，n等于20，变化过程为：20、10、5、16、8、4、2、1。编写程序，用户输入n，输出变化过程以及变化的次数。
n=int(input(""))
s=[]
count=0
while n!=1:
    s.append(int(n))
    count+=1
    if n%2==0:
        n=n/2
    else:
        n=n*3+1
s.append(int(n))
count+=1
for num in s:
    if num!=1:
        print(num, end=" ")
    else:
        print(num)
print("count =",count)

