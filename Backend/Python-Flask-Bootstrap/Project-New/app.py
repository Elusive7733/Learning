from myproject import app
from flask import render_template



@app.route('/')
def Home(): 
    return render_template('Home.html')

if __name__ == '__main__':
    app.run(debug=True)