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

void exisitiertInVector(string x, vector<string> y, string nameEingabe)		//Überprüft ob Variable in Vektor exisiert
{
	for (int i = 0; i < y.size(); ++i)
	{
		if (x == y[i])									//Wenn ja, dann true zurück
		{
			return;
		}
	}
	error("Der " + nameEingabe + " konnte nicht gelesen werden.\n");								//Wenn alle nein, dann Fehler
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
	if (y == 0)
	{
		error("Division durch 0 ist nicht erlaubt\n");
	}
	else
	{
		return double(x) / y;			//Nichttypsicher
	}
}

int geteilt(int x, int y)
{
	if (y == 0)
	{
		error("Division durch 0 ist nicht erlaubt\n");
	}
	else
	{
		return x / y;
	}
}


int main()
{
	string ersterOperand;
	string rechenZeichen;
	string zweiterOperand;

	vector<string> erlaubteZahlen = {"null", "ein", "eins", "zwei", "drei", "vier", "fuenf", "sechs", "sieben", "acht", "neun", "zehn" };
	vector<string> erlaubteOperatoren = { "plus", "minus", "mal", "geteilt-durch", "dividiert-durch" };
	vector<double> Ergebnisse = {};				//Nichttypsicher

	while (true)
	{
		bool thisLoopError = false;				//Variable für später zum Überprüfen, ob es in diesem Durchlauf einen Fehler gab
		cin >> ersterOperand;
		if (ersterOperand == "ende")
		{
			break;								//while beenden
		}
		cin >> rechenZeichen;
		if (rechenZeichen == "ende")
		{
			break;								//while beenden
		}
		cin >> zweiterOperand;
		if (zweiterOperand == "ende")
		{
			break;								//while beenden
		}
		try 
		{
			exisitiertInVector(ersterOperand, erlaubteZahlen, "erste Operand");
			exisitiertInVector(rechenZeichen, erlaubteOperatoren, "Operator");
			exisitiertInVector(zweiterOperand, erlaubteZahlen, "zweite Operand");
		}
		catch (runtime_error& e)		//Fehler auffangen
		{
			cout << e.what();
			thisLoopError = true;		//Fehler merken
		};

		if (!thisLoopError)		//Wenn kein Error geschehen ist machen
		{
			
			int ersteZahl = konvertierungVonStringInInt(ersterOperand);
			int zweiteZahl = konvertierungVonStringInInt(zweiterOperand);
			
			//Rechnen und speichern
			if (rechenZeichen == "plus")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(addition(ersteZahl, zweiteZahl));
			}
			else if (rechenZeichen == "mal")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(multiplikation(ersteZahl, zweiteZahl));
			}
			else if (rechenZeichen == "minus")
			{
				cout << "Gespeichert\n";
				Ergebnisse.push_back(subtraktion(ersteZahl, zweiteZahl));
			}
			else if (rechenZeichen == "geteilt-durch")
			{
				try
				{
					Ergebnisse.push_back(geteilt(ersteZahl, zweiteZahl));
					cout << "Gespeichert\n";
				}
				catch (runtime_error& e)
				{
					cout << e.what();
				}
			}
			else if (rechenZeichen == "dividiert-durch")
			{
				try
				{
					Ergebnisse.push_back(division(ersteZahl, zweiteZahl));
					cout << "Gespeichert\n";
				}
				catch(runtime_error& e)
				{
					cout << e.what();
				}
			}
		}
	}
	//Ausgabe der Ergebnisse
	if (Ergebnisse.size() == 0)
	{
		cout << "Es gibt keine Ergebnisse\n";
	}
	else if (Ergebnisse.size() == 1)
	{
		cout << "Das Ergebnis ist: " << Ergebnisse[0] << '\n';
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
			else 
			{
				cout << Ergebnisse[i] << ", ";
			}
		}
	}
	return 0;
}
