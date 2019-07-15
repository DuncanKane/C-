#pragma once
#include <string>
#include <vector>

using namespace std;

#ifndef Login
class Login
{
public:
	void GetLoginDetails(string sUsernamePass, string sPasswordPass);
	bool CheckAdminLogin();
protected:
	string sUsername, sPassword, sUsernameCheck, sPasswordCheck;
	int iCount;
};

#endif // !Login

#ifndef Doctor
class Doctor
{
public:
	void GetDetails(string sNamePass, string sSpecialistAreaPass, string sUsernamePass, string sPasswordPass, string sLocationPass);
	void OutputDetails();
	void OutputRceptionistView();
	string OutputBooking(string sName);
	void AppointmentBooked();
	Doctor();
	~Doctor();
protected:
	string sName = "";
	string sSpecialistArea = "";
	string sUsername = "";
	string sPassword = "";
	string sLocation = "";
	int iAppointmentSlots = 8;
};
#endif // !Doctor

#ifndef Receptionist
class Receptionist
{
public:
	void GetDetails(string sNamePass);
	void OutputDetails();
	string OutputBooking(string sName);
protected:
	string sName = "";
};
#endif // !Receptionist

#ifndef Appointments
class Appointments : public Doctor, public Receptionist
{
public:
	void GetDetails(string sAssignDoctorPass, string sAssignReceptionistPass, string sPatientPass);
	void OutputAppointmentDetails();
protected:
	string sAssignedDoctor = "";
	string sAssignedReceptionist = "";
	string sPatientName = "";
};
#endif // !Appointments

#ifndef Patient
class Patient
{
public:
	void GetDetails(string sPatientNamePass, int iContactNumberPass, string sAddressPass, string sAilmentPass);
	void ShowDetails();
	int AppointmentCost(int iChargePass);
	void GetCost(int iTotalCostPass);
protected:
	string sPatientName = "";
	int iContactNumber, iTotalCharge, iBookedSlots;
	string sAddress = "";
	string sAilment = "";
	int iCharge = 25;
};
#endif // !Patient
