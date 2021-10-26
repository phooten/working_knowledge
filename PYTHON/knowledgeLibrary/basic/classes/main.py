#
#
#
#
#

class Employee():
    num_of_emps = 0
    raise_amount = 4

    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@'
        
        Employee.num_of_emps += 1
        
        return

    def fullname(self):
        return '{} {}'.format(self.first, self.last)

    def apply_raise(self):
        self.pay = int(self.pay * (1 + Employee.raise_amount * 0.01))
        return


#
#
#
def main():
    
    emp_1 = Employee('Corey', 'Schafer', 50000)
    emp_2 = Employee('Kevin', 'Tracey', 60000)

    print(Employee.__dict__)
    print(emp_1.__dict__)
    print(Employee.raise_amount)
    print(emp_1.raise_amount)
    print(emp_2.raise_amount)

    emp_1.raise_amount = 5

    print(Employee.__dict__)
    print(emp_1.__dict__)
    print(Employee.raise_amount)
    print(emp_1.raise_amount)
    print(emp_2.raise_amount)

    # print(emp_1.pay)
    # emp_1.apply_raise(4)
    # print(emp_1.pay)


    return
    
main()