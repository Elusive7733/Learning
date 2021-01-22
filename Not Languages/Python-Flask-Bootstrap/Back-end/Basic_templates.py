from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('home.html')

@app.route('/signup')
def signup():
    return render_template('signup.html')

@app.route('/checkout')
def checkout():
    U_flag = False
    L_flag = False
    Num_flag = False
    fname = request.args.get('fname')
    lname = request.args.get('lname')
    uname = request.args.get('uname')
    em = request.args.get('em')
    pw = request.args.get('pw')
    pnum = request.args.get('pnum')
    for letter in uname:
        if letter.isupper():
            U_flag = True
        elif letter.isnumeric() == False:
            L_flag = True

    if uname[-1].isnumeric():
        Num_flag = True
                
    return render_template('checkout.html', fname=fname, lname=lname, uname=uname, em=em, pw=pw, pnum=pnum, U_flag=U_flag, L_flag=L_flag, Num_flag=Num_flag)

if __name__ == '__main__':
    app.run(debug = True)
    