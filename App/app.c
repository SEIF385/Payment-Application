#include <stdio.h>
#include <stdlib.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "app.h"



void appStart(void)
{
   //card
   ST_cardData_t Card;
   getCardHolderName(&Card);
   getCardExpiryDate(&Card);
   getCardPAN(&Card);
   //terminal
     ST_terminalData_t TRD ;
     getTransactionDate(&TRD);
   //server
    ST_transaction_t transData;
    transData.cardHolderData = Card;
    transData.terminalData = TRD;

   if(isCardExpired(Card,TRD)!=TERMINAL_OK)
     {   puts("Expired Card");
         return ;
     }
     else
     {
         if(getTransactionAmount(&TRD)!=TERMINAL_OK)
         {
             puts("Amount Exceeding limit");
             return ;
         }
         else
         {
             if(isValidCardPAN(&Card)!=TERMINAL_OK)
             {
                puts("Invalid account");
                return ;
             }
             else
             {
                  setMaxAmount(&TRD);
                 if(isBelowMaxAmount(&TRD)!=TERMINAL_OK)
                 {
                   puts(" Insuffecient funds ");
                  return ;
                 }
                 else
                 {
                     EN_transState_t state;
                     state=recieveTransactionData(&transData);
                    if(state==APPROVED)
                        printf("APPROVED");
                    else if(state==DECLINED_STOLEN_CARD)
                        printf("DECLINED STOLEN CARD");
                    else if(state==INTERNAL_SERVER_ERROR)
                        printf("INTERNAL SERVER ERROR");
                 }
             }

         }
     }

 //server



}
