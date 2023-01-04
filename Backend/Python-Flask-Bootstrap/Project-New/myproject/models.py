from myproject import db

class Rick(db.Model):
    __tablename__ = 'Rick'

    id = db.Column(db.Integer, primary_key = True)
    Dim = db.Column(db.Text)
    Morty_id = db.Column(db.Integer, db.ForeignKey('Morty.id')) 
    On_the_council = db.Column(db.Boolean)
    # Morty = db.relationship('Morty', backref = 'Rick', uselist = False)

    def __init__(self, Dim, Morty_id, On_the_council):
        self.Dim = Dim
        self.Morty_id = Morty_id
        self.On_the_council = On_the_council
    
    def __repr__(self):
        if self.Morty_id:
            return f"Rick Dimension: {self.Dim}, owns Morty: {self.Morty_id} and is on the council: {self.On_the_council}"
        else:
            return f"Rick Dimension: {self.Dim}, doesn't have a Morty and is on the council: {self.On_the_council}"

class Morty(db.Model):
    __tablename__ = 'Morty'

    id = db.Column(db.Integer, primary_key = True)
    Dim = db.Column(db.Text)
    Rickless = db.Column(db.Boolean)
    Rick = db.relationship('Rick', backref = 'Morty', uselist = False)

    def __init__(self, Dim, Rickless):
        self.Dim = Dim
        self.Rickless = Rickless
    
    def __repr__(self):
        if self.Rick:
            return f"Morty Morty Dimension: {self.Dim}, is owned by Rick {self.Rick.id} of Dimension: {self.Rick.Dim}" 
        else:
            return f"Morty Dimension: {self.Dim}, is Rickless"