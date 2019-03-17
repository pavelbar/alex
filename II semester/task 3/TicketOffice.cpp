#include "TicketOffice.h"

//TicketOffice::TicketOffice()
//{
//}
//
//TicketOffice::~TicketOffice()
//{
//}

string TicketOffice::GetTicketNumber(void) const
{
	return ticketNumber;
}

string TicketOffice::GetFullNameCashier(void) const
{
	return fullNameCashier;
}

string TicketOffice::GetAmountSoldTickets(void) const
{
	return amountSoldTickets;
}

string TicketOffice::GetTotalRevenue(void) const
{
	return totalRevenue;
}

string TicketOffice::GetSalesDate(void) const
{
	return salesDate;
}

//----
void TicketOffice::SetTicketNumber(const string s)
{
	ticketNumber = s;
}

void TicketOffice::SetFullNameCashier(const string s)
{
	fullNameCashier = s;
}

void TicketOffice::SetAmountSoldTickets(const string s)
{
	amountSoldTickets = s;
}

void TicketOffice::SetTotalRevenue(const string s)
{
	totalRevenue = s;
}

void TicketOffice::SetSalesDate(const string s)
{
	salesDate = s;
}

//----

string TicketOffice::GetNameTicketNumber(void) const
{
	return "Ticket number : ";
}

string TicketOffice::GetNameFullNameCashier(void) const
{
	return "Full name cashier: ";
}

string TicketOffice::GetNameAmountSoldTickets(void) const
{
	return "Amount sold tickets: ";
}

string TicketOffice::GetNameTotalRevenue(void) const
{
	return "Total revenue: ";
}

string TicketOffice::GetNameSalesDate(void) const
{
	return "Sales date: ";
}
