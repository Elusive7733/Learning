import os
from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, SubmitField, BooleanField

class AddForm(FlaskForm):
    Dim = StringField("Origin Dimention: ")
    Morty_id = IntegerField("Morty's ID: ")
    On_the_council = BooleanField("Check if Rick is on the council: ")
    submit = SubmitField("Add Rick")

class DelForm(FlaskForm):
    id = IntegerField("Dead Rick's Id: ")
    submit = SubmitField("Remove Rick")
