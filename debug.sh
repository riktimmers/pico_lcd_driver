openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" 

# gdb name.elf 
# target remote localhost:3333
# monitor reset init 
# load 
# continue
