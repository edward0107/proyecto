#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"
#include "Puestos.h"
#include "marcas.h"
#include "preveedores.h"
#include "productos.h"
#include "empleados.h"
#include "ventasMaestrod.h"
#include "detalle_ventas.h"

using namespace std;
void  menuPrincipal(Cliente c) {
	int menuS;

	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU CLIENTES :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO CLIENTE" << endl;
		cout << "\t\t\t 2.  LEER CLIENTE" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR CLIENTE" << endl;
		cout << "\t\t\t 4.  ELIMINAR CLIENTE" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> menuS;
		switch (menuS) {
		case 1:
			system("cls");
			c.crear();
			system("pause");
			break;
		case 2:
			c.leer();
			system("pause");
			break;
		case 3:
			c.actualizar();
			system("pause");
			break;
		case 4:
			c.eliminar();
			system("pause");
			break;
		case 5:
			cout <<"Ha salido Exitosamente..." << endl;
			
			system("pause");
			
			break;
		}
		system("cls");
	} while (menuS != 5);

}
void Menu_puestos(Puestos p){
	int opc2;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU PUESTOS :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO PUESTO" << endl;
		cout << "\t\t\t 2.  LEER PUESTO" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR PUESTO" << endl;
		cout << "\t\t\t 4.  ELIMINAR PUESTO" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc2;
		switch (opc2) {
		case 1:
			system("cls");
			p.crear();
			system("pause");
			break;
		case 2:
			p.leer();
			system("pause");
			break;
		case 3:
			p.actualizar();
			system("pause");
			break;
		case 4:
			p.eliminar();
			system("pause");
			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");
			break;
		}
		system("cls");
	} while (opc2 != 5);

}
void menu_marcas(Marcas m) {
	int opc3;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU MARCAS :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVA MARCA" << endl;
		cout << "\t\t\t 2.  LEER MARCA" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR MARCA" << endl;
		cout << "\t\t\t 4.  ELIMINAR MARCA" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc3;
		switch (opc3) {
		case 1:
			system("cls");
			m.crear();
			system("pause");
			break;
		case 2:
			m.leer();
			system("pause");
			break;
		case 3:
			m.actualizar();
			system("pause");
			break;
		case 4:
			m.eliminar();
			system("pause");
			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");
			
			break;
		}
		system("cls");
	} while (opc3 != 5);


}
void menu_proveedores(Proveedores pr) {
	int opc4;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU PROVEEDORES :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO PROVEEDOR" << endl;
		cout << "\t\t\t 2.  LEER PROVEEDOR" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR PROVEEDOR" << endl;
		cout << "\t\t\t 4.  ELIMINAR PROVEEDOR" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc4;
		switch (opc4) {
		case 1:
			system("cls");
			pr.crear();
			system("pause");
			break;
		case 2:
			pr.leer();
			system("pause");
			break;
		case 3:
			pr.actualizar();
			system("pause");
			break;
		case 4:
			pr.eliminar();
			system("pause");
			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");
			break;
		}
		system("cls");
	} while (opc4 != 5);
}
void menu_productos(producto pd) {
	int opc5;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU PRODUCTOS :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO PRODUCTO" << endl;
		cout << "\t\t\t 2.  LEER PRODUCTO" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR PRODUCTO" << endl;
		cout << "\t\t\t 4.  ELIMINAR PRODUCTO" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc5;
		switch (opc5) {
		case 1:
			system("cls");
			pd.crear();
			system("pause");
			break;
		case 2:
			pd.leer();
			system("pause");
			break;
		case 3:
			pd.actualizar();
			system("pause");
			break;
		case 4:
			pd.eliminar();
			system("pause");
			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");
			
			break;
		}
		system("cls");
	} while (opc5 != 5);
}

void menu_empleados(empleados emp) {
	int opc5;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD MENU EMPLEADOS :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVO EMPLEADO" << endl;
		cout << "\t\t\t 2.  LEER EMPLEADOS" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR EMPLEADOS" << endl;
		cout << "\t\t\t 4.  ELIMINAR EMPLEADO" << endl;
		cout << "\t\t\t 5.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc5;
		switch (opc5) {
		case 1:
			system("cls");
			emp.crear();
			system("pause");
			break;
		case 2:
			emp.leer();
			system("pause");
			break;
		case 3:
			emp.actualizar();
			system("pause");
			break;
		case 4:
			emp.eliminar();
			system("pause");
			break;
		case 5:
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");

			break;
		}
		system("cls");
	} while (opc5 != 5);
}
void menu_ventas(ventasMaestrod vmd ,detalle_venta dt ) {
	int opc5;
	do {
		cout << "\t\t\t*******" << endl;
		cout << "\t\t\t\t     .: CRUD VENTAS DETALLE :.    " << endl << endl;
		cout << "\t\t\t 1.  CREAR NUEVA VENTA" << endl;
		cout << "\t\t\t 2.  LEER VENTAS" << endl;
		cout << "\t\t\t 3.  ACTUALIZAR VENTA" << endl;
		cout << "\t\t\t 4.  ELIMINAR VENTA" << endl;
		cout << "\t\t\t 5.  Agregar los detalles a la venta" << endl;
		cout << "\t\t\t 6.  SALIR" << endl << endl;
		cout << "\t\t\t*******" << endl;

		cout << "\nINGRESE UNA OPCION: " << endl;
		cin >> opc5;
		switch (opc5) {
		case 1:
			system("cls");
			vmd.crear();
			system("pause");
			break;
		case 2:
			vmd.leer();
			system("pause");
			break;
		case 3:
			vmd.actualizar();
			system("pause");
			break;
		case 4:
			vmd.eliminar();
			system("pause");
			break;
		case 5:
			
			int val;
			do
			{
				cout << "\t\t\t\tDETALLES DE LA TABLA VENTAS " << endl;
				cout << "\t\t\t 1. CREAR" << endl;
				cout << "\t\t\t 2. VER DETALLES DE LA TABLA " << endl;
				cout << "\t\t\t 3. ELIMANAR DATO " << endl;
				cout << "\t\t\t 4. salir: " << endl;
				cout << "Ingres una opcion" << endl;
				cin >> val;
				switch (val)
				{
				case 1:
					dt.crear();
					system("pause");
					break;
				case 2:
					dt.leer();
					system("pause");
					break;
				case 3: 
					dt.eliminar();
					system("pause");
					break;
					case 4:
					cout << "salir " << endl;

					break;
				}
			} while (val !=4);
			system("cls");

			break;
		case 6: 
			cout << "Ha salido Exitosamente..." << endl;
			system("pause");
			break;
	
		}
		system("cls");
	} while (opc5 != 6);
}
int main()
{
	system("color f0");
	Cliente c = Cliente();
	Puestos p = Puestos();
	Marcas m = Marcas();
	Proveedores pr = Proveedores();
	producto pd = producto();
	empleados emp = empleados();
	ventasMaestrod vmd=ventasMaestrod();
	detalle_venta dt = detalle_venta();
	
	int opc;
	
	cout << "\t\t\t\t\t\tMENU PRINCIPAL" << endl;
	cout << "                                              ----------------\n\n" << endl;
	cout << "\t\t\t\t 1.___ Ver Crud Clientes.........." << endl;
	cout << "\t\t\t\t 2.___ Ver Crud Puestos..........." << endl;
	cout << "\t\t\t\t 3.___ Ver Crud Marcas............" << endl;
	cout << "\t\t\t\t 4.___ Ver Crud Proveedores......." << endl;
	cout << "\t\t\t\t 5.___ Ver Crud Productos........." << endl;
	cout << "\t\t\t\t 6.___ Ver Crud empleados........." << endl;
	cout << "\t\t\t\t 7.___ Ver Crud ventas maestro...." << endl;
	
	cin >> opc;
	switch (opc)
	{
	case 1:
		system("cls");
		menuPrincipal(c);
		system("Pause");
		break;
	case 2:
		Menu_puestos(p);
		system("pause");
		break;
	case 3:
		menu_marcas(m);
		system("pause");
		break;
	case 4:
		menu_proveedores(pr);
		system("pause");
		break;
	case 5:
		menu_productos(pd);
		system("pause");
		break;
	case 6:
		menu_empleados(emp);
		system("Pause");
		break;
	case 7: 
		menu_ventas(vmd,dt);
		system("pause");
		break;


	}

	system("pause");
	return 0;
}