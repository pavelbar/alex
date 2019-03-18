#pragma once
#include <string>

using namespace std;

class TicketOffice
{
private:
	string ticketNumber;//номер кассы
	string fullNameCashier;//ФИО кассира
	string amountSoldTickets;//Кол-во проанных билетов
	string totalRevenue;//Суммарная выручка
	string salesDate;//Дата продажи

public:
	string GetTicketNumber(void) const;
	string GetFullNameCashier(void) const;
	string GetAmountSoldTickets(void) const;
	string GetTotalRevenue(void) const;
	string GetSalesDate(void) const;

	void SetTicketNumber(const string s);
	void SetFullNameCashier(const string s);
	void SetAmountSoldTickets(const string s);
	void SetTotalRevenue(const string s);
	void SetSalesDate(const string s);

	string GetNameTicketNumber(void) const;
	string GetNameFullNameCashier(void) const;
	string GetNameAmountSoldTickets(void) const;
	string GetNameTotalRevenue(void) const;
	string GetNameSalesDate(void) const;
};
