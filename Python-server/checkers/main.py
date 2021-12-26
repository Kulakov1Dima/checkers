from flask import Flask, request

app = Flask(__name__)


@app.route('/', methods=['POST'])

def respond():
    data = request.json
    command = data.get('request', {}).get('command', '')

    if command:
        response_text = 'Ненавижу Python!'
    else: 
        response_text = 'Привет'

    response = {
        'response': {
            'text': response_text,
        },
        'version': '1.0'
    }
    return response

