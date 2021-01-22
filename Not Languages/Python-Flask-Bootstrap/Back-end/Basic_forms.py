from flask import Flask, render_template
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField


app = Flask(__name__)

app.config['SECRET_KEY'] = 'hello'    

class basicform(FlaskForm):

    name = StringField("what is your name?")
    submit = SubmitField('Submit')

@app.route('/', methods=['GET', 'POST'])
def basic_forms():
    name = False

    form = basicform()

    if form.validate_on_submit():
        
        name = form.name.data
        form.name.data = ""
    return render_template('basic_forms.html', form=form, name=name)

if __name__ == '__main__': 
    app.run(debug=True)  