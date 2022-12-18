FROM		alpine:3.16

RUN			apk update -y
RUN			apk upgrade -y
RUN			apk add nginx openssl -y
RUN			apk add dumb-init -y
RUN			chmod +x /usr/bin/dumb-init


COPY		conf/nginx.conf /etc/nginx/nginx.conf
			tools/script.sh /tmp/script.sh

RUN			chmod +x /tmp/script.sh

EXPOSE		443

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD			["nginx", "-g", "daemon off;"]
