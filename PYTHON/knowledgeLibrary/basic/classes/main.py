# Date:         10-25-2021
# File:         main.py
# Version:      1.0
# Status        INCOMPLETE
# Contributers	Parker Hooten
#
# Purpose:      to complete a problem statement from geeksforgeeks and
#               practice writing code in python

# References:   Very good tutorial to follow: https://www.youtube.com/watch?v=ZDa-Z5JzLYM
# 
# Credit:       Corey Schafer
#               This code was based on his youtube tutorial series which is linked
#               above
#
class Employee():

    # Class variables
    num_of_emps = 0
    raise_amount = 4
    company = "spacex"

    # Shows what 'pass' does
    def ignore_this():
        pass

    # Constructor                                           # recieves the first instance as the first argument 
    def __init__(self, first, last, pay, company):          # by convention we should call it 'self'
        self.first = first
        self.last = last
        self.pay = pay
        self.company = company
        self.email = first + '.' + last + '@' + company + '.com'
        
        Employee.num_of_emps += 1
        
        return


    # Constructor ( without company input )
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@' + self.company + '.com'

        Employee.num_of_emps += 1

        return


    # Display the full name
    def fullname(self):
        return '{} {}'.format(self.first, self.last)        # {} inside string is a place holder


    # Applies rais to empolyee
    def apply_raise(self):
        self.pay = int(self.pay * (1 + Employee.raise_amount * 0.01))
        
        return
    

    # Shows how to use class methods
    @classmethod                        # We recieve the class as the first argument instead of the instance
    def set_raise_amt(cls, amount):     # cls - convention for the class variable name
        cls.raise_amount = amount
        
        return
    

    # Class method example - Parcing input
    # see example 4 for explaination
    @classmethod
    def from_string(cls, emp_str):
        first, last, pay = emp_str.split('-')
        return cls(first, last, pay)        


    @staticmethod                       # static methods don't take any argument in first
    def is_workday(day):
        if day.weekday()==5 or day.weekday()==6:
            return False
        return True


#
#
#
def main():
    
    # Initializing employees
    emp_1 = Employee('Corey', 'Schafer', 50000)
    emp_2 = Employee('Kevin', 'Tracey', 60000)
    

    # example 1:
    
    # example 2:
    # example 3:

    # #=======================================================================
    # # example 4:
    # # " when people say they use 'class methods' as 'constructors' "

    # # Description:
    # #   If the programmer has to parce the strings every they get new info
    # #   It would be better if the class did this fo them rather than doing
    # #   what is seen below. In this case we would use an alternative constructor
    # #   which can be found under the member function: 'def from_string()'
    
    print('\n\n\nExample 4:\n')
    
    # BEFORE
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    # emp_str = [ 'John-Doe-70000', 'Steve-Smith-30000', 'Jane-Doe-90000' ]

    # inputs = emp_str[0].split('-')
    # emp_a = Employee(inputs[0], inputs[1], inputs[2])
    # print(emp_a.email)

    # inputs = emp_str[1].split('-')
    # emp_b = Employee(inputs[0], inputs[1], inputs[2])
    # print(emp_b.email)

    # inputs = emp_str[2].split('-')
    # emp_c = Employee(inputs[0], inputs[1], inputs[2])
    # print(emp_c.email)
    
    # AFTER
    # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    emp_str = ['John-Doe-70000', 'Steve-Smith-30000', 'Jane-Doe-90000']
    emp_a = Employee.from_string(emp_str[2])
    print(emp_a.email)




    # #=======================================================================
    # # example 5:
    # # " static methods "

    # # Description:
    # #     Usually a give away that a method should be static is if you don't
    # #     use the instance or the class anywhere within the function 
    print('\n\n\nExample 5:\n')
    
    import datetime
                    #   ...(year, month, day)
    my_date = datetime.date(2021, 10, 25)
    print('Today is a weekday: ', Employee.is_workday(my_date))

    # #=======================================================================

    return
    
main()