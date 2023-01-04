from flask import Blueprint, render_template, redirect, url_for
from myproject import db
from myproject.models import Rick
from myproject.ricks.forms import AddForm, DelForm

ricks_blueprint = Blueprint('ricks',__name__,template_folder='templates/ricks')

@ricks_blueprint.route('/Add', methods=['GET', 'POST'])
def Add():

    form = AddForm()

    if form.validate_on_submit():
        Dim = form.Dim.data
        Morty_id = form.Morty_id.data
        On_the_council = form.On_the_council.data
 
        new_rick = Rick(Dim, Morty_id, On_the_council)
        db.session.add(new_rick)
        db.session.commit()

        return redirect(url_for('mortys.List'))
  
    return render_template('Add.html', form=form)

@ricks_blueprint.route('/Delete', methods=['GET', 'POST'])
def Delete():

    form = DelForm()

    if form.validate_on_submit():
        id = form.id.data
        rick = Rick.query.get(id)
        db.session.delete(rick)
        db.session.commit()

        return redirect(url_for('mortys.List'))
    return render_template('Delete.html', form=form)