#include <iostream>
#include <cmath>

using namespace std;

int main() {
    Start:

    cout << "---------Electricity Calculator---------" << endl;
    cout << "----------------------------------------\n";

    //Input for Power Options:
    int selections{0};
    Power_Options:
    cout << "Choose Power Option: " << endl;
    cout << "1) Kw\n2) Watts\n\nSelection: ";
    cin >> selections;
    if (selections > 2) {
        system("cls");
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Invalid selection. Try again..\n" << endl;
        goto Power_Options;
    }
    system("cls");
    string Power_String{};

    //Allocate Memory.
    double PowerPower{0}; //Power Calculated.
    double Kw{0};
    double Watts{0};
    double Volts{0};
    double Amps{0};

    //Selection for Power
    if (selections == 1) {
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Input Kw: ";
        cin >> Kw;
        cout << "Input Volts: ";
        cin >> Volts;
        double Power{Kw * 1000};
        Amps = {Power / Volts};
        Power_String = "Kw: ";
        PowerPower = {Kw};
        system("cls");
    }
    if (selections == 2) {
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Input Watts: ";
        cin >> Watts;
        cout << "Input Volts: ";
        cin >> Volts;
        Amps = {Watts / Volts};
        Power_String = "Watts: ";
        PowerPower = {Watts};
        system("cls");
    }

    //Input for Ambient Temperature
    cout << "---------Electricity Calculator---------" << endl;
    cout << "----------------------------------------\n";
    Temperature_Options:
    cout << "Choose Temperature Option: " << endl;
    cout << "1) Fahrenheit \n2) Celsius\n\nSelection: ";
    cin >> selections;
    if (selections > 2) {
        system("cls");
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Invalid selection. Try again..\n" << endl;
        goto Temperature_Options;
    }
    system("cls");

    //Allocate Memory.
    double Fahrenheit{0};
    double Convert_Celsius{0};
    double Celsius{0};
    double Initial_Temperature;
    string Temperature_String{};

    //Selection for Temperature
    if (selections == 1) {
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Input Fahrenheit: ";
        cin >> Fahrenheit;
        Convert_Celsius = {(Fahrenheit - 32) * 5 / 9};
        Initial_Temperature = Fahrenheit;
        Temperature_String = "Fahrenheit";
        system("cls");
    }
    if (selections == 2) {
        cout << "---------Electricity Calculator---------" << endl;
        cout << "----------------------------------------\n";
        cout << "Input Celsius: ";
        cin >> Celsius;
        Initial_Temperature = Celsius;
        Temperature_String = "Celsius";
        system("cls");
    }

    //Calculating Ambient/Amp Corrections
    double Ambient_Correction{0};
    double Amp_Correction{0};
    double Differance{0};

    //50 or less Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius <= 10) {
            Ambient_Correction = {1.29};
            Amp_Correction = {Amps};
        }
    }

    //10 or less Celsius
    if (selections == 2) {
        if (Initial_Temperature <= 10.99) {
            Ambient_Correction = {1.29};
            Amp_Correction = {Amps};
        }
    }

    //51-59 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 10.5555 && Convert_Celsius <= 15) {
            Ambient_Correction = {1.22};
            Amp_Correction = {Amps};
        }
    }

    //11-15 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 11 && Initial_Temperature <= 15.99) {
            Ambient_Correction = {1.22};
            Amp_Correction = {Amps};
        }
    }

    //60-68 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 15.5555 && Convert_Celsius <= 20) {
            Ambient_Correction = {1.15};
            Amp_Correction = {Amps};
        }
    }

    //16-20 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 16 && Initial_Temperature <= 20.99) {
            Ambient_Correction = {1.15};
            Amp_Correction = {Amps};
        }
    }

    //69-77 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 20.5555 && Convert_Celsius <= 25) {
            Ambient_Correction = {1.08};
            Amp_Correction = {Amps};
        }
    }

    //21-25 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 21 && Initial_Temperature <= 25.99) {
            Ambient_Correction = {1.08};
            Amp_Correction = {Amps};
        }
    }

    //78-86 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 25.5555 && Convert_Celsius <= 30) {
            Ambient_Correction = {1.00};
            Amp_Correction = {Amps};
        }
    }

    //26-30 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 26 && Initial_Temperature <= 30.99) {
            Ambient_Correction = {1.00};
            Amp_Correction = {Amps};
        }
    }

    //87-95 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 30.5555 && Convert_Celsius <= 35) {
            Ambient_Correction = {0.91};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //31-35 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 31 && Initial_Temperature <= 35.99) {
            Ambient_Correction = {0.91};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //96-104 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 35.5555 && Convert_Celsius <= 40) {
            Ambient_Correction = {0.82};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //36-40 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 36 && Initial_Temperature <= 40.99) {
            Ambient_Correction = {0.82};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //105-113 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 40.5555 && Convert_Celsius <= 45) {
            Ambient_Correction = {0.71};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //41-45 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 41 && Initial_Temperature <= 45.99) {
            Ambient_Correction = {0.71};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //114-122 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 45.5555 && Convert_Celsius <= 50) {
            Ambient_Correction = {0.58};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //46-50 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 46 && Initial_Temperature <= 50.99) {
            Ambient_Correction = {0.58};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //123-131 Fahrenheit
    if (selections == 1) {
        if (Convert_Celsius >= 50.5555 && Convert_Celsius <= 55) {
            Ambient_Correction = {0.41};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //46-50 Celsius
    if (selections == 2) {
        if (Initial_Temperature >= 46 && Initial_Temperature <= 50.99) {
            Ambient_Correction = {0.41};
            Differance = {Amps*Ambient_Correction-Amps};
            Amp_Correction = {fabs(Differance)+Amps};
        }
    }

    //Searching for AWG
    string AWG_Copper{};
    string AWG_Aluminum{};
    string Double_Check{};
    if (Amp_Correction <= 15.99) {
        AWG_Copper = "14 AWG (Copper Wiring)";
    }
    if (Amp_Correction <= 15.99) {
        AWG_Aluminum = "12 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 16 && Amp_Correction <= 20.99) {
        AWG_Copper = "12 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 16 && Amp_Correction <= 25.99) {
        AWG_Aluminum = "10 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 21 && Amp_Correction <= 30.99) {
        AWG_Copper = "10 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 26 && Amp_Correction <= 35.99) {
        AWG_Aluminum = "8 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 31 && Amp_Correction <= 40.99) {
        AWG_Copper = "8 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 36 && Amp_Correction <= 40.99) {
        AWG_Aluminum = "6 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 41 && Amp_Correction <= 55.99) {
        AWG_Copper = "6 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 41 && Amp_Correction <= 55.99) {
        AWG_Aluminum = "4 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 56 && Amp_Correction <= 70.99) {
        AWG_Copper = "4 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 56 && Amp_Correction <= 65.99) {
        AWG_Aluminum = "3 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 71 && Amp_Correction <= 85.99) {
        AWG_Copper = "3 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 66 && Amp_Correction <= 75.99) {
        AWG_Aluminum = "2 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 86 && Amp_Correction <= 95.99) {
        AWG_Copper = "2 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 76 && Amp_Correction <= 85.99) {
        AWG_Aluminum = "1 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction >= 96 && Amp_Correction <= 110.99) {
        AWG_Copper = "1 AWG (Copper Wiring)";
    }
    if (Amp_Correction >= 86 && Amp_Correction <= 100.99) {
        AWG_Aluminum = "1 AWG (Aluminum or Copper-Clad)";
    }
    if (Amp_Correction > 111) {
        AWG_Copper = "-You should consult with a professional before proceeding..";
    }

    //Main Information
    system("cls");
    cout << "---------Electricity Calculator---------" << endl;
    cout << "----------------------------------------\n";
    cout << "Information:\n" << endl;

    //Display Watts/Kw
    cout << Power_String << PowerPower << endl;

    //Display Volts
    cout << "Volts: " << Volts << endl;

    //Display Ambient Temperature
    cout << Temperature_String << ": " << Initial_Temperature << endl;

    //Display Amp/Ambient Correction Factor
    cout << "Amp/Ambient CF: " << Ambient_Correction << endl;

    //Display Corrected Amps
    cout << "Peak Amps: " << Amps << endl;

    //Display AWG
    if(Ambient_Correction>=1){
        cout << "\nRecommended wire sizes are:\n" << "-" << AWG_Copper << "\n" << "-" << AWG_Aluminum << endl;
//        cout << "*This wire can handle up to " << Amps * Ambient_Correction << " amps in temperatures at " << Initial_Temperature << " " << Temperature_String << ". If current increases, proceed with caution." << endl;
    }
    if(Ambient_Correction<=.99){
        cout << "\nCorrected wire sizes are:\n" << "-" << AWG_Copper << "\n" << "-" << AWG_Aluminum << endl;
//        cout << "*Wire size increased due to elevated ambient temperatures." << endl;
    }
    cout << "\n\n**Death is possible. 1.0 to 4.3 Amps Rhythmic pumping action of the heart ceases. \nMuscular contraction and nerve damage occur; death is likely. 10 Amps Cardiac arrest, \nsevere burns, death is probable.\n\n" << endl;

    //Exiting Program
    cout << "----------------------------------------\n";
    cout << "Exit Application? y/n: ";
    char exit;
    cin >> exit;
    if (exit == 'n') {
        system("cls");
        goto Start;
    }
    if (exit == 'y') {
        return 0;
    }
}
