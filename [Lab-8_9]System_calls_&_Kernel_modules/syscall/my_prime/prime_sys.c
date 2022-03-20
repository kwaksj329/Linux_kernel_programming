#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/random.h>
#include <linux/slab.h>

SYSCALL_DEFINE1(my_prime, const int __user*, num)
{
	unsigned int *arr;
	int i, j, flag, knum; 
	int n = 0;
	int answer = 0;

	copy_from_user(&knum, num, sizeof(int));

	arr = (unsigned int*)kmalloc(sizeof(unsigned int) * knum, GFP_KERNEL);

	printk(KERN_INFO "The number of total random numbers: %d\n", knum);

	get_random_bytes(arr, sizeof(unsigned int) * knum);

	for(i = 0 ; i < knum ; i++){
		//get_random_bytes(&n, sizeof(int) - 1);
		arr[i] = arr[i] % (knum-1) + 2;
		//printk(KERN_INFO "n: %d\n", arr[i]);
	}

	for(i = 0; i < knum ; i++){
		
		flag = 1;

		if(arr[i] != 2 && arr[i] % 2 == 0){  
			flag = 0;
			continue;
		}

		for(j = 3; j * j <= arr[i]; j+=2){
    			if(arr[i] % j ==0){
				flag = 0;
				break;
			}
		}

		if(flag == 1) answer++;
	}
	
	kfree(arr);
	return answer;
}
