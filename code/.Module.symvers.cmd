cmd_/home/hlafi98/kernel_programming/Module.symvers := sed 's/ko$$/o/' /home/hlafi98/kernel_programming/modules.order | scripts/mod/modpost  -a   -o /home/hlafi98/kernel_programming/Module.symvers -e -i Module.symvers   -T -