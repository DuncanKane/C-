// SurgeryApp1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SurgeryHeader.h"
#include <conio.h>
#include <string>
#include <iostream>
#include <array>
#include <vector>

using namespace std;


int main()
{
	string sUsername, sPassword, sName, sSpecialistArea, sLocation, sBookingDoctor, sBookingReceptionist, sPatientName, sAddress, sAilment;
	int iNumber, iContactNumber;
	int iCost = 25;
	bool bMainMenu = false;
	bool bAdminMenu = false;
	bool bReceptionistMenu = false;
	bool bDoctorMenu = false;
	bool bVerify = false;
	vector <Doctor> oDoctor(2);
	vector <Receptionist> oReceptionist(1);
	vector <Appointments> oAppointment(0);
	vector <Patient> oPatient(0);

	//Constructor 
	//Doctor oDoctor(sName, sSpecialistArea, sUsername, sPassword);
	//Doctor oDoctor();
	//Doctor[0].GetDetails(Leanne, Physio, Leanne, Password1);
	
	//class object for login
	Login oLogin;

	//iNumber = oDoctor.size();

	int iAttempts = 0;
	//login check for username and password
	do
	{
		cout << "Please enter Username \n";
		cin >> sUsername;
		cout << "Please enter Password \n";
		cin >> sPassword;

		oLogin.GetLoginDetails(sUsername, sPassword);
		bVerify = oLogin.CheckAdminLogin();
		iAttempts++;
	} while (bVerify == false || iAttempts > 2);

	//add Doctors for surgery
	for (int iCount = 0; iCount < 2; iCount++)
	{
		cout << "Please insert name for Doctor " << iCount + 1 << ":\n";
		cin >> sName;
		cout << "Please insert Specialist Area for Doctor " << iCount + 1 << ":\n";
		cin >> sSpecialistArea;
		cout << "Please insert Username for Doctor " << iCount + 1 << ":\n";
		cin >> sUsername;
		cout << "Please insert Password for Doctor " << iCount + 1 << ":\n";
		cin >> sPassword;
		cout << "Please insert Location for Doctor " << iCount + 1 << ":\n";
		cin >> sLocation;
		oDoctor[iCount].GetDetails(sName, sSpecialistArea, sUsername, sPassword, sLocation);
	}

	//add receptionist
	cout << "Please insert Receptionist Name: ";
	cin >> sName;
	oReceptionist[0].GetDetails(sName);
	
	int iChoice = 0;
	do
	{
		cout << "Main Emnu \n";
		cout << "1: Admin Menu \n";
		cout << "2: Receptionist Menu \n";
		cout << "3: Doctor Menu \n";
		cout << "9: Exit \n";
		cin >> iChoice;

		switch (iChoice)
		{
		case 1:
		{
			do
			{
				cout << "Admin Menu \n";
				cout << "1: Add Doctor \n";
				cout << "2: Add Receptionist \n";
				cout << "7: Change Default Receptionist \n";
				cout << "8: Change Default Doctors \n";
				cout << "9: Exit \n";
				cin >> iChoice;

				switch (iChoice)
				{
				case 1:
				{
					// changing the size of the vector
					oDoctor.resize(oDoctor.size() + 1);
					//create the object for the extra space for a pushback
					Doctor oDoctorPush;

					cout << "\nInsert Doctors Name \n";
					cin >> sName;
					cout << "\nInsert Doctors specialist Area \n";
					cin >> sSpecialistArea;
					cout << "\nInsert Username for Doctor \n";
					cin >> sUsername;
					cout << "\nInsert Doctors Password \n";
					cin >> sPassword;
					cout << "\nInsert Doctors Location \n";
					cin >> sLocation;

					// populate the object for the pushback
					oDoctorPush.GetDetails(sName, sSpecialistArea, sUsername, sPassword, sLocation);
					// push back command to add the object to the vector
					oDoctor.push_back(oDoctorPush);
					//output to check the correct details have been added
					oDoctor[oDoctor.size() - 1].OutputDetails();
					break;
				}

				case 2:
				{
					// changing the size of the vector
					oReceptionist.resize(oReceptionist.size() + 1);
					//create the object for the extra space for a pushback
					Receptionist oReceptionistPush;

					cout << "\nInsert Receptionist Name \n";
					cin >> sName;

					// populate the object for the pushback
					oReceptionistPush.GetDetails(sName);
					// push back command to add the object to the vector
					oReceptionist.push_back(oReceptionistPush);
					//output to check the correct details have been added
					oReceptionist[oReceptionist.size() - 1].OutputDetails();
					break;
				}

				case 7:
				{
					cout << "Please insert Receptionist name \n";
					cin >> sName;
					oReceptionist[0].GetDetails(sName);
					break;
				}

				case 8:
				{
					for (int iCount = 0; iCount < 2; iCount++)
					{
						cout << "Please insert name for Doctor " << iCount + 1 << ":\n";
						cin >> sName;
						cout << "Please insert Specialist Area for Doctor " << iCount + 1 << ":\n";
						cin >> sSpecialistArea;
						cout << "Please insert Username for Doctor " << iCount + 1 << ":\n";
						cin >> sUsername;
						cout << "Please insert Password for Doctor " << iCount + 1 << ":\n";
						cin >> sPassword;
						cout << "Please insert Location for Doctor " << iCount + 1 << ":\n";
						cin >> sLocation;
						oDoctor[iCount].GetDetails(sName, sSpecialistArea, sUsername, sPassword, sLocation);
					}
				}
				break;

				case 9:
					bAdminMenu = true;
					break;
				}
			} while (bAdminMenu == true);

		}
		case 2:
			do
			{
				cout << "Receptionist Menu \n";
				cout << "1: View available appiontments \n";
				cout << "2: Book Appiontment \n";
				cout << "3: Book 2 Appointment slots \n";
				cout << "4: Cancel Appointment \n";
				cout << "9: Exit \n";
				cin >> iChoice;
				switch (iChoice)
				{
				case 1:
					//loop to display all doctors and appointments available
					for (int iCount = 0; iCount < oDoctor.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oDoctor[iCount].OutputRceptionistView();
					}
					break;
				case 2:
				{

					cout << "Please type Patient name: \n";
					cin >> sPatientName;
					cout << "Enter Patient Address: \n";
					cin >> sAddress;
					cout << "Enter Patient Conact Number: \n";
					cin >> iContactNumber;
					cout << "Enter Patient Ailment \n";
					cin >> sAilment;
					//resize vector for push back
					oPatient.resize(oPatient.size() + 1);
					//create object for pushback
					Patient oPatientPush;
					//populate object
					oPatientPush.GetDetails(sPatientName, iContactNumber, sAddress, sAilment);
					// push back the object on to the vector
					oPatient.push_back(oPatientPush);
					//output the logged object
					oPatient[oPatient.size() - 1].ShowDetails();

					cout << "Select Doctor to book: \n";
					for (int iCount = 0; iCount < oDoctor.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oDoctor[iCount].OutputRceptionistView();
					}

					cin >> iNumber;
					
					// taking the Dcotor and receptionist from it's object into a parameter
					oDoctor[iNumber - 1].OutputBooking(sBookingDoctor);
					oReceptionist[iNumber - 1].OutputBooking(sBookingReceptionist);
					// changing the size of the vector
					oAppointment.resize(oAppointment.size() + 1);
					//create the object for the extra space for a pushback
					Appointments oAppointmentPush;
					// populate the object for the pushback
					oAppointmentPush.GetDetails(sBookingDoctor, sBookingReceptionist, sPatientName);
					// push back command to add the object to the vector
					oAppointment.push_back(oAppointmentPush);
					//output to check the correct details have been added
					oAppointment[oAppointment.size() - 1].OutputAppointmentDetails();
					
					
					//adjust the available slots for the doctor
					oAppointment[iNumber - 1].AppointmentBooked();
					iCost = 25;
					//oPatient[oPatient.size()].AppointmentCost;
					oPatient[oPatient.size()].GetCost(iCost);
				}
				break;

				case 3:
					break;
				case 4:
				{
					cout << "Select appointment to cancel: \n";
					//output booked appointments
					for (int iCount = 0; iCount < oAppointment.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oAppointment[iCount].OutputAppointmentDetails();
					}

					cin >> iNumber;
					//swapping the vector around until the appointment to remove is at the back
					//oAppointment.swap (oAppointment[iNumber -1]);
					oAppointment.push_back(oAppointment[iNumber -1]);
					//reduce the size of the vector to remove the last object
					oAppointment.pop_back();
					//output booked appointments
					for (int iCount = 0; iCount < oAppointment.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oAppointment[iCount].OutputAppointmentDetails();
					}
				}
				break;

				case 9:
					bReceptionistMenu = true;
					break;

				} 
			} while (bReceptionistMenu == true);

		case 3:
			do
			{
				cout << "Doctor Menu \n";
				cout << "1: View Appointments \n";
				cout << "2: View Slots left \n";
				cout << "9: Exit \n";
				cin >> iChoice;
				switch (iChoice)
				{
				case 1:
					for (int iCount = 0; iCount < oAppointment.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oAppointment[iCount].OutputAppointmentDetails();
					}
					break;
				case 2:
					for (int iCount = 0; iCount < oDoctor.size(); iCount++)
					{
						cout << iCount + 1 << ": \n";
						oDoctor[iCount].OutputDetails();
					}
					break;
				case 9:
					bDoctorMenu = true;
					break;
				}
			} while (bDoctorMenu == true);
		case 9:
			bMainMenu = true;
			break;
		}
	
		
		
	} while (bMainMenu == true);

	_getch();
    return 0;
}

