#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

//Variables Globales
double salMin= 1160000;
int cantUsers= 3;
double eBasica[2][4], eMedia[2][4], eSuperior[2][4];


//FUnciones
void Reporte();
// double calculoSalario(string educacion, int anios,int certificados);
void ConsultarInfo();
void CrearTabla(double eBasica[2][4], double eMedia[2][4], double eSuperior[2][4]);

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
    CrearTabla(eBasica,eMedia,eSuperior);
	
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
    ofstream nomina2;
    ofstream nomina3;
    ofstream nomina4;
    ofstream nomina5;

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

                //Evaluando Certificaciones
                if(info[i].certificaciones>=0 && info[i].certificaciones<=1){
                    info[i].salario+=(salMin*0.02);
                }else if (info[i].certificaciones>=2 && info[i].certificaciones<=4){
                    info[i].salario+=(salMin*0.10);
                }else if(info[i].certificaciones>=5){
                    info[i].salario+=(salMin*0.35);
                }

                     //Evalunado anios de experiencia
                if(info[i].anios==0){
                    info[i].salario+=(salMin*0.00);
                    //Capturando datos para tabla comparativa
                        if (info[i].nivel_edu.compare("EB")==0 && info[i].anios==0)
                        {
                            eBasica[0][0]+=1;
                            eBasica[1][0]+= info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("EM")==0 && info[i].anios==0){
                            eMedia[0][0]+=1;
                            eMedia[1][0]+=info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("ES")==0 && info[i].anios==0){
                            eSuperior[0][0]+=1;
                            eSuperior[1][0]+=info[i].salario;
                        }
                }else if(info[i].anios>=1 && info[i].anios<=3){
                    info[i].salario+=(salMin*0.15);
                    //Capturando Datos
                        if (info[i].nivel_edu.compare("EB")==0 && info[i].anios>=1 && info[i].anios<=3)
                        {
                            eBasica[0][1]+=1;
                            eBasica[1][1]+= info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("EM")==0 && info[i].anios>=1 && info[i].anios<=3){
                            eMedia[0][1]+=1;
                            eMedia[1][1]+=info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("ES")==0 && info[i].anios>=1 && info[i].anios<=3){
                            eSuperior[0][1]+=1;
                            eSuperior[1][1]+=info[i].salario;
                        }
                }else if(info[i].anios>=4 && info[i].anios<=7){
                    info[i].salario+=(salMin*0.25);
                    //Capturando Datos
                        if (info[i].nivel_edu.compare("EB")==0 && info[i].anios>=4 && info[i].anios<=7)
                        {
                            eBasica[0][2]+=1;
                            eBasica[1][2]+= info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("EM")==0 && info[i].anios>=4 && info[i].anios<=7){
                            eMedia[0][2]+=1;
                            eMedia[1][2]+=info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("ES")==0 && info[i].anios>=4 && info[i].anios<=7){
                            eSuperior[0][2]+=1;
                            eSuperior[1][2]+=info[i].salario;
                        }
                }else if(info[i].anios>=8){
                    info[i].salario+=(salMin*0.40);
                    //Capturando Datos
                        if (info[i].nivel_edu.compare("EB")==0 && info[i].anios>=8)
                        {
                            eBasica[0][3]+=1;
                            eBasica[1][3]+= info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("EM")==0 && info[i].anios>=8){
                            eMedia[0][3]+=1;
                            eMedia[1][3]+=info[i].salario;
                        }
                        if(info[i].nivel_edu.compare("ES")==0 && info[i].anios>=8){
                            eSuperior[0][3]+=1;
                            eSuperior[1][3]+=info[i].salario;
                        }
                }

                info[i].salEnMinimos= info[i].salario/salMin;
                //Determinando Si es extranjero o no
				if (info[i].doc.compare("CE")==0){
					info[i].salario= info[i].salario/dollar;
					info[i].moneda = "USD";
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
            //Completado
			cout<<"(1) Generar Reporte con los Usuarios en el Orden Registrado"<<endl;
			//Completado
            cout<<"(2) Generar Rerporte por Orden en el Numero de Documento"<<endl;
			//Incompleto
            cout<<"(3) Generar Reporte por Orden Alfabetico en Nombres"<<endl;
            //Completo
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
					nomina2.open("reporteOrdenadoNumeroDocumento.txt");

                    cout<< fixed << showpoint <<setprecision(2);
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;
					cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;

                    nomina2<<setfill('-')<<setw(116)<<'-'<<endl;
                    nomina2<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					nomina2<<setfill('-')<<setw(116)<<'-'<<endl;
					
                    if(!nomina2.fail()){
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

                        *kk=cantUsers;
                        countt= 0;

                        for (int j = 0; j < i; j++)
                        {
                                cout<<endl;
                                cout<<setfill('.')<<left<<setw(6)<<tempCase2[j].doc<<left<<setw(11)<<tempCase2[j].num_doc<<setw(10)<<tempCase2[j].nombre<<setw(14)<<tempCase2[j].apellido<<setw(14)<<tempCase2[j].nivel_edu<<setw(13)<<tempCase2[j].anios<<setw(14)<<tempCase2[j].certificaciones<<"$"<<setw(14)<<tempCase2[j].salario<<setw(11)<<tempCase2[j].salEnMinimos<<setw(8)<<tempCase2[j].moneda<<endl;

                                nomina2<<endl;
                                nomina2<< fixed << showpoint <<setprecision(2);
                                nomina2<<setfill('.')<<left<<setw(6)<<tempCase2[j].doc<<left<<setw(11)<<tempCase2[j].num_doc<<setw(10)<<tempCase2[j].nombre<<setw(14)<<tempCase2[j].apellido<<setw(14)<<tempCase2[j].nivel_edu<<setw(13)<<tempCase2[j].anios<<setw(14)<<tempCase2[j].certificaciones<<"$"<<setw(14)<<tempCase2[j].salario<<setw(11)<<tempCase2[j].salEnMinimos<<setw(8)<<tempCase2[j].moneda<<endl;
                        }
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina2<<endl;
                        nomina2<<setfill('-')<<setw(116)<<'-'<<endl;
					}

					break;
				case 3:
					nomina3.open("reporteOrdenadoAlfabeticamente.txt");

                    cout<< fixed << showpoint <<setprecision(2);
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;
					cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;

                    nomina3<<setfill('-')<<setw(116)<<'-'<<endl;
                    nomina3<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					nomina3<<setfill('-')<<setw(116)<<'-'<<endl;
					
                    if(!nomina3.fail()){
                        while(countt<3){
                            for (int j = 0; j < (*(kk)-countt); j++)
                            {
                                if (((tempCase3[j].nombre).compare(tempCase3[j+1].nombre))>0)
                                {
                                    aux[j]= tempCase3[j];
                                    tempCase3[j]= tempCase3[j+1];
                                    tempCase3[j+1]= aux[j];
                                }
                                countt++;
                            }
                        }

                        *kk=cantUsers;
                        countt= 0;

                        for (int j = 0; j < i; j++)
                        {
                                cout<<endl;
                                cout<<setfill('.')<<left<<setw(6)<<tempCase3[j].doc<<left<<setw(11)<<tempCase3[j].num_doc<<setw(10)<<tempCase3[j].nombre<<setw(14)<<tempCase3[j].apellido<<setw(14)<<tempCase3[j].nivel_edu<<setw(13)<<tempCase3[j].anios<<setw(14)<<tempCase3[j].certificaciones<<"$"<<setw(14)<<tempCase3[j].salario<<setw(11)<<tempCase3[j].salEnMinimos<<setw(8)<<tempCase3[j].moneda<<endl;

                                nomina3<<endl;
                                nomina3<< fixed << showpoint <<setprecision(2);
                                nomina3<<setfill('.')<<left<<setw(6)<<tempCase3[j].doc<<left<<setw(11)<<tempCase3[j].num_doc<<setw(10)<<tempCase3[j].nombre<<setw(14)<<tempCase3[j].apellido<<setw(14)<<tempCase3[j].nivel_edu<<setw(13)<<tempCase3[j].anios<<setw(14)<<tempCase3[j].certificaciones<<"$"<<setw(14)<<tempCase3[j].salario<<setw(11)<<tempCase3[j].salEnMinimos<<setw(8)<<tempCase3[j].moneda<<endl;
                        }
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina3<<endl;
                        nomina3<<setfill('-')<<setw(116)<<'-'<<endl;
					}

					break;
				case 4:
					nomina4.open("reporteOrdenadoAniosExperiencia.txt");

                    cout<< fixed << showpoint <<setprecision(2);
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;
					cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;

                    nomina4<<setfill('-')<<setw(116)<<'-'<<endl;
                    nomina4<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					nomina4<<setfill('-')<<setw(116)<<'-'<<endl;
					
                    if(!nomina4.fail()){
                        while(countt<3){
                            for (int j = 0; j < (*(kk)-countt); j++)
                            {
                                if (tempCase4[j].anios>tempCase4[j+1].anios)
                                {
                                    aux[j]= tempCase4[j];
                                    tempCase4[j]= tempCase4[j+1];
                                    tempCase4[j+1]= aux[j];
                                }
                                countt++;
                            }
                        }

                        *kk=cantUsers;
                        countt= 0;

                        for (int j = 0; j < i; j++)
                        {
                            cout<<endl;
                            cout<<setfill('.')<<left<<setw(6)<<tempCase4[j].doc<<left<<setw(11)<<tempCase4[j].num_doc<<setw(10)<<tempCase4[j].nombre<<setw(14)<<tempCase4[j].apellido<<setw(14)<<tempCase4[j].nivel_edu<<setw(13)<<tempCase4[j].anios<<setw(14)<<tempCase4[j].certificaciones<<"$"<<setw(14)<<tempCase4[j].salario<<setw(11)<<tempCase4[j].salEnMinimos<<setw(8)<<tempCase4[j].moneda<<endl;

                            nomina4<<endl;
                            nomina4<< fixed << showpoint <<setprecision(2);
                            nomina4<<setfill('.')<<left<<setw(6)<<tempCase4[j].doc<<left<<setw(11)<<tempCase4[j].num_doc<<setw(10)<<tempCase4[j].nombre<<setw(14)<<tempCase4[j].apellido<<setw(14)<<tempCase4[j].nivel_edu<<setw(13)<<tempCase4[j].anios<<setw(14)<<tempCase4[j].certificaciones<<"$"<<setw(14)<<tempCase4[j].salario<<setw(11)<<tempCase4[j].salEnMinimos<<setw(8)<<tempCase4[j].moneda<<endl;
                        }
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina4<<endl;
                        nomina4<<setfill('-')<<setw(116)<<'-'<<endl;
					}
					break;
				case 5:
					nomina5.open("reportOrdenadoSalariosMinimos.txt");

                    cout<< fixed << showpoint <<setprecision(2);
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;
					cout<<setfill('.')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
                    cout<<setfill('-')<<setw(116)<<'-'<<endl;

                    nomina5<<setfill('-')<<setw(116)<<'-'<<endl;
                    nomina5<<setfill(' ')<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(10)<<"Nombre"<<setw(14)<<"Apellido"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(14)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					nomina5<<setfill('-')<<setw(116)<<'-'<<endl;
					
                    if(!nomina5.fail()){
                        while(countt<3){
                            for (int j = 0; j < (*(kk)-countt); j++)
                            {
                                if (tempCase5[j].salEnMinimos>tempCase5[j+1].salEnMinimos)
                                {
                                    aux[j]= tempCase5[j];
                                    tempCase5[j]= tempCase5[j+1];
                                    tempCase5[j+1]= aux[j];
                                }
                                countt++;
                            }
                        }
                        *kk=cantUsers;
                        countt= 0;
                        for (int j = 0; j < i; j++)
                        {
                                cout<<endl;
                                cout<<setfill('.')<<left<<setw(6)<<tempCase5[j].doc<<left<<setw(11)<<tempCase5[j].num_doc<<setw(10)<<tempCase5[j].nombre<<setw(14)<<tempCase5[j].apellido<<setw(14)<<tempCase5[j].nivel_edu<<setw(13)<<tempCase5[j].anios<<setw(14)<<tempCase5[j].certificaciones<<"$"<<setw(14)<<tempCase5[j].salario<<setw(11)<<tempCase5[j].salEnMinimos<<setw(8)<<tempCase5[j].moneda<<endl;

                                nomina5<<endl;
                                nomina5<< fixed << showpoint <<setprecision(2);
                                nomina5<<setfill('.')<<left<<setw(6)<<tempCase5[j].doc<<left<<setw(11)<<tempCase5[j].num_doc<<setw(10)<<tempCase5[j].nombre<<setw(14)<<tempCase5[j].apellido<<setw(14)<<tempCase5[j].nivel_edu<<setw(13)<<tempCase5[j].anios<<setw(14)<<tempCase5[j].certificaciones<<"$"<<setw(14)<<tempCase5[j].salario<<setw(11)<<tempCase5[j].salEnMinimos<<setw(8)<<tempCase5[j].moneda<<endl;
                        }
                        cout<<endl;
                        cout<<setfill('-')<<setw(116)<<'-'<<endl;
                        nomina5<<endl;
                        nomina5<<setfill('-')<<setw(116)<<'-'<<endl;
					}
					break;
				case 6:
					cout<<"Has salido."<<endl;
                    delete[] tempCase2,tempCase3, tempCase4, tempCase5;
                    delete kk;

                    break;
				default:
					cout<<"Opcion Equivocada"<<endl;
					cout<<"Ingrese una opcion validad nuevamente"<<endl;
					break;
			}

		} while (op!=6);
		
		
}

void ConsultarInfo(){
//David	
}

void CrearTabla(double eBasica[2][4], double eMedia[2][4], double eSuperior[2][4]){
    int op=0;
    do
    {
        cout<<"MENU"<<endl;
        cout<<"(1) Tabla comparativa de empleados entre nivel educativo y anios de experiencia."<<endl;
        cout<<"(2) Tabla comparativa de salarios entre nivel educativo y anios de experiencia."<<endl;
        cout<<"(3) Salir."<<endl;
        cin>>op;
        switch (op)
        {
            case 1:
                cout<<setfill('-')<<setw(48)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<' '<<setw(12)<<"0 Anios"<<setw(12)<<"1-3 Anios"<<setw(12)<<"4-7 Anios"<<setw(12)<<"8 o mas"<<endl;
                cout<<setfill('-')<<setw(48)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"EB"<<setw(12)<<eBasica[0][0]<<setw(12)<<eBasica[0][1]<<setw(12)<<eBasica[0][2]<<setw(12)<<eBasica[0][3]<<endl;
                cout<<setfill('-')<<setw(48)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"EM"<<setw(12)<<eMedia[0][0]<<setw(12)<<eMedia[0][1]<<setw(12)<<eMedia[0][2]<<setw(12)<<eMedia[0][3]<<endl;
                cout<<setfill('-')<<setw(48)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"ES"<<setw(12)<<eSuperior[0][0]<<setw(12)<<eSuperior[0][1]<<setw(12)<<eSuperior[0][2]<<setw(12)<<eSuperior[0][3]<<endl;
                cout<<setfill('-')<<setw(48)<<'-'<<endl;
                break;
            case 2:
                cout<<setfill('-')<<setw(80)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<" "<<setw(20)<<"0 Anios"<<setw(20)<<"1-3 Anios"<<setw(20)<<"4-7 Anios"<<setw(20)<<"8 o mas"<<endl;
                cout<<setfill('-')<<setw(80)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"EB"<<setw(20)<<eBasica[1][0]<<setw(20)<<eBasica[1][1]<<setw(20)<<eBasica[1][2]<<setw(20)<<eBasica[1][3]<<endl;
                cout<<setfill('-')<<setw(80)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"EM"<<setw(20)<<eMedia[1][0]<<setw(20)<<eMedia[1][1]<<setw(20)<<eMedia[1][2]<<setw(20)<<eMedia[1][3]<<endl;
                cout<<setfill('-')<<setw(80)<<'-'<<endl;
                cout<<setfill(' ')<<left<<setw(4)<<"ES"<<setw(20)<<eSuperior[1][0]<<setw(20)<<eSuperior[1][1]<<setw(20)<<eSuperior[1][2]<<setw(20)<<eSuperior[1][3]<<endl;
                cout<<setfill('-')<<setw(80)<<'-'<<endl;
                break;
            case 3: 
                    cout<<"Ha salido"<<endl;
                break;
            default:
                    cout<<"Opcion Errada"<<endl;
                    cout<<"Escoja una nueva opcion"<<endl;
                break;
        }
    } while (op!=3);


}
