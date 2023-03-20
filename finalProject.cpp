#include <bits/stdc++.h>
using namespace std;

//Proyecto 1 Programacion Avanzada
//David Cuadros Astro
//Santiago Mendez
//Diego Albarracin

struct Empleados{
    string doc;
    long long num_doc;
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

struct Empleados1{
	char * doc;
    int num_doc;
    char * nombre;
    char * apellido;
    char * nivel_edu;
    int anios;
    int certificaciones;
};

//Variables Globales
double salMin= 1160000;
int cantUsers=0;
double eBasica[2][4], eMedia[2][4], eSuperior[2][4];


//FUnciones
void agregarEmpleado(Empleados empleado);
void actualizar_empleado(Empleados empleado);
void ConsultarInfo();
void Reporte();
void CrearTabla(double eBasica[2][4], double eMedia[2][4], double eSuperior[2][4]);
int obtenerNumUsers();

int main(){
	int opcion;
    Empleados empleado;
    do {
        // Mostrar el menú
        cout << "MENU PRINCIPAL" << endl;
        cout << "1. Agregar Empleado." << endl;
        cout << "2. Actualizar Empleado." << endl;
        cout << "3. Consultar Informacion de Empleado."<<endl;
        cout << "4. Crear Reporte de Nomina y Tablas Comparativas."<<endl;
        cout << "5. Salir." << endl;

        // Pedir la opción al usuario
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        // Ejecutar la opción seleccionada
        switch (opcion){
            case 1:
                agregarEmpleado(empleado);
                break;
            case 2:
                actualizar_empleado(empleado);
                break;
            case 3:
                ConsultarInfo();
                break;
            case 4:
                cantUsers= obtenerNumUsers();
                Reporte();
                break;
            case 5:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcion != 5);
}

//Funciones----------------------------------

void agregarEmpleado(Empleados empleado) {
    fstream archivoEmpleados;
    // Pedir los datos del empleado al usuario
    cout << "Ingrese el tipo de documento (CC/CE): ";
    cin >> empleado.doc;
    cout << "Ingrese el numero de documento: ";
    cin >> empleado.num_doc;
    cout << "Ingrese el nombre: ";
    cin >> empleado.nombre;
    cout << "Ingrese el apellido: ";
    cin >> empleado.apellido;
    cout << "Ingrese el nivel educativo (EB/EM/ES): ";
    cin >> empleado.nivel_edu;
    cout << "Ingrese el numero de anios de experiencia: ";
    cin >> empleado.anios;
    cout << "Ingrese el numero de certificaciones: ";
    cin >> empleado.certificaciones;

    // Abrir el archivo empleados.txt en modo append
   // ofstream archivoEmpleados("empleados.txt", ios::app);
    archivoEmpleados.open("empleados.txt", ios::app);
    // Verificar que el archivo se abrió correctamente
    if (!archivoEmpleados.is_open()) {
        cerr << "Error al abrir el archivo empleados.txt" << endl;
        return;
    }

    // Escribir los datos del empleado en el archivo
    archivoEmpleados << empleado.doc << " " << empleado.num_doc << " " << empleado.nombre << " " << empleado.apellido << " " << empleado.nivel_edu << " " << empleado.anios << " " << empleado.certificaciones << endl;

    // Cerrar el archivo
    archivoEmpleados.close();

    cout << "Empleado agregado exitosamente" << endl;
}

void actualizar_empleado(Empleados empleado) {
        
    fstream archivoEmpleados;
    int docu;
    cout << "Ingrese el numero de documento del empleado a actualizar: ";
    cin >> docu;

    archivoEmpleados.open("empleados.txt", ios::in | ios::out);

    if (!archivoEmpleados) {
        cerr << "Error al abrir el archivo de empleados" << endl;
        return;
    }

    bool encontrado = false;

    while (!archivoEmpleados.eof()) {
        int pos = archivoEmpleados.tellg();
        archivoEmpleados >> empleado.doc >> empleado.num_doc >> empleado.nombre >> empleado.apellido >> empleado.nivel_edu >> empleado.anios >> empleado.certificaciones;

        if (archivoEmpleados.fail()) {
            break;
        }

        if ((empleado.num_doc == docu && empleado.doc == "CC")||(empleado.num_doc == docu && empleado.doc == "CE")) {
            encontrado = true;
            cout << "Ingrese el nuevo nombre: ";
            cin >> empleado.nombre;
            cout << "Ingrese el nuevo apellido: ";
            cin >> empleado.apellido;
            cout << "Ingrese el nuevo nivel educativo (EB/EM/ES): ";
            cin >> empleado.nivel_edu;
            cout << "Ingrese los nuevos años de experiencia: ";
            cin >> empleado.anios;
            cout << "Ingrese el nuevo número de certificaciones: ";
            cin >> empleado.certificaciones;

            archivoEmpleados.seekp(pos);
            archivoEmpleados << empleado.doc << " " << empleado.num_doc << " " << empleado.nombre << " " << empleado.apellido << " " << empleado.nivel_edu << " " << empleado.anios << " " << empleado.certificaciones << endl;
            cout << "Datos actualizados correctamente" << endl;
            break;
        }
    }

    if (!encontrado) {
        cerr << "No se encontró ningún empleado con el número de documento ingresado" << endl;
    }

    archivoEmpleados.close();
}

void ConsultarInfo(){
    int ingresar;
    ifstream archivo;
    archivo.open("empleados.txt", ios::in);
    ofstream escribirArchivo;
	
	escribirArchivo.open("consultaInfoEmpleados.txt");
    int opc;
    string na;
    char nombre[30];
    int cert, exp;
    string linea;
    char * separador;
    Empleados1 e;
    
    
    do
    {
            cout<<"Ingrese la opcion segun sea el caso: \nRealizar la busqueda segun: "<<endl;
            cout<<"1. Nombre \n2. Nivel academico \n3. Anios de experiencia \n4. Numero de certificaciones"<<endl;
            cin>>opc;
            
            switch (opc){
        //11111111111111111111111111111111111111111111111111111111111111111111		
                case 1:
                    cout<<"Ingrese nombre del empleado: ";
                    cin>>nombre;
                    while(!archivo.eof()){
                        getline(archivo, linea);
                        separador = strtok((char*)linea.c_str()," ");
                        e.doc = separador;
                        for(int i=1;i<7;i++){
                            separador = strtok(NULL," ");
                            if(i==1){
                                e.num_doc = atoi(separador);
                            }else if(i==2){
                                e.nombre = separador;
                            }
                            else if(i==3){
                                e.apellido = separador;
                            }
                            else if(i==4){
                                e.nivel_edu = separador;
                            }
                            else if(i==5){
                                e.anios = atoi(separador);
                                
                            }	
                            else{
                                e.certificaciones = atoi(separador);
                            }
                        }

                        if(strcmp(e.nombre, nombre)==0){
                            cout <<e.doc <<" "<<e.num_doc<<" "<<e.nombre<<" "<<e.apellido<<" "<<e.nivel_edu<<" "<<e.anios<<" "<<e.certificaciones<<endl;
                            escribirArchivo <<e.doc <<"-"<<e.num_doc<<"-"<<e.nombre<<"-"<<e.apellido<<"-"<<e.nivel_edu<<"-"<<e.anios<<"-"<<e.certificaciones<<endl;            		
                        }
                    }
                break;
        //2222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
                case 2:
                    cout<<"Ingrese nivel educativo (EM, EB, ES): ";
                        cin>>nombre;
                    while(!archivo.eof()){
                        getline(archivo, linea);
                        separador = strtok((char*)linea.c_str()," ");
                        e.doc = separador;
                        for(int i=1;i<7;i++){
                            separador = strtok(NULL," ");
                            if(i==1){
                                e.num_doc = atoi(separador);
                            }else if(i==2){
                                e.nombre = separador;
                            }
                            else if(i==3){
                                e.apellido = separador;
                            }
                            else if(i==4){
                                e.nivel_edu = separador;
                            }
                            else if(i==5){
                                e.anios = atoi(separador);
                                
                            }	
                            else{
                                e.certificaciones = atoi(separador);
                            }
                        }
                            
                            
                            
                        if(strcmp(e.nivel_edu, nombre)==0){
                            cout <<e.doc <<" "<<e.num_doc<<" "<<e.nombre<<" "<<e.apellido<<" "<<e.nivel_edu<<" "<<e.anios<<" "<<e.certificaciones<<endl;
                            escribirArchivo <<e.doc <<"#"<<e.num_doc<<"#"<<e.nombre<<"#"<<e.apellido<<"#"<<e.nivel_edu<<"#"<<e.anios<<"#"<<e.certificaciones<<endl;            		
                        }
 
                    }
                break;
        //33333333333333333333333333333333333333333333333333333333333333333333333333333333333333
                case 3:
                    cout<<"Ingrese anios de experiencia: ";
                        cin>>ingresar;
                    while(!archivo.eof()){
                        getline(archivo, linea);
                        separador = strtok((char*)linea.c_str()," ");
                        e.doc = separador;
                        for(int i=1;i<7;i++){
                            separador = strtok(NULL," ");
                            if(i==1){
                                e.num_doc = atoi(separador);
                            }else if(i==2){
                                e.nombre = separador;
                            }
                            else if(i==3){
                                e.apellido = separador;
                            }
                            else if(i==4){
                                e.nivel_edu = separador;
                            }
                            else if(i==5){
                                e.anios = atoi(separador);
                                
                            }	
                            else{
                                e.certificaciones = atoi(separador);
                            }
                        }
 
                        if(ingresar==e.anios){
                            cout <<e.doc <<" "<<e.num_doc<<" "<<e.nombre<<" "<<e.apellido<<" "<<e.nivel_edu<<" "<<e.anios<<" "<<e.certificaciones<<endl;
                            escribirArchivo <<e.doc <<"#"<<e.num_doc<<"#"<<e.nombre<<"#"<<e.apellido<<"#"<<e.nivel_edu<<"#"<<e.anios<<"#"<<e.certificaciones<<endl;            		
                        }

                    }
                break;
        //444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
                case 4:
                    cout<<"Ingrese numero de certificaciones: ";
                        cin>>ingresar;
                    while(!archivo.eof()){
                        getline(archivo, linea);
                        separador = strtok((char*)linea.c_str()," ");
                        e.doc = separador;
                        for(int i=1;i<7;i++){
                            separador = strtok(NULL," ");
                            if(i==1){
                                e.num_doc = atoi(separador);
                            }else if(i==2){
                                e.nombre = separador;
                            }
                            else if(i==3){
                                e.apellido = separador;
                            }
                            else if(i==4){
                                e.nivel_edu = separador;
                            }
                            else if(i==5){
                                e.anios = atoi(separador);
                                
                            }	
                            else{
                                e.certificaciones = atoi(separador);
                            }
                        }

                            if(e.certificaciones==ingresar){
                                cout <<e.doc <<" "<<e.num_doc<<" "<<e.nombre<<" "<<e.apellido<<" "<<e.nivel_edu<<" "<<e.anios<<" "<<e.certificaciones<<endl;
                                escribirArchivo <<e.doc <<"#"<<e.num_doc<<"#"<<e.nombre<<"#"<<e.apellido<<"#"<<e.nivel_edu<<"#"<<e.anios<<"#"<<e.certificaciones<<endl;            		
                            }

                    }
                    break;
            case 5:
                cout<<"Ha salido"<<endl;
                break;
            default:
                cout<<"Opcion Equivocada"<<endl;
                break;
        }
    }while (opc!=5);
    
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
    cantUsers=i;
	for (int j = 0; j < cantUsers; j++)
    {
        tempCase2[j]= info[j];
        tempCase3[j]= info[j];
        tempCase4[j]= info[j];
        tempCase5[j]= info[j];
    }
    
    do
		{
			cout<<"MENU PARA LA CREACION DEL REPORTE DE NOMINA Y TABLAS COMPARATIVAS"<<endl;
            cout<<endl;
			cout<<"(1) Generar Reporte con los Usuarios en el Orden Registrado."<<endl;
            cout<<"(2) Generar Rerporte por Orden en el Numero de Documento."<<endl;
            cout<<"(3) Generar Reporte por Orden Alfabetico en Nombres."<<endl;
			cout<<"(4) Generar Reporte por Orden en Anos de Experiencia."<<endl;
			cout<<"(5) Generar Reporte por Orden en Cantidad de Salarios Minimos"<<endl;
            cout<<"(6) Crear Tablas Comparativas."<<endl;
			cout<<"(7) Salir."<<endl;
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
                    CrearTabla(eBasica,eMedia,eSuperior);
                    break;
                case 7:
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
int obtenerNumUsers(){
    int num=0;
    ifstream numeros;
    Empleados info;
    numeros.open("empleados.txt");

	if(numeros.fail()){
		cout<<"El archivo no se puedo capturar correctamente."<<endl;
	}else{
        while (!numeros.eof()){
			numeros>>info.doc>>info.num_doc>>info.nombre>>info.apellido>>info.nivel_edu>>info.anios>>info.certificaciones;

            if (numeros.eof()==true){
				break;
            }
            num= num+1;
        }
    }

    return num;

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
                cout<< fixed << showpoint <<setprecision(2);
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
                cout<< fixed << showpoint <<setprecision(2);
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
