from Basic_Db import db, Hello

#_________________________create_________________________
# print('creating: \n')
test = Hello('Nibba', 5)
db.session.add(test)
db.session.commit()

#__________________________read__________________________
print('\nreading: \n')
all_nibbas = Hello.query.all()
print(all_nibbas)

#select by id
print('\nreading cid = 1')
print(Hello.query.get(1))

#filter
print('\nFilter age = 5')
print(Hello.query.filter_by(age=5).all())


#_________________________update_________________________
# print('\nupdating: \n')
old_nibba = Hello.query.get(1)
old_nibba.age = 10
db.session.add(old_nibba)
db.session.commit()


#_________________________delete_________________________
# print('\ndeleteing: \n')
db.session.delete(Hello.query.get(1))
db.session.commit()


all_nibbas = Hello.query.all()
print(all_nibbas)