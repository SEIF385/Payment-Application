#include "card.h"
#include <stdio.h>
#include <string.h>

void getCardHolderNameTest(void)
{
    ST_cardData_t cardData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getCardHolderName\n");

    printf("Test Case 1: seif naem \n");
    printf("Input Data: seif naem \n");
    printf("Expected Result: 1\n");
    printf("Actual Result:%d\n",getCardHolderName(&cardData));
    printf("********************************************\n");
    printf("Test Case 2:seif naem mohamed naem shedeed\n");
    printf("Input Data:seif naem mohamed naem shedeed\n");
    printf("Expected Result:1\n");
    printf("Actual Result:%d\n",getCardHolderName(&cardData));
    printf("********************************************\n");
    printf("Test Case 3:seif naem mohamed naem\n");
    printf("Input Data:seif naem mohamed naem \n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",getCardHolderName(&cardData));
    printf("********************************************\n");
    printf("Test Case 4:NULL\n");
    printf("Input Data:\0 \n");
    printf("Expected Result:1\n");
    printf("Actual Result:%d\n",getCardHolderName(&cardData));
    printf("********************************************\n");
}

void getCardExpiryDateTest (void)
{

    ST_cardData_t cardData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getCardExpiryDateTest\n");

    printf("Test Case 1: 2030\n");
    printf("Input Data: 2030 \n");
    printf("Expected Result: 2\n");
    printf("Actual Result:%d\n",getCardExpiryDate(& cardData));
    printf("********************************************\n");
    printf("Test Case 2:20300\n");
    printf("Input Data:20300\n");
    printf("Expected Result:2\n");
    printf("Actual Result:%d\n",getCardExpiryDate(& cardData));
    printf("********************************************\n");
    printf("Test Case 3:12/30\n");
    printf("Input Data:\n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",getCardExpiryDate(& cardData));
    printf("********************************************\n");
    printf("Test Case 4:12*30\n");
    printf("Input Data:12*30 \n");
    printf("Expected Result:2\n");
    printf("Actual Result:%d\n",getCardExpiryDate(& cardData));
    printf("********************************************\n");

}

void getCardPANTest (void)
{

    ST_cardData_t cardData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getCardPAN\n");

    printf("Test Case 1: 1234567891234\n");
    printf("Input Data: 1234567891234 \n");
    printf("Expected Result: 3\n");
    printf("Actual Result:%d\n",getCardPAN(& cardData));
    printf("********************************************\n");
    printf("Test Case 2:12345678912345678912\n");
    printf("Input Data:12345678912345678912\n");
    printf("Expected Result:3\n");
    printf("Actual Result:%d\n",getCardPAN(& cardData));
    printf("********************************************\n");
    printf("Test Case 3:1234567891234567\n");
    printf("Input Data:1234567891234567\n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",getCardPAN(& cardData));
    printf("********************************************\n");
;

}


EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("Please Enter your Card's Name\n");
	gets(cardData->cardHolderName);
	if(strlen(cardData->cardHolderName)>=20 && strlen(cardData->cardHolderName) <= 24)
	    return CARD_OK;
	else
		return WRONG_NAME;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("Please Enter your Card's Expiry Date in form MM/YY\n");
	gets(cardData->cardExpirationDate);
	if (strlen(cardData->cardExpirationDate) == 5 &&cardData->cardExpirationDate[2]=='/')
		return CARD_OK;
	else
		return WRONG_EXP_DATE;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("Please Enter your Card's PAN\n");
	gets(cardData->primaryAccountNumber);
	if (strlen(cardData->primaryAccountNumber) >= 16 && strlen(cardData->primaryAccountNumber) <= 19)
		return CARD_OK;
	else
		return WRONG_PAN;
}
