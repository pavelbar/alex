#include "TicketOffice.h"

MString TicketOffice::GetTicketNumber(void) const
{
	return ticketNumber;
}

MString TicketOffice::GetFullNameCashier(void) const
{
	return fullNameCashier;
}

MString TicketOffice::GetAmountSoldTickets(void) const
{
	return amountSoldTickets;
}

MString TicketOffice::GetTotalRevenue(void) const
{
	return totalRevenue;
}

MString TicketOffice::GetSalesDate(void) const
{
	return salesDate;
}

//----
void TicketOffice::SetTicketNumber(const MString s)
{
	ticketNumber = s;
}

void TicketOffice::SetFullNameCashier(const MString s)
{
	fullNameCashier = s;
}

void TicketOffice::SetAmountSoldTickets(const MString s)
{
	amountSoldTickets = s;
}

void TicketOffice::SetTotalRevenue(const MString s)
{
	totalRevenue = s;
}

void TicketOffice::SetSalesDate(const MString s)
{
	salesDate = s;
}

//----

MString TicketOffice::GetNameTicketNumber(void) const
{
	return "Ticket number : ";
}

MString TicketOffice::GetNameFullNameCashier(void) const
{
	return "Full name cashier: ";
}

MString TicketOffice::GetNameAmountSoldTickets(void) const
{
	return "Amount sold tickets: ";
}

MString TicketOffice::GetNameTotalRevenue(void) const
{
	return "Total revenue: ";
}

MString TicketOffice::GetNameSalesDate(void) const
{
	return "Sales date: ";
}
