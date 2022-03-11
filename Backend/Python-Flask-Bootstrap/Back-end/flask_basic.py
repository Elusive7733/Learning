from flask import Flask

app = Flask(__name__)

# http://127.0.0.1:5000/
@app.route('/') 
def test():
    return '<h1>Hello Mofo in latin!</h1>'

@app.route('/latin/<name>')
def latin(name):
    if name[len(name) - 1] == 'y':
        name = name.replace(name[len(name) - 1] ,'iful')
    else:
        name += 'y'
    return f"<h1>Hello {name}</h1>"

if __name__ == "__main__":
    app.run(debug=True)  