
ALL:build up

.PHONY:build
build:
	docker compose -f ./srcs/docker-compose.yaml build 

.PHONY:up
up:
	docker compose -f ./srcs/docker-compose.yaml  up --timeout 3

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
