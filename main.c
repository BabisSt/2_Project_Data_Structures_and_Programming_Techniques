/* Stevis Charalampos-Antonios AM:1115201600278 main.c */

#include <stdio.h>
#include <stdlib.h>

#include "Session.h"



int main(void) {
	InfoSessionPtr 	MySession1=NULL, MySession2=NULL;
	int epilogh = 100;
	char address[100];

	while (epilogh != 0){
		printf("Epelekse mia apo tis parakatw energies: \n");
		printf(" 1 : SessionNew \n 2 : SessionNewTab \n 3 : SessionTabShow \n 4 : SessionTabNext \n 5 : SessionTabPrev\n 6 : SessionTabMoveLeft \n 7 : SessionTabMoveRight \n 8 : SessionNewOpeningAddress \n 9 : SessionShowOpeningAddress \n 10 : SessionSiteNext \n 11 : SessionSitePrev \n 12 : SessionSiteShow \n 13 : SessionTabClose \n 14 : SessionClose\n 15 : SessionNewAddress \n 0 : Quit \n");
		scanf("%d",&epilogh);

		switch(epilogh){

			case 1 :
				printf("Dwse Opening Address \n");
				scanf("%c",address);
				SessionNew(address);
				break;
			case 2 :
				SessionNewTab(MySession1);
				break;
			case 3 :
				SessionTabShow(MySession1);
				break;
			case 4 :
				SessionTabNext(MySession1);
				break;
			case 5 :
				SessionTabPrev(MySession1);
				break;
			case 6 :
				SessionTabMoveLeft(MySession1);
				break;
			case 7 :
				SessionTabMoveRight(MySession1);
				break;
			case 8 :
				printf("Dwse nea OpeningAddress \n");
				scanf("%c",address);
				SessionNewOpeningAddress(address,MySession1);
				break;
			case 9 :
				SessionShowOpeningAddress(MySession1);
				break;
			case 10:
				SessionSiteNext(MySession1);
				break;
			case 11:
				SessionSitePrev(MySession1);
				break;
			case 12:
				SessionSiteShow(MySession1);
				break;
			case 13:
				SessionTabClose(MySession1);
				break;
			case 14:
				SessionClose(MySession1);
				break;
			case 15:
				printf("Dwse address \n");
				scanf("%c",address);
				SessionNewAddress(address,MySession1);
				break;
		}
	}

	return 0;
}
