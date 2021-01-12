download: blink.ihx
	stm8flash -c stlinkv3 -p stm8s208cb -w blink.ihx

blink.ihx: blink.c
	sdcc -mstm8 --std-c99 blink.c

