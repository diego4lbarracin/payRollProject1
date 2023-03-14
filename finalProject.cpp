#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

void Reporte();

struct infoEmpleado
{	
	char tipoDoc[2]; //CC, Cedula Ciudadania, CE, Cedula Extranjeria
	long long numDoc;
	char nombre[20];
	char apellido[20];
	char nivelEducativo[2];//EB, Educacion Basica, EM, Educacion Media, ES, Educacion Superior.
	int anosExperiencia;
	int numCertificaciones;

	//necesarios
	long double salario;
	double salEnSalariosMinimos;
	char moneda[3];

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
	int op=0;

		char tipoDoc[2]; //CC, Cedula Ciudadania, CE, Cedula Extranjeria
	char numDoc[16];
	char nombre[20];
	char apellido[20];
	char nivelEducativo[2];//EB, Educacion Basica, EM, Educacion Media, ES, Educacion Superior.
	int anosExperiencia;
	int numCertificaciones;
	char tipoDoc[2]; //CC, Cedula Ciudadania, CE, Cedula Extranjeria
	long long numDoc;
	char nombre[20];
	char apellido[20];
	char nivelEducativo[2];//EB, Educacion Basica, EM, Educacion Media, ES, Educacion Superior.
	int anosExperiencia;
	int numCertificaciones;
	long double salario;
	double salEnSalariosMinimos;
	char moneda[3];

	ifstream arEmpleados;
	ofstream nomina;
	int i=0;
	infoEmpleado infoEm;
	vector <infoEmpleado> info;


	arEmpleados.open("empleados.txt");


	if(arEmpleados.fail()){
		cout<<"El archivo no se puedo capturar correctamente."<<endl;
	}else{

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

				// for (int i = 0; i < 3; i++)
				// {
					nomina.open("reporteNominaNormal.txt");
					if(!nomina.fail()){
						while (!arEmpleados.eof()){
						// arEmpleados.read((char *)&info, sizeof(infoEmpleado));
						arEmpleados>>tipoDoc>>infoEm.nombre>>infoEm.apellido>>infoEm.nivelEducativo>>infoEm.anosExperiencia>>infoEm.numCertificaciones>>infoEm.salario>>infoEm.salEnSalariosMinimos>>infoEm.moneda;
						
						info.push_back(infoEmpleado());
						info[0].tipoDoc = tipoDoc;
							cout<< fixed << showpoint <<setprecision(2);
							cout<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(14)<<"Nombre"<<setw(14)<<"Apellidp"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(18)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
							cout<<left<<setw(6)<<info[i].tipoDoc<<setw(11)<<info[i].numDoc<<setw(14)<<info[i].nombre<<setw(14)<<info[i].apellido<<setw(14)<<info[i].nivelEducativo<<setw(13)<<info[i].anosExperiencia<<setw(14)<<info[i].numCertificaciones<<setw(18)<<info[i].salario<<setw(12)<<info[i].salEnSalariosMinimos<<setw(8)<<info[i].moneda<<endl;
							
							nomina<< fixed << showpoint <<setprecision(2);
							nomina<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(14)<<"Nombre"<<setw(14)<<"Apellidp"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(18)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
							nomina<<left<<setw(6)<<info[i].tipoDoc<<left<<setw(11)<<info[i].numDoc<<setw(14)<<info[i].nombre<<setw(14)<<info[i].apellido<<setw(14)<<info[i].nivelEducativo<<setw(13)<<info[i].anosExperiencia<<setw(14)<<info[i].numCertificaciones<<"$"<<setw(18)<<info[i].salario<<setw(12)<<info[i].salEnSalariosMinimos<<setw(8)<<info[i].moneda<<endl;
							if (arEmpleados.eof())
							{
								break;
							}
							
						}
					}
					
				// }		
				break;
			case 2:
				/* code */
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

}

void ConsultarInfo(){
//David	
}

void CrearTabla(){	
//Diego
}
