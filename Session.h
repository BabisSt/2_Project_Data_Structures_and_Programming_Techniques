/* Stevis Charalampos-Antonios AM:1115201600278 Session.h */

#ifndef __SESSION__
#define __SESSION__

typedef struct InfoSession *InfoSessionPtr;

InfoSessionPtr SessionNew(char *);
void SessionNewTab(InfoSessionPtr);
void SessionTabShow(InfoSessionPtr);
void SessionTabNext(InfoSessionPtr);
void SessionTabPrev(InfoSessionPtr);
void SessionTabMoveLeft(InfoSessionPtr);
void SessionTabMoveRight(InfoSessionPtr);
void SessionNewOpeningAddress(char *, InfoSessionPtr);
void SessionShowOpeningAddress(InfoSessionPtr);
void SessionSiteNext(InfoSessionPtr);
void SessionSitePrev(InfoSessionPtr);
void SessionSiteShow(InfoSessionPtr);
int SessionTabClose(InfoSessionPtr);
void SessionClose(InfoSessionPtr);
void SessionNewAddress(char *,InfoSessionPtr);
#endif
