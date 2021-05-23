from random import randint
from os import mkdir
ops = ('data',)

def values_generator(min_value: int = -32767, max_value: int = 32767):
    """Function to generate values for tests"""
    for op in ops:
        mkdir(op)
        for elements_quantity in (500, 10**3,  10**4, 10**5, 5 * (10**5)):
            with open(f'{op}/data({elements_quantity}).txt', "a") as inp:
                for i in range(elements_quantity):
                    value = randint(min_value, max_value)
                    inp.write(str(value) + " ")
                inp.write("\n")


if __name__ == '__main__':
    help_message = """"""
    values_generator()
    print('successfully')
