
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
