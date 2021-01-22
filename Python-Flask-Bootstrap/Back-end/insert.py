from DB_Models import db, Cats, Toy, Owner 


# fufi = Cats('fufi', 3)
# fufa = Cats('fufa', 5)

# db.session.add_all([fufi, fufa])
# db.session.commit()

print(Cats.query.all())

fufi = Cats.query.filter_by(name = 'fufi').first()
print(fufi)

# Abdullah = Owner('Abdullah', fufi.id)

# toy1 = Toy('Squeeky Toy', fufi.id)
# toy2 = Toy('Qasim', fufi.id)

# db.session.add_all([Abdullah, toy1, toy2])
# db.session.commit()

# fufi = Cats.query.filter_by(name = 'fufi').first()
# print(fufi)

fufi.report_toys()
