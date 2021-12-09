#include <stdio.h>
#include <conio.h>
#include <String.h>
#include <fstream>
using namespace std;

char falso[2];

class Archivo{
	public:
		int idPac, positivo, fallecido, idEst;
	public:
		// por default
		Archivo(){
			idPac=0;
			positivo=0;
			fallecido=0;
			idEst=0;
		}
		
		// con parametros
		Archivo(int pidPac, int ppositivo, int pfallecido, int pidEst){
			idPac=pidPac;
			positivo=ppositivo;
			fallecido=pfallecido;
			idEst=pidEst;
		}
		
		// valida que no se repitan los folio
		bool existe_id(int busca_id){
			ifstream arch;
			arch.open("datos.txt",ios::in);
			while(!arch.eof()){
				arch >>idPac >>positivo >>fallecido >>idEst;
				if(busca_id == idPac){
					arch.close();
					return (true);
				}
			}
			arch.close();
			return (false);
		}
		
		// graba nueva informacion en el archivo
		void grabar(){
			ofstream arch;
			arch.open("datos.txt",ios::app);
			arch <<idPac << " " <<positivo << " " <<fallecido << " " <<idEst <<"\n";
			arch.close();
		}
		
		// se usa cuando se consulta
		void muestra(){
			printf("ID del paciente               : %d\n",idPac);
			printf("Positivo                      : %d\n",positivo);
			printf("Fallecido                     : %d\n",fallecido);
			printf("ID del estado                 : %d\n",idEst);
		}
		
		// 3) Conteo y porcentaje de positivos
		void cyp_p(int pidPac, int ppositivos, int pfallecido, int pidEst){
			printf("\n");
			printf("******************************************************\n");
			printf("*********  CONTEO Y PORCENTAJE DE POSITIVOS  *********\n");
			printf("******************************************************\n");
			ifstream arch;
			arch.open("datos.txt",ios::in);
			float sp,tr=-1.00,pp;
			while(!arch.eof()){
				arch >>idPac >>positivo >>fallecido >>idEst;
				
				if(positivo==1){     // suma positivos
					sp++;
				}
				tr++;                // contador
				pp = (sp/tr)*100;    // porcentaje 
			}
			printf("Positivos               :   %.2f \n",sp);
			printf("Total de registros      :  %.2f\n",tr);
			printf("Porcentaje de positivos :   %.2f %c\n",pp,37);

			arch.close();
			getche();
		}
		
		// 4) Conteo y porcentaje de negativos
		void cyp_n(int pidPac, int ppositivos, int pfallecido, int pidEst){
			printf("\n");
			printf("******************************************************\n");
			printf("*********  CONTEO Y PORCENTAJE DE NEGATIVOS  *********\n");
			printf("******************************************************\n");
			ifstream arch;
			arch.open("datos.txt",ios::in);
			float sn,tr=-1.00,pn;
			while(!arch.eof()){
				arch >>idPac >>positivo >>fallecido >>idEst;
				
				if(positivo==0){     // suma de negativos
					sn++;
				}
				tr++;                // contador
				pn = (sn/tr)*100;    // porcentaje 
			}
			printf("Negativos               :   %.2f \n",sn);
			printf("Total de registros      :  %.2f\n",tr);
			printf("Porcentaje de negativos :   %.2f %c\n",pn,37);

			arch.close();
			getche();
		}
		
        // 5) Conteo y porcentaje de positivos fallecidos
		void cypp_f(int pidPac, int ppositivos, int pfallecido, int pidEst){
			printf("\n");
			printf("******************************************************\n");
			printf("***  CONTEO Y PORCENTAJE DE POSITIVOS FALLECIDOS  ****\n");
			printf("******************************************************\n");
			ifstream arch;
			arch.open("datos.txt",ios::in);
			float sp,tr=-1.00,sf,ppfp,ppftr;
			while(!arch.eof()){
				arch >>idPac >>positivo >>fallecido >>idEst;
				
				if(positivo==1){         // suma de positivos
					sp++;
				}
				tr++;                    // contador
				if((positivo==1) && (fallecido==1)){        // suma fallecidos positivos
					sf++;
				}
				ppfp = (sf/sp)*100;      // porcentaje respecto a positivos
				ppftr = (sf/tr)*100;     // porcentaje respecto a total registros
			}
			printf("Positivos                          :   %.2f \n",sp);
			printf("Total de registros                 :  %.2f\n",tr);
			printf("Fallecidos                         :   %.2f\n",sf);
			printf("Porcentaje de positivos fallecidos :   %.2f %c (CON RESPECTO A POSITIVOS)\n",ppfp,37);
			printf("Porcentaje de positivos fallecidos :   %.2f %c (CON RESPECTO A TOTAL DE REGISTROS)\n",ppftr,37);

			arch.close();
			getche();
		}	
		
 		// 6) Conteo y porcentaje de positivos NO fallecidos
		void cypp_nf(int pidPac, int ppositivos, int pfallecido, int pidEst){
			printf("\n");
			printf("******************************************************\n");
			printf("**  CONTEO Y PORCENTAJE DE POSITIVOS NO FALLECIDOS  **\n");
			printf("******************************************************\n");
			ifstream arch;
			arch.open("datos.txt",ios::in);
			float sp,tr=-1.00,snf,ppfp,ppftr;
			while(!arch.eof()){
				arch >>idPac >>positivo >>fallecido >>idEst;
				
				if(positivo==1){         // suma de positivos
					sp++;
				}
				tr++;                    // contador
				if((positivo==1) && (fallecido==0)){        // suma no fallecidos positivos
					snf++;
				}
				ppfp = (snf/sp)*100;      // porcentaje respecto a positivos
				ppftr = (snf/tr)*100;     // porcentaje respecto a total registros
			}
			printf("Positivos                          :   %.2f \n",sp);
			printf("Total de registros                 :  %.2f\n",tr);
			printf("NO fallecidos                      :   %.2f\n",snf);
			printf("Porcentaje de positivos fallecidos :   %.2f %c (CON RESPECTO A POSITIVOS)\n",ppfp,37);
			printf("Porcentaje de positivos fallecidos :   %.2f %c (CON RESPECTO A TOTAL DE REGISTROS)\n",ppftr,37);

			arch.close();
			getche();
		}		
};

// 1) Altas de registros
void altas(){
	int idPac,positivo,fallecido,idEst;
	printf("\n");
	printf("******************************************************\n");
	printf("*****************  ALTAS DE REGISTRO  ****************\n");
	printf("******************************************************\n");	
	do{
		printf("Indique el ID del paciente                      :  "); scanf("%d",&idPac); gets(falso);
		if((idPac<1)|| (idPac>9999)){
			printf("Error, el rango del ID del paciente es de 1 a 9999 ...\n");
			getche();
		}
	} while ((idPac<1) || (idPac>9999));
	
	Archivo obj;
	if (obj.existe_id(idPac)){
		printf("Error, el ID del paciente se duplica en la base de datos ...\n");
		getche();
	}
	// valida las variables 
	else{
		do{
			printf("El paciente es positivo? (1 para si, 0 para no) :  "); scanf("%d",&positivo); gets(falso);
			if ((positivo>1) || (positivo<0)){
				printf("Error, el valor solo puede ser 0 o 1 ...\n");
				getche();
			} 
		} while ((positivo>1) || (positivo<0));
		
		do{
			printf("El paciente falleci%c? (1 para si, 0 para no)    :  ",162); scanf("%d",&fallecido); gets(falso);
			if ((fallecido>1) || (fallecido<0)){
				printf("Error, el valor solo puede ser 0 o 1 ...\n");
				getche();
			} 
		} while ((fallecido>1) || (fallecido<0));
		
		do{
			printf("Indique el ID del estado                        :  "); scanf("%d",&idEst); gets(falso);
			if((idEst<1)|| (idEst>32)){
				printf("Error, el rango del ID del estado es de 1 a 32 ...\n");
				getche();
			}
		} while ((idEst<1)|| (idEst>32));
		
		// graba en el archivo
		Archivo obj(idPac,positivo,fallecido,idEst);
		obj.grabar();
		printf("\n");
		printf("El registro ha sido grabado correctamente [ENTER] para continuar\n");
		getche();
	}
}

// 2) Consulta por folio de registro
void consultas(){
	int idPac;
	printf("\n");
	printf("******************************************************\n");
	printf("****************  CONSULTA POR FOLIO  ****************\n");
	printf("******************************************************\n");
	printf("Indica el ID del paciente     : "); scanf("%d",&idPac); gets(falso);
	Archivo obj;
	if (!obj.existe_id(idPac)){
		printf("Error, ID del paciente inexistentes en la base de datos ...\n");
		getche();
	}
	else{
		printf("\n");
		obj.muestra();
		getche();
	}
}

void menu(){
	int op;
	while(op!=7){
		system("clS");
		printf("\n");
		printf("******************************************************\n");
		printf("******************  MENU PRINCIPAL  ******************\n");
		printf("******************************************************\n");
		printf("1) Altas de registros\n");
		printf("2) Consulta por folio de registro\n");
		printf("3) Conteo y porcentaje de positivos\n");
		printf("4) Conteo y porcentaje de negativos\n");
		printf("5) Conteo y porcentaje de positivos fallecidos\n");
		printf("6) Conteo y porcentaje de positivos NO fallecidos\n");
		printf("7) TERMINAR\n");
		printf("\n");
		printf("Indique la opci%cn deseada: ",162);
		scanf("%d",&op); gets(falso);
		
		if ((op<1)|| (op>7)){
			printf("Error, opci%cn fuer de rango entre 1 y 7 ...\n",162);
			getche();
		}
		else{
			if(op==1) altas();
			if(op==2) consultas();
			Archivo obj;
			if(op==3) obj.cyp_p(0,0,0,0);
			if(op==4) obj.cyp_n(0,0,0,0);
			if(op==5) obj.cypp_f(0,0,0,0);
			if(op==6) obj.cypp_nf(0,0,0,0);
		}
	}
}


main(){
	menu();
}
