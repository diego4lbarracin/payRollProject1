#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

//Variables Globales
double salMin= 1160000;
int cantUsers= 3;

//FUnciones
void Reporte();
double calculoSalario(string educacion, int anios,int certificados);


struct Empleados{
    string doc;
    int num_doc;
    string nombre;
    string apellido;
    string nivel_edu;
    int anios;
    int certificaciones;

	//para reporte
	double salario;
	double salEnMinimos;
	string moneda;
};


int main(){
	
	Reporte();
	
	
	
	
	
}

//Funciones----------------------------------

void AdicionEmpleado(){
	//Santiago
}

void ActualizarInfo(){
	//Santiago	
}

void Reporte(){	
	int op=0, countt=0, i=0;
	double dollar= 4746.62; 
    int* kk= new int;
    *kk= cantUsers;
	
    ifstream arEmpleados;
	ofstream nomina;
    ofstream nomina1;

	Empleados info[cantUsers];
    Empleados aux[cantUsers];

    Empleados* tempCase2= new Empleados[cantUsers];
    Empleados* tempCase3= new Empleados[cantUsers];
    Empleados* tempCase4= new Empleados[cantUsers];
    Empleados* tempCase5= new Empleados[cantUsers];

	arEmpleados.open("empleados.txt");

	if(arEmpleados.fail()){
		cout<<"El archivo no se puedo capturar correctamente."<<endl;
	}else{
        while (!arEmpleados.eof()){
			arEmpleados>>info[i].doc>>info[i].num_doc>>info[i].nombre>>info[i].apellido>>info[i].nivel_edu>>info[i].anios>>info[i].certificaciones;
            if (arEmpleados.eof()==true){
				break;
			}else{
                // Calculo de salario//
                if (info[i].nivel_edu.compare("EB")==0)
                {
                    info[i].salario= salMin*1;
                }else if(info[i].nivel_edu.compare("EM")==0){
                    info[i].salario= salMin*1.5;
                }else if (info[i].nivel_edu.compare("ES")==0){
                    info[i].salario= salMin*2.5;
                }
                                //Evalunado anios de experiencia
                if(info[i].anios==0){
                    info[i].salario+=(salMin*0.00);
                }else if(info[i].anios>=1 && info[i].anios<=3){
                    info[i].salario+=(salMin*0.15);
                }else if(info[i].anios>=4 && info[i].anios<=7){
                    info[i].salario+=(salMin*0.25);
                }else if(info[i].anios>=8){
                    info[i].salario+=(salMin*0.40);
                }
                //Evaluando Certificaciones
                if(info[i].certificaciones>=0 && info[i].certificaciones<=1){
                    info[i].salario+=(salMin*0.02);
                }else if (info[i].certificaciones>=2 && info[i].certificaciones<=4){
                    info[i].salario+=(salMin*0.10);
                }else if(info[i].certificaciones>=5){
                    info[i].salario+=(salMin*0.35);
                }
                // info[i].salario= info[i].salario+ calculoSalario(info[i].nivel_edu, info[i].anios,info[i].certificaciones);
                
                                //Representando el Salario en Cantidad de Salarios minimos.
                                info[i].salEnMinimos= info[i].salario/salMin;
                                //Determinando Si es extranjero o no
								if (info[i].doc.compare("CE")==0){
									info[i].salario= info[i].salario/dollar;
									info[i].moneda = "USD";
									// nomina<< fixed << showpoint <<setprecision(2);
									// cout<<endl;
									// cout<<setfill('.')<<left<<setw(6)<<info[i].doc<<left<<setw(11)<<info[i].num_doc<<setw(10)<<info[i].nombre<<setw(14)<<info[i].apellido<<setw(14)<<info[i].nivel_edu<<setw(13)<<info[i].anios<<setw(14)<<info[i].certificaciones<<"$"<<setw(14)<<info[i].salario<<setw(11)<<info[i].salEnMinimos<<setw(8)<<info[i].moneda<<endl;


                                    // nomina<<endl;
                                    // nomina<<setfill('.')<<left<<setw(6)<<info[i].doc<<left<<setw(11)<<info[i].num_doc<<setw(10)<<info[i].nombre<<setw(14)<<info[i].apellido<<setw(14)<<info[i].nivel_edu<<setw(13)<<info[i].anios<<setw(14)<<info[i].certificaciones<<"$"<<setw(14)<<info[i].salario<<setw(11)<<info[i].salEnMinimos<<setw(8)<<info[i].moneda<<endl;
                                }else{
									info[i].moneda = "COP";

                                }
				}
            i+=1;
		}
    }
	for (int j = 0; j < cantUsers; j++)
    {
        tempCase2[j]= info[j];
        tempCase3[j]= info[j];
        tempCase4[j]= info[j];
        tempCase5[j]= info[j];
    }
    
    do
		{
			cout<<"MENU PARA LA CREACION DEL REPORTE DE NOMINA"<<endl;
			cout<<"(1) Generar Reporte con los Usuarios en el Orden Registrado"<<endl;
			cout<<"(2) Generar Rerporte por Orden en el Numero de Documento"<<endl;
			cout<<"(3) Generar Reporte por Orden Alfabetico en Nombres"<<endl;
			cout<<"(4) Generar Reporte por Orden en Anos de Experiencia"<<endl;
			cout<<"(5) Generar Reporte por Orden en Cantidad de Salarios Minimos"<<endl;
			cout<<"(6) Salir."<<endl;
			cout<<"Seleccione una Opcion: "<<endl;
			cin>>op;
			switch (op)
			{
				case 1:
					nomina.open("reporteNominaNormal.txt");
					if(!nomina.fail()){
						cout<< fixed << showpoint <<setprecision(2);
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
						cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;

                        nomina<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
						nomina<<setfill('-')<<setw(116)<<'-'<<endl;
                        for (int j = 0; j < cantUsers; j++)
                        {
                            cout<<endl;
							cout<<setfill('.')<<left<<setw(6)<<info[j].doc<<left<<setw(11)<<info[j].num_doc<<setw(10)<<info[j].nombre<<setw(14)<<info[j].apellido<<setw(14)<<info[j].nivel_edu<<setw(13)<<info[j].anios<<setw(14)<<info[j].certificaciones<<"$"<<setw(14)<<info[j].salario<<setw(11)<<info[j].salEnMinimos<<setw(8)<<info[j].moneda<<endl;

                            nomina<<endl;
                            nomina<< fixed << showpoint <<setprecision(2);
							nomina<<setfill('.')<<left<<setw(6)<<info[j].doc<<left<<setw(11)<<info[j].num_doc<<setw(10)<<info[j].nombre<<setw(14)<<info[j].apellido<<setw(14)<<info[j].nivel_edu<<setw(13)<<info[j].anios<<setw(14)<<info[j].certificaciones<<"$"<<setw(14)<<info[j].salario<<setw(11)<<info[j].salEnMinimos<<setw(8)<<info[j].moneda<<endl;
                        }
                        
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina<<endl;
                        nomina<<setfill('-')<<setw(116)<<'-'<<endl;
					}	
					break;
				case 2:
					nomina1.open("reporteOrdenadoNumeroDocumento.txt");

                    cout<< fixed << showpoint <<setprecision(2);
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;
					cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;

                    nomina1<<setfill('-')<<setw(116)<<'-'<<endl;
                    nomina1<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					nomina1<<setfill('-')<<setw(116)<<'-'<<endl;
					
                    if(!nomina1.fail()){
                        while(countt<3){
                            for (int j = 0; j < (*(kk)-countt); j++)
                            {
                                if (tempCase2[j].num_doc>tempCase2[j+1].num_doc)
                                {
                                    aux[j]= tempCase2[j];
                                    tempCase2[j]= tempCase2[j+1];
                                    tempCase2[j+1]= aux[j];
                                }
                                countt++;
                            }
                        }

                    for (int j = 0; j < i; j++)
                    {
                            cout<<endl;
							cout<<setfill('.')<<left<<setw(6)<<tempCase2[j].doc<<left<<setw(11)<<tempCase2[j].num_doc<<setw(10)<<tempCase2[j].nombre<<setw(14)<<tempCase2[j].apellido<<setw(14)<<tempCase2[j].nivel_edu<<setw(13)<<tempCase2[j].anios<<setw(14)<<tempCase2[j].certificaciones<<"$"<<setw(14)<<tempCase2[j].salario<<setw(11)<<tempCase2[j].salEnMinimos<<setw(8)<<tempCase2[j].moneda<<endl;

                            nomina1<<endl;
                            nomina1<< fixed << showpoint <<setprecision(2);
							nomina1<<setfill('.')<<left<<setw(6)<<tempCase2[j].doc<<left<<setw(11)<<tempCase2[j].num_doc<<setw(10)<<tempCase2[j].nombre<<setw(14)<<tempCase2[j].apellido<<setw(14)<<tempCase2[j].nivel_edu<<setw(13)<<tempCase2[j].anios<<setw(14)<<tempCase2[j].certificaciones<<"$"<<setw(14)<<tempCase2[j].salario<<setw(11)<<tempCase2[j].salEnMinimos<<setw(8)<<tempCase2[j].moneda<<endl;
                    }
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina1<<endl;
                        nomina1<<setfill('-')<<setw(116)<<'-'<<endl;
					}	
					break;
				case 3:
					/* code */

					break;
				case 4:
					/* code */
					break;
				case 5:
					/* code */
					break;
				case 6:
					cout<<"Has salido."<<endl;
				default:
					cout<<"Opcion Equivocada"<<endl;
					cout<<"Ingrese una opcion validad nuevamente"<<endl;
					break;
			}

		} while (op!=6);
		
		
}

double calculoSalario(string educacion, int anios,int certificados){
        double salario=0;
        if (educacion.compare("EB")==0)
        {
            salario= salMin*1;
        }else if(educacion.compare("EM")==0){
            salario= salMin*1.5;
        }else if (educacion.compare("ES")==0){
            salario= salMin*2.5;
        }
        //Evalunado anios de experiencia
        if(anios==0){
            salario+=(salMin*0.00);
        }else if(anios>=1 && anios<=3){
            salario+=(salMin*0.15);
        }else if(anios>=4 && anios<=7){
            salario+=(salMin*0.25);
        }else if(anios>=8){
            salario=(salMin*0.40);
        }
        //Evaluando Certificaciones
        if(certificados>=0 && certificados<=1){
            salario+=(salMin*0.02);
        }else if (certificados>=2 && certificados<=4){
            salario+=(salMin*0.10);
        }else if(certificados>=5){
            salario+=(salMin*0.35);
        }

       return salario;
       salario=0;
}

void ConsultarInfo(){
//David	
}

void CrearTabla(){	
//Diego
}
