import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

basedir = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir, 'data.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)
Migrate(app, db)

class Cats(db.Model):
    __tablename__ = 'Cats'

    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.Text)
    age = db.Column(db.Integer)

    toys = db.relationship('Toy', backref = 'Cats', lazy = 'dynamic')   #one to many
    owner = db.relationship('Owner', backref = 'Cats', uselist = False) #one to one


    def __init__(self, name, age):
        self.name = name
        self.age = age
    
    def __repr__(self):
        if self.owner:
            return f"Cato {self.name}'s ({self.age} year old) owner is: {self.owner.name}"
        else:
            return f"Cato {self.name} doesn't have a owner"

    def report_toys(self):
        print(f"Here are the cato {self.name}'s toys: ")
        for toy in self.toys:
            print(toy.item_name)

class Toy(db.Model):
    __tablename__ = 'Toy'
    
    id = db.Column(db.Integer, primary_key = True)
    item_name = db.Column(db.Text) 
    cats_id = db.Column(db.Integer, db.ForeignKey('Cats.id'))

    def __init__(self, item_name, cats_id):
        self.item_name = item_name
        self.cats_id = cats_id

class Owner(db.Model):
    __tablename__ = 'Owner'

    id = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.Text)
    cats_id = db.Column(db.Integer, db.ForeignKey('Cats.id'))

    def __init__(self, name, cats_id):
        self.name = name
        self.cats_id = cats_id

 