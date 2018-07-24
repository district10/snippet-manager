all: try

docker:
	@echo make dockerbuild
	@echo make dockerrun

build: dockerbuild
dockerbuild:
	docker build -t snippet_manager .

run: dockerrun
dockerrun:
	docker run -it snippet_manager zsh

try: dockerbuild dockerrun


.PHONY: docker dockerbuild dockerrun try
