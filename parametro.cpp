#include <iostream> 
#include <stdlib.h> 
#include <math.h> 
#include <conio.h>
using namespace std;

int main()

{
    int i;
    int opcao, escala;
    float temperatura[3], temperaturaC[3], temperaturaR[3], kuop[3];
    float api[3];
    float  densidade[3];

    do{ 

    cout <<"       |                                           |"<< "\n"
         <<"       |  PARAMETROS DE CARACTERIZACAO DO PETROLEO |"<< "\n"
         <<"       |                                           |"<< "\n"
         <<""
         <<"| ------------------------------------------------------------|"<<"\n"
         <<"| 1 - CALCULAR O VALOR DO GRAU API DAS AMOSTRA                |"<<"\n"
         <<"| 2 - CLASSIFICACAO DA AMOSTRA DO PETROLEO SEGUNDO O GRAU API |"<< "\n"
         <<"| 3 - FATOR KUOP E CLASSIFICACAO DA AMOSTRA                   |"<<"\n"
         <<"| 4 - TIPO DE PRODUTO DESTILADO ESPERADO PARA A AMOSTRA       |"<<"\n"
         <<"| 5 - SAIR                                                    |"<<"\n"
         <<"|-------------------------------------------------------------|"<<"\n"
         <<"\n"; 
    cin >> opcao;

    system("cls");
    switch(opcao) {

    case 1:
        for (i=0; i<3; i++){ 
          
            cout << "Digite o valor da densidade da amostra " << i+1<<":  ";
            cin >>densidade[i];
        }
        for (i=0; i<3; i++){
		api[i] = (141.5 / densidade[i])- 131.5;
		cout.setf(ios::fixed);  
		cout.precision(0);
            	cout <<"Grau API: " <<i+1<<":  "<< api[i]<<"\n";
        }

         break;


     case 2:
            for (i=0; i<3; i++){
            cout << "amostra " << i+1 <<" :  ";


            api[i] = (141.5 / densidade[i])- 131.5;

     if ( api[i] > 30.0){
             cout << " A CLASSIFICACAO DO HIDROCARBONETO = PETROLEO LEVE" <<endl;
         }else if (  api[i] >= 21.0 &&  api[i] <= 30.0){
             cout << " A CLASSIFICACAO DO HIDROCARBONETO = PETROLEO MEDIO" <<endl;
         }else{
             cout << " A CLASSIFICACAO DO HIDROCARBONETO = PETROLEO PESADO" <<endl;
         }
            }
         break;
    case 3:
        for (i=0; i<3; i++){
        cout << "amostra " << i+1 <<" :  ";
        cout << "Qual a temperatura de EBULICAO(graus celsius)"<<":  ";
        cin>> temperaturaC[i];


    temperaturaR[i]= ( 18*temperaturaC[i]+ 491.2) / 8;
    kuop[i]=  pow(temperaturaR[i],1.0/3.0) / densidade[i];
    	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(2);

    if (kuop[i]>= 12.0){
         cout << " KUOP= "<< kuop[i]<<"\nCLASSIFICACAO: OLEO PREDOMINANTIMENTE PARAFINICO\n" << endl;
        }else if (kuop[i]> 10.0 && kuop[i]<= 11.8){
         cout << " KUOP= "<< kuop[i]<< "\nCLASSIFICACAO: OLEO PREDOMINANTIMENTE NAFTENICO\n" << endl;
         }else{
         cout << "KUOP= "<< kuop[i]<< "\nCLASSIFICACAO: OLEO PREDOMINANTIMENTE AROMATICO\n" << endl;
         }
        }
   break;


   case 4:

            cout<<"| Qual a escala de temperatura que voce vai utilizar?   |"<<"\n"
                <<"| 1 - CELSIUS                                           |"<<"\n"
                <<"| 2 - FAHRENHEIT                                        |"<<"\n"
                <<"\n";
                cin >> escala;
                 system("cls");
                  for ( i=0; i<3; i++)
        {
            cout << " Digite o valor de temperatura de DESTILACAO " << i+1 <<":  ";
            cin >> temperatura[i];}
          for ( i=0; i<3; i++) {
//usar matriz
                switch(escala) {
            case 1:
               if (temperatura[i] < 33.0){
               cout << "temperatura "<<temperatura[i]<< " \nDESTILADO SERA: GAS BUTANO OU FRACOES INFERIORES "<< endl;
               }else if (temperatura[i] >= 33.0 && temperatura[i] <= 105.0){
               cout << "temperatura "<<temperatura[i]<<" \nDESTILADO SERA:  GASOLINA"<< endl;
               }else if (temperatura[i]>= 105.0 && temperatura[i] <= 158.0){
               cout << "temperatura "<<temperatura[i]<<" \nDESTILADO SERA:  NAFTA"<< endl;
              }else if (temperatura[i]>= 158.0 && temperatura[i] <= 233.0){
                cout <<"temperatura "<<temperatura[i]<< "\nDESTILADO SERA:  QUEROSENE"<< endl;
                }else if (temperatura[i]>= 233.0 && temperatura[i] <= 427.0){
                cout << "temperatura "<<temperatura[i]<<" \nDESTILADO SERA:  GASOLEO"<< endl;
                }else{
                cout << "temperatura"<<temperatura[i]<<" \nDESTILADO SERA:  RESIDUOS"<< endl;
                }
              break;
            case 2:
            if (temperatura[i] < 62.6){ //usarmatriz
            cout <<"temperatura "<< temperatura[i]<<" \nDESTILADO SERA: GAS BUTANO OU FRACOES INFERIORES "<< endl;
           }else if (temperatura[i] >= 62.6 && temperatura[i] <= 192.2){
            cout <<"temperatura "<<temperatura[i]<< " \nDESTILADO SERA:  GASOLINA"<< endl;
           }else if (temperatura[i]>= 192.2 && temperatura[i] <= 287.6){
              cout <<"temperatura "<< temperatura[i]<<" \nDESTILADO SERA:  NAFTA"<< endl;
           }else if (temperatura[i]>= 287.6 && temperatura[i] <= 422.6){
                cout <<"temperatura "<<temperatura[i]<< "\nDESTILADO SERA:  QUEROSENE"<< endl;
           }else if (temperatura[i]>= 422.6 && temperatura[i] <= 771.8){
                cout <<"temperatura "<<temperatura[i]<< " \nDESTILADO SERA:  GASOLEO"<< endl;
           }else{
                cout << "temperatura "<<temperatura[i]<<" \nDESTILADO SERA:  RESIDUOS"<< endl;
                }
            break;
           default:
                 cout <<"VOCE NAO OBTERA DESTILADO "<< endl;
                }
                }
           break;

    case 5:

        cout <<"*****FIM DO PROCESSO****"<<endl;

        break;

        default:
    cout << "opcao invalida";
        break;

    }
    getch();
system("cls");
    }while (i != 5);
    return 0;

}
