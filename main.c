#include<stdio.h>
#include<string.h>
int main(){
    char titre[100][20];
    char auteur[100][20];
    char rechrTitre[100];
    int tquantt = 0;
    int tv = 0; 
    float prix[100];
    int quantite[100];
    int num_livre = 0;
    int chx , i;
    do{
         printf("\n*** Gestion du stock de livres dans  Librairie M.CHERKAOUI ***\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre du stock\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("7. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &chx);
        //Ajouter un livre au stock.
        if(chx==1){
             printf("Entrez le titre du livre : ");
                scanf(" %s[^\n]", titre[num_livre]);
                printf("Entrez l'auteur du livre : ");
                scanf(" %s[^\n]", auteur[num_livre]);
                printf("Entrez le prix du livre : ");
                scanf("%f", &prix[num_livre]);
                printf("Entrez la quantité : ");
                scanf("%d", &quantite[num_livre]);
                num_livre++;
                printf("Livre ajouté avec succès.\n");
        }else //Afficher tous les livres disponibles.
        if(chx == 2){
            if (num_livre == 0) {
                printf("Aucun livre en stock.\n");
            } else {
                printf("\n*** Livres en stock ***\n");
                for (i = 0; i < num_livre; i++) {
                    printf("Titre : %s\n Auteur : %s\n Prix : %.2f\n Quantité : %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                }
        }
        } else //Rechercher un livre par son titre.
         if (chx == 3) {
            printf("Entrez le titre du livre à rechercher : ");
            scanf(" %s[^\n]", rechrTitre);
             // Reset tv avant de chercher
            for (i = 0; i < num_livre; i++) {
                if (strcmp(titre[i], rechrTitre) == 0) {
                    printf("Livre trouvé :\n");
                    printf("Titre : %s\nAuteur : %s\nPrix : %.2f\nQuantité : %d\n", titre[i], auteur[i], prix[i], quantite[i]);
                    tv = 1;
                    break;
                }
            }
            if (tv == 0) {
                printf("Livre non trouvé.\n");
            }
        }else //Mettre à jour la quantité d'un livre.
        if(chx == 4){
              printf("Entrez le titre du livre à rechercher : ");
            scanf(" %s[^\n]", rechrTitre);
            for (i = 0; i < num_livre; i++) {
                
                    if (strcmp(titre[i], rechrTitre) == 0) {
                    printf("Entrez la nouvelle quantite : ");
                    scanf("%d", &quantite[i]);
                    
                    printf("Quantite Mise a jour avec succes.\n");
                    tv = 1;
                    break;
        }
            }
         
        if(tv == 0){
            printf("Livre non trouvé.\n");
        }
        } else // Afficher le nombre total de livres en stock.
        if(chx == 5){
             printf("Entrez le titre du livre à rechercher : ");
            scanf(" %s[^\n]", rechrTitre);
              for (i = 0; i < num_livre; i++) {
                if (strcmp(titre[i], rechrTitre) == 0) {  
              for (int j = i; j < num_livre-1; j++) {
                  strcpy(titre[j], titre[j + 1]);
                        strcpy(auteur[j], auteur[j + 1]);
                        prix[j] = prix[j + 1];
                        quantite[j] = quantite[j + 1];
              }
              num_livre--;
               printf("Livre supprimer avec succes.\n");
                    tv = 1;
                    break;
                }
            }
            if (tv == 0) {
                printf("Livre non trouve.\n");
            }
         }else //Afficher le nombre total de livres en stock.
         if(chx  == 6){
            for (int i = 0; i < num_livre; i++) {
                tquantt += quantite[i];
            }
            printf("Nombre total de livres en stock : %d\n", tquantt);
       
         }
              
        
    }while(chx != 7);
    printf(" Systeme est Terminer.");
    return 0 ;
}
