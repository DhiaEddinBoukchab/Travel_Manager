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
void generateflight(struct flight flight ){
    printf("\n\n");
    printf("\t     ADV. FLIGHT");
    printf("\n\t     -------------------------");
    printf("\nDate: %d:%d:%d", flight.date.jours,flight.date.mois,flight.date.annee);
    printf("\nHorloge: %d:%d", flight.flight_time.heure,flight.flight_time.minute);
    printf("\nFlight To: %s", flight.destination);
    printf("\n");
    printf("------------------------------------------------------------\n");
    printf("Number of places : %d",flight.nb_place);
    printf("flight number : %d ",flight.nb_flight);
    printf("Price : %f ",flight.price);
    printf("------------------------------------------------------------\n");
    printf("\n\n");

}
int main(){
    int opt,i, foundflight=0 ,nb; 
     struct flight flt[1000];
    int cpt=0;
    struct Date date;
    struct Horloge horloge;
    char d;
    
    char savefile ='y';
    FILE *fp;
    char answer;
    do{
    printf("\t====================ADV. FLIGHT=================="); 
    printf("\n1.Add A Flight");
    printf("\n2.Show the description of the flight");
    printf("\n3.Edit A Flight");
    printf("\n4.Search A Flight According To The Date");
    printf("\n5.Add a client to a flight");
    printf("\n6.QUIT");
    printf("\n\nPlease enter your desirable operation:\t");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt){
        case 1:
        system("clear");
        printf("\nAdd a new flight:\t");
        printf("\nDestination of the flight :  "  );
        fflush(stdin);
        fgets(flt[cpt].destination,50,stdin);
        printf("\nNumber of the flight :  \n");
        scanf("%d",&flt[cpt].nb_flight);
        printf("\nNumber of the places :  \n");
        scanf("%d",&flt[cpt].nb_place);
        printf("\nPrice of the flight :  \n");
        scanf("%f",&flt[cpt].price);
        flt[cpt].places_empty=flt[cpt].nb_place;
        
        printf("\nDATE : ");
        scanf("%d:%d:%d",&date.jours,&date.mois,&date.annee);
        printf("\nHORLOGE : ");
        scanf("%d:%d",&horloge.heure,&horloge.minute);
        printf("\nOperation Well Done");
        cpt++;
        printf("\nSave the operation [y/n]:\t");
        scanf("%c",&savefile);
        if (savefile == 'y'){
            fp = fopen("Flight.dat","a+");
            fwrite(&flt[cpt-1],sizeof(struct flight),1,fp);
            if(!fwrite !=0){
                printf("\nWell Saved");}
                else 
                      printf("Error Saving");
                      fclose(fp);
            }
        
        break;
        case 2:
        printf("Description of the flight:\t");
        printf("\nPlease enter the number flight  : ");
        scanf("%d",&i);
        system("clear");
        fp = fopen("Flight.dat","r");
        printf("\n  *******THE DESCRIPTION OF %d flight*******\n" , i);
        while(fread(&flight,sizeof(struct flight),1,fp)){
           if(flight.nb_flight==i)
             {generateflight(flight);}
        }
        fclose(fp);
        break;
        case 3:
        system("clear");
        printf("\nEdit A flight \n\n");
        printf("nb_flight  : ");
        int i;
        scanf("%d",&i);
         fp = fopen("Flight.dat","r");
         int j=0;
         while(fread(&flight,sizeof(struct flight),1,fp))
            {flt[j]=flight;
             j++;}
         for(int k=0;k<=j;k++)
           {if(flt[k].nb_flight==i)
              {printf("1.Edit the  date\n");
               printf("2.Edit the flight time \n ");
               printf("3.Edit places Number \n");
               printf("4.Edit the Destination \n");
               printf("5.Edit the price \n");
               int o;
               scanf("%d",&o);
               switch(o){
                     case 1:
                     system("clear");
                     printf("day: \n");
                     scanf("%d",&flt[k].date.jours);
                     printf("month :\n");
                     scanf("%d",&flt[k].date.mois);
                     printf("year: \n");
                     scanf("%d",&flt[k].date.annee);
                     printf("operation well done \n");
                     break;
                     case 2:
                     system("clear");
                     printf("flight time :\n");
                     scanf("%d:%d",&flt[k].flight_time.heure,&flt[k].flight_time.minute);
                     printf("opertaion well done");
                     break;
                     case 3:
                     printf("places number :\n");
                     scanf("%d",&flt[k].nb_place);
                     printf("operation well done ");
                     break;
                     case 4 :
                     printf("destination : \n");
                     fgets(flt[k].destination,50,stdin);
                     printf("operation well done");
                     break;
                     case 5:
                     printf("price :");
                     scanf("%f",&flt[k].price);
                     printf("operation well done");
                     break;}}}
            printf("\nSave the operation [y/n]:\t");
            fclose(fp);
            scanf("%c",&savefile);     
            if(savefile=='y')
                 {  fp = fopen("Flight.dat","w+");
                    for(int k=0;k<=j;k++)
                      {fwrite(&flt[k],sizeof(struct flight),1,fp);}
                    printf("well saved") ;
                     fclose(fp);}
            break;         
           case 4: 
           
           printf("the date :\n");
           scanf("%d:%d:%d",&date.jours,&date.mois,&date.annee);
           fp = fopen("Flight.dat","r");
           while(fread(&flight,sizeof(struct flight),1,fp))
             {   char f='n';
                 if(flight.date.jours==date.jours&&flight.date.mois==date.mois&&flight.date.annee==date.annee)
                   {f='y';
                    printf("flight number : %d \n",flight.nb_flight);
                    printf("destination : %s \n",flight.destination);
                    printf("number of places : %d \n",flight.nb_place);
                    printf("date : %d:%d:%d \n",date.jours,date.mois,date.annee);
                    printf("flight time : %d:%d \n",flight.flight_time.heure,flight.flight_time.minute);
                    printf("price : %d \n",flight.price);}
                    
               }
            fclose(fp);
            break;
            case 5: 
             fp = fopen("Flight.dat","r");
             j=0;
             while(fread(&flight,sizeof(struct flight),1,fp))
                {flt[j]=flight;
                  j++;}
             printf("flight number :\n");
			 
			 scanf("%d",&i);
			 printf("first name :\n");
			 fgets(client.first_name,50,stdin);
			 printf("last name :\n");
			 fgets(client.last_name,50,stdin);
			 printf("N° carte identite : \n");
			 fgets(client.ncin,8,stdin);
			 printf("N° de telephone :\n");
			 fgets(client.ntlf,8,stdin);
			 for(int k=0;k<=j;k++){
			 	if(flt[k].nb_flight==i){flt[k].clients[flt[k].nb_place-flt[k].places_empty]=client;
			 	flt[k].places_empty--;
				 }
			 }
			 fclose(fp);
			 printf("operation well done !\n");
			 printf("\nSave the operation [y/n]:\t\n");
			 scanf("%c",&savefile);
			 if(savefile=='y'){
			 fp = fopen("Flight.dat","w+");    
			 for(int k=0;k<=j;k++)
                      {fwrite(&flt[k],sizeof(struct flight),1,fp);}
                    printf("well saved") ;
                     fclose(fp);}
			break; }  }
			while(opt=!6);
			return 0;}
