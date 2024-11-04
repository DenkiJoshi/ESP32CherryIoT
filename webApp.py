from flask import Flask, render_template, request, jsonify
import os
import shutil
import threading
import time

app = Flask(__name__)

# 監視中のファイルパス
watched_file_path = None
# ファイル内容のキャッシュ
file_content_cache = []

def get_last_10_lines(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            lines = file.readlines()
            return lines[-15:]
    except:
        return []

def watch_file():
    global file_content_cache
    while True:
        if watched_file_path and os.path.exists(watched_file_path):
            file_content_cache = get_last_10_lines(watched_file_path)
        time.sleep(1)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/upload', methods=['POST'])
def upload_file():
    global watched_file_path
    file = request.files['file']
    upload_folder = 'uploads'
    os.makedirs(upload_folder, exist_ok=True)
    watched_file_path = os.path.join(upload_folder, file.filename)
    file.save(watched_file_path)
    return jsonify(success=True)

@app.route('/update', methods=['GET'])
def update_file():
    return jsonify(file_content_cache)

if __name__ == '__main__':
    threading.Thread(target=watch_file, daemon=True).start()
    app.run(debug=True)

