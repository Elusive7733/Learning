import os
from flask import Flask, render_template, url_for, redirect
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate
from Forms import Add_Morty_Form, Add_Rick_Form, Del_Morty_Form, Del_Rick_Form


basedir = os.path.abspath(os.path.dirname(__file__))

app = Flask(__name__)

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir, 'data.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
SECRET_KEY = os.urandom(32)
app.config['SECRET_KEY'] = SECRET_KEY

db = SQLAlchemy(app)
Migrate(app, db)

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


@app.route('/')
def Home(): 
    return render_template('Home.html')

@app.route('/Add_Rick', methods=['GET', 'POST'])
def Add_Rick():

    form = Add_Rick_Form()

    if form.validate_on_submit():
        Dim = form.Dim.data
        Morty_id = form.Morty_id.data
        On_the_council = form.On_the_council.data
 
        new_rick = Rick(Dim, Morty_id, On_the_council)
        db.session.add(new_rick)
        db.session.commit()

        return redirect(url_for('List'))
  
    return render_template('Add_Rick.html', form=form)


@app.route('/Add_Morty', methods=['GET', 'POST'])
def Add_Morty():

    form = Add_Morty_Form()

    if form.validate_on_submit():
        Dim = form.Dim.data
        Rickless = form.Rickless.data

        new_morty = Morty(Dim, Rickless)
        db.session.add(new_morty)
        db.session.commit()

        return redirect(url_for('List'))
  
    return render_template('Add_Morty.html', form=form) 


@app.route('/Delete_Rick', methods=['GET','POST'])
def Delete_Rick():

    form = Del_Rick_Form()

    if form.validate_on_submit():
        id = form.id.data
        rick = Rick.query.get(id)
        db.session.delete(rick)
        db.session.commit()

        return redirect(url_for('List'))
    return render_template('Delete_Rick.html', form=form)


@app.route('/Delete_Morty', methods=['GET','POST'])
def Delete_Morty():

    form = Del_Morty_Form()

    if form.validate_on_submit():
        id = form.id.data
        morty = Morty.query.get(id)
        db.session.delete(morty)
        db.session.commit()

        return redirect(url_for('List'))
    return render_template('Delete_Morty.html', form=form)


@app.route('/List') 
def List():
    ricks = Rick.query.all()
    mortys = Morty.query.all()
    return render_template('List.html', ricks=ricks, mortys=mortys)


if __name__ == '__main__':
    app.run(debug=True)