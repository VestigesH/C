//某公司要将员工按年龄分配职务，22~30岁担任外勤业务员，31~45岁担任内勤文员，45~55岁担任仓库管理员，56岁以上退休。请编程实现。
#include <stdio.h>
int main()
{
	int age;
	printf("请输入年龄：");
	scanf("%d",&age);
	if(age >= 22 && age <= 30)
	{
		printf("您的职务是外勤业务员！");	
	} 
	else if(age >= 31 && age <= 45)
	{
		printf("您的职务是内勤文员！"); 
	}
	else if(age >= 45 && age <= 55)
	{
		printf("您的职务是仓库管理员！");
	}
	else if(age >=56)
	{
		printf("退休"); 
	}
	else 
	{
		printf("该年龄不在分配职务年龄范围！");
	}
	return 0;
} 
