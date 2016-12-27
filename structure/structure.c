#include <stdio.h>
#include <stdlib.h>

/*
 * In kernel there is ".read = read_function", 
 * maybe I have never seen the pattern like this,
 * it's function pointer's feature.
 *
 * */
struct file_operations
{
	int (*write)(char *str);
	int (*print)(char *str);
};

int my_write(char *str)
{
	printf("%s: %s\n", __func__, str);
	//printf("%s\n",str);
	return 0;
}

int my_print(char *str)
{
	printf("%s: %s\n", __func__, str);
	//printf("%s\n",str);
	return 0;
}

/*struct file_operations demo_ops = 
{
	.write = my_write;
	.print = my_print;
};*/

struct file_operations demo_ops = 
{
	my_write,
	my_print,
};

int main()
{
	int *a;
	a=(int *)malloc(sizeof(int));
	*a=1;
	*(a+1)=2;
	printf("%p\n",a);
	printf("%p\n",a+1);
	/*struct file_operations demo_ops;
	demo_ops.write=my_write;
	demo_ops.print=my_print;*/
	demo_ops.write("abc");
	demo_ops.print("abc");
	return 0;
}
