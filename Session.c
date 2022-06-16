/* Stevis Charalampos-Antonios AM:1115201600278 Session.c */

#include <stdlib.h>
#include "Session.h"
#include <string.h>
#include <stdio.h>
typedef struct TabNode *TabNodePtr;
typedef struct SiteNode *SiteNodePtr;


struct InfoSession {
	TabNodePtr FirstTab;	//deiktis ston prwto komvo ths listas
	TabNodePtr LastTab;	//deiktis ston teleutaio komvo ths listas
	TabNodePtr CurrTab;	//deiktis ston trexon komvo ths listas
	TabNodePtr AuxTab;	//deiktis gia pithanes metakinhseis
	char *OpeningAddress;	//default address
};

struct TabNode {		//dipla kuklikh sundedemenh lista
	TabNodePtr PrevTab, NextTab;	//deiktes stous prev/next komvous
	SiteNodePtr FirstSite;	//deikths sto prwto kombo tou tab
	SiteNodePtr CurrSite;	//deikthts ston trexon komvo tou tab
};

struct SiteNode{		//dipla sundedemenh lista
	SiteNodePtr PrevSite, NextSite;	//deiktes gia prev/next site
	TabNodePtr UpTab;	//deikthss gia komvo tab
	char *Address;		//dieuthinsh site
};


InfoSessionPtr SessionNew(char *OpeningAddress){		//Dimiourgia Neou Session

	InfoSessionPtr infoSession;				//komvos session me malloc
	infoSession = malloc(sizeof(InfoSessionPtr));

	TabNodePtr tabNode;					//komvos tab me malloc
	tabNode = malloc(sizeof(TabNodePtr));

	SiteNodePtr siteNode;					//komvos site me malloc
	siteNode = malloc(sizeof(SiteNodePtr));

	infoSession->FirstTab = tabNode;			//Arxikopoihsh melwn tou Session
	infoSession->LastTab = tabNode;
	infoSession->CurrTab = tabNode;
	infoSession->AuxTab = NULL;

	tabNode->PrevTab = NULL;				//Arxikopoihsh melwn tou Tab
	tabNode->NextTab = NULL;
	tabNode->FirstSite = siteNode;
	tabNode->CurrSite = siteNode;

	siteNode->PrevSite = NULL;				//Arxikopoihsh melwn tou Site
	siteNode->NextSite = NULL;
	siteNode->UpTab = tabNode;

	infoSession->OpeningAddress = siteNode->Address;	//Perasma tou OpeningAddress sto Address tou Site

	return infoSession;					//Epistrofh tou Address
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionNewTab(InfoSessionPtr Session){			//Dhmiourgia Neou Tab

	TabNodePtr newtabNode;
	SiteNodePtr newsiteNode;

	Session->LastTab = newtabNode;				//Thetei neo komvo tab sto telos ths listas kai anoigei ena site
	Session->CurrTab = newtabNode;
	newsiteNode->PrevSite = NULL;
	newsiteNode->NextSite = NULL;
	newsiteNode->UpTab = newtabNode;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionTabShow(InfoSessionPtr Session){			//Emfanizei ta dedomena tou CurrSite

	printf("%s" ,Session->CurrTab->CurrSite->Address);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionTabNext(InfoSessionPtr Session){			//Allagh tou CurrTab ston epomeno
	TabNodePtr prosorinos;
	prosorinos = Session->CurrTab;
	Session->CurrTab = prosorinos->NextTab;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionTabPrev(InfoSessionPtr Session){			//Allagh tou CurrTab ston prohgoumeno
	TabNodePtr prosorinos;
	prosorinos = Session->CurrTab;
	Session->CurrTab = prosorinos->PrevTab;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionTabMoveLeft(InfoSessionPtr Session){		//Switch metaksi twn tab
	TabNodePtr prosorinos1,prosorinos2;
	prosorinos1 = malloc(sizeof(TabNodePtr));
	prosorinos2 = malloc(sizeof(TabNodePtr));

	prosorinos1 = Session->CurrTab;
	prosorinos2 = prosorinos1->PrevTab;

	if(Session->FirstTab == Session->CurrTab)		//an uparxei mono enan komvos mhn kaneis tipota
		return;
	else
	{
		prosorinos2->NextTab = prosorinos1->NextTab;
		prosorinos2->PrevTab = prosorinos1;
		prosorinos1->NextTab = prosorinos2;
		prosorinos1->PrevTab = prosorinos2->PrevTab;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionTabMoveRight(InfoSessionPtr Session){		//Switch metaksi twn tab
	TabNodePtr prosorinos1,prosorinos2;
	prosorinos1 = malloc(sizeof(TabNodePtr));
	prosorinos2 = malloc(sizeof(TabNodePtr));

	prosorinos1 = Session->CurrTab;
	prosorinos2 = prosorinos1->NextTab;

	prosorinos1->NextTab = prosorinos2->NextTab;
	prosorinos1->PrevTab = prosorinos2;
	prosorinos2->NextTab = prosorinos1;
	prosorinos2->PrevTab = prosorinos1->PrevTab;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionNewOpeningAddress(char *newAddress, InfoSessionPtr Session){ //Allagh default OpeningAddress
	Session->OpeningAddress = newAddress;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionShowOpeningAddress(InfoSessionPtr Session){		//Emfanizei to default OpeningAddress
	printf("%s",Session->OpeningAddress);

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionSiteNext(InfoSessionPtr Session){			//O CurrSite ston epomeno komvo site
	SiteNodePtr prosorinos;

	prosorinos = Session->CurrTab->CurrSite;
	if(prosorinos->NextSite != NULL)
		Session->CurrTab->CurrSite = prosorinos->NextSite;
	else
		return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionSitePrev(InfoSessionPtr Session){			//O CurrSite ston prohgoumeno komvo site
	SiteNodePtr prosorinos;

	prosorinos = Session->CurrTab->CurrSite;
	if(prosorinos->PrevSite != NULL)
		Session->CurrTab->CurrSite = prosorinos->PrevSite;
	else
		return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionSiteShow (InfoSessionPtr Session){			//Emfanizei to address tou CurrSite
	printf("%s",Session->CurrTab->CurrSite->Address);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int SessionTabClose (InfoSessionPtr Session){			//Diagrafh twn Site kai tou Tab ston opoio briskontai
	TabNodePtr prosorinosTab;
	SiteNodePtr prosorinosSite;

	prosorinosTab = Session->CurrTab->PrevTab;

	while(Session->CurrTab->CurrSite->NextSite != NULL)	//Phgainei sto teleutaio
		SessionSiteNext(Session);

	while(Session->CurrTab->FirstSite->NextSite != NULL)	//Diagrafh tou site
	{
		prosorinosSite = Session->CurrTab->CurrSite->PrevSite;
		free(prosorinosSite->NextSite->Address);
		free(prosorinosSite->NextSite);
		prosorinosSite->NextSite = NULL;
		Session->CurrTab->CurrSite = prosorinosSite;
	}

	if(Session->FirstTab == Session->LastTab)		//monadikos komvos
	{
		free(Session->CurrTab);
		free(Session);
		return 0 ;
	}

	if(Session->CurrTab == Session->FirstTab)		//metakinisi tou firstTab
		Session->FirstTab = Session->CurrTab->NextTab;

	if(Session->CurrTab == Session->LastTab)		//metakinisi tou lastTab
		Session->LastTab = Session->CurrTab->PrevTab;


	SessionTabNext(Session);
	free(Session->CurrTab->PrevTab);
	prosorinosTab->NextTab = Session->CurrTab;
	Session->CurrTab->PrevTab = prosorinosTab;

	return 1;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionClose(InfoSessionPtr Session){			//Diafrafh ths domhs
	TabNodePtr prosorinosTab;
	SiteNodePtr prosorinosSite;

	prosorinosTab = Session->CurrTab->PrevTab;

	while(Session->CurrTab!= prosorinosTab)
	{
		while(Session->CurrTab->CurrSite->NextSite != NULL)
		{
			SessionTabClose(Session);
		}
	}

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void SessionNewAddress(char *newAddress,InfoSessionPtr Session){	//nea address se kainourgio Tab
	SiteNodePtr prosorinos;
	prosorinos = malloc(sizeof(SiteNodePtr));

	prosorinos = Session->CurrTab->CurrSite->NextSite;
	prosorinos->Address = newAddress;

}
