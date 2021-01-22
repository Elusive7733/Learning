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

class Hello(db.Model):

    __tablename__ = 'Cats' #manual table name override

    cid = db.Column(db.Integer, primary_key = True)
    name = db.Column(db.Text)
    age = db.Column(db.Integer)
    size = db.Column(db.Integer)

    def __init__(self, name, age, size):
        self.name = name
        self.age = age
        self.size = sizes
    
    def __repr__(self):
        return f"Cato {self.name} is {self.age} years old"

 