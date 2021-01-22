def code(mystr):
    vowel = 'aeiou'

    for letter in mystr:
        if letter in vowel:
            mystr = mystr.replace(letter, 'x')

    return mystr


# print(code('Abdullah Raheel'))


class Elusive():

    def __init__(self, fname, lname):
        self.fname = fname
        self.lname = lname
        print(self)

    def __repr__(self):
        return f"{self.fname} {self.lname}"


class COE(Elusive):
      
    def __init__(self, fname, lname):
        # Elusive.__init__(self, lname, "Raheel")
        self.fname = fname
        self.lname = lname
    
    def new_decor(self, old_print):

        def wrap_print():
            print("Grand parent is: Raheel")

        old_print(self)

        print("Great Grand parent is: Ahmed")
        return wrap_print

qasim = COE("Qasim", "Talha")
# print(qasim)
qasim.new_decor(print)




