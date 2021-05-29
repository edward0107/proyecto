#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "conexion.h"
using namespace std;
class producto {
	//atributos
private:
	string Nproducto, idmarca, descripcion, imagen,  fecha_ingreso;
	int preciocosto = 0,precioventa=0,existencia=0;
	//constructor
public:
	producto() {
	}
	producto(string _idmarca, string _descripcion, string _imagen, int _preciocosto,int _precioventa, int _existencia, string fi, string _Nproducto) {
		Nproducto = _Nproducto;
		 idmarca= _idmarca;
		descripcion =_descripcion;
		imagen = _imagen;
		preciocosto =_preciocosto;
		precioventa = _precioventa;
		existencia = _existencia;
		fecha_ingreso = fi;
	}
	// metodo
	void crear() {
		int q_estado;
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			
			string idproducto,Nproducto, idmarca, descripcion, imagen, fecha_ingreso;
			int preciocosto = 0, precioventa = 0, existencia = 0;
			string pc = to_string(preciocosto);
			string pv = to_string(precioventa);
			string ex = to_string(existencia);
			cin.ignore();
			cout << "Ingrese Id_producto :" << endl;
			getline(cin, idproducto);
			cout << "Ingrese producto: " << endl;
			getline(cin, Nproducto);
			cout << "Ingrese el Id_marca del producto: " << endl;
			getline(cin, idmarca);
			cout << "Ingrese Descripcion: " << endl;
			getline(cin, descripcion);
			cout << "Ingrese Imagen: " << endl;
			getline(cin , imagen);
			cin.ignore();
			cout << "Ingrese Fecha de Ingreso: " << endl;
			getline(cin, fecha_ingreso);
			cout << "Ingrese el precio costo del producto: " << endl;
			cin >> preciocosto;
			cout << "Ingrese precio venta del producto: " << endl;
			cin >> precioventa;
			cout << "Ingrese cuantos hay en existencia: " << endl;
			cin >> existencia;
			string insert = "INSERT INTO productos VALUES ('"+idproducto+"','" + Nproducto + "','" + idmarca + "','" + descripcion + "','" + imagen + "','" + pc+ "','" + pv + "','"+ex+"',current_time());";
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
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				cout << "-----------------------------Clientes----------------------------" << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7]<<fila[8] << endl;
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
		string pc = to_string(preciocosto);
		string pv = to_string(precioventa);
		string ex = to_string(existencia);
		conexion cn = conexion();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			int q_estado;
			string producto, idmarca, descripcion, imagen, fecha_ingreso;
			int preciocosto = 0, precioventa = 0, existencia = 0;
			cout << "Ingrese el producto que desea Actualizar: " << endl;
			cin >> producto;
			cin.ignore();

			cout << "Ingrese Id_marca: " << endl;
			getline(cin, idmarca);

			cout << "Ingrese Descripcion: " << endl;
			getline(cin,descripcion);

			cout << "Ingrese imagen: " << endl;
			getline(cin, imagen);

			cout << "Ingrese fecha ingreso: " << endl;
			cin >> fecha_ingreso;
			cin.ignore();

			cout << "Ingrese Precio costo: " << endl;
			cin>>pc;

			cout << "Ingrese precio venta: " << endl;
			cin>> pv;
			cout << "Ingrese la existencia " << endl;
			cin >> existencia;

			string update = "UPDATE productos SET nombres ='" + producto + "',idMarca ='" + idmarca + "',descripcion ='" + descripcion + "',imagen = '" + imagen + "',precio_costo='" + pc + "',precio_venta ='" + pv + "'  WHERE idCliente = '" + producto + "'";
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
			
			cout << "Ingrese el producto que desea eliminar" << endl;
			cin >> Nproducto;
			string eliminar = "Delete from productos where producto ='" + Nproducto + "'";
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

