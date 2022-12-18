FROM		alpine:3.16

RUN			apk update -y
RUN			apk upgrade -y
RUN			apk add -y \
			mariadb-client \
			wget \
			curl \
			tar \
			php7.3-fpm \
			php-cli \
			php-mysql \
			vim \
			sudo
RUN			apk add dumb-init -y
RUN			chmod +x /usr/bin/dumb-init

COPY		./tools/wordpress.sh /tmp/wordpress.sh
COPY		./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
RUN			wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
			chmod +x wp-cli.phar && \
			mv wp-cli.phar /usr/bin/wp

WORKDIR		/var/www/html/wordpress
RUN			mkdir -p /run/php

EXPOSE		9000

ENTRYPOINT	["/usr/bin/dumb-init", "--"]

CMD			["sh", "/tmp/wordpress.sh"]
