#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 // nombre maximum de produits
#define SEUIL 5 // seuil d'alerte pour faible quantité
struct Produit{
int code;
char nom[50];
int quantite;
float prix;
} typedef Produit;
// Prototypes des fonctions
void afficherMenu();
void ajouterProduit(Produit *stock, int *n);
void supprimerProduit(Produit *stock, int *n, int code);
void modifierProduit(Produit *stock, int n, int code);
void afficherStock(Produit *stock, int n);
void rechercherProduit(Produit *stock, int n, int code);
void verifierAlertes(Produit *stock, int n);
// Affichage du menu
void afficherMenu() {
printf("\n=== Gestion de stock de pharmacie ===\n");
printf("1. Ajouter un produit\n");
printf("2. Supprimer un produit\n");
printf("3. Modifier un produit\n");
printf("4. Afficher le stock\n");
printf("5. Rechercher un produit\n");
printf("6. Verifier les alertes de rupture\n");
printf("0. Quitter\n");
printf("Votre choix : ");
}
// Ajouter un produit
void ajouterProduit(Produit *stock, int *n) {
if (*n >= MAX) {
printf("Stock plein, impossible d'ajouter.\n");
return;
}
printf("Code : ");
scanf("%d", &stock[*n].code);
printf("Nom : ");
scanf("%s", stock[*n].nom);
printf("Quantite : ");
scanf("%d", &stock[*n].quantite);
printf("Prix : ");
scanf("%f", &stock[*n].prix);
(*n)++;
printf("Produit ajoute avec succes.\n");
}
// Supprimer un produit
void supprimerProduit(Produit *stock, int *n, int code) {
int i, j, trouve = 0;
for(i = 0; i < *n; i++) {
if(stock[i].code == code) {
trouve = 1;
for(j = i; j < *n - 1; j++) {
stock[j] = stock[j+1];
}
(*n)--;
printf("Produit supprimé avec succès.\n");
break;
}
}
if(!trouve) {
printf("Produit introuvable.\n");
}
}
// Modifier un produit
void modifierProduit(Produit *stock, int n, int code) {
int i, trouve = 0;
for(i = 0; i < n; i++) {
    if(stock[i].code == code) {
trouve = 1;
printf("Nouveau nom : ");
scanf("%s", stock[i].nom);
printf("Nouvelle quantité : ");
scanf("%d", &stock[i].quantite);
printf("Nouveau prix : ");
scanf("%f", &stock[i].prix);
printf("Produit modifié avec succès.\n");
break;
}
}
if(!trouve) {
printf("Produit introuvable.\n");
}
}
// Afficher le stock
void afficherStock(Produit *stock, int n) {
if(n == 0) {
printf("Stock vide.\n");
return;
}
printf("\n--- Liste des produits ---\n");
for(int i = 0; i < n; i++) {
printf("Code: %d | Nom: %s | Quantité: %d | Prix: %.2f\n",
stock[i].code, stock[i].nom, stock[i].quantite, stock[i].prix);
}
}
// Rechercher un produit
void rechercherProduit(Produit *stock, int n, int code) {
int i, trouve = 0;
for(i = 0; i < n; i++) {
if(stock[i].code == code) {
trouve = 1;
printf("Produit trouvé : %s (Quantité: %d, Prix: %.2f)\n",
stock[i].nom, stock[i].quantite, stock[i].prix);
break;
}
}
if(!trouve) {
printf("Produit introuvable.\n");
}
}
// Vérifier les alertes
void verifierAlertes(Produit *stock, int n) {
int i, alerte = 0;
printf("\n--- Produits en faible quantité ---\n");
for(i = 0; i < n; i++) {
if(stock[i].quantite < SEUIL) {
alerte = 1;
printf("ALERTE: %s (Code: %d) - Quantité restante: %d\n",
stock[i].nom, stock[i].code, stock[i].quantite);
}
}
if(!alerte) {
printf("Aucun produit en faible quantité.\n");
}
}
// Programme principal placé à la fin
int main() {
Produit stock[MAX];
int n = 0; // nombre de produits dans le stock
int choix, code;
do {
afficherMenu();
scanf("%d", &choix);
if (choix == 1) {
ajouterProduit(stock, &n);
}
else if (choix == 2) {
printf("Entrer le code du produit à supprimer : ");
scanf("%d", &code);
supprimerProduit(stock, &n, code);
}
else if (choix == 3) {
printf("Entrer le code du produit à modifier : ");
scanf("%d", &code);
modifierProduit(stock, n, code);
}
else if (choix == 4) {
afficherStock(stock, n);
}
else if (choix == 5) {
printf("Entrer le code du produit à rechercher : ");
scanf("%d", &code);
rechercherProduit(stock, n, code);
}
else if (choix == 6) {
verifierAlertes(stock, n);
}
else if (choix == 0) {
printf("Fermeture du programme...\n");
}
else {
printf("Choix invalide.\n");
}
} while(choix != 0);
return 0;
}