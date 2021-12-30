
from plcd import *

from flask import request, Flask, send_file
app = Flask(__name__)

@app.route("/")
def ix():
    #return "ok"
    return send_file('index.html')

@app.route("/text", methods=['GET'])
def text():
    t = request.args.get('t', default='', type=str)
    lcd_init()
    lcd_string(t[0:20], LCD_LINE_1)
    lcd_string(t[20:40], LCD_LINE_2)
    lcd_string(t[40:60], LCD_LINE_3)
    return "ok"

if __name__== '__main__':
    app.run()
