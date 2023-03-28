# stm32f103 blink period change
## Main case
find variable address ```static unsigned long my_array_[1];``` in [map file](openocd_stm_blink/bin_files/sketch_mar5a.ino.map) 

```
 .bss._ZL9my_array_
                0x0000000020000484        0x4 /tmp/arduino/sketches/BDAA1909B2769F757400EDF4F6E727D0/sketch/sketch_mar5a.ino.cpp.o
```
readme for [openocd_test](openocd_stm_blink/OpenOCD_test/README.md)\
after it change in cycle blinking period [test_openocd.py](openocd_stm_blink/OpenOCD_test/test_openocd.py)

```oocd.write_memory(0x0000000020000484, [i], 32)```
## flash binary data
```
openocd  -s share/openocd -f interface/stlink-v2.cfg -f target/cs32f1x.cfg -c "program <path/filename.bin> exit 0x08000000"
```