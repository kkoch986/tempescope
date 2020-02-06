PIO=${HOME}/.local/bin/pio

compile: 
	${PIO} run

upload: 
	${PIO} run --target=upload

logs: 
	${PIO} device monitor -b 115200

.PHONY: compile upload logs