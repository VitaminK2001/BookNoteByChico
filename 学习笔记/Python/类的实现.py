# 类的属性和方法查看
# class Person_1:
#     mind = "思想"
#     pay = "支付宝"

#     def work():
#         print('what job?')

# print(Person_1.__dict__['mind'])
# print(Person_1.work())
# Person_1.age = 15  # 增加变量age和他的值

# 类体中、所有函数之外：此范围定义的变量，称为类属性或类变量；
    # 类变量的特点是，所有类的实例化对象都同时共享类变量。
    # 可以使用类名直接调用、修改  可以被类对象访问，但是无法修改，
    # 这是因为，通过类对象修改类变量的值，不是在给“类变量赋值”，而是定义新的实例变量。
    # 类中，实例变量和类变量可以同名，但这种情况下使用类对象将无法调用类变量，它会首选实例变量，
    # 这也是不推荐“类变量使用对象名调用”的原因。
# 类体中，所有函数内部：以“self.变量名”的方式定义的变量，称为实例属性或实例变量；
    # 实例变量只能通过变量名访问 无法通过类名访问
# 类体中，所有函数内部：以“变量名=变量值”的方式定义的变量，称为局部变量。
    # 定义局部变量是为了所在类方法功能的实现。需要注意的一点是，
    # 局部变量只能用于所在函数中，函数执行完成后，局部变量也会被销毁。
class Person(object):
    grade = 6  # 类变量
    
    def __init__(self) -> None:  # 没有self可以用类名调用函数 有self必须创建实例
        self.name = "king";  # 只作用于调用方法的对象
        self.age = 20
    
    def sayHi(self):  # 加self区别于普通函数 
        print("hi, your name is ?", self.name)  # 这里的name是实例变量
    
    def sayAge():
        print("hi, your age is", Person.age)  # 这里的name是类变量

    @staticmethod 
    # 和类没有什么关系的方法
    def sayName():  # 不能访问类和对象的数据 也就是不能访问类变量和实例变量
        print('My name is king')
    
    @classmethod
    # classmethod的第一个参数为类本身(cls)，正如实例方法的第一个参数为对象本身(self)
    # 类方法可以通过类或者类的实例来调用
    def classMethod(cls):  # 类方法可以访问类变量 但是不能访问实例变量
        print('cls:',cls)
        # print(cls.name) # 报错 无法访问
        print(cls.grade) # 可以访问 因为是类变量
        cls.grade = 10  # 可以修改类属性

if __name__ == '__main__':
    Person.classMethod() # 打印6
    a = Person()
    print(a.grade) # 打印10
