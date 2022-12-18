FROM		alpine:3.16

RUN			apk update -y
RUN			apk upgrade -y
RUN			apk -y add \
			mariadb-server \
			mariadb-client
RUN			apk add dumb-init -y
RUN			chmod +x /usr/bin/dumb-init

COPY		./tools/mariadb.sh /tmp/mariadb.sh
COPY		./conf/mariadb.conf /etc/mysql/mariadb.conf.d/

EXPOSE		3306

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD			["sh", "/tmp/mariadb.sh"]
