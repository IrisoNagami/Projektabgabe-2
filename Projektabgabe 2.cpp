#include "std_lib_inc.h"

int konvertierungVonStringInInt(string x)
{
	if (x == "ein" or x == "eins")
		return 1;
	else if (x == "zwei")
		return 2;
	else if (x == "drei")
		return 3;
	else if (x == "vier")
		return 4;
	else if (x == "fuenf")
		return 5;
	else if (x == "sechs")
		return 6;
	else if (x == "sieben")
		return 7;
	else if (x == "acht")
		return 8;
	else if (x == "neun")
		return 9;
	else if (x == "zehn")
		return 10;
	else if (x == "null")
		return 0;
}

bool exisitiertInVector(string x, vector<string> y)		//Überprüft ob Variable in Vektor exisiert
{
	for (int i = 0; i < y.size(); ++i)
	{
		if (x == y[i])									//Wenn ja, dann true zurück
		{
			return true;
		}
	}
	return false;										//Wenn alle nein, dann false zurück
}

int addition(int x, int y)
{
	return x + y;
}

int multiplikation(int x, int y)
{
	return x * y;
}

int subtraktion(int x, int y)
{
	return x - y;
}

double division(int x, int y)		//Gleitkommazahlen
{
	return double(x) / y;
}

int geteilt(int x, int y)
{
	return x / y;
}

void AusgabeErgebnisse(vector<double> Ergebnisse)
{
	//Ausgabe der Ergebnisse
	cout << "Die Ergebnisse sind: ";
	for (int i = 0; i < Ergebnisse.size(); ++i)
	{
		cout << Ergebnisse[i] << ", ";
	}
}

int main()
{
	string ersterOperant;
	string rechenZeichen;
	string zweiterOperant;

	vector<string> erlaubteZahlen = {"null", "ein", "eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun", "zehn" };
	vector<string> erlaubteOperatoren = { "plus", "minus", "mal", "geteilt-durch", "dividiert-durch" };
	vector<double> Ergebnisse = {};

	//Überprüfung, ob beendet werden soll
	if (ersterOperant == "ende")
	{
		AusgabeErgebnisse(Ergebnisse);
		return 0;
	}



	while (true)
	{
		cin >> ersterOperant;
		if (ersterOperant == "ende")
		{
			break;
		}
		cin >> rechenZeichen;
		cin >> zweiterOperant;

		bool korrekteEingabe_ersterOperant = exisitiertInVector(ersterOperant, erlaubteZahlen);
		bool korrekteEingabe_zweiterOperant = exisitiertInVector(zweiterOperant, erlaubteZahlen);
		bool korrekteEingabe_rechenZeichen = exisitiertInVector(rechenZeichen, erlaubteOperatoren);

		//Ausgabe, bei einer falschen Eingabe
		if (!(korrekteEingabe_ersterOperant))
		{
			cout << "Der erste Operand konnte nicht gelesen werden." << "\n";
		}
		else if (!(korrekteEingabe_rechenZeichen))
		{
			cout << "Der Operator konnte nicht gelesen werden." << "\n";
		}
		else if (!(korrekteEingabe_zweiterOperant))
		{
			cout << "Der zweite Operand konnte nicht gelesen werden." << "\n";
		}
		else
		{
			if ((rechenZeichen == "dividiert-durch" || rechenZeichen == "geteilt-durch") && zweiterOperant == "null")
			{
				cout << "Division durch 0 ist nicht erlaubt\n";
			}
			//Rechnen und speichern
			else if (rechenZeichen == "plus")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(addition(konvertierungVonStringInInt(ersterOperant), konvertierungVonStringInInt(zweiterOperant)));
			}
			else if (rechenZeichen == "mal")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(multiplikation(konvertierungVonStringInInt(ersterOperant), konvertierungVonStringInInt(zweiterOperant)));
			}
			else if (rechenZeichen == "minus")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(subtraktion(konvertierungVonStringInInt(ersterOperant), konvertierungVonStringInInt(zweiterOperant)));
			}
			else if (rechenZeichen == "geteilt-durch")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(geteilt(konvertierungVonStringInInt(ersterOperant), konvertierungVonStringInInt(zweiterOperant)));
			}
			else if (rechenZeichen == "dividiert-durch")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(division(konvertierungVonStringInInt(ersterOperant), konvertierungVonStringInInt(zweiterOperant)));
			}
		}
	}
	//Ausgabe der Ergebnisse
	if (Ergebnisse.size() == 0)
	{
		cout << "Es gibt keine Ergebnisse\n";
	}
	else
	{
		cout << "Die Ergebnisse sind: ";
		for (int i = 0; i < Ergebnisse.size(); ++i)
		{
			if (i + 1 == Ergebnisse.size())
			{
				cout << Ergebnisse[i] << "\n";
			}
			cout << Ergebnisse[i] << ", ";
		}
	}
	//AusgabeErgebnisse(Ergebnisse);
	return 0;
}