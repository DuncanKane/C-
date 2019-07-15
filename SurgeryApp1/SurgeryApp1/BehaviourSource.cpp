#include "stdafx.h"
#include "SurgeryHeader.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <array>
#include <vector>

using namespace std;

void Login::GetLoginDetails(string sUsernamePass, string sPasswordPass)
{
	sUsername = sUsernamePass;
	sPassword = sPasswordPass;
}
// function for a secure login
bool Login::CheckAdminLogin()
{
	bool bVerify = false;
	
	
		if (sUsername == "Admin" && sPassword == "Password")
		{
			cout << "Logged in! \n";
			bVerify = true;
		}

		else
		{
			cout << "Incorrect Username or Password! \n";

		}
	

	return bVerify;
}
// Doctor login check
/*bool Doctor::CheckDoctorLogin(vector <Doctor> oDoctor, string sUsername, string sPassword, int iNumber)
{
	bool bVerify = false;
	string sUsernamePass, sPasswordPass, sUsernameCheck, sPasswordCheck;

	do
	{
		do
		{
			for (int iCount = 0; iCount < iNumber; iCount++)
			{
				oDoctor[iCount].sUsername = sUsernamePass;
				oDoctor[iCount].sPassword = sPasswordPass;

				if (sUsername == sUsernamePass && sPassword == sPasswordPass)
				{
					cout << "Logged in! \n";
					bVerify = true;
				}
			}


			cout << "Incorrect Username or Password! \n";
			break;


		} while (bVerify == true);

		{

		}
	} while (bVerify == true);

	return bVerify;
}*/

void Doctor::GetDetails(string sNamePass, string sSpecialistAreaPass, string sUsernamePass, string sPasswordPass, string sLocationPass)
{
	sName = sNamePass;
	sSpecialistArea = sSpecialistAreaPass;
	sUsername = sUsernamePass;
	sPassword = sPasswordPass;
	sLocation = sLocationPass;
}

void Doctor::OutputDetails()
{
	cout << "Doctor " << sName << " has a specialist area of " << sSpecialistArea << "\n\n";
	cout << "Available appiontments: " << iAppointmentSlots << "\n";
}

void Doctor::OutputRceptionistView()
{
	cout << "Doctor " << sName << "\n";
	cout << "Available appiontments: " << iAppointmentSlots << "\n";
}

string Doctor::OutputBooking(string sName)
{
	return sName;
}

void Doctor::AppointmentBooked()
{
	iAppointmentSlots - 1;
}

/*Doctor::Doctor(string sNamePass, string sSpecialistAreaPass, string sUsernamePass, string sPasswordPass)
{
sName = sNamePass;
sSpecialistArea = sSpecialistAreaPass;
sUsername = sUsernamePass;
sPassword = sPasswordPass;
}*/

Doctor::Doctor()
{

}

Doctor::~Doctor()
{
	cout << "Doctor account deleted \n";
}

// procedure for parameter passing receptionist information
void Receptionist::GetDetails(string sNamePass)
{
	sName = sNamePass;
}
// procedure for outputing receptionist information
void Receptionist::OutputDetails()
{
	cout << "Recptionish name is " << sName;
}

string Receptionist::OutputBooking(string sName)
{
	return sName;
}

void Appointments::GetDetails(string sAssignDoctorPass, string sAssignReceptionistPass, string sPatientNamePass)
{
	sAssignedDoctor = sAssignDoctorPass;
	sAssignedReceptionist = sAssignReceptionistPass;
	sPatientName = sPatientNamePass;
}

void Appointments::OutputAppointmentDetails()
{
	cout << "Patient: " << sPatientName;
	cout << "\nDoctor booked: " << sAssignedDoctor;
	cout << "\nBooked by " << sAssignedReceptionist;
}

void Patient::GetDetails(string sPatientNamePass, int iContactNumberPass, string sAddressPass, string sAilmentPass)
{
	sPatientName = sPatientNamePass;
	iContactNumber = iContactNumberPass;
	sAddress = sAddressPass;
	sAilment = sAilmentPass;
}

void Patient::ShowDetails()
{
	cout << "Patient Name: " << sPatientName << "\n";
	cout << "Contact Number: " << iContactNumber << "\n";
	cout << "Address: " << sAddress << "\n";
	cout << "Patient Ailment: " << sAilment << "\n";
	cout << "Slots Booked: " << iBookedSlots << "\n";
}

int Patient::AppointmentCost(int iChargePass)
{
	iChargePass = iCharge;
	return iCharge;

}

void Patient::GetCost(int iTotalCostPass)
{
	iTotalCharge = iTotalCostPass;
	iBookedSlots + 1;
}