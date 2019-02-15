FROM ubuntu:latest

RUN apt install apache2 mysql-server php7.2 libapache2-mod-php7.2 php-mysql
RUN service apache2 start
RUN service mysql start

COPY client /
RUN /client localhost 12345
