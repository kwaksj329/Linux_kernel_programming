syscall 실행을 위해

1. src/linux-5.15.4/ 위치에 my_prime 폴더를 복사해주세요.

2. kernel Makefile 에서 core-y += kernel/ ... 에 my_prime/ 을 추가해주세요.

3. syscall_64.tbl에 549	64	my_prime	sys_my_prime 을 추가해주세요. 

4. syscalls.h 에 asmlinkage long sys_my_prime(void); 를 추가해주세요.

5. src/linux-5.15.4 에서 make -j$(nrpoc) 실행 후 VM에서 ./prime_sys_test -n 100000 과 같이 실행




