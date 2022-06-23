
ALL:build up

.PHONY:build
build:
	docker compose -f ./srcs/docker-compose.yaml build 

.PHONY:up
up:
	docker compose -f ./srcs/docker-compose.yaml up

.PHONY:prune
prune:
	docker system  prune

.PHONY:review
review:
	docker stop `docker ps -qa`;
	docker rm `docker ps -qa`;
	docker rmi -f `docker images -qa`;
	docker volume rm `docker volume ls -q`;
	docker network rm `docker network ls -q` 2>/dev/null

.PHONY: setup
setup:
	sudo mkdir -p /home/takkatao/data/mysql
	sudo mkdir -p /home/takkatao/data/wordpress
	grep '127.0.0.1 takkatao.42.fr' /etc/hosts > /dev/null || sudo -- sh -c "echo '127.0.0.1 takkatao.42.fr' >> /etc/hosts"


.PHONY: clean
clean: 
	- sudo rm -rf /home/takkatao
	- grep '127.0.0.1 takkatao.42.fr' /etc/hosts > /dev/null && sudo -- sh -c "sed -i /'127.0.0.1 takkatao.42.fr'/d /etc/hosts"
	- docker volume rm srcs_mariadb_volume srcs_wordpress_volume
	- docker image rm mariadb:inception nginx:inception wordpress:inception
