import os
from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, SubmitField, BooleanField

class AddForm(FlaskForm):
    Dim = StringField("Origin Dimention: ")
    Rickless = BooleanField("Check if Morty doesn't have a Rick: ")
    submit = SubmitField("Add Morty")

class DelForm(FlaskForm):
    id = IntegerField("Dead Morty's Id: ")
    submit = SubmitField("Remove Morty")