import os
from flask_wtf import FlaskForm
from wtforms import StringField, IntegerField, SubmitField, BooleanField




class Add_Rick_Form(FlaskForm):
    Dim = StringField("Origin Dimention: ")
    Morty_id = IntegerField("Morty's ID: ")
    On_the_council = BooleanField("Check if Rick is on the council: ")
    submit = SubmitField("Add Rick")

class Add_Morty_Form(FlaskForm):
    Dim = StringField("Origin Dimention: ")
    Rickless = BooleanField("Check if Morty doesn't have a Rick: ")
    submit = SubmitField("Add Morty")

class Del_Rick_Form(FlaskForm):
    id = IntegerField("Dead Rick's Id: ")
    submit = SubmitField("Remove Rick")
 
class Del_Morty_Form(FlaskForm):
    id = IntegerField("Dead Morty's Id: ")
    submit = SubmitField("Remove Morty")