#include<stdio.h>
#include<string.h>


/*    Le but du programme est d'indiquer � l'utilisateur , la valeur ohmique d'une resistance electronique. Le programme prends en charge les deux types de r�sistance electronique :
 * 
 * La r�sistance qui contient des bandes de couleur  (code couleur)
 * dont celles � 
 * 
 * - 4 bandes (3 bandes pour la valeur + 1 pour la tolerance)
 * - 5 bandes (4 bandes pour la valeur + 1 pour la tolerance)
 * - 6 bandes (4 bandes pour la valeur + 1 pour la tolerance + 1 pour le coef de temp�rature)
 * 
 * La r�sistance CMS qui est plus sofistiquer ,plus petite souvent la plus difficile � d�chifrer de t�te , qui contient que des lettres et des chiffres:
 * dont celles � 
 * 
 * - 3 caract�res
 * - 4 caract�res
 * - et celle dite code eia-56
 */
 
 
int add (int a, int b);
int puiss10 (int p, int n);
int calcul_resistance_4_bandes(int ch1, int ch2,int ch_mul);
int calcul_resistance_5_bandes(int ch1, int ch2, int ch3,int ch_mul);
int calcul_resistance_6_bandes(int ch1, int ch2, int ch3,int ch_mul);
int pos_b (char *tab[],char *bande_couleur,int tt);
void affiche_resis_cms_menu();   //prototype de la fonction qui sert a afficher le menu
void affiche_resis_bandes_menu();    //prototype de la fonction
void affiche_interface_menu();  //prototype de la fonction

int main (){
    
    int nb_bandes; // va contenir le nombre de bande de la resistance
    int nb_caract; //va contenir le nombre de caract�re inscrit de la reisistance cms
    
    char  *type_resis_bandes = "bandes" ;
    char  *type_resis_cms = "cms" ;
    char  type_resis [10]; //va contenir la saisie du type de resistance electronique
    
    //les diff�rents tableaux (pour les dif�rentes valeurs valeur de la couleur / tol�rance etc)
    
    char * tab_couleurs[]={"noir","marron","rouge","orange","jaune","vert","bleu","violet","gris","blanc","or","argent"};
    char * tab_couleurs_tolerance[]={"x","+1%","+2%","x","x","+0.5%","+0.25%","+0.1%","+0.05%","x","+5%","+10%"};
    char * tab_couleurs_ppm[]={"x","100ppm","50ppm","15ppm","25ppm","x","10ppm","5ppm","x","x","x","x"};
    int nb_couleurs = sizeof(tab_couleurs)/sizeof(*tab_couleurs);
    
    char b1[10];
    char b2[10];
    char b3[10];
    char b4[10];
    char b5[10];
    char b6[10];
    char **p;
  
    char * tab_clr_bande[6]={};
   
    p=tab_clr_bande;
   
    int ps,a,b,c,d,i;
   
   affiche_interface_menu(); //affiche l'interface du menu principale
   printf("resistance � bandes  ou  cms (en cours de d�veloppement)  ? \n ");
   scanf("%s",type_resis); //saisie du type de reisistance electronique
  
   
   if(!(strcmp(type_resis,type_resis_bandes))){   // 1er condtion si l'utilisateur veut connaitre la valeur d'une resistance cms
       affiche_resis_bandes_menu(); //affichage du menu des resistance a bande
       printf("Combien de bandes y'a t-il ? \n");
       scanf("%d",&nb_bandes); //r�cuperation de la saisie du nombre de bande
       if(nb_bandes == 4){
        // A REMPLACER PAR UNE BOUCLE FOR pour plus d'optimisation
           printf("Entrez la couleur de la bande num�ro 1 ==>  ");
           scanf("%s",b1);
           printf("Entrez la couleur de la bande num�ro 2 ==>  ");
           scanf("%s",b2);
           printf("Entrez la couleur de la bande num�ro 3 ==>  ");
           scanf("%s",b3);
           printf("Entrez la couleur de la bande num�ro 4 ==>  ");
           scanf("%s",b4); 
           printf("La resistance est de %d ohm ",calcul_resistance_4_bandes(pos_b(tab_couleurs,b1,12),pos_b(tab_couleurs,b2,12),pos_b(tab_couleurs,b3,12)));
           printf("==> tolerance de %s. ",*(tab_couleurs_tolerance + pos_b(tab_couleurs,b4,12)));
           
       }
       if(nb_bandes == 5){
       	// A REMPLACER PAR UNE BOUCLE FOR pour plus d'optimisation
           printf("Entrez la couleur de la bande num�ro 1 ==>  ");
           scanf("%s",b1);
           printf("Entrez la couleur de la bande num�ro 2 ==>  ");
           scanf("%s",b2);
           printf("Entrez la couleur de la bande num�ro 3 ==>  ");
           scanf("%s",b3);
           printf("Entrez la couleur de la bande num�ro 4 ==>  ");
           scanf("%s",b4);
           printf("Entrez la couleur de la bande num�ro 5 ==>  ");
           scanf("%s",b5); 
           printf("La resistance est de %d ohm ",calcul_resistance_5_bandes(pos_b(tab_couleurs,b1,12),pos_b(tab_couleurs,b2,12),pos_b(tab_couleurs,b3,12),pos_b(tab_couleurs,b4,12)));
           printf("==> tolerance de %s. ",*(tab_couleurs_tolerance + pos_b(tab_couleurs,b5,12)));
       }
       if(nb_bandes == 6){
       	// A REMPLACER PAR UNE BOUCLE FOR pour plus d'optimisation
           printf("Entrez la couleur de la bande num�ro 1 ==>  ");    
           scanf("%s",b1);
           printf("Entrez la couleur de la bande num�ro 2 ==>  ");
           scanf("%s",b2);
           printf("Entrez la couleur de la bande num�ro 3 ==>  ");
           scanf("%s",b3);
           printf("Entrez la couleur de la bande num�ro 4 ==>  ");
           scanf("%s",b4);
           printf("Entrez la couleur de la bande num�ro 5 ==>  ");
           scanf("%s",b5); 
           printf("Entrez la couleur de la bande num�ro 6 ==>  ");
           scanf("%s",b6); 
           printf("La resistance est de %d ohm ",calcul_resistance_6_bandes(pos_b(tab_couleurs,b1,12),pos_b(tab_couleurs,b2,12),pos_b(tab_couleurs,b3,12),pos_b(tab_couleurs,b4,12)));
           printf("==> tolerance de %s. ",*(tab_couleurs_tolerance + pos_b(tab_couleurs,b5,12)));
           printf("==>  %s. ",*(tab_couleurs_ppm + pos_b(tab_couleurs,b6,12)));
       }
       
   }else if(!(strcmp(type_resis,type_resis_cms))){  // 2eme condtion si l'utilisateur veut connaitre la valeur d'une resistance cms
        affiche_resis_cms_menu();
        printf("Combien de caract�res y'a t-il ? \n");
        scanf("%d",&nb_caract);
        /*
        
        EN COURS DE DEVELOPPEMENT
        IL ME RESTE A FINIR CETTE PARTIE
        
        */
        
    }
    
    printf("\n");
    return 0;
    
}


int puiss10 (int p, int n){
    int res;
    for(res=1; n>0; n--){
        res*=p;
    }
    return res;
}

int pos_b (char *tab[],char *bande_couleur,int tt){
    
    int i, p;
    for(i=0;i<tt;i++){
        if(!(strcmp(bande_couleur,tab[i]))){
            p=i;
            break;
        }
    }
    return p;
}


int calcul_resistance_4_bandes (int ch1, int ch2,int ch_mul){
    
    int resul;
    int pos_b_tol;
    resul=(ch1*10)+(ch2*1);
    resul=resul*(puiss10(10,ch_mul));
    return resul;
}


int calcul_resistance_5_bandes(int ch1, int ch2, int ch3,int ch_mul){
    
    int resul;
    
    resul=(ch1*100)+(ch2*10)+(ch3*1);
    resul=resul*(puiss10(10,ch_mul));
    return resul;
}


int calcul_resistance_6_bandes (int ch1, int ch2, int ch3,int ch_mul){
    
    int resul;
    
    resul=(ch1*100)+(ch2*10)+(ch3*1);
    resul=resul*(puiss10(10,ch_mul));
  
    return resul;
}


/* 
 * les fonctions pour void qui suivent vont servir � guider l'utilisateur durant le programme
 * 
 *  affiche_interface_menu() ==> menu principale
 *  affiche_resis_bandes_menu() ==> menu qui concerne les r�sistance � bande : choix du nombre de bande
 *  affiche_resis_cms_menu() ==> menu qui concerne les r�sistance � cms : choix du nombre de caract�re
 * 
 */


void affiche_interface_menu(){
   printf("- une version avec une interface graphique est en cours...\n");
   printf("\n");
   printf("\n");
   printf("- Resistance_Indicator   VERSION-1.0\n");
   printf("\n");
   printf("type: bandes                              type: cms (PAS ENCORE DISPONIBLE)\n");
   printf("                                           ______________________________ \n");
   printf("      ________________________            |   |                      |   |\n");
   printf("     |    |   |  |   |        |           |   |                      |   |\n");
   printf(" ____|    |   |  |   |   ?Ohm |____   ou  |   |            ?ohm      |   |\n");
   printf("|    |____|___|__|___|________|    |      |   |      |               |   |\n");
   printf("|         |   |  |   |             |      |   |      |               |   |\n");
   printf("|         V   V  V   V                    |___|______|_______________|___|\n");
   printf("        bandes de couleurs                           V\n");
   printf("                                           chiffres et lettres\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("\n");
   printf("                                                     D�vlopp� par Hadj-Rabah\n");
   printf("                                                                 Zine-Eddine\n");
   printf("\n");
   printf("De quels types de r�sistances voulez vous conna�tre sa valeurs en Ohm () : \n ");
   printf("\n");
    
}
void affiche_resis_bandes_menu(){
   printf("     _______________________\n");
   printf("    |   |   |  |   |        |\n");
   printf("    |   |   |  |   |        |\n");
   printf(" ___|   |   |  |   |    ?Ohm|____ 4 bandes\n");
   printf("|   |   |   |  |   |        |    |\n");
   printf("|   |___|___|__|___|________|    |\n");
   printf("        |   |  |   |\n");
   printf("        V   V  V   V\n");
   printf("        1   2  3   4\n");
   printf("\n");
   printf("    ______________________________ \n");
   printf("   |    |   |  |   |     |        |\n");
   printf("   |    |   |  |   |     |        |\n");
   printf("___|    |   |  |   |     |   ?Ohm |___ 5 bandes\n");
   printf("|  |    |   |  |   |     |        |   |\n");
   printf("|  |____|___|__|___|_____|________|   |\n");
   printf("        |   |  |   |     |\n");
   printf("        V   V  V   V     V\n");
   printf("        1   2  3   4     5\n");
   printf("\n");
   printf("     _________________________________\n");
   printf("    |    |   |  |   |     |     |     |\n");
   printf("    |    |   |  |   |     |     |     |\n");
   printf(" ___|    |   |  |   |     |     | ?Ohm|___6 bandes\n");
   printf("|   |    |   |  |   |     |     |     |   |\n");
   printf("|   |____|___|__|___|_____|_____|_____|   |\n");
   printf("         |   |  |   |     |     |\n");
   printf("         V   V  V   V     V     V\n");
   printf("         1   2  3   4     5     6\n");
   printf("\n");
  
}

void affiche_resis_cms_menu(){
    
   printf("\n");  
   printf("   ______________________________ \n");
   printf("  |   |                      |   |\n");
   printf("  |   |                      |   |\n");
   printf("  |   |            ?ohm      |   |\n");
   printf("  |   |      |               |   |\n");
   printf("  |   |      |               |   |\n");
   printf("  |___|______|_______________|___|\n");
   printf("             |\n");
   printf("             V\n");
   printf("      CHIFFRES ET LETTRES\n");
   printf("\n");
   printf("\n");  

}
