FROM		alpine:3.16

RUN			apk update && \
			apk add nginx openssl && \
			apt install dumb-init && \
			chmod +x /usr/bin/dumb-init && \


COPY		conf/nginx.conf /etc/nginx/nginx.conf
			tools/script.sh /tmp/script.sh

RUN			chmod +x /tmp/script.sh

EXPOSE		443

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD			["nginx", "-g", "daemon off;"]
