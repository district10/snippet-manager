all: docker

docker:
	@echo make dockerbuild
	@echo make dockerrun

dockerbuild:
	docker build -t snippet_manager .

dockerrun:
	docker run -it snippet_manager sh

.PHONY: docker dockerbuild dockerrun
