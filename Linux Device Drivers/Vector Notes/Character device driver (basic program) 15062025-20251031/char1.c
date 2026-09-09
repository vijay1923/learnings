#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>  


int major;
struct file_operations fops;

int char_init(void)
{
	major=register_chrdev(0, "VECTOR", &fops);		
	if(major < 0)
	{
	  printk("Error: register_chrdev\n");
  	  return major;	  
	}
	
	printk("MAJOR= %d\n",major);
	printk("your driver is registered sucessfully\n");
	return 0;
}


void char_exit(void)
{
	unregister_chrdev(major, "VECTOR");
	printk("your driver is unregistered sucessfully\n");
}

module_init(char_init);
module_exit(char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pramod@vectorindia.org");
MODULE_DESCRIPTION("simple character device driver");

