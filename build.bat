@echo off

arm-none-eabi-gcc -c src\main.c -mthumb-interwork -mthumb -O2 -o main.o
arm-none-eabi-gcc main.o -mthumb-interwork -mthumb -specs=gba.specs -o main.elf
arm-none-eabi-objcopy -v -O binary main.elf main.gba

rm main.o
rm main.elf
