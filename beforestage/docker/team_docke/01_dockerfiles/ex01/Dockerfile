FROM debian:9.3

RUN apt-get update && apt-get -y upgrade && apt -y install wget && apt-get -y install bzip2

RUN wget https://files.teamspeak-services.com/releases/server/3.6.1/teamspeak3-server_linux_amd64-3.6.1.tar.bz2 \
    && tar -xf teamspeak3-server_linux_amd64-3.6.1.tar.bz2

ENV TS3SERVER_LICENSE=accept

EXPOSE 9987/udp 10011 30033 41144

CMD /teamspeak3-server_linux_amd64/ts3server_minimal_runscript.sh start

# docker build -t teamspook .
# docker run -p 9987:9987/udp -p 10011:10011 -p 30033:30033 -p 41144:41144 -d teamspook
