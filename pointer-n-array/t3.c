#include <stdio.h>
struct file_operations
{
	void (*write)(char *str);
	void (*print)(char *str);
};
void my_write(char *str)
{
	printf("%s: %s\n",__func__,str);
};
void my_print(char *str)
{
	printf("%s: %s\n",__func__,str);
};
struct file_operations demo_ops = 
{
	.write = my_write,
	.print = my_print,
};
int main()
{
	demo_ops.write("abc");
	demo_ops.print("abc");
	return 0;
}
