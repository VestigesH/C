#include <stdio.h>
int main()
{
	int choice;
	printf("\n		******�Զ���������ѯϵͳ******\n");
	printf("��ѯ�۸��밴��Ʒǰ�����,��0�˳���ѯ��\n");
	printf("				1.�̲�\n");
	printf("				2.����\n");
	printf("				3.�Ҵ�\n");
	printf("				4.��Ȫˮ\n");
	printf("				5.���׻�\n");
	printf("				6.����\n");
	printf("				0.�˳�\n");
	printf("��Ҫ��ѯ: ");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1:printf("�̲裺4Ԫ/ƿ");break;
		case 2:printf("���֣�3.5Ԫ/ƿ");break;
		case 3:printf("�Ҵ3Ԫ/ƿ");break;
		case 4:printf("��Ȫˮ��1.5Ԫ/ƿ");break;
		case 5:printf("���׻���5Ԫ/Ͱ");break;
		case 6:printf("���ӣ�2.5Ԫ/��");break;
		case 0:return 0;
	}
	printf("\n"); 
}
