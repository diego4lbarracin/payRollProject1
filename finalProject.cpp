#include <bits/stdc++.h>
using namespace std;

struct infoEmpleado
{	
	char tipoDoc[2]; //CC, Cedula Ciudadania, CE, Cedula Extranjeria
	char numDoc[16];
	char nombre[20];
	char apellido[20];
	char nivelEducativo[2];//EB, Educacion Basica, EM, Educacion Media, ES, Educacion Superior.
	int anosExperiencia;
	int numCertificaciones;
};


int main(){
	
	//David
	
	
	
	
	
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

	// 	char tipoDoc[2]; //CC, Cedula Ciudadania, CE, Cedula Extranjeria
	// char numDoc[16];
	// char nombre[20];
	// char apellido[20];
	// char nivelEducativo[2];//EB, Educacion Basica, EM, Educacion Media, ES, Educacion Superior.
	// int anosExperiencia;
	// int numCertificaciones;
	
	ifstream arEmpleados;
	ofstream nomina;

	infoEmpleado info;
	arEmpleados.open("empleados.txt");
	nomina.open("reporteNomina.txt", ios::trunc);

	if(arEmpleados.fail()){
		cout<<"El archivo no se puedo capturar correctamente."<<endl;
	}else{

		do
		{
			cout<<"MENU PARA LA CREACIÓN DEL REPORTE DE NOMINA"<<endl;
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
				while (!arEmpleados.eof()){
					// arEmpleados.read((char *)&info, sizeof(infoEmpleado));
					arEmpleados>>info.tipoDoc>>info.numDoc>>info.nombre>>info.apellido>>info.nivelEducativo>>info.anosExperiencia>>info.numCertificaciones;
					if(!nomina.fail()){
						nomina<< fixed << showpoint <<setprecision(2);
						nomina<<left<<setw(6)<<"Tipo"<<setw(11)<<"Documento"<<setw(14)<<"Nombre"<<setw(14)<<"Apellidp"<<setw(14)<<"N.Educativo"<<setw(13)<<"Experiencia"<<setw(14)<<"Certificados"<<setw(12)<<"Salario"<<setw(12)<<"S.Minimos"<<setw(8)<<"Moneda"<<endl;
					}
			}		
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
