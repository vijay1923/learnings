#include <linux/fs.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>	//copy_from_user

ssize_t my_read(struct file *f, char __user *ubuf, size_t s, loff_t *l){
	printk("my_read invoked\n");
	return 0;
}

ssize_t my_write (struct file *f, const char __user *ubuf, size_t s, loff_t *l){
	char kbuf[50];
	
	printk("my_write invoked\n");

	if(copy_from_user(kbuf, ubuf, sizeof(kbuf))){
		printk("err: copy_from_user\n");
		return -EFAULT;
	}

	printk("string from user space---> %s\n",kbuf);

	return 0;
}


int my_open (struct inode *i, struct file *f){
	printk("my_open invoked\n");
	return 0;
}


int my_release (struct inode *i, struct file *f){
	printk("my_release invoked\n");
	return 0;
}




int major;
struct file_operations fops={
 .open=my_open,
 .release=my_release,
 .write=my_write,
 .read=my_read
};

int char_init(void){
	major=register_chrdev(0, "VECTOR", &fops);		
	if(major < 0){
	  printk("Error: register_chrdev\n");
  	  return major;	  
	}
	
	printk("MAJOR= %d\n",major);
	printk("your driver is registered sucessfully\n");
	return 0;
}


void char_exit(void){
	unregister_chrdev(major, "VECTOR");
	printk("your driver is unregistered sucessfully\n");
}

module_init(char_init);
module_exit(char_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("pramod@vectorindia.org");
MODULE_DESCRIPTION("simple character device driver");

