FROM debian:9.0

RUN apt update && apt -y upgrade && apt -y install openjdk-8-jre-headless screen wget

RUN wget https://launcher.mojang.com/v1/objects/3737db93722a9e39eeada7c27e7aca28b144ffa7/server.jar -O minecraft_server.1.13.jar

RUN java -Xms1024M -Xmx1536M -jar minecraft_server.1.13.jar -o true

RUN sed -i "s/eula/#eula/g" eula.txt && echo "eula=true" >> eula.txt

EXPOSE 25565

CMD java -Xms1024M -Xmx1536M -jar minecraft_server.1.13.jar -o true
