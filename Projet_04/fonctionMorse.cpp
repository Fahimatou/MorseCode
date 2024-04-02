//D�FINITIONS
#include <windows.h>
#include <iostream>
#include <cctype>






const int TONE = 500; // fr�quence de tonalit� sonore
const int VITESSE = 50; // cadence de r�f�rence
// vitesse de transmission (en millisecondes)
const int TI = VITESSE; // dur�e d'un ti (point) en ms
const int TA = 3 * TI; // dur�e d'un ta (trait) en ms
const int ESPACE_SYMBOLE = TI; // dur�e du silence (en ms) entre chaque ti ou ta d'un caract�re
const int ESPACE_LETTRE = TA; // dur�e du silence (en ms) entre chaque lettre d'un mot
const int ESPACE_MOT = 5 * TI; // dur�e du silence (en ms) entre chaque mot du message
const int MAX_TITA = 6; // maximum de ti et ta dans un caract�re traduisible
// A COMPLETER
const int SIGNAL[][MAX_TITA] = {
	{ TI,TA             },// A
    { TA,TI,TI,TI       },// B  
	{ TA, TI, TA,TI     },// C
    { TA,TI,TI          },// D
	{ TI                },// E
	{ TI,TI,TA,TI       },// F
	{ TA,TA,TI          },// G
	{ TI,TI,TI,TI       },// H
	{ TI,TI             },// I
	{ TI,TA,TA,TA       },// J
	{ TA,TI,TA          },// K
	{ TI,TA,TI,TI       },// L
	{ TA,TA             },// M
	{ TA,TI             },// N
	{ TA,TA,TA          },// O
	{ TI,TA,TA,TI       },// P
	{ TA,TA,TI,TA       },// Q
	{ TI,TA,TI          },// R
	{ TI,TI,TI          },// S
	{ TA                },// T
	{ TI,TI,TA          },// U
	{ TI,TI,TI,TA       },// V
	{ TI,TA,TA          },// W
	{ TA,TI,TI,TA       },// X
	{ TA,TI,TA,TA       },// Y
	{ TA,TA,TI,TI       },// Z
	{ TA,TA,TA,TA,TA    },// 0
	{ TI,TA,TA,TA,TA    },// 1
	{ TI,TI,TA,TA,TA    },// 2
	{ TI,TI,TI,TA,TA    },// 3
	{ TI,TI,TI,TI,TA    },// 4
	{ TI,TI,TI,TI,TI    },// 5
	{ TA,TI,TI,TI,TI    },// 6
	{ TA,TA,TI,TI,TI    },// 7
	{ TA,TA,TA,TI,TI    },// 8
	{ TA,TA,TA,TA,TI    },// 9
	{ TI,TA,TI,TA,TI,TA },// .
	{ TA,TA,TI,TI,TA,TA },// ,
	{ TA,TI,TA,TI,TA,TI },// ;
};
// Fonction de transmission d'un message en Morse
// msg[] : cha�ne de caract�res � transmettre en Morse sonore
// afficher : true si le code Morse doit aussi �tre afficher
// dans la console
// La fonction retourne le nombre de caract�res n'ayant pu �tre transmis



int strMorse(const char msg[], bool afficher) {
	int compteInconnus = 0; // compte le nombre de caract�res non transmis
	// Traiter chaque caract�re du message individuellement
	for (unsigned int i = 0; i < strlen(msg); i++) {
		// Est-ce un espace entre deux mots?
		if (msg[i] == ' ') {
			Sleep(ESPACE_MOT);
			if (afficher)
				std::cout << '/';
			continue;
		}
		// Identifier le caract�re et le transmettre
		int idx = -1; // index du caract�re dans le tableau signal
		// Les lettres minuscules et majuscule
		// sont trait�es sans distinction de case
		// Identifier les caract�res MORSES de la table SIGNAL (A COMPLETER)


		
		//compare alphabet avec le contenue de msg 
		const char* alphabet = "abcdefghijklmnopqrstuvwxyz0123456789.,;";
		for (int j = 0; j < 42; j++) {
			if (msg[i] == alphabet[j]) {
				idx = j;
				break;
			}
		}


		// Si le caract�re est reconnu, alors le transmettre
		if (idx >= 0)
			// Transmettre chaque symbole du caract�re
			for (int j = 0; j < MAX_TITA; j++) {
				if (SIGNAL[idx][j] > 0) {
					// Transmission visuelle
					if (afficher)
						if (SIGNAL[idx][j] == TI)
							std::cout << '.';
						else
							std::cout << '-';
					// Transmission sonore
					Beep(TONE, SIGNAL[idx][j]);
				}
				// Seulement �couler un d�lai
				// inter-symboles s'il reste un symbole
				// � transmettre pour le caract�re courant
				if (j < 4 && SIGNAL[idx][j + 1] > 0)
					Sleep(ESPACE_SYMBOLE);
			}
		// �couler le d�lai inter-lettres avant de passer au prochain caract�re
		if (idx >= 0)
			Sleep(ESPACE_LETTRE);
		else {
			// Si le caract�re est invalide, l'indiquer visuellement (?) et de
			// fa�on sonoe (pause correspondant � un espace)
			if (afficher)
				std::cout << ' ';
			Sleep(ESPACE_MOT);
			compteInconnus++;
		}
	}
	// Retourner le nombre de caract�re n'ayant pu �tre transmis
	return compteInconnus;
}



		

		
			


