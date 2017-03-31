
#include <stdlib.h>
#include "iostream"
using namespace std;

/*metavlites tou pinaka*/
char BoxOne = ' ';     /*    arxikopoioume tis metablites twn keliwn tou pinaka           */
char BoxTwo = ' ';
char BoxThree = ' ';
char BoxFour = ' ';
char BoxFive = ' ';
char BoxSix = ' ';
char BoxSeven = ' ';
char BoxEight = ' ';
char BoxNine = ' ';

/*metablites*/
int retry(0);//metavliti  pou xrisimopoieite stin sinartisi void PlayAgain gia na rwtisei an theloume kialo giro
int EpilogiPexti;// einai i epilogi pou dinei o pektis apo to pliktrologio
int WhoWins(0); //  xekinaei apo tin timi 0  . an parei tin timi 1 i 2 i 3 stamataei to loop kai checkarei poios kerdise.An einai 1 kerdizei o AI an einai 2 kerdizei o pextis an einai 3 isopalia
bool SeiraPexti;//true otan einai i seira tou pexti , false otan einai i seira tou AI

/*sinartiseis*/
int CheckEpilogiPexti();// me vasi tin epilogi tou pexti vazei ston pinaka to 'X' sto katalilo kouti
int PaiximoAI(); //pezei to AI simfwna me tis nikitries stiles
int AIWins();// an kanei triliza me 'O' nikaei o AI
int PlayerWins();//an kanei triliza me 'X' nikaei o pextis
int Isopalia();// an teleiwsoun ta koutakia kai dn iparxei triliza simeiwnei isopalia
int WhoseTurn();// Rwtaei an theloume na pexoume prwtoi i na pexei o AI prwtos

void EmfaniseWhoWins(); // Emfanizei ean nikisame - xasame i irthe isopalia
void EmfanisiPinaka();//emfanizei ton pinaka tis trilizas
void PlayAgain();//sinartisi p xrisimopoieite gia na pexoume alon giro
void Welcome();// kalosorisma sto paixnidi


int main(int argc, char** argv) {

	do
	{

	Welcome();
	WhoseTurn();
	do
	{

		if (SeiraPexti == true) {
			cout << "\t\t\t       Seira tou paixti !\n\n";
			cout << "\t\t\tEpelexe ena koutaki apo to 1-9" << endl;
			EmfanisiPinaka();
			cin >> EpilogiPexti;
			cout << endl;
			while (EpilogiPexti < 1 || EpilogiPexti > 9 || EpilogiPexti == ' ')
			{
				cout << "\n\t\t\tExeis dwsei lathos apantisi.\n\t\t     Parakalw pliktrologise apo to 1-9 !\n\n";
				cin.clear();                        /*    aftes oi 2 edoles katharizoun to cin mas  kai etc den exoume atermona broxo. an tis paralipsw tha kolisei i console.*/
				cin.ignore(1, '\n');
				cin >> EpilogiPexti;
				cout << endl;
				continue;

			}

			CheckEpilogiPexti();
			cout << "\t\t\t Exeis epilexei  \" X \"  sto " << EpilogiPexti << endl;
			EmfanisiPinaka();
			PlayerWins();
			Isopalia();
			SeiraPexti = false;

		}


		if (SeiraPexti == false) {
			/*   edw benei i eswteriki if dioti aliws otan gemizoun ta koutia allazei i seira tou pexti se false  kai benei kai trexei ali mia fora , emfanizei dixws logo to cout minima kai ton pinaka kai afou vlepei oti dn exei alla koutia tote mas  vgazei pios kerdise   */
			if (WhoWins == 0) {
				cout << "\t\t      Seira tou Artificial Inteligence  !\n" << endl;
				PaiximoAI();
				EmfanisiPinaka();
				AIWins();
				Isopalia();

			}

		}

	} while (WhoWins == 0);

	EmfaniseWhoWins();

	PlayAgain();


	} while (retry == 0);





    return (EXIT_SUCCESS);
}

int CheckEpilogiPexti() {
	while ((EpilogiPexti == 1 && (BoxOne == 'O' || BoxOne == 'X')) || (EpilogiPexti == 2 && (BoxTwo == 'O' || BoxTwo == 'X')) || (EpilogiPexti == 3 && (BoxThree == 'O' || BoxThree == 'X')) || (EpilogiPexti == 4 && (BoxFour == 'O' || BoxFour == 'X')) || (EpilogiPexti == 5 && (BoxFive == 'O' || BoxFive == 'X')) || (EpilogiPexti == 6 && (BoxSix == 'O' || BoxSix == 'X')) || (EpilogiPexti == 7 && (BoxSeven == 'O' || BoxSeven == 'X')) || (EpilogiPexti == 8 && (BoxEight == 'O' || BoxEight == 'X')) || (EpilogiPexti == 9 && (BoxNine == 'O' || BoxNine == 'Z')))

	{
		cout << "\t\t  To koutaki pou epelexes xrisimopoieitai.\n\t\t\t  Parakalw dwse ali epilogi\n";
		cin.clear();
		cin.ignore(1, '\n');
		cin >> EpilogiPexti;
		cout << endl;
		continue;
	}

	if (EpilogiPexti == 1) {


		BoxOne = 'X';

	}
	if (EpilogiPexti == 2) {

		BoxTwo = 'X';

	}

	if (EpilogiPexti == 3) {

		BoxThree = 'X';
	}

	if (EpilogiPexti == 4) {

		BoxFour = 'X';

	}

	if (EpilogiPexti == 5) {

		BoxFive = 'X';

	}

	if (EpilogiPexti == 6) {

		BoxSix = 'X';

	}

	if (EpilogiPexti == 7) {

		BoxSeven = 'X';
	}

	if (EpilogiPexti == 8) {

		BoxEight = 'X';

	}

	if (EpilogiPexti == 9) {

		BoxNine = 'X';

	}


	return 0;
}

int PaiximoAI() {
	//apo edw pezei gia na nikisei ton pexti (kinisi me kinitro tin niki ). Opote prwta tha psaxei na nikisei kai meta na aminthei. episis epeidi exei pola kritiria na psaxei benei i else if dioti an valoume apla if tixainei na dwsei 2 koutakia se mia mono kinisi tou AI.

	//kouti 1-2-3
	if (BoxOne == 'O' && BoxTwo == 'O'  && BoxThree == ' '  && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi  \" O \"  sto 3";
		BoxThree = 'O';
		SeiraPexti = true;

	}
	if (BoxOne == 'O' && BoxTwo == ' ' && BoxThree == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 2";
		BoxTwo = 'O';
		SeiraPexti = true;
	}
	if (BoxOne == ' ' && BoxTwo == 'O'  && BoxThree == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 1";
		BoxOne = 'O';
		SeiraPexti = true;

	}

	//kouti 4-5-6
	if (BoxFour == 'O' && BoxFive == 'O'  && BoxSix == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 6";
		BoxSix = 'O';
		SeiraPexti = true;

	}
	if (BoxFour == 'O' && BoxFive == ' '  && BoxSix == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 5";
		BoxFive = 'O';
		SeiraPexti = true;
	}
	if (BoxFour == ' ' && BoxFive == 'O'  && BoxSix == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 4";
		BoxFour = 'O';
		SeiraPexti = true;
	}
	//kouti 7-8-9
	if (BoxSeven == 'O' && BoxEight == 'O'  && BoxNine == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 9";
		BoxNine = 'O';
		SeiraPexti = true;
	}
	if (BoxSeven == 'O' && BoxEight == ' ' && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 8";
		BoxEight = 'O';
		SeiraPexti = true;
	}
	if (BoxSeven == ' ' && BoxEight == 'O'  && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 7";
		BoxSeven = 'O';
		SeiraPexti = true;
	}
	//kouti kouti 1-5-9
	if (BoxOne == 'O' && BoxFive == 'O'  && BoxNine == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 9";
		BoxNine = 'O';
		SeiraPexti = true;
	}
	if (BoxOne == 'O' && BoxFive == ' '  && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 5";
		BoxFive = 'O';
		SeiraPexti = true;
	}
	if (BoxOne == ' ' && BoxFive == 'O' && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 1";
		BoxOne = 'O';
		SeiraPexti = true;
	}
	//kouti 3-5-7
	if (BoxThree == 'O' && BoxFive == 'O'  && BoxSeven == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 7";
		BoxSeven = 'O';
		SeiraPexti = true;
	}
	if (BoxThree == 'O' && BoxFive == ' '  && BoxSeven == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 5";
		BoxFive = 'O';
		SeiraPexti = true;
	}
	if (BoxThree == ' ' && BoxFive == 'O' && BoxSeven == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 3";
		BoxThree = 'O';
		SeiraPexti = true;
	}
	//kouti 1-4-7
	if (BoxOne == 'O' && BoxFour == 'O'  && BoxSeven == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 7";
		BoxSeven = 'O';
		SeiraPexti = true;
	}
	if (BoxOne == 'O' && BoxFour == ' '  && BoxSeven == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 4";
		BoxFour = 'O';
		SeiraPexti = true;
	}
	if (BoxOne == ' ' && BoxFour == 'O'  && BoxSeven == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 1";
		BoxOne = 'O';
		SeiraPexti = true;
	}
	//kouti 2-5-8
	if (BoxTwo == 'O' && BoxFive == 'O'  && BoxEight == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 8";
		BoxEight = 'O';
		SeiraPexti = true;
	}
	if (BoxTwo == 'O' && BoxFive == ' '  && BoxEight == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 5";
		BoxFive = 'O';
		SeiraPexti = true;
	}
	if (BoxTwo == ' ' && BoxFive == 'O'  && BoxEight == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 2";
		BoxTwo = 'O';
		SeiraPexti = true;
	}
	//kouti 3-6-9
	if (BoxThree == 'O' && BoxSix == 'O'  && BoxNine == ' ' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 9";
		BoxNine = 'O';
		SeiraPexti = true;
	}
	if (BoxThree == 'O' && BoxSix == ' '  && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 6";
		BoxSix = 'O';
		SeiraPexti = true;
	}
	if (BoxThree == ' ' && BoxSix == 'O'  && BoxNine == 'O' && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 3";
		BoxThree = 'O';
		SeiraPexti = true;
	}
	//apo edw pezei gia na aminthei apenanti ston pexti ( apotropi trilizas pexti)


	//kouti 1-2-3
	if ((EpilogiPexti == 1 || EpilogiPexti == 2 || EpilogiPexti == 3) && SeiraPexti == false) {

		if (BoxOne == 'X' && BoxTwo == 'X' && BoxThree == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 3";
			BoxThree = 'O';
			SeiraPexti = true;

		}
		if (BoxOne == 'X' && BoxTwo == ' ' && BoxThree == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 2";
			BoxTwo = 'O';
			SeiraPexti = true;
		}
		if (BoxOne == ' ' && BoxTwo == 'X' && BoxThree == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 1";
			BoxOne = 'O';
			SeiraPexti = true;

		}

	}

	//kouti 4-5-6
	if ((EpilogiPexti == 4 || EpilogiPexti == 5 || EpilogiPexti == 6) && SeiraPexti == false) {

		if (BoxFour == 'X' && BoxFive == 'X' && BoxSix == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 6";
			BoxSix = 'O';
			SeiraPexti = true;

		}
		if (BoxFour == 'X' && BoxFive == ' ' && BoxSix == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 5";
			BoxFive = 'O';
			SeiraPexti = true;
		}
		if (BoxFour == ' ' && BoxFive == 'X' && BoxSix == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 4";
			BoxFour = 'O';
			SeiraPexti = true;
		}
	}
	//kouti 7-8-9

	if ((EpilogiPexti == 7 || EpilogiPexti == 8 || EpilogiPexti == 9) && SeiraPexti == false) {

		if (BoxSeven == 'X' && BoxEight == 'X' && BoxNine == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 9";
			BoxNine = 'O';
			SeiraPexti = true;
		}
		if (BoxSeven == 'X' && BoxEight == ' ' && BoxNine == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 8";
			BoxEight = 'O';
			SeiraPexti = true;
		}
		if (BoxSeven == ' ' && BoxEight == 'X' && BoxNine == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 7";
			BoxSeven = 'O';
			SeiraPexti = true;
		}
	}

	//kouti 1-5-9
	if ((EpilogiPexti == 1 || EpilogiPexti == 5 || EpilogiPexti == 9) && SeiraPexti == false) {

		if (BoxOne == 'X' && BoxFive == 'X' && BoxNine == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 9";
			BoxNine = 'O';
			SeiraPexti = true;
		}
		if (BoxOne == 'X' && BoxFive == ' ' && BoxNine == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 5";
			BoxFive = 'O';
			SeiraPexti = true;
		}
		if (BoxOne == ' ' && BoxFive == 'X' && BoxNine == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 1";
			BoxOne = 'O';
			SeiraPexti = true;
		}
	}

	//kouti 3-5-7
	if ((EpilogiPexti == 3 || EpilogiPexti == 5 || EpilogiPexti == 7) && SeiraPexti == false) {

		if (BoxThree == 'X' && BoxFive == 'X' && BoxSeven == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 7";
			BoxSeven = 'O';
			SeiraPexti = true;
		}
		if (BoxThree == 'X' && BoxFive == ' ' && BoxSeven == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 5";
			BoxFive = 'O';
			SeiraPexti = true;
		}
		if (BoxThree == ' ' && BoxFive == 'X' && BoxSeven == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 3";
			BoxThree = 'O';
			SeiraPexti = true;
		}
	}

	//kouti 1-4-7
	if ((EpilogiPexti == 1 || EpilogiPexti == 4 || EpilogiPexti == 7) && SeiraPexti == false) {

		if (BoxOne == 'X' && BoxFour == 'X' && BoxSeven == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 7";
			BoxSeven = 'O';
			SeiraPexti = true;
		}
		if (BoxOne == 'X' && BoxFour == ' ' && BoxSeven == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 4";
			BoxFour = 'O';
			SeiraPexti = true;
		}
		if (BoxOne == ' ' && BoxFour == 'X' && BoxSeven == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 1";
			BoxOne = 'O';
			SeiraPexti = true;
		}
	}

	//kouti 2-5-8
	if ((EpilogiPexti == 2 || EpilogiPexti == 5 || EpilogiPexti == 8) && SeiraPexti == false) {

		if (BoxTwo == 'X' && BoxFive == 'X' && BoxEight == ' ' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 8";
			BoxEight = 'O';
			SeiraPexti = true;
		}
		if (BoxTwo == 'X' && BoxFive == ' ' && BoxEight == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 5";
			BoxFive = 'O';
			SeiraPexti = true;
		}
		if (BoxTwo == ' ' && BoxFive == 'X' && BoxEight == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 2";
			BoxTwo = 'O';
			SeiraPexti = true;
		}
	}

	//kouti 3-6-9
	if ((EpilogiPexti == 3 || EpilogiPexti == 6 || EpilogiPexti == 9) && SeiraPexti == false) {

		if (BoxThree == 'X' && BoxSix == 'X' && BoxNine == ' ' && SeiraPexti == false) {

			cout << "\t\t\t    Exei epilexi \" O \" sto 9";
			BoxNine = 'O';
			SeiraPexti = true;
		}
		if (BoxThree == 'X' && BoxSix == ' ' && BoxNine == 'X' && SeiraPexti == false) {

			cout << "\t\t\t    Exei epilexi \" O \" sto 6";
			BoxSix = 'O';
			SeiraPexti = true;
		}
		if (BoxThree == ' ' && BoxSix == 'X' && BoxNine == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 3";
			BoxThree = 'O';
			SeiraPexti = true;
		}

	}

	/*  epeidi stin arxi dn exei na sigrinei kati epeidi exei mono 1 stixio i triliza  (X)  i (O)   tha erthei kai tha  pexei simfwna me to parakatw  , giafto benei kai teleftea afto to group twn if              */


	if ((BoxFive == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 5";
		BoxFive = 'O';
		SeiraPexti = true;
	}
	if ((BoxOne == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 1";
		BoxOne = 'O';
		SeiraPexti = true;
	}
	if ((BoxNine == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 9";
		BoxNine = 'O';
		SeiraPexti = true;

	}
	if ((BoxThree == ' ') && SeiraPexti == false) {
		if (BoxNine == 'X'&& BoxOne == 'X' && SeiraPexti == false) {
			cout << "\t\t\t    Exei epilexi \" O \" sto 4";
			BoxFour = 'O';
			SeiraPexti = true;
		}
		else
		{
			cout << "\t\t\t    Exei epilexi \" O \" sto 3";
			BoxThree = 'O';
			SeiraPexti = true;
		}

	}

	if ((BoxSeven == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 7";
		BoxSeven = 'O';
		SeiraPexti = true;
	}
	if ((BoxFour == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 4";
		BoxFour = 'O';
		SeiraPexti = true;
	}

	if ((BoxTwo == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 2";
		BoxTwo = 'O';
		SeiraPexti = true;
	}

	if ((BoxSix == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 6";
		BoxSix = 'O';
		SeiraPexti = true;
	}



	if ((BoxEight == ' ') && SeiraPexti == false) {
		cout << "\t\t\t    Exei epilexi \" O \" sto 8";
		BoxEight = 'O';
		SeiraPexti = true;
	}

	return 0;
}

int AIWins() {
	if (BoxOne == 'O' && BoxTwo == 'O' && BoxThree == 'O') {

		WhoWins = 1;
	}
	if (BoxFour == 'O' && BoxFive == 'O' && BoxSix == 'O') {

		WhoWins = 1;
	}
	if (BoxSeven == 'O' && BoxEight == 'O' && BoxNine == 'O') {

		WhoWins = 1;

	}
	if (BoxOne == 'O' && BoxFour == 'O' && BoxSeven == 'O') {

		WhoWins = 1;
	}
	if (BoxTwo == 'O' && BoxFive == 'O' && BoxEight == 'O') {

		WhoWins = 1;
	}
	if (BoxThree == 'O' && BoxSix == 'O' && BoxNine == 'O') {

		WhoWins = 1;
	}
	if (BoxOne == 'O' && BoxFive == 'O' && BoxNine == 'O') {

		WhoWins = 1;
	}
	if (BoxThree == 'O' && BoxFive == 'O' && BoxSeven == 'O') {

		WhoWins = 1;
	}

	return WhoWins;

}

int PlayerWins() {
	if (BoxOne == 'X' && BoxTwo == 'X' && BoxThree == 'X') {

		WhoWins = 2;
	}
	if (BoxFour == 'X' && BoxFive == 'X' && BoxSix == 'X') {

		WhoWins = 2;
	}
	if (BoxSeven == 'X' && BoxEight == 'X' && BoxNine == 'X') {

		WhoWins = 2;

	}
	if (BoxOne == 'X' && BoxFour == 'X' && BoxSeven == 'X') {

		WhoWins = 2;
	}
	if (BoxTwo == 'X' && BoxFive == 'X' && BoxEight == 'X') {

		WhoWins = 2;
	}
	if (BoxThree == 'X' && BoxSix == 'X' && BoxNine == 'X') {

		WhoWins = 2;
	}
	if (BoxOne == 'X' && BoxFive == 'X' && BoxNine == 'X') {

		WhoWins = 2;
	}
	if (BoxThree == 'X' && BoxFive == 'X' && BoxSeven == 'X') {

		WhoWins = 2;
	}

	return WhoWins;


}

int Isopalia() {
	/* to dokimasa etc kai doulevei enalaktika tha borousa na to grapsw pio swsta ws  if ((BoxOne == 'O" || BoxOne == 'X') && (BoxTwo == 'O' || BoxTwo == 'X').......(BoxNine == 'O' || BoxNine == 'X'))       */

	if (BoxOne != ' ' && BoxTwo != ' ' && BoxThree != ' ' && BoxFour != ' ' && BoxFive != ' ' && BoxSix != ' ' && BoxSeven != ' ' && BoxEight != ' ' && BoxNine != ' ') {

		WhoWins = 3;
	}
	return WhoWins;
}

int WhoseTurn() {

	int apantisi;


	cout << "\n\n\n\t\t\tGia na pexeis prwtos patise  1\n\n\t\tGia na pexei o Artificial Inteligence patise 2 \n\n ";
	cin >> apantisi;
	cout << endl;
	while (apantisi < 1 || apantisi > 2 || apantisi == ' ') {

		cout << "\t\tExeis dwsei lathos apantisi, epelexe 1 i 2!\n\n ";
		cin.clear();
		cin.ignore(1, '\n');
		cin >> apantisi;
		continue;

	}
	if (apantisi == 1) {

		SeiraPexti = true;
	}
	if (apantisi == 2) {
		SeiraPexti = false;
	}
	return SeiraPexti;

}

void EmfaniseWhoWins() {

	if (WhoWins == 1) {

		cout << "\t\t    Kerdise o Aartifixcial Inteligence !\n\n";
	}
	if (WhoWins == 2) {

		cout << "\t\t\t  Kerdises, sigxaritiria !\n\n";
	}

	if (WhoWins == 3) {

		cout << "\t\t\t  To Score Einai Isopalia !\n\n";
	}
}

void PlayAgain() {
	int PareApantisi ;
	cout << "\t\tTheleis na paixeis alon giro ? 1) Nai | 2) Oxi \n\n";
		cin >> PareApantisi;
		while (PareApantisi < 1 || PareApantisi > 2)
		{
			cout << "\t\t\tExeis dwsei lanthasmenh apantisi.\n\n\t\t\t     Parakalw epelexe 1 i 2\n\n";
			cin.clear();
			cin.ignore(1, '\n');
			cin >> PareApantisi;
			cout << endl;
			continue;
		}


		if (PareApantisi == 1 ){

			retry = 0;
			WhoWins = 0;
			BoxOne = char(32); // char (32) einai to space . an dn to orisoume exei stin mnimi ta proigoumena apotelesmata kai otan xekinae defteros giros emfanizei ston pinaka afta p exoun pextei apo ton proigoumeno gyro.
			BoxTwo = char(32);
			BoxThree = char(32);
			BoxFour = char(32);
			BoxFive = char(32);
			BoxSix = char(32);
			BoxSeven = char(32);
			BoxEight = char(32);
			BoxNine = char(32);

		}
		else
		{
			retry = 1;
		}





}

void Welcome() {
	char BoxOne = '1';
	char BoxTwo = '2';
	char BoxThree = '3';
	char BoxFour = '4';
	char BoxFive = '5';
	char BoxSix = '6';
	char BoxSeven = '7';
	char BoxEight = '8';
	char BoxNine = '9';


	cout << "\t\t      Kalwsirthes sto paixnidi triliza!\n\n\t\t      San paixtis exeis tin epilogi \" X \"\n\n\t\tO Artificial inteligence exei tin epilogh \" O \"\n\n";
	cout << "\t\tO pinakas exei 9 koutakia kai einai tis morfis :";
	cout << "\n\n\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxOne << "  |  " << BoxTwo << "  |  " << BoxThree << "  |" << endl;
	cout << "\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxFour << "  |  " << BoxFive << "  |  " << BoxSix << "  |" << endl;
	cout << "\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxSeven << "  |  " << BoxEight << "  |  " << BoxNine << "  |" << endl;
	cout << "\t\t\t     -------------------\n\n" << endl;

}

void EmfanisiPinaka() {

	cout << "\n\n\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxOne << "  |  " << BoxTwo << "  |  " << BoxThree << "  |" << endl;
	cout << "\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxFour << "  |  " << BoxFive << "  |  " << BoxSix << "  |" << endl;
	cout << "\t\t\t     -------------------" << endl;
	cout << "\t\t\t     |  " << BoxSeven << "  |  " << BoxEight << "  |  " << BoxNine << "  |" << endl;
	cout << "\t\t\t     -------------------\n\n" << endl;


}