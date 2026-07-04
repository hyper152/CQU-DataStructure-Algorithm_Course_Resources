# Python 类（Class）详解

## 一、类的基本概念

类是面向对象编程（OOP）的核心概念，它是创建对象的蓝图或模板。对象是类的实例，包含数据（属性）和方法（行为）。

### 1. 基本语法

```python
class ClassName:
    """类的文档字符串（docstring），描述类的用途"""
    
    # 类变量（所有实例共享）
    class_variable = 0
    
    def __init__(self, param1, param2):
        """构造函数，在创建对象时自动调用"""
        # 实例变量（每个实例独有）
        self.instance_var1 = param1
        self.instance_var2 = param2
    
    def method(self):
        """实例方法，可以访问实例变量和类变量"""
        return f"{self.instance_var1}, {self.instance_var2}"
```

## 二、类的组成部分详解

### 1. `__init__` 方法（构造函数）

```python
class Person:
    def __init__(self, name, age):
        """
        构造函数
        - self: 指向新创建的实例对象，必须作为第一个参数
        - name, age: 其他初始参数
        """
        self.name = name    # 实例属性
        self.age = age      # 实例属性
        print(f"Person {name} created")

# 创建实例时自动调用 __init__
person1 = Person("张三", 25)  # 输出: Person 张三 created
person2 = Person("李四", 30)  # 输出: Person 李四 created
```

### 2. self 参数

```python
class Student:
    def __init__(self, name):
        self.name = name  # self.name 是实例属性
    
    def study(self):
        # self 代表调用这个方法的实例对象
        print(f"{self.name} is studying")
    
    def change_name(self, new_name):
        self.name = new_name  # 通过 self 修改实例属性

# self 的自动传递
stu = Student("王五")
stu.study()  # 等价于 Student.study(stu)
```

### 3. 实例变量 vs 类变量

```python
class Dog:
    # 类变量：所有实例共享
    species = "犬科"
    count = 0
    
    def __init__(self, name):
        # 实例变量：每个实例独有
        self.name = name
        Dog.count += 1  # 修改类变量
    
    def bark(self):
        print(f"{self.name} 在叫")

# 类变量可以被类直接访问
print(Dog.species)  # 输出: 犬科
print(Dog.count)    # 输出: 0

# 创建实例
dog1 = Dog("旺财")
dog2 = Dog("小白")

print(dog1.name)     # 输出: 旺财（实例变量）
print(dog1.species)  # 输出: 犬科（通过实例访问类变量）
print(Dog.count)     # 输出: 2（所有实例共享计数）
```

## 三、方法类型

### 1. 实例方法

```python
class Calculator:
    def __init__(self, value=0):
        self.value = value
    
    def add(self, num):
        """实例方法：第一个参数是 self"""
        self.value += num
        return self.value
    
    def multiply(self, num):
        """实例方法可以调用其他实例方法"""
        self.value *= num
        return self.value

calc = Calculator(10)
print(calc.add(5))      # 输出: 15
print(calc.multiply(3)) # 输出: 45
```

### 2. 类方法（@classmethod）

```python
class Date:
    date_format = "YYYY-MM-DD"
    
    def __init__(self, year, month, day):
        self.year = year
        self.month = month
        self.day = day
    
    @classmethod
    def change_format(cls, new_format):
        """类方法：第一个参数是 cls（类本身），可以修改类变量"""
        cls.date_format = new_format
    
    @classmethod
    def from_string(cls, date_str):
        """类方法常用作备选构造函数"""
        year, month, day = map(int, date_str.split('-'))
        return cls(year, month, day)
    
    def display(self):
        return f"{self.year}-{self.month:02d}-{self.day:02d}"

# 使用类方法创建实例
date1 = Date(2024, 1, 15)
date2 = Date.from_string("2024-06-20")  # 备选构造方式

print(date2.display())  # 输出: 2024-06-20

# 修改类变量
Date.change_format("DD/MM/YYYY")
print(Date.date_format)  # 输出: DD/MM/YYYY
```

### 3. 静态方法（@staticmethod）

```python
class MathUtils:
    @staticmethod
    def add(x, y):
        """静态方法：不需要 self 或 cls 参数"""
        return x + y
    
    @staticmethod
    def is_even(num):
        """
        静态方法：类似于普通函数，但与类相关
        不能访问实例属性或类属性
        """
        return num % 2 == 0
    
    @staticmethod
    def validate_number(num):
        """静态方法常用于工具函数"""
        return isinstance(num, (int, float)) and num > 0

# 可以直接通过类名调用
print(MathUtils.add(3, 5))          # 输出: 8
print(MathUtils.is_even(10))        # 输出: True
print(MathUtils.validate_number(5)) # 输出: True

# 也可以通过实例调用
utils = MathUtils()
print(utils.add(10, 20)) # 输出: 30
```

### 4. 三种方法对比

```python
class MyClass:
    class_var = 0
    
    def __init__(self, val):
        self.instance_var = val
    
    def instance_method(self):
        """可以访问实例变量和类变量"""
        return f"Instance: {self.instance_var}, Class: {MyClass.class_var}"
    
    @classmethod
    def class_method(cls):
        """只能访问类变量，不能访问实例变量"""
        return f"Class var: {cls.class_var}"
    
    @staticmethod
    def static_method():
        """不能访问实例变量和类变量"""
        return "I'm independent"

obj = MyClass(10)
print(obj.instance_method())  # 输出: Instance: 10, Class: 0
print(MyClass.class_method()) # 输出: Class var: 0
print(MyClass.static_method())# 输出: I'm independent
```

## 四、特殊方法（魔术方法）

### 1. 字符串表示方法

```python
class Book:
    def __init__(self, title, author, price):
        self.title = title
        self.author = author
        self.price = price
    
    def __str__(self):
        """用于 print() 和 str()，给用户看的友好表示"""
        return f"《{self.title}》 by {self.author}"
    
    def __repr__(self):
        """用于调试，给开发者看的官方表示"""
        return f"Book('{self.title}', '{self.author}', {self.price})"

book = Book("Python编程", "张三", 59.9)
print(book)        # 输出: 《Python编程》 by 张三
print(str(book))   # 输出: 《Python编程》 by 张三
print(repr(book))  # 输出: Book('Python编程', '张三', 59.9)
```

### 2. 运算符重载

```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def __add__(self, other):
        """重载 + 运算符"""
        return Vector(self.x + other.x, self.y + other.y)
    
    def __sub__(self, other):
        """重载 - 运算符"""
        return Vector(self.x - other.x, self.y - other.y)
    
    def __mul__(self, scalar):
        """重载 * 运算符（标量乘法）"""
        return Vector(self.x * scalar, self.y * scalar)
    
    def __eq__(self, other):
        """重载 == 运算符"""
        return self.x == other.x and self.y == other.y
    
    def __str__(self):
        return f"Vector({self.x}, {self.y})"

v1 = Vector(2, 3)
v2 = Vector(5, 1)

print(v1 + v2)    # 输出: Vector(7, 4)
print(v1 - v2)    # 输出: Vector(-3, 2)
print(v1 * 3)     # 输出: Vector(6, 9)
print(v1 == v2)   # 输出: False
print(v1 == Vector(2, 3)) # 输出: True
```

### 3. 上下文管理器

```python
class FileHandler:
    def __init__(self, filename, mode):
        self.filename = filename
        self.mode = mode
        self.file = None
    
    def __enter__(self):
        """进入 with 语句时调用"""
        print(f"打开文件: {self.filename}")
        self.file = open(self.filename, self.mode)
        return self.file
    
    def __exit__(self, exc_type, exc_val, exc_tb):
        """退出 with 语句时调用"""
        print(f"关闭文件: {self.filename}")
        if self.file:
            self.file.close()
        # 返回 False 会向上抛出异常，True 会抑制异常

# 使用 with 语句自动管理资源
with FileHandler('test.txt', 'w') as f:
    f.write('Hello, World!')
```

## 五、访问控制和属性封装

### 1. 命名约定（Python 没有真正的私有）

```python
class BankAccount:
    def __init__(self, account_number, balance):
        self.account_number = account_number    # 公开属性
        self._bank_name = "Python银行"          # 受保护属性（约定，仍可访问）
        self.__balance = balance                # 私有属性（名称修饰）
    
    def deposit(self, amount):
        """通过公开方法修改私有属性"""
        if amount > 0:
            self.__balance += amount
            print(f"存入 {amount}，余额: {self.__balance}")
    
    def get_balance(self):
        """通过公开方法访问私有属性"""
        return self.__balance
    
    def __internal_method(self):
        """私有方法"""
        print("这是内部方法")

account = BankAccount("12345", 1000)

# 直接访问
print(account.account_number)  # 输出: 12345
print(account._bank_name)      # 输出: Python银行（约定，但可以访问）

# 访问私有属性
try:
    print(account.__balance)   # AttributeError
except AttributeError as e:
    print(f"错误: {e}")

# 名称修饰：_类名__属性名
print(account._BankAccount__balance)  # 输出: 1000（但不推荐这样做）

# 通过方法访问
print(account.get_balance())  # 输出: 1000
account.deposit(500)          # 输出: 存入 500，余额: 1500
```

### 2. property 装饰器

```python
class Temperature:
    def __init__(self, celsius=0):
        self._celsius = celsius
    
    @property
    def celsius(self):
        """getter：获取温度（摄氏度）"""
        print("获取摄氏温度")
        return self._celsius
    
    @celsius.setter
    def celsius(self, value):
        """setter：设置温度（摄氏度）"""
        if value < -273.15:
            raise ValueError("温度不能低于绝对零度")
        print(f"设置摄氏温度: {value}")
        self._celsius = value
    
    @property
    def fahrenheit(self):
        """计算属性：华氏温度"""
        return self._celsius * 9/5 + 32
    
    @fahrenheit.setter
    def fahrenheit(self, value):
        """通过华氏温度设置摄氏温度"""
        self.celsius = (value - 32) * 5/9
    
    @property
    def kelvin(self):
        """只读属性：开尔文温度"""
        return self._celsius + 273.15

# 使用 property
temp = Temperature(25)
print(temp.celsius)     # 输出: 获取摄氏温度\n25
print(temp.fahrenheit)  # 输出: 77.0

temp.celsius = 30       # 输出: 设置摄氏温度: 30
print(temp.fahrenheit)  # 输出: 86.0

temp.fahrenheit = 100   # 设置华氏温度
print(f"{temp.celsius:.1f}°C")  # 输出: 设置摄氏温度: 37.77777777777778\n37.8°C

print(f"{temp.kelvin:.1f}K")     # 输出: 310.9K
```

## 六、继承与多态

### 1. 单继承

```python
class Animal:
    def __init__(self, name):
        self.name = name
    
    def speak(self):
        """基类方法"""
        return f"{self.name} makes a sound"
    
    def eat(self):
        return f"{self.name} is eating"

class Dog(Animal):
    def __init__(self, name, breed):
        # 调用父类的 __init__
        super().__init__(name)
        self.breed = breed
    
    def speak(self):
        """方法重写（覆盖）"""
        return f"{self.name} barks: Woof!"
    
    def fetch(self):
        """子类独有的方法"""
        return f"{self.name} fetches the ball"

class Cat(Animal):
    def speak(self):
        return f"{self.name} meows: Meow!"
    
    def scratch(self):
        return f"{self.name} scratches furniture"

# 多态：不同对象调用相同方法，产生不同行为
animals = [Dog("旺财", "金毛"), Cat("咪咪"), Dog("小白", "柯基")]

for animal in animals:
    print(animal.speak())

# 输出:
# 旺财 barks: Woof!
# 咪咪 meows: Meow!
# 小白 barks: Woof!

# isinstance 检查
dog = Dog("旺财", "金毛")
print(isinstance(dog, Dog))     # 输出: True
print(isinstance(dog, Animal))   # 输出: True
print(isinstance(dog, Cat))      # 输出: False
```

### 2. 多继承

```python
class Flyable:
    def fly(self):
        return f"{self.__class__.__name__} is flying"

class Swimmable:
    def swim(self):
        return f"{self.__class__.__name__} is swimming"

class Duck(Animal, Flyable, Swimmable):
    def speak(self):
        return f"{self.name} quacks: Quack!"

class Penguin(Animal, Swimmable):
    def speak(self):
        return f"{self.name} honks: Honk!"

duck = Duck("唐老鸭")
print(duck.speak())  # 输出: 唐老鸭 quacks: Quack!
print(duck.fly())    # 输出: Duck is flying
print(duck.swim())   # 输出: Duck is swimming

penguin = Penguin("企鹅")
print(penguin.swim())  # 输出: Penguin is swimming
# penguin.fly()  # AttributeError
```

### 3. 抽象类

```python
from abc import ABC, abstractmethod

class Shape(ABC):
    """抽象基类"""
    
    def __init__(self, color='black'):
        self.color = color
    
    @abstractmethod
    def area(self):
        """抽象方法：子类必须实现"""
        pass
    
    @abstractmethod
    def perimeter(self):
        """抽象方法：子类必须实现"""
        pass
    
    def describe(self):
        """具体方法：可以被子类继承"""
        return f"A {self.color} shape with area {self.area():.2f}"

class Circle(Shape):
    def __init__(self, radius, color='black'):
        super().__init__(color)
        self.radius = radius
    
    def area(self):
        return 3.14159 * self.radius ** 2
    
    def perimeter(self):
        return 2 * 3.14159 * self.radius

class Rectangle(Shape):
    def __init__(self, width, height, color='black'):
        super().__init__(color)
        self.width = width
        self.height = height
    
    def area(self):
        return self.width * self.height
    
    def perimeter(self):
        return 2 * (self.width + self.height)

# 不能实例化抽象类
# shape = Shape()  # TypeError: Can't instantiate abstract class

circle = Circle(5, 'blue')
rect = Rectangle(4, 6, 'red')

print(circle.describe())  # 输出: A blue shape with area 78.54
print(rect.describe())    # 输出: A red shape with area 24.00
```

## 七、类的高级特性

### 1. `__slots__` 优化内存

```python
class Point:
    __slots__ = ['x', 'y']  # 限制只能有这些属性，减少内存占用
    
    def __init__(self, x, y):
        self.x = x
        self.y = y

class PointWithoutSlots:
    def __init__(self, x, y):
        self.x = x
        self.y = y

# 使用 __slots__ 可以节省内存
p1 = Point(1, 2)
# p1.z = 3  # AttributeError: 'Point' object has no attribute 'z'
```

### 2. 数据类（Python 3.7+）

```python
from dataclasses import dataclass

@dataclass
class Person:
    name: str
    age: int
    email: str = ""  # 默认值
    
    # 自动生成 __init__, __repr__, __eq__ 等方法

# 等价于手动编写的类，但更简洁
p1 = Person("张三", 25, "zhangsan@example.com")
p2 = Person("李四", 30)

print(p1)  # 输出: Person(name='张三', age=25, email='zhangsan@example.com')
print(p2)  # 输出: Person(name='李四', age=30, email='')
print(p1 == Person("张三", 25, "zhangsan@example.com"))  # 输出: True
```

### 3. `__call__` 使实例可调用

```python
class Multiplier:
    def __init__(self, factor):
        self.factor = factor
    
    def __call__(self, x):
        """使实例可以像函数一样被调用"""
        return x * self.factor

doubler = Multiplier(2)
tripler = Multiplier(3)

print(doubler(5))  # 输出: 10
print(tripler(5))  # 输出: 15
```
