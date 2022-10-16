#include "terminal.h"
#include "../Card/card.h"
#include <string.h>
#include <stdlib.h>
void getTransactionDateTest(void)
{
    ST_terminalData_t termData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getTransactionDate\n");

    printf("Test Case 1: 20/10 \n");
    printf("Input Data: 20/10 \n");
    printf("Expected Result: 1\n");
    printf("Actual Result:%d\n",getTransactionDate(&termData));
    printf("********************************************\n");
    printf("Test Case 2:10/20/10\n");
    printf("Input Data:10/20/10\n");
    printf("Expected Result:1\n");
    printf("Actual Result:%d\n",getTransactionDate(&termData));
    printf("********************************************\n");
    printf("Test Case 3:20/12/2000\n");
    printf("Input Data:20/12/2000 \n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",getTransactionDate(&termData));
    printf("********************************************\n");
    printf("Test Case 4:NULL\n");
    printf("Input Data: \\0 \n");
    printf("Expected Result:1\n");
    printf("Actual Result:%d\n",getTransactionDate(&termData));
    printf("********************************************\n");
}
void isCardExpriedTest(void)
{
    ST_terminalData_t termData;
    ST_cardData_t cardData;


    printf("Tester Name: Seif Naem \n");
    printf("Function Name: isCardExpried\n");

    printf("Test Case 1: EXPIRED CARD \n");
    printf("Input Data: 10/21 \& 20/12/2022 \n");
    printf("Expected Result: 2\n");
    getCardExpiryDate(&cardData);
    getTransactionDate(&termData);
    printf("Actual Result:%d\n",isCardExpired( cardData, termData));
    printf("********************************************\n");
    printf("Test Case 2:EXPIRED CARD\n");
    printf("Input Data: 10/22 \& 20/12/2022\n");
    printf("Expected Result:2\n");
    getCardExpiryDate(&cardData);
    getTransactionDate(&termData);
    printf("Actual Result:%d\n",isCardExpired( cardData, termData));
    printf("********************************************\n");
    printf("Test Case 3:TERMINAL OK\n");
    printf("Input Data: 10/25 \& 20/12/2022 \n");
    printf("Expected Result:0\n");
    getCardExpiryDate(&cardData);
    getTransactionDate(&termData);
    printf("Actual Result:%d\n",isCardExpired( cardData, termData));
    printf("********************************************\n");
}

void getTransactionAmountTest(void)
{
    ST_terminalData_t termData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getTransactionAmount\n");

    printf("Test Case 1: IINVALID AMOUNT \n");
    printf("Input Data: 0.0 \n");
    printf("Expected Result: 4\n");
    printf("Actual Result:%d\n",getTransactionAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 2:INVALID AMOUNT\n");
    printf("Input Data:-10 \n");
    printf("Expected Result:4\n");
    printf("Actual Result:%d\n",getTransactionAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 3:TERMINAL OK\n");
    printf("Input Data:100 \n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",getTransactionAmount(&termData));
    printf("********************************************\n");

}

void isBelowMaxAmountTest(void)
{

    ST_terminalData_t termData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: isBelowMaxAmount\n");
    setMaxAmount(&termData);
    printf("********************************************\n");
    printf("Test Case 1: EXCEED MAX AMOUNT \n");
    printf("Input Data: 10000 \n");
    printf("Expected Result: 5\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isBelowMaxAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 2:IEXCEED MAX AMOUNT\n");
    printf("Input Data:20000 \n");
    printf("Expected Result:5\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isBelowMaxAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 3:TERMINAL OK\n");
    printf("Input Data:1000 \n");
    printf("Expected Result:0\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isBelowMaxAmount(&termData));
    printf("********************************************\n");

}

void setMaxAmountTest(void)
{
    ST_terminalData_t termData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: setMaxAmount\n");

    printf("Test Case 1: INVALID MAX AMOUNT \n");
    printf("Input Data: -100 \n");
    printf("Expected Result: 6\n");
    printf("Actual Result:%d\n",setMaxAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 2:INVALID MAX AMOUNT\n");
    printf("Input Data:0\n");
    printf("Expected Result:6\n");
    printf("Actual Result:%d\n",setMaxAmount(&termData));
    printf("********************************************\n");
    printf("Test Case 3:TERMINAL OK\n");
    printf("Input Data:1000 \n");
    printf("Expected Result:0\n");
    printf("Actual Result:%d\n",setMaxAmount(&termData));
    printf("********************************************\n");

}
void isValidCardPANTest(void)
{
     ST_cardData_t cardData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: isValidCardPAN\n");

    printf("Test Case 1: INVALID CARD \n");
    printf("Input Data: 123456789123 \n");
    printf("Expected Result: 3\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidCardPAN( &cardData));
    printf("********************************************\n");
    printf("Test Case 2: INVALID CARD \n");
    printf("Input Data: 12345678912345678912 \n");
    printf("Expected Result: 3\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidCardPAN( &cardData));
    printf("********************************************\n");
    printf("Test Case 3: TERMINAL OK \n");
    printf("Input Data: 12345678912345678 \n");
    printf("Expected Result: 0\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidCardPAN(&cardData));
    printf("********************************************\n");
}

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("Please Enter the transaction data in form DD/MM/YYYY\n");
	gets(termData->transactionDate);
	if (strlen(termData->transactionDate) == 10)
		return TERMINAL_OK;
	else
		return WRONG_DATE;

}
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	int year, month;
	month =(int) ((cardData.cardExpirationDate[0] - 48) * 10 + (cardData.cardExpirationDate[1] - 48))
		- ((termData.transactionDate[3] - 48) * 10 + (termData.transactionDate[4] - 48));

	year = (int)((cardData.cardExpirationDate[3] - 48) * 10 + (cardData.cardExpirationDate[4] - 48))
		- ((termData.transactionDate[8] - 48) * 10 + (termData.transactionDate[9] - 48));
	if ( (year > 0)|| (year >= 0 && month > 0) )
		return TERMINAL_OK;
	else
		return EXPIRED_CARD;
}
EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData)
{

	if (strlen(cardData->primaryAccountNumber) >= 16 && strlen(cardData->primaryAccountNumber) <= 19)
		return TERMINAL_OK;
	else
		return INVALID_CARD;

}
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	printf("Please Enter the transaction amount \n");
	scanf("%f",&termData->transAmount);
	if (termData->transAmount > 0)
		return TERMINAL_OK;
	else
		return INVALID_AMOUNT;
}
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
		return EXCEED_MAX_AMOUNT;
	else
		return TERMINAL_OK;
}
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)
{
	printf("Please Enter Max amount \n");
	scanf("%f", &termData->maxTransAmount);
	if (termData->maxTransAmount > 0)
		return TERMINAL_OK;
	else
		return INVALID_MAX_AMOUNT;

}
