#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Date{
    int jours ;
    int mois;
    int annee;
}date;
struct Horloge{
    int heure;
    int minute;
    int second;
    };
struct Client{
    char first_name [50];
    char last_name [50];
    char ncin [8];
    char ntlf [8];
}client;
struct flight{
    char destination[50];
    float price;
    int nb_place;
    int nb_flight;
    struct Date date;
    struct Horloge flight_time ;
    int places_empty;
    struct Client clients [50];
}flight;
void generateflight(char destination[50], char client[50],char horloge[50] ,char date[50] ){
    printf("\n\n");
    printf("\t     ADV. FLIGHT");
    printf("\n\t     -------------------------");
    printf("\nDate:%s", date);
    printf("\nHorloge:%s", horloge);
    printf("\nFlight To: %s", destination);
    printf("\nClient:%s", client);
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("nb_place\t\t");
    printf("nb_flight\t\t");
    printf("price\t\t");
    printf("------------------------------------------------------------\n");
    printf("\n\n");

}
int main(){
 
    int opt,i, foundflight=0 ,nb; 
    flight flt[100];
    int cpt=0;
    struct Date date;
    struct Horloge horloge;
    char d;
    client clt[50];
    char savefile ='y';
    FILE *fp;
    char answer;
    printf("\t====================ADV. FLIGHT=================="); 
    printf("\n1.Add A Flight");
    printf("\n2.Show the description of the flight");
    printf("\n3.Remove A Flight");
    printf("\n4.Edit A Flight");
    printf("\n5.Search A Flight According To The Date");
    printf("\n\nPlease enter your desirable operation:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt){
        case 1:
        system("clear");
        printf("\nAdd a new flight:\t");
        flt.[cpt].nb_flight=cpt+1;
        printf("\nDestination of the flight :  "  ,);
        fflush(stdin);
        gets(flt[cpt].destination);
        printf("\nNumber of the flight :  %d\n"  , flt[cpt].nb_flight);
        printf("\nNumber of the places :  %d\n"  , flt[cpt].nb_place);
        printf("\nPrice of the flight :  %f\n"  , flt[cpt].price);
        printf("\nLimit number of the flight :  %d\n"  , flt[cpt].empty_places);
        if(flt[cpt].empty_places>100){
            printf("you can't add flight")
        }break;
        printf("\nDATE : ");
        scanf("%d:%d:%d",&Date.jours,&Date.mois,&Date.annee);
        printf("\nHORLOGE : ");
        scanf("%d:%d:%d",&Horloge.heure,&Horloge.minute,&Horloge.second);
        printf("\nCLIENT : %s", flt[cpt].Client);
        printf("\nOperation Well Done");
        cpt++;
        getch();
        printf("\nSave the operation [y/n]:\t");
        scanf("%s",&savefile);
        if (savefile == 'y'){
            fp = fopen("Flight.dat","a+");
            fwrite(&flt,sizeof(struct flight),1,fp);
            if(!fwrite !=0){
                printf("\nWell Saved");
                else 
                      printf("Error Saving");
                      fclose(fp);
            }
        }
        break;
        case 2:
        printf("Description of the flight:\t");
        printf("\nPlease enter the number flight  : %d" ,i);
        system("clear");
        fp = fopen("Flight.dat","r");
        printf("\n  *******THE DESCRIPTION OF %d flight*******\n" , flt[i].nb_flight);
        while(fred(&flight,sizeof(struct flight),1,fp)){
            generateflight(flt[i].destination, flt[i].client,flt[i].horloge ,flt[i].date )
        }
        fclose(fp);
        break;
        case 3:
        system("clear");
        printf("\nDelete A Flight\n\n");
        printf("nb : ");
        foundflight=0;
        for(int j=0 ; cpt;j++){
            if(flt[j].nb_flight==nb)
            {
                foundflight = 1;
                printf("\nDo You Want To Delete The Flight %s %d ?\n", flt[j].destination , flt[j].nb_flight);
                fflush(stdin);
                answer =getchar()
                if((answer=='o') || (answer='O') ){
                    for(int k=j;k<cpt;k++){
                        flt[k]=flt[k+1];
                    }
                    cpt--;
                    printf("\nOperation Well Done !");
                }
            }
        }
        if (foundflight==0){
            printf("\nFlight Not Found !");
        }
        getch();
        break;
        case 4:
        system("clear");
        printf("\nEdit A flight \n\n");
        printf("nb_flight  : %d" , nb);
        foundflight = 0;
        for(int j=0 ;j<cpt;j++){
            if(flt.nb_flight == nb){
                foundflight = 1;
                printf("\n"The Old Coordinate of  %d Flight , flt[j].nb_flight);
                printf("\nDestination    : %s ",flt[j].destination);
                printf("\nNumber Of the Flight   : %d",flt[j].nb_flight);
                printf("\nNumber Of the Place   : %d",flt[j].nb_place);
                printf("\nPrice Of the Flight   : %d",fl
