#define BLACK 0 
#define O_YELLOW  6
#define YELLOW 14 
#define WHITE 15 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <windows.h>

struct item
{
	char cate[20];
};
struct shop
{
	char name[100];
	int price;
};
void q();
void qq();
int select_s();
int product(); 
int choose();
int number();
int stock(); 
int size_i(); 
int c_coupon();
void textcolor(int foreground, int background); 
void main()
{
	struct cate *ptr1=NULL;
	struct item category[4] = { {"top"}, {"pants"},{"outer"},{"skirt"} };
	struct shop *ptr=NULL;
	struct shop top_menu[4] = { {"[Covernat] �� ��ư 2-PACK Ƽ����", 43000},
										{"[LEE] �� Ʈ��ġ �ΰ� Ƽ����", 35000}, 
										{"[thisisneverthat] T-Logo Tee", 39000}, 
										{"[��ũ ���߷���] ���� ���� ���� Ƽ����", 39000} 
									};
	struct shop pants_menu[4] = { {"[���Ż� ���Ĵٵ�] �����۵� ���� ��� ũ�� ������", 32900}, 
											{"[�ķ��꽺��Ʈ] ���ϼ��� ���� ���̵� ��� ������", 54000},	
											{"[����Ű] ����� �ݹ���", 49000}, 
											{"[�Ƶ�ٽ�] �ΰ� Ʈ���̴� ����", 54900}
										};
	struct shop outer_menu[4] = { {"[���Ż� ���Ĵٵ�] ���̽� ������", 70900},	
											{"[��ݵ�Ÿ��] �Ƴ�� �����ǽ� �¾�", 69000}, 
											{"[��ũ ���߷���] ���� �Ƴ�� ����", 79000}, 
											{"[����] ���� �ĵ� ����", 45000} 
											};
	struct shop skirt_menu[4] = { {"[�Ƶ�ٽ�] �Ƶ�극��ũ ��ĿƮ", 79000}, 
											{"[�����̿�����] PLAEATED MINI SKIRT", 79000},	
											{"[���뽺���̽�] ������ ī�� �÷��� ��ĿƮ", 129000}, 
											{"[�ҽ�Ŭ��] �ö�� ���� ���� �ս�ĿƮ", 62000} 
										};
	
	int i, select_num, num, sstock, nnum, aa, point, price, p_stock;
	char j=37; char k=92;

	printf("\n   C ���� ���θ��� ���� ���� ȯ���մϴ�.\n ( C ���� ���θ��� �ߺ������� �ȵǸ�, �ߺ������� �ϱ����� ���ֹ��� �ؾ��մϴ�. ) \n"); 
	
	printf("\n =====ǰ��=====\n\n");
	for(i=0; i<4; i++){
		textcolor(YELLOW, BLACK); 
		printf("  �� %s\n",category[i].cate);
	}
	textcolor(WHITE, BLACK); 
	printf("\n ==============\n");
	
	select_num = select_s();
	switch(select_num){
		case 1:
			
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" �� %s -  %d\n\n",top_menu[i].name, top_menu[i].price);
			textcolor(WHITE, BLACK); 
			qq(); 
			 num=product();
			printf("\n\n �����Ͻ� [ %s ] ��ǰ�� ��� ���ðڽ��ϱ�? ( ��:1, �ƴϿ�:2 ) : ",top_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n ��� : %d�� ���ҽ��ϴ�.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//�����
			else{
				stock(); break;//�����X
			}break;

		case 2: 
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" �� %s -  %d\n\n",pants_menu[i].name, pants_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n �����Ͻ� [ %s ] ��ǰ�� ��� ���ðڽ��ϱ�? ( ��:1, �ƴϿ�:2 ) : ",pants_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n ��� : %d�� ���ҽ��ϴ�.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//�����
			else{
				stock(); break;//�����X
			}break;

		case 3: 
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" �� %s -  %d\n\n",outer_menu[i].name, outer_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n �����Ͻ� [ %s ] ��ǰ�� ��� ���ðڽ��ϱ�? ( ��:1, �ƴϿ�:2 ) : ",outer_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n ��� : %d�� ���ҽ��ϴ�.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//�����
			else{
				stock(); break;//�����X
			}break;

		case 4:
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" �� %s -  %d\n\n",skirt_menu[i].name, skirt_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n �����Ͻ� [ %s ] ��ǰ�� ��� ���ðڽ��ϱ�? ( ��:1, �ƴϿ�:2 ) : ",skirt_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n ��� : %d�� ���ҽ��ϴ�.\n\n",p_stock); 	textcolor(WHITE, BLACK); break; }//�����
		
			else{
				stock(); break;//�����X
			}break;
		default :
			exit(1);
		}

	if (choose() == 1) //��ǰ ����
	{
		nnum = number();
		if( nnum > p_stock ) {		//����>���
			printf("\n ������ ����� ������ �����ϴ�. ������ �ٽ� �Է��ϼ��� :");
			scanf("%d",&nnum); }
	}
	else //��ǰ���� X
	{
		printf(" ���α׷��� �����ϰڽ��ϴ�.\n\n");
		exit(0);
	}
	aa=size_i();
	

	if( aa> nnum){
		printf("\n SIZE�� ������ �ʰ��Ͽ����ϴ�. �ٽ� �Է����ּ���. \n"); size_i();
	}
	else if( aa < nnum){
		printf("\n SIZE�� ������ �����մϴ�. �ٽ� �Է����ּ���. \n"); size_i();
	}
	point=c_coupon();
	printf("\n**�����Ͻ� ��ǰ�� 7%c�� �����մϴ�. (��, ���� ���� ���밡�ݿ��� 7%c����)**\n",j,j);
	textcolor(O_YELLOW, BLACK); 
	printf("\n\n\n ====================�ֹ���====================\n\n");
	if(point==1)
	{
		switch(select_num){
			case 1:
				price = top_menu[num-1].price * aa-1000;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",top_menu[num-1].name, aa, price, k, price*0.07,k);
				break;

			case 2: 
				price = pants_menu[num-1].price * aa-1000;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",pants_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 3: 
				price = outer_menu[num-1].price * aa-1000;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",outer_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 4:
				price = skirt_menu[num-1].price * aa-1000;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",skirt_menu[num-1].name, aa,price, k, price*0.07,k);
				break;
		}
	}else {
		switch(select_num){
			case 1:
				price = top_menu[num-1].price * aa;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",top_menu[num-1].name, aa, price, k, price*0.07,k);
				break;

			case 2: 
				price = pants_menu[num-1].price * aa;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",pants_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 3: 
				price = outer_menu[num-1].price * aa;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",outer_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 4:
				price = skirt_menu[num-1].price * aa;
				printf("�� ��ǰ�� : %s \n�� ���� : %d \n�� ���� : %d%c\n�� ������ : %.0f%c\n",skirt_menu[num-1].name, aa,price, k, price*0.07,k);
				break;
		}
	
	}
	qq();
	textcolor(WHITE, BLACK); 
	printf("\n\n C���� ���θ��� �̿����ּż� �����մϴ٢�\n\n");
	
}

void q()
{
	printf("\n ====================��ǰ=====================\n\n"); }
void qq(){
	printf("\n ==============================================\n"); }

int select_s()
{
	int category_num;
	printf("\n ǰ���� �������ּ���. 1~4 (�� ���� ��ǰ ���� �� ���α׷� ����) : ");
	scanf("%d",&category_num);

	return category_num;
}

int product()
{
	int number;
	printf("\n ��ǰ�� �������ּ��� 1~4 (�� ���� ��ǰ ���� �� ���α׷� ����) : ");
	scanf("%d",&number);

	return number;
}

int choose()
{
	int purchase;
	printf("\n ��ǰ�� ���� �Ͻðڽ��ϱ�? (�� : 1, �ƴϿ� : 2) : ");
		scanf("%d", &purchase);
	return purchase;
}

int number()
{
	int quantity;
	printf("\n ������ �������ּ��� : ");
	scanf("%d",&quantity);
	return quantity;
}


int stock() {
	int i;
	srand( (unsigned int) time(NULL));
	i=rand()%1000+1;
	return i; }

int size_i()
{
	int s,m,l, a;
	printf("\n ====== SIZE ====== \n\n 1 : S SIZE \n 2 : M SIZE \n 3 : L SIZE\n\n ==================\n");
	printf("\n SIZE�� ������ �������ּ���. \n");
	printf(" S size / M size / L size  (ex. 1 1 1) : ");
	scanf("%d %d %d",&s,&m,&l);
	a=s+m+l;
	textcolor(YELLOW, BLACK);
	printf("\n S size %d �� M size %d ��  L size %d ��, �� %d�� �����ϼ̽��ϴ�.\n",s,m,l,a);
	textcolor(WHITE, BLACK);
	return a;
}
int c_coupon()
{
	int point;
	char k=92;
	printf("\n\n ������ ����Ͻðڽ��ϱ�? (�� : 1, �ƴϿ� : 2) : ");
	scanf("%d",&point);
	if(point == 1){
		printf(" ' C���� ���� ( 1000%c ���� ) '�� ����մϴ�. \n\n",k);
	}
	else{
		printf(" ������ ������� �ʰ� �����մϴ�.\n");
	}
	return point;
}
void textcolor(int foreground, int background) 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
