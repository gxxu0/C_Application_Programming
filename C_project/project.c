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
	struct shop top_menu[4] = { {"[Covernat] 쿨 코튼 2-PACK 티셔츠", 43000},
										{"[LEE] 빅 트위치 로고 티셔츠", 35000}, 
										{"[thisisneverthat] T-Logo Tee", 39000}, 
										{"[마크 곤잘레스] 엔젤 와펜 반팔 티셔츠", 39000} 
									};
	struct shop pants_menu[4] = { {"[무신사 스탠다드] 테이퍼드 히든 밴딩 크롭 슬랙스", 32900}, 
											{"[후러브스아트] 유니섹스 세미 와이드 밴딩 슬랙스", 54000},	
											{"[나이키] 스우시 반바지", 49000}, 
											{"[아디다스] 로고 트레이닝 팬츠", 54900}
										};
	struct shop outer_menu[4] = { {"[무신사 스탠다드] 베이식 블레이저", 70900},	
											{"[어반디타입] 아노락 쓰리피스 셋업", 69000}, 
											{"[마크 곤잘레스] 엔젤 아노락 자켓", 79000}, 
											{"[토피] 스웻 후드 집업", 45000} 
											};
	struct shop skirt_menu[4] = { {"[아디다스] 아디브레이크 스커트", 79000}, 
											{"[오아이오아이] PLAEATED MINI SKIRT", 79000},	
											{"[더노스페이스] 벅스턴 카고 플레어 스커트", 129000}, 
											{"[팬시클럽] 플라워 패턴 슬릿 롱스커트", 62000} 
										};
	
	int i, select_num, num, sstock, nnum, aa, point, price, p_stock;
	char j=37; char k=92;

	printf("\n   C 응용 쇼핑몰에 오신 것을 환영합니다.\n ( C 응용 쇼핑몰은 중복선택이 안되며, 중복선택을 하기위해 재주문을 해야합니다. ) \n"); 
	
	printf("\n =====품목=====\n\n");
	for(i=0; i<4; i++){
		textcolor(YELLOW, BLACK); 
		printf("  ▷ %s\n",category[i].cate);
	}
	textcolor(WHITE, BLACK); 
	printf("\n ==============\n");
	
	select_num = select_s();
	switch(select_num){
		case 1:
			
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" ▷ %s -  %d\n\n",top_menu[i].name, top_menu[i].price);
			textcolor(WHITE, BLACK); 
			qq(); 
			 num=product();
			printf("\n\n 선택하신 [ %s ] 상품의 재고를 보시겠습니까? ( 예:1, 아니오:2 ) : ",top_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n 재고 : %d개 남았습니다.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//재고명시
			else{
				stock(); break;//재고명시X
			}break;

		case 2: 
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" ▷ %s -  %d\n\n",pants_menu[i].name, pants_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n 선택하신 [ %s ] 상품의 재고를 보시겠습니까? ( 예:1, 아니오:2 ) : ",pants_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n 재고 : %d개 남았습니다.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//재고명시
			else{
				stock(); break;//재고명시X
			}break;

		case 3: 
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" ▷ %s -  %d\n\n",outer_menu[i].name, outer_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n 선택하신 [ %s ] 상품의 재고를 보시겠습니까? ( 예:1, 아니오:2 ) : ",outer_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n 재고 : %d개 남았습니다.\n\n",p_stock); textcolor(WHITE, BLACK); break; }//재고명시
			else{
				stock(); break;//재고명시X
			}break;

		case 4:
			q(); textcolor(YELLOW, BLACK); 
			for(i=0; i<4; i++)
				printf(" ▷ %s -  %d\n\n",skirt_menu[i].name, skirt_menu[i].price);
			textcolor(WHITE, BLACK); qq(); 
			 num=product();
			printf("\n\n 선택하신 [ %s ] 상품의 재고를 보시겠습니까? ( 예:1, 아니오:2 ) : ",skirt_menu[num-1].name); 
			scanf("%d",&sstock);
			if(sstock == 1){
				p_stock=stock();
				textcolor(YELLOW, BLACK);
				printf("\n 재고 : %d개 남았습니다.\n\n",p_stock); 	textcolor(WHITE, BLACK); break; }//재고명시
		
			else{
				stock(); break;//재고명시X
			}break;
		default :
			exit(1);
		}

	if (choose() == 1) //상품 구매
	{
		nnum = number();
		if( nnum > p_stock ) {		//수량>재고
			printf("\n 보유된 재고보다 수량이 많습니다. 수량을 다시 입력하세요 :");
			scanf("%d",&nnum); }
	}
	else //상품구매 X
	{
		printf(" 프로그램을 종료하겠습니다.\n\n");
		exit(0);
	}
	aa=size_i();
	

	if( aa> nnum){
		printf("\n SIZE의 개수를 초과하였습니다. 다시 입력해주세요. \n"); size_i();
	}
	else if( aa < nnum){
		printf("\n SIZE의 개수가 부족합니다. 다시 입력해주세요. \n"); size_i();
	}
	point=c_coupon();
	printf("\n**구매하신 상품의 7%c를 적립합니다. (단, 쿠폰 사용시 적용가격에서 7%c적립)**\n",j,j);
	textcolor(O_YELLOW, BLACK); 
	printf("\n\n\n ====================주문서====================\n\n");
	if(point==1)
	{
		switch(select_num){
			case 1:
				price = top_menu[num-1].price * aa-1000;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",top_menu[num-1].name, aa, price, k, price*0.07,k);
				break;

			case 2: 
				price = pants_menu[num-1].price * aa-1000;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",pants_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 3: 
				price = outer_menu[num-1].price * aa-1000;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",outer_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 4:
				price = skirt_menu[num-1].price * aa-1000;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",skirt_menu[num-1].name, aa,price, k, price*0.07,k);
				break;
		}
	}else {
		switch(select_num){
			case 1:
				price = top_menu[num-1].price * aa;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",top_menu[num-1].name, aa, price, k, price*0.07,k);
				break;

			case 2: 
				price = pants_menu[num-1].price * aa;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",pants_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 3: 
				price = outer_menu[num-1].price * aa;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",outer_menu[num-1].name, aa,price, k, price*0.07,k);
				break;

			case 4:
				price = skirt_menu[num-1].price * aa;
				printf("▷ 상품명 : %s \n▷ 수량 : %d \n▷ 가격 : %d%c\n▷ 적립금 : %.0f%c\n",skirt_menu[num-1].name, aa,price, k, price*0.07,k);
				break;
		}
	
	}
	qq();
	textcolor(WHITE, BLACK); 
	printf("\n\n C응용 쇼핑몰을 이용해주셔서 감사합니다♥\n\n");
	
}

void q()
{
	printf("\n ====================상품=====================\n\n"); }
void qq(){
	printf("\n ==============================================\n"); }

int select_s()
{
	int category_num;
	printf("\n 품목을 선택해주세요. 1~4 (이 외의 상품 선택 시 프로그램 종료) : ");
	scanf("%d",&category_num);

	return category_num;
}

int product()
{
	int number;
	printf("\n 상품을 선택해주세요 1~4 (이 외의 상품 선택 시 프로그램 종료) : ");
	scanf("%d",&number);

	return number;
}

int choose()
{
	int purchase;
	printf("\n 상품을 구매 하시겠습니까? (예 : 1, 아니오 : 2) : ");
		scanf("%d", &purchase);
	return purchase;
}

int number()
{
	int quantity;
	printf("\n 수량을 선택해주세요 : ");
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
	printf("\n SIZE의 개수를 선택해주세요. \n");
	printf(" S size / M size / L size  (ex. 1 1 1) : ");
	scanf("%d %d %d",&s,&m,&l);
	a=s+m+l;
	textcolor(YELLOW, BLACK);
	printf("\n S size %d 개 M size %d 개  L size %d 개, 총 %d개 선택하셨습니다.\n",s,m,l,a);
	textcolor(WHITE, BLACK);
	return a;
}
int c_coupon()
{
	int point;
	char k=92;
	printf("\n\n 쿠폰을 사용하시겠습니까? (예 : 1, 아니오 : 2) : ");
	scanf("%d",&point);
	if(point == 1){
		printf(" ' C응용 쿠폰 ( 1000%c 할인 ) '을 사용합니다. \n\n",k);
	}
	else{
		printf(" 쿠폰을 사용하지 않고 결제합니다.\n");
	}
	return point;
}
void textcolor(int foreground, int background) 
{ 
int color=foreground+background*16; 
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
