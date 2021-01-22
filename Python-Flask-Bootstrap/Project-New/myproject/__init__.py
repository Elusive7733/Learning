import os
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__))

app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir, 'data.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config['SECRET_KEY'] = 'mysecretkey'

db = SQLAlchemy(app)
Migrate(app, db)

from myproject.mortys.views import mortys_blueprint
from myproject.ricks.views import ricks_blueprint

app.register_blueprint(ricks_blueprint, url_prefix='/ricks')
app.register_blueprint(mortys_blueprint, url_prefix='/mortys') 