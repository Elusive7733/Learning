import sqlite3
import json

conn = sqlite3.connect('rosterdb.sqlite')
cur = conn.cursor()

# Do some setup
cur.executescript('''
DROP TABLE IF EXISTS User;
DROP TABLE IF EXISTS Member;
DROP TABLE IF EXISTS Course;

CREATE TABLE User (
    id     INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    name   TEXT UNIQUE
);

CREATE TABLE Course (
    id     INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,
    title  TEXT UNIQUE
);

CREATE TABLE Member (
    user_id     INTEGER,
    course_id   INTEGER,
    role        INTEGER,
    PRIMARY KEY (user_id, course_id)
)
''')

fname = 'roster_data.json'
fh = open(fname)
data = json.loads(fh.read())

for item in data:
    name = item[0]
    title = item[1]
    role = item[2]

    cur.execute('''INSERT OR IGNORE INTO User (name) 
        VALUES ( ? )''', (name,) )
    cur.execute('SELECT id FROM User WHERE name = ? ', (name,))
    user_id = cur.fetchone()[0]

    cur.execute('''INSERT OR IGNORE INTO Course (title) 
        VALUES ( ? )''', (title,) )
    cur.execute('SELECT id FROM Course WHERE title = ? ', (title,))
    course_id = cur.fetchone()[0]

    # cur.execute('''INSERT OR IGNORE INTO Member (role) 
    #     VALUES ( ? )''', (role,) )
    # cur.execute('SELECT id FROM Member WHERE role = ? ', (role,))
    # course_id = cur.fetchone()[0]

    cur.execute('''INSERT OR REPLACE INTO Member
    (user_id, course_id, role) VALUES ( ?, ?, ? )''',
    ( user_id, course_id, role) )

conn.commit()