PIO=${HOME}/.local/bin/pio
ENVSTR=
ifdef PIOENV
	ENVSTR="-e"${PIOENV}
endif

compile: 
	${PIO} run

upload: 
	${PIO} run --target=upload ${ENVSTR}

logs: 
	${PIO} device monitor -b 115200

.PHONY: compile upload logs