.PHONY: build run

build:
	docker build \
		-t sq-lab2 \
		.

run:
	docker run \
		--rm \
		-it \
		-v $(PWD)/beispiele:/app \
		sq-lab2 \
		bash
