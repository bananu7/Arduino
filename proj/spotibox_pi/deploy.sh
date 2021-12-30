USER=pi
HOST=192.168.1.114
REMOTE=${USER}@${HOST}

rsync -a ./flask/ ${REMOTE}:/var/www/flask
rsync www/uwsgi.ini ${REMOTE}:/etc/uwsgi/apps-enabled/text.ini
rsync www/nginx-site ${REMOTE}:/etc/nginx/sites-enabled/default

