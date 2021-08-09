//*******************************************************************
//*                       Pac My Man                                *
//*******************************************************************


#include <iostream>   // librairie g�rant les flux d'entree et de sortie
#include <fstream>   // librairie g�rant les fichiers
#include <math.h>
#include <graphics.h>
#include <GraphicsISN.h> // Modification disque local c > include > (400;400) (initwindow(400,400,"Graphique ISN",0,0);
using namespace std;  

int main()

{
  
  char QUIT;
  int G[20][20];
  int T[20][20];// cr�ation du tableau
  int L=0 ;
  int C=0 ;
  char touche = 'z';
  int compteurTemps = 0;
  int pacmanX = 8;
  int pacmanY = 11;
  int fantomeX=11;
  int fantomeY=8;
  int fantome2Y=7;
  int fantome2X=18;
  srand(time(NULL));
  int nbgen=0;
  
  // TERRAINPACMAN
  //Initialisation du tableau en BLANC
  // Utiliser deux boucles "pour"
  for(L=0; L<=19;L++)
  {
     for(int C=0; C<=19;C++)
     {
        T[C][L]=255;
     }
  }
  
  // Points noirs 
  
  L=0; // premi�re ligne noire
  {
     for(int C=0; C<=19;C++)
     {
       T[C][L]=0;
     }
  }
  
 L=19; // derni�re ligne noire 
  {     
    for(int C=0; C<=19;C++)
    {
      T[C][L]=0;
    }
  }
  
  for(L=0; L<=19;L++) // premi�re colonne noire
  {     
     C=0;
     {
       T[C][L]=0;
     }
  }
  
   for(L=0; L<=19;L++) // derni�re colonne noire
  {     
     C=19;
     {
        T[C][L]=0;
     }
  }
  
  for(L=0; L<=19;L++) // colonnes noires 9 & 10
  {     
     for(C=9; C<=10;C++)
     {
        T[C][L]=0;
     }
  }
  
   L=7; // ligne noire coup�e gauche sup�rieure
  {     
     for(int C=2; C<=7;C++)
     {
        T[C][L]=0;
     }
  }
   L=7; // ligne noire coup�e droite sup�rieure
  {     
  for(int C=12; C<=17;C++)
     {
        T[C][L]=0;
     }
  }

  L=12; // ligne noire gauche coup�e inf�rieure
  for(int C=2; C<=7;C++)
   {
      T[C][L]=0;
   }
  
  L=12; // ligne noire droite coup�e inf�rieure
  for(int C=12; C<=17;C++)
   {
      T[C][L]=0;
   }
  
  L=2; // Partie sym�trique 1 (haut-gauche) 3eme ligne (2eme ds le code)
  for(int C=2; C<=4;C++) // d�but du l 
   { 
      T[C][L]=0;
   }
   
   for(int L=2; L<=5;L++) 
  {
     C=2;
     {
        T[C][L]=0;       // fin du l
     }
  }
   L=2; 
  for(int C=6; C<=7;C++)
   { 
      T[C][L]=0;
   }
   
   
   for(int L=4; L<=5;L++) // petit trait vertical
  {
      C=4;
      {
         T[C][L]=0;
      }
  }
   
  T[6][4]=0; // le carr�
  T[6][5]=0;
  T[7][4]=0;
  T[7][5]=0;
   
   
  L=2; // Partie sym�trique 2 (haut-droit) 3eme ligne (2eme ds le code)on reprend la boucle pr�c�dente en effectuant la diff�rence 19-x
  for(int C=15; C<=17;C++) // d�but du l 
   { 
   T[C][L]=0;
   }
  
   for(int L=2; L<=5;L++)  
  {
   C=17;
   {
    T[C][L]=0;           // fin du l
   }
  }
  
  L=2; 
  for(int C=12; C<=13;C++)
   { 
   T[C][L]=0;
   }
   
   
   for(int L=4; L<=5;L++) // petit trait vertical
  {
   C=15;
   {
    T[C][L]=0;        
   }
  }
   
    T[12][4]=0; // le carr�
    T[13][5]=0;
    T[12][5]=0;
    T[13][4]=0;
   
   
   for( int L=9; L<=10;L++) // Les deux petits traits verticaux du milieu
   {
    C=7;  
   {
    T[C][L]=0;        
   }
  }
   
    for( int L=9; L<=10;L++) // Les deux petits traits verticaux du milieu
   {
    C=12;  
   {
    T[C][L]=0;        
   }
  }
   
 
  L=17; // Partie sym�trique 3 (bas-gauche) 18eme ligne (17eme ds le code)
  for(int C=2; C<=4;C++) // d�but du l 
   { 
   T[C][L]=0;
   }
   
  for(int L=14; L<=17;L++) 
  {
   C=2;
   {
    T[C][L]=0;        // fin du l 
   }
  }
  
   L=17; 
  for(int C=6; C<=7;C++)
   { 
   T[C][L]=0;
   }
   
   
   for(int L=14; L<=15;L++) // petit trait vertical
  {
   C=4;
   {
    T[C][L]=0;        
   }
  }
   
    T[6][14]=0; // le carr�
    T[7][14]=0;
    T[6][15]=0;
    T[7][15]=0;
   
   
   
  
  
   L=17; // Partie sym�trique 4 (bas-droit) 18eme ligne (17eme ds le code)on reprend la boucle pr�c�dente en effectuant la diff�rence 19-x
  for(int C=15; C<=17;C++) // d�but du l 
   { 
   T[C][L]=0;
   }
   
    for(int L=14; L<=17;L++) 
  {
   C=17;
   {
    T[C][L]=0;           // fin du l 
   }
  }
  
  L=17; 
   for(int C=12; C<=13;C++)
   { 
   T[C][L]=0;
   }
   
   
   for(int L=14; L<=15;L++) // petit trait vertical
  {
   C=15;
   {
    T[C][L]=0;        
   }
  }
   
    T[12][14]=0; // le carr�
    T[12][15]=0;
    T[13][14]=0;
    T[13][15]=0;
   
   
   
   for(L=9; L<=10;L++) // gros traits centraux gauche
  {     
   for(int C=0; C<=5;C++)
   {
   T[C][L]=0;          
   }
  }
  
  
   for(L=9; L<=10;L++) // gros traits centraux droite
  {     
   for(int C=14; C<=19;C++)
   {
   T[C][L]=0;          
   }
  }
  
    T[9][6]=255; // pixels blancs sur la gros colonne noire 
    T[10][6]=255;
    T[9][8]=255;
    T[10][8]=255;
    T[9][11]=255; 
    T[10][11]=255;
    T[9][13]=255;
    T[10][13]=255;
    
  // FIN TERRAINPACMAN
    cout << "       ###############                        "<< endl;         
    cout << "      ##################              "<< endl;       
    cout << "    #######################                   "<< endl;         
    cout << "  ##############   ###########                                "<< endl;
    cout << "##############################                                "<< endl;
    cout << "#######################                               "<< endl;
    cout << "####################                          "<< endl;
    cout << "################                      "<< endl;
    cout << "#############                         "<< endl;
    cout << "###########                                   "<< endl;   
    cout << "#########                                     "<< endl;
    cout << "############                          "<< "PAC MY MAN" << endl;         
    cout << "##################            "<< endl;       
    cout << "#######################               "<< endl;         
    cout << "###########################                                   "<< endl;
    cout << "##############################                                "<< endl;
    cout << "    #######################                                   "<< endl;
    cout << "      ####################                    "<< endl;
    cout << "        ################                      "<< endl;

    cout << endl;
    
    while (touche != 'p') // Tant que touche est diff�rent de 'p' boucler
    {
          cout<< " Appuyer sur p pour lancer le jeu "<< endl;
          cin>> touche;
        
    }  
        
    
    
  //Gestion de l'�cran graphique
  InitialiseFenetreGraphique(20);  
  Grille();
  
  //Affichage du TERRAIN � l'�cran 
  //Utiliser deux boucles "pour"
   for(L=0; L<=19;L++)
  {     
   for(int C=0; C<=19;C++)
   {
   MetPoint (C,L,T[C][L]);
   }
  }
     

//initialisation des deplacemet pacman

int mort =0;
  
//deplacement pacman   
while (mort !=1)
{   
   delay (10);
   int nbgen=rand()%4+1;    //entre 1-4
   int nbgen2=rand()%4+1;    //entre 1-4
 
   delay(10);
   if (compteurTemps > 10)
   {
   // D�placement de l'alli�
   if(GetKeyState('Q') & 0x8000) // Si la touche Q est press� aller vers la gauche
   {
   if (T[pacmanX-1][pacmanY]==255)//pacman peut y aller seulement quand la case est blanche 
   { 
    MetPoint(pacmanX,pacmanY,255);
    pacmanX -= 1;
   }
   }
   else if(GetKeyState('D') & 0x8000) // Si la touche D est press� aller vers la droite
   {
   if (T[pacmanX+1][pacmanY]==255)//pacman peut y aller seulement quand la case est blanche
   {
    MetPoint(pacmanX,pacmanY,255);
    pacmanX += 1;
   }
   }
    else if(GetKeyState('Z') & 0x8000) // Si la touche Z est press� aller vers le haut
   {
    if (T[pacmanX][pacmanY-1]==255)  //pacman peut y aller seulement quand la case est blanche
    {
     MetPoint(pacmanX,pacmanY,255);
    pacmanY -= 1;
    }
   }
   else if(GetKeyState('S') & 0x8000) // Si la touche S est press� aller vers le bas
  {
   if (T[pacmanX][pacmanY+1]==255)  //pacman peut y aller seulement quand la case est blanche 
   {
    MetPoint(pacmanX,pacmanY,255);
    pacmanY += 1;
   }
  }
  MetPoint(pacmanX,pacmanY,150);
// deplacement fantome 1
   if(nbgen==1) // si nb al�atoire =1 aller vers la gauche 
   {
    if (T[fantomeX-1][fantomeY]==255)//fantome peut y aller seulement quand la case est blanche 
    { 
     MetPoint(fantomeX,fantomeY,255);
     fantomeX -= 1;
    }
   } 
   else if(nbgen==2) // si nb al�atoire =2 aller vers la droite
   {
    if (T[fantomeX+1][fantomeY]==255)//fantome peut y aller seulement quand la case est blanche 
    {
     MetPoint(fantomeX,fantomeY,255);
     fantomeX += 1;
     }
    }
    else if(nbgen==3) // si nb al�atoire =3 aller vers le haut 
    {
     if (T[fantomeX][fantomeY-1]==255)  //fantome peut y aller seulement quand la case est blanche 
     {
     MetPoint(fantomeX,fantomeY,255);
     fantomeY -= 1;
     }
    }
    else if(nbgen==4) // si nb al�atoire =4 aller vers le bas 
    {
     if (T[fantomeX][fantomeY+1]==255)  //fantome peut y aller seulement quand la case est blanche 
     {
     MetPoint(fantomeX,fantomeY,255);
     fantomeY += 1;
     }
    }
    MetPoint(fantomeX,fantomeY,200);
    
    //d�placement fantome 2
    
     if(nbgen2==1) // si nb al�atoire =1 aller vers la gauche 
   {
    if (T[fantome2X-1][fantome2Y]==255)//fantome peut y aller seulement quand la case est blanche 
    { 
     MetPoint(fantome2X,fantome2Y,255);
     fantome2X -= 1;
    }
   } 
   else if(nbgen2==2) // si nb al�atoire =2 aller vers la droite
   {
    if (T[fantome2X+1][fantome2Y]==255)//fantome peut y aller seulement quand la case est blanche 
    {
     MetPoint(fantome2X,fantome2Y,255);
     fantome2X += 1;
     }
    }
    else if(nbgen2==3) // si nb al�atoire =3 aller vers le haut 
    {
     if (T[fantome2X][fantome2Y-1]==255)  //fantome peut y aller seulement quand la case est blanche 
     {
     MetPoint(fantome2X,fantome2Y,255);
     fantome2Y -= 1;
     }
    }
    else if(nbgen2==4) // si nb al�atoire =4 aller vers le bas 
    {
     if (T[fantome2X][fantome2Y+1]==255)  //fantome peut y aller seulement quand la case est blanche 
     {
     MetPoint(fantome2X,fantome2Y,255);
     fantome2Y += 1;
     }
    }
    MetPoint(fantome2X,fantome2Y,200);
      
    if (pacmanX==fantome2X && pacmanY==fantome2Y)
     {
      mort=1;
     }
    
    if (pacmanX==fantomeX && pacmanY==fantomeY)
     {
      mort=1;
     }
    compteurTemps = 0;
    } 
  compteurTemps++;

  }
 delay (50);
  // ECRAN GAME OVER
  //Initialisation du tableau en BLANC
  // Utiliser deux boucles "pour"
  for(L=0; L<=19;L++)
  {     
   for(int C=0; C<=19;C++)
   {
   G[C][L]=0;          
   }
  }
  
  // GAME
  // Lettre G
 
  L=3; // trait horizontal sup�rieur du G
  {     
    for(int C=1; C<=4;C++)
   {
   G[C][L]=255;          
   }
  }
        
     L=7; // trait horizontal du G
  {     
    for(int C=1; C<=4;C++)
   {
   G[C][L]=255;          
   }
  }
  
   L=5; // deux pixels blancs milieu du G
  {     
    for(int C=3; C<=4;C++)
   {
   G[C][L]=255;          
   }
  }
  
   for(int L=3; L<=6;L++) // Trait gauche vertical du G 
  {
   C=1;
   {
    G[C][L]=255;        
   }
  }
  
  for(int L=6; L<=7;L++) // Trait gauche vertical du G 
  {
   C=4;
   {
    G[C][L]=255;        
   }
  }
  
  // Lettre A
  
  for(int L=3; L<=7;L++) // Trait gauche vertical du A
  {
   C=6;
   {
    G[C][L]=255;        
   }
  }
  
   for(int L=3; L<=7;L++) // Trait de droite vertical du A
  {
   C=9;
   {
    G[C][L]=255;        
   }
  }
  
   L=3; // trait horizontal sup�rieur du A 
  {     
    for(int C=6; C<=9;C++)
   {
   G[C][L]=255;          
   }
  }
  
   L=5; // trait horizontal sup�rieur du A 
  {     
    for(int C=6; C<=9;C++)
   {
   G[C][L]=255;          
   }
  }
  
  // Lettre M
  
   for(int L=3; L<=7;L++) // Trait vertical de gauche du M
  {
   C=11;
   {
    G[C][L]=255;        
   }
  }
  
   for(int L=3; L<=7;L++) // Trait vertical de droite du M
  {
   C=14;
   {
    G[C][L]=255;         
   }   
  }
  
    L=4; // trait horizontal du M
  {     
    for(int C=12; C<=13;C++)
   {
   G[C][L]=255;          
   }
  }
  
  // Lettre E
  
  for(int L=3; L<=7;L++) // Trait vertical du E
  {
   C=16;
   {
    G[C][L]=255;        
   }
  }
   
    L=3; // trait horizontal sup�rieur  du E
  {     
    for(int C=17; C<=18;C++)
   {
   G[C][L]=255;          
   }
  }
  
   L=5; // trait horizontal central  du E
  {     
    for(int C=17; C<=18;C++)
   {
   G[C][L]=255;          
   }
  }
  
     L=7; // trait horizontal inf�rieur  du E
  {     
    for(int C=17; C<=18;C++)
   {
   G[C][L]=255;          
   }
  }
  
  // OVER
  // Lettre 0
  
  for(int L=12; L<=16;L++) // Trait vertical gauche du O
  {
   C=1;
   {
    G[C][L]=255;        
   }
  }
  
   for(int L=12; L<=16;L++) // Trait vertical droit du O
  {
   C=3;
   {
    G[C][L]=255;        
   }
  }
  
   G[2][12]=255; // pixel du milieu haut du O 
   G[2][16]=255; // pixel du milieu bas du O 
  
  
  // Lettre V
  
  G[5][12]=255; // trait vertical du haut gauche
  G[5][13]=255; 
  
  G[9][12]=255; // trait vetical du haut droit
  G[9][13]=255; 
  
  G[6][14]=255; // trait vertical du milieu gauche
  G[6][15]=255; 
  
  G[8][14]=255; // trait vetical du milieu droit
  G[8][15]=255;
   
  G[7][16]=255; // pixel de la pointe du V
  
  
  // Lettre E
  
  for(int L=12; L<=16;L++) // Trait vertical du E
  {
   C=11;
   {
    G[C][L]=255;        
   }
  }
   
    L=12; // trait horizontal sup�rieur  du E
  {     
    for(int C=12; C<=13;C++)
   {
   G[C][L]=255;          
   }
  }
  
   L=14; // trait horizontal central  du E
  {     
    for(int C=12; C<=13;C++)
   {
   G[C][L]=255;          
   }
  }
  
     L=16; // trait horizontal inf�rieur  du E
  {     
    for(int C=12; C<=13;C++)
   {
   G[C][L]=255;          
   }
  }
  
  
  // Lettre R
  
   for(int L=12; L<=16;L++) // Trait vertical du R
  {
   C=15;
   {
    G[C][L]=255;        
   }
  }
  
  G[16][12]=255; // trait horizontal haut du R
  G[17][12]=255; 
  
  G[16][15]=255; // trait horizontal bas du R
  G[17][15]=255; 
  
  G[18][13]=255; // trait vetical droit du R
  G[18][14]=255;
   
  G[18][16]=255; // pixel bas droit du R 
  
  
  
  
  
  
  
  
  
  
  
  //Gestion de l'�cran graphique
  InitialiseFenetreGraphique(20);  
  Grille();
  
  //Affichage du TERRAIN � l'�cran 
  //Utiliser deux boucles "pour"
   for(L=0; L<=19;L++)
  {     
   for(int C=0; C<=19;C++)
   {
   MetPoint (C,L,G[C][L]);
   }
  }
  delay (50000);
}





  
  
  
  
  
  
  
  
















