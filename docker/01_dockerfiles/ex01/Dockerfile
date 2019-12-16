FROM debian:8
WORKDIR /home/ts3
RUN apt-get update && apt-get install -y bzip2 wget nano
RUN adduser --disabled-login teamspeak; exit 0
RUN su teamspeak
RUN wget http://dl.4players.de/ts/releases/3.1.1/teamspeak3-server_linux_amd64-3.1.1.tar.bz2
RUN tar xvf teamspeak3-server_linux_amd64-3.1.1.tar.bz2
RUN rm teamspeak3-server_linux_amd64-3.1.1.tar.bz2
RUN cd teamspeak3-server_linux_amd64
RUN touch .ts3server_license_accepted
ENTRYPOINT ["sh", "ts3server_startscript.sh", "start"]
