#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>

using namespace std;

// Helper function to clear the screen based on the OS.
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to get a valid number input from the user.
double getValidInput(const string& prompt) {
    double value;
    cout << prompt;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a valid number: ";
    }
    return value;
}

// Function to get a valid selection within a given range.
int getValidSelection(const string& prompt, int min, int max) {
    int selection;
    while (true) {
        cout << prompt;
        if (cin >> selection && selection >= min && selection <= max) {
            break;
        }
        else {
            cout << "Invalid selection. Try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return selection;
}

// Function to determine the copper AWG based on corrected amps.
string getCopperAWG(double ampCorr) {
    if (ampCorr > 111)
        return "Consult with a professional";
    else if (ampCorr >= 96)
        return "1 AWG (Copper Wiring)";
    else if (ampCorr >= 86)
        return "2 AWG (Copper Wiring)";
    else if (ampCorr >= 71)
        return "3 AWG (Copper Wiring)";
    else if (ampCorr >= 56)
        return "4 AWG (Copper Wiring)";
    else if (ampCorr >= 41)
        return "6 AWG (Copper Wiring)";
    else if (ampCorr >= 31)
        return "8 AWG (Copper Wiring)";
    else if (ampCorr >= 21)
        return "10 AWG (Copper Wiring)";
    else if (ampCorr >= 16)
        return "12 AWG (Copper Wiring)";
    else
        return "14 AWG (Copper Wiring)";
}

// Function to determine the aluminum AWG based on corrected amps.
string getAluminumAWG(double ampCorr) {
    if (ampCorr > 111)
        return "Consult with a professional";
    else if (ampCorr <= 15.99)
        return "12 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 25.99)
        return "10 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 35.99)
        return "8 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 40.99)
        return "6 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 55.99)
        return "4 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 65.99)
        return "3 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 75.99)
        return "2 AWG (Aluminum or Copper-Clad)";
    else if (ampCorr <= 100.99)
        return "1 AWG (Aluminum or Copper-Clad)";
    else
        return "1 AWG (Aluminum or Copper-Clad)";
}

int main() {
    bool run = true;
    while (run) {
        clearScreen();
        cout << "---------Electricity Calculator---------\n"
            << "----------------------------------------\n";

        // Power input selection
        int powerSelection = getValidSelection(
            "Choose Power Option:\n1) kW\n2) Watts\n\nSelection: ", 1, 2);

        double powerValue, volts, amps;
        string powerLabel;
        if (powerSelection == 1) {
            powerValue = getValidInput("Input kW: ");
            volts = getValidInput("Input Volts: ");
            // Convert kW to Watts
            double watts = powerValue * 1000;
            amps = watts / volts;
            powerLabel = "kW: ";
        }
        else {
            powerValue = getValidInput("Input Watts: ");
            volts = getValidInput("Input Volts: ");
            amps = powerValue / volts;
            powerLabel = "Watts: ";
        }
        clearScreen();

        // Temperature input selection
        cout << "---------Electricity Calculator---------\n"
            << "----------------------------------------\n";
        int tempSelection = getValidSelection(
            "Choose Temperature Option:\n1) Fahrenheit\n2) Celsius\n\nSelection: ", 1, 2);
        double tempInput, tempC;
        string tempLabel;
        if (tempSelection == 1) {
            tempInput = getValidInput("Input Fahrenheit: ");
            // Convert Fahrenheit to Celsius
            tempC = (tempInput - 32) * 5.0 / 9.0;
            tempLabel = "Fahrenheit";
        }
        else {
            tempInput = getValidInput("Input Celsius: ");
            tempC = tempInput;
            tempLabel = "Celsius";
        }
        clearScreen();

        // Determine ambient correction factor based on temperature (in Celsius)
        double ambientCorrection = 1.0;
        if (tempC <= 10)
            ambientCorrection = 1.29;
        else if (tempC <= 15)
            ambientCorrection = 1.22;
        else if (tempC <= 20)
            ambientCorrection = 1.15;
        else if (tempC <= 25)
            ambientCorrection = 1.08;
        else if (tempC <= 30)
            ambientCorrection = 1.00;
        else if (tempC <= 35)
            ambientCorrection = 0.91;
        else if (tempC <= 40)
            ambientCorrection = 0.82;
        else if (tempC <= 45)
            ambientCorrection = 0.71;
        else if (tempC <= 50)
            ambientCorrection = 0.58;
        else if (tempC <= 55)
            ambientCorrection = 0.41;
        else
            ambientCorrection = 0.41;  // Default for temperatures above 55°C

        // Calculate corrected amps: adjust if ambientCorrection is less than 1.
        double correctedAmps = (ambientCorrection < 1.0) ? amps * (2 - ambientCorrection) : amps;

        // Determine recommended wire sizes based on the corrected amps.
        string copperAWG = getCopperAWG(correctedAmps);
        string aluminumAWG = getAluminumAWG(correctedAmps);

        // Display the results.
        cout << "\n----------------Results-----------------\n"
            << "----------------------------------------\n";
        cout << "\n";
        cout << powerLabel << powerValue << "\n";
        cout << "Volts: " << volts << "\n";
        cout << tempLabel << ": " << tempInput << "\n";
        cout << "Amp/Ambient Correction Factor: " << ambientCorrection << "\n";
        cout << "Peak Amps: " << amps << "\n\n";
        cout << "Recommended wire sizes are:\n";
        cout << "- " << copperAWG << "\n";
        cout << "- " << aluminumAWG << "\n\n";

        // Ask if the user wants to exit.
        cout << "Exit Application? (y/n): ";
        char exitChoice;
        cin >> exitChoice;
        if (tolower(exitChoice) == 'y') {
            run = false;
        }
    }
    return 0;
}
