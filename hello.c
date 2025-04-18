#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

int myint = 7;
module_param(myint,int,0);
MODULE_PARM_DESC(myint, "An Integer");
static int __init hello_init(void) {
	printk(KERN_INFO "Hello, myint = %d\n", myint);
	return 0;
}

static void __exit hello_exit(void){
	printk(KERN_INFO "Goodbye, myint = %d\n", myint);
}
module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");


