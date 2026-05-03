
FROM gcc:latest


WORKDIR /usr/src/phonebook


COPY . .


RUN g++ -o phonebook main.cpp

CMD ["./phonebook"]
