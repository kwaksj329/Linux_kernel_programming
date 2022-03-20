#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/random.h>
#include <linux/slab.h>
#include <linux/ktime.h>

static int n = 0;
module_param(n, int, 0);
MODULE_PARM_DESC(n, "number of total random numbers");

static int __init lkp_init(void)
{
	struct timespec64 start, end;
        long time;
	unsigned int *arr;
        int i, j, flag, knum;
	int answer = 0;
 
	ktime_get_ts64(&start);

	knum = n;
	printk(KERN_INFO "The number of total random numbers: %d \n", knum);

        arr = (unsigned int*)kmalloc(sizeof(unsigned int) * knum, GFP_KERNEL);

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

	printk(KERN_INFO "The number of prime number: %d\n", answer);
        kfree(arr);	

	ktime_get_ts64(&end);
	time = 1000000 * (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec)/1000;
        printk("Processing time: %ld us \n", time);

	return 0;
}

static void __exit lkp_exit(void)
{
	printk(KERN_INFO "Module exiting ... \n");
}

module_init(lkp_init);
module_exit(lkp_exit);
MODULE_LICENSE("GPL");
