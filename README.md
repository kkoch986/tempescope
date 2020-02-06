# tempescope

## Getting Started

Start by making sure you have 
[platformio core](https://docs.platformio.org/en/latest/installation.html) installed.

If you are not using the 
[esp32 devkit board](https://docs.zerynth.com/latest/official/board.zerynth.doit_esp32/docs/index.html) 
you may need to modify `platformio.ini` to reflect the correct environment. 
You can create new envs by tagging the config, for example:

```
[env:arduino]
platform = espressif32
board = esp32doit-devkit-v1
framework = arduino
```

Then when compiling add the `--env arduino` flag to the `pio` command.

There is a Makefile for the basic configuration, you can refer there for the basic commands.

To compile run:

```
make
```

To compile and upload:

```
make upload
```

To drop into the Serial Monitor for the connected board:

```
make logs
```

## Links

* [esp32 board](https://circuits4you.com/2018/12/31/esp32-devkit-esp32-wroom-gpio-pinout/)
