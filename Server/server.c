#include "server.h"
#include "../Terminal/terminal.h"
#include "../Card/card.h"
#include <string.h>

ST_accountsDB_t  accountsDB[255] = { {2000.0,"1234567899876543210"},
									 {3000.0,"1234567899876543211"},
									 {4000.0,"1234567899876543212"},
									 {5000.0,"1234567899876543213"},
									 {6000.0,"1234567899876543214"},
									 {7000.0,"1234567899876543215"} };

ST_transaction_t TRS[255] = { 0 };

void recieveTransactionDataTest(void)
{
    ST_transaction_t transData1={{"seif naem mohamed shedeed","12/25","1234567891234567"},{200.0,2000.0,"12/12/2020"},1,211};
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: recieveTransactionData\n");

    printf("Test Case 1: DECLINED STOLEN CARD\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,200.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 2\n");
    printf("Actual Result:%d\n",recieveTransactionData(&transData1));
    printf("********************************************\n");
    ST_transaction_t transData2={{"seif naem mohamed shedeed","12/25","1234567899876543210"},{30000.0,2000.0,"12/12/2020"},1,211};
    printf("Test Case 2: DECLINED INSUFFECIENT FUND\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567899876543210,3000.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 1\n");
    printf("Actual Result:%d\n",recieveTransactionData(&transData2));
    printf("********************************************\n");
   ST_transaction_t  transData3={{"seif naem mohamed shedeed","12/25","1234567899876543210"},{500.0,2000.0,"12/12/2020"},1,211};
    printf("Test Case 3: APPROVED\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,500.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 0\n");
    printf("Actual Result:%d\n",recieveTransactionData(& transData3));
    printf("********************************************\n");

}
void isValidAccountTest(void)
{
    ST_cardData_t cardData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: isValidAccount\n");

    printf("Test Case 1: SERVER OK \n");
    printf("Input Data: 1234567899876543210 \n");
    printf("Expected Result: 0\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidAccount(&cardData));
    printf("********************************************\n");
    printf("Test Case 2:SERVER OK\n");
    printf("Input Data:1234567899876543211 \n");
    printf("Expected Result:0\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidAccount(&cardData));
    printf("********************************************\n");
    printf("Test Case 3:ACCOUNT NOT FOUND\n");
    printf("Input Data:1234567899876543216 \n");
    printf("Expected Result:3\n");
    getCardPAN(&cardData);
    printf("Actual Result:%d\n",isValidAccount(&cardData));
    printf("********************************************\n");

}
void isAmountAvailableTest(void)
{
    ST_cardData_t cardData;
    ST_terminalData_t termData;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: isAmountAvailable\n");
    printf("Account PAN in database :1234567899876543210\n");
    getCardPAN(&cardData);
    printf("Test Case 1: SERVER OK\n");
    printf("Input Data: 1000  \n");
    printf("Expected Result: 0\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isAmountAvailable(&termData));
    printf("********************************************\n");
    printf("Test Case 2:SERVER OK\n");
    printf("Input Data: 2000\n");
    printf("Expected Result:0\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isAmountAvailable(&termData));

    printf("********************************************\n");
    printf("Test Case 3:LOW BALANCE\n");
    printf("Input Data:3000 \n");
    printf("Expected Result:4\n");
    getTransactionAmount(&termData);
    printf("Actual Result:%d\n",isAmountAvailable(&termData));
    printf("********************************************\n");
}
void saveTransactionTest(void)
{
  ST_transaction_t transData={{"seif naem mohamed shedeed","12/25","1234567891234567"},{200.0,2000.0,"12/12/2020"},1,211};
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: saveTransaction\n");

    printf("Test Case 1: SERVER OK\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,200.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 0\n");
    printf("Actual Result:%d\n",saveTransaction(& transData));
    printf("********************************************\n");
    printf("Test Case 2: SERVER OK\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,200.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 0\n");
    printf("Actual Result:%d\n",saveTransaction(& transData));
    printf("********************************************\n");
     printf("Test Case 3: SERVER OK\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,200.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 0\n");
    printf("Actual Result:%d\n",saveTransaction(& transData));
    printf("********************************************\n");
     printf("Test Case 4: SAVING FAILED\n");
    printf("Input Data: seif naem mohamed shedeed,12/25,1234567891234567,200.0,2000.0,12/12/2020,1,211\n");
    printf("Expected Result: 1\n");
    printf("Actual Result:%d\n",saveTransaction(& transData));
    printf("********************************************\n");

}
void getTransactionTest(void)
{

    ST_transaction_t transData;
    uint32_t transactionSequenceNumber;
    printf("Tester Name: Seif Naem \n");
    printf("Function Name: getTransaction\n");

    printf("Test Case 1: SERVER OK\n");
    printf("Input Data: 211 \n");
    printf("Expected Result: 0\n");
    printf("Enter transactionSequenceNumber :\n");
    scanf("%d",&transactionSequenceNumber);
    printf("Actual Result:%d\n",getTransaction( transactionSequenceNumber, &transData));
    printf("********************************************\n");

}

int i=0;
int x=0;
EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{

	if(isValidAccount(&transData->cardHolderData) != SERVER_OK)
		return DECLINED_STOLEN_CARD;
	else if (isAmountAvailable(&transData->terminalData) != SERVER_OK)
		return DECLINED_INSUFFECIENT_FUND;
	else if (saveTransaction(transData) != SERVER_OK)
		return INTERNAL_SERVER_ERROR;
    else{
        return APPROVED;
    }
}
EN_serverError_t isValidAccount(ST_cardData_t* cardData)
{

	for (; i < 6; i++)
	{
		if (strcmp(cardData->primaryAccountNumber, accountsDB[i].primaryAccountNumber) == 0)
			return SERVER_OK;
	}
	return ACCOUNT_NOT_FOUND;
}
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData)
{

	if (termData->transAmount<=accountsDB[i].balance)
		return SERVER_OK;

	return LOW_BALANCE;
}
EN_serverError_t saveTransaction(ST_transaction_t* transData)
{

	if (x < 3)
	{
		TRS[x].cardHolderData = transData->cardHolderData;
		TRS[x].terminalData = transData->terminalData;
		TRS[x].transactionSequenceNumber = transData->transactionSequenceNumber;
		TRS[x].transState = transData->transState;
		x++;
		return SERVER_OK;
	}
	else if (x >= 3)
		return SAVING_FAILED;


}
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData)
{
     ST_cardData_t card;
     ST_terminalData_t tr;
	 transData->transactionSequenceNumber=transactionSequenceNumber;
	 getCardHolderName(&card);
	  gets();
	 getCardExpiryDate(&card);
	 getCardPAN(&card);
     getTransactionDate(&tr);
     printf("state:INSUFFECIENTFUND 1,STOLENCARD 2, INTERNAL SERVER ERROR 3 \n");
     scanf("%d",&transData->transState);
     transData->cardHolderData=card;
     transData->terminalData=tr;
     return SERVER_OK;


}

