from Basic_Db import db, Hello

db.create_all()

fufi = Hello('Fufi', 3)
fufa = Hello('Fufa', 4)

print(fufi.cid)
print(fufa.cid)

db.session.add_all([fufi,fufa])

db.session.commit()

print(fufi.cid)
print(fufa.cid)