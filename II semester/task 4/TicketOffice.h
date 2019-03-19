#pragma once
#include "MString.h"

class TicketOffice
{
private:
	MString ticketNumber;//номер кассы
	MString fullNameCashier;//ФИО кассира
	MString amountSoldTickets;//Кол-во проанных билетов
	MString totalRevenue;//Суммарная выручка
	MString salesDate;//Дата продажи

public:
	MString GetTicketNumber(void) const;
	MString GetFullNameCashier(void) const;
	MString GetAmountSoldTickets(void) const;
	MString GetTotalRevenue(void) const;
	MString GetSalesDate(void) const;

	void SetTicketNumber(const MString s);
	void SetFullNameCashier(const MString s);
	void SetAmountSoldTickets(const MString s);
	void SetTotalRevenue(const MString s);
	void SetSalesDate(const MString s);

	MString GetNameTicketNumber(void) const;
	MString GetNameFullNameCashier(void) const;
	MString GetNameAmountSoldTickets(void) const;
	MString GetNameTotalRevenue(void) const;
	MString GetNameSalesDate(void) const;
};
