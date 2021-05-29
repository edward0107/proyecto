#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "conexion.h"
using namespace std;
class ventasMaestrod{
	//atributos
private:
	string no_fact,serie,fecha_fact, id_cliente, id_emple, fecha_ingreso;
	
	//constructor
public:
	ventasMaestrod() {
	}
	ventasMaestrod(string _no_fact,string _serie, string _fecha_fact, string _id_cliente, string _id_emple,string _fecha_ingreso) {
		no_fact = _no_fact;
		serie = _serie;
		fecha_fact = _fecha_fact;
		id_cliente = _id_cliente;
		id_emple = _id_emple;
		fecha_ingreso = _fecha_ingreso;
		
	}
	// metodo
	void crear() {
		int q_estado;
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Ingrese No factura: " << endl;
			cin>> no_fact;
			cout << "Ingrese la serie : " << endl;
			cin>> serie;
			cout << "Ingrese fecha de la factura: " << endl;
			cin>> fecha_fact;
			cout << "Ingrese el id del cliente: " << endl;
			cin >> id_cliente;
			cin.ignore();
			cout << "Ingrese Correo el id del empleado " << endl;
			getline(cin, id_emple);

			string insert = "INSERT INTO ventas(no_factura,serie,fecha_factura,id_cliente,id_empleado,fecha_ingreso)VALUES('" + no_fact + "' ,'" + serie + "','" + fecha_fact + "','" + id_cliente + "','" + id_emple + "',current_timestamp());";
			
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Ingreso Exitoso...." << endl;
			}
			else {
				cout << "xxxx Error al Ingresar xxxxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexion..." << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		conexion cn = conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string consulta = "select * from ventas";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------------------Clientes----------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << endl;
				}
			}
			else {
				cout << "xxxx Error al Consultar xxxxx" << endl;
			}
		}
		else {
			cout << "Error en la Conexion..." << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int q_estado;
			string id;
			cout << "Ingrese el Id de la venta que desea Actualizar: " << endl;
			cin >> id;
			cin.ignore();

			cout << "Ingrese No factura: " << endl;
			getline(cin, no_fact);
			cout << "Ingrese la serie : " << endl;
			getline(cin, serie);
			cout << "Ingrese fecha de la factura: " << endl;
			getline(cin, fecha_fact);
			cout << "Ingrese el id del cliente: " << endl;
			cin >> id_cliente;
			cin.ignore();
			cout << "Ingrese Correo el id del empleado " << endl;
			getline(cin, id_emple);

			string update = "UPDATE ventas SET no_factura ='" + no_fact + "',serie ='" + serie+ "',fecha_factura  ='" +fecha_fact + "',id_cliente = '" + id_cliente + "',id_empleado ='" + id_emple + "',fecha_ingreso ='current_time()'  WHERE Id_venta  = '" + id + "'";
			const char* i = update.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Registro Actualizado Exitosamente... " << endl;
			}
			else {
				cout << "xxx Error al actualizar el Registro xxx " << endl;
			}

		}
		else {
			cout << "Error en la conexion... " << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar() {
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int q_estado;
			string id;
			cout << "Ingrese el Id venta  que desea eliminar" << endl;
			cin >> id;
			string eliminar = "Delete from ventas where Id_venta ='" + id + "'";
			const char* i = eliminar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Registro Eliminado Exitosamente... " << endl;
			}
			else {
				cout << "xxx Error al eliminar el Registro xxx " << endl;
			}

		}
		else {
			cout << "Error en la conexion... " << endl;
		}
		cn.cerrar_conexion();
	}

};


