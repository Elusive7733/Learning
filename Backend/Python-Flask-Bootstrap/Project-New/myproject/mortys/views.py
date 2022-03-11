from flask import Blueprint, render_template, redirect, url_for
from myproject import db
from myproject.models import Morty, Rick
from myproject.mortys.forms import AddForm, DelForm

mortys_blueprint = Blueprint('mortys',__name__,template_folder='templates/mortys')


@mortys_blueprint.route('/Add', methods=['GET', 'POST'])
def Add():

    form = AddForm()

    if form.validate_on_submit():
        Dim = form.Dim.data
        Rickless = form.Rickless.data

        new_morty = Morty(Dim, Rickless)
        db.session.add(new_morty)
        db.session.commit()

        return redirect(url_for('mortys.List'))
  
    return render_template('MortyAdd.html', form=form) 


@mortys_blueprint.route('/Delete', methods=['GET', 'POST'])
def Delete():

    form = DelForm()

    if form.validate_on_submit():
        id = form.id.data
        morty = Morty.query.get(id)
        db.session.delete(morty)
        db.session.commit()

        return redirect(url_for('mortys.List'))
    return render_template('Delete.html', form=form)


@mortys_blueprint.route('/List')
def List():
    ricks = Rick.query.all()
    mortys = Morty.query.all()
    return render_template('List.html', ricks=ricks, mortys=mortys)


