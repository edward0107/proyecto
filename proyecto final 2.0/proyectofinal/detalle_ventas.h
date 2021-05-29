#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "conexion.h"
using namespace std;
class detalle_venta {
	//atributos
private:
	string id_venta, id_producto, cantidad, precio_uni,id_detalle;

	//constructor
public:
	detalle_venta() {
	}
	detalle_venta(string _id_venta, string _id_producto, string _cantidad, string _precio_uni,string _id_detalle) {
		id_venta = _id_venta;
		id_producto = _id_producto;
		cantidad = _cantidad;
		precio_uni = _precio_uni;
		id_detalle = _id_detalle;
	}
	// metodo
	void crear() {
		int q_estado;
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			cout << "Ingrese su id del detalle de venta" << endl;
			cin >> id_detalle;
			cout << "Ingrese Id de ventas: " << endl;
			cin >> id_venta;
			cout << "Ingrese Id del producto : " << endl;
			cin >> id_producto;
			cout << "Ingrese cantidad que llevara : " << endl;
			cin >> cantidad;
			cout << "Ingrese el precio unitario : " << endl;
			cin >> precio_uni;

			string insert = "INSERT INTO ventas_detalle(id_venta_detalle,id_venta,id_producto,cantidad,precio_unitario)VALUES('"+id_detalle+"','" + id_venta + "' ,'" + id_producto + "','" +cantidad + "','" +precio_uni + "')";

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
			string consulta = "select * from ventas_detalle";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------------------Detalles de venta----------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Id_detalle" << "--" << "Id_venta" << "--" << "Id_producto" <<"--"<< "cantidad" <<"--"<< "Precio unitario"<<endl;
					cout << "|" << endl; cout << fila[0] << "-------" << fila[1] << "------ " << fila[2] << "-----" << fila[3] << "----" << fila[4] << endl;
					
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
			cout << "Ingrese el Id del detalle de venta que desea Actualizar: " << endl;
			cin >> id;
			

			cout << "Ingrese Id venta: " << endl;
			cin>>id_venta;
			cout << "Ingrese Id_producto : " << endl;
			cin>>id_producto;
			cout << "Ingrese fecha de la factura: " << endl;
			cin>>cantidad;
			cout << "Ingrese el precio unitario: " << endl;
			cin >> precio_uni;
			
	

			string update = "UPDATE ventas SET id_venta ='" + id_venta + "',id_producto ='" + id_producto + "',cantidad  ='" + cantidad + "',precio_unitario = '" + precio_uni + "' WHERE Id_venta_detalle = '" + id + "'";
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
			cout << "Ingrese el Id venta_detalle que desea eliminar" << endl;
			cin >> id;
			string eliminar = "Delete from ventas_detalle where Id_venta_detalle ='" + id + "'";
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
