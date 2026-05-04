g++ main.cpp -o main
./main 
run in terminal on vscode(BLue)

# Docker

# build
docker build -t phonebook-app .

# run
docker run -it phonebook-app

# rebuild after changing code
docker build -t phonebook-app .
docker run -it phonebook-app

# list containers
docker ps -a

# view logs
docker logs <container_id>

# remove container
docker rm <container_id>
