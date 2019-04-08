//*************************************************************************************************************//
//                               UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                       //
//                   				Proyecto Final de estructura de datos                  				       //
//           Integrantes:  Miguel Guaño-Wladymir Brborich      NRC:4408                                        //
//           Docente: Ing Fernando Solis       Asingatura: Estructura de datos                                 //
//           Carrera: Ingenieria en Sistemas e informatica. fecha:2016-08-17                                   //
//                                                                                                             //
//                                                                                                             //
//                                                                                                             //
//*************************************************************************************************************//
#include"MyForm1.h"
#include"NodoSimple.h"
#include"NodoDoble.h"
#include"NodoCircular.h"
#include"Pila.h"
#include"Colas.h"
#include"Arboles.h"
ListaSimple ListaSimpleNueva = NULL;
ListaDoble ListaDobleNueva = NULL;
ListaCircular ListaCircularNueva = NULL;
ListaCircular ListaDobleCircularNueva = NULL;
ARBOL NuevoArbol = NULL;
Pila_simple NuevaPila = NULL;
Pila_simple Basurero = NULL;
struct cola ColaNueva;
struct cola ColaBasura;
#pragma once
namespace ProyectoFinalEstructuraDeDatos 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using  System::Security::Permissions::FileIOPermission;
	using System::Drawing::Imaging::ImageFormat;
	using System::Drawing::Imaging::PixelFormat;
	using System::IO::FileStream;
	using System::Drawing::Printing::PrintDocument;
	using System::Drawing::Printing::PrintEventHandler;
	using System::Drawing::Printing::PrintPageEventHandler;
	using System::Drawing::Printing::PrintPageEventArgs;
	using System::Drawing::Printing::PrinterSettings;
	using namespace System::IO;	
	using namespace System::Threading;
	//using System::Drawing::Printing::
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: MyForm1 ^Ventana = gcnew MyForm1(); //ventana auxiliar
	public: int *ValoresCopia=new int[15]; //ValoresCopia que se autogeneran para un arbol
	public: int BanderaPos;
	public: int ContadorValoresAuxArbol=0;
	public:  Bitmap^ memoryImage;
	public: PrintDocument ^PrtDoc = gcnew PrintDocument();
	public: 
		int cont = 0;
		int contArrD = 0;
		int Apertura = 120;	
		int cantidadDeDatos = 0;
		int ContadorDeClicks = 0;
	private: array <Point^>  ^Posiciones = gcnew array<Point^>(20);
	private: array <Label^>  ^Labels = gcnew array<Label^>(20);
	private: array <Label^>  ^LabelsLista = gcnew array<Label^>(20);
	private: array <Label^>  ^LabelsListaBasurero = gcnew array<Label^>(20);
	public: array <Point^>  ^PosicionesPantalla = gcnew array<Point^>(20);
	public: array <Point^>  ^PosicionesPantallaPilas = gcnew array<Point^>(20);
	public: array <Point^>  ^PosicionesPantallaBasurero = gcnew array<Point^>(20);
	private: PrintDocument^ DocumentoParaImprimir = gcnew PrintDocument();
	private: PrintDialog^ Impresora = gcnew PrintDialog();
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  archivoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  guardarComoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  imprimirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  salirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  listasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  listaSimpleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlInicioToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoALaMitadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlFinalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  eliminarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  listaDobleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlInicioToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoALaMitadToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlFinalToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  eliminarToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  listaCircularSimpleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlInicioToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoALaMitadToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlFinalToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  eliminarToolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^  listaCircularDobleToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlInicioToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlFinalToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoAlFinalToolStripMenuItem4;
	private: System::Windows::Forms::ToolStripMenuItem^  eliminarToolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  pilasYColasToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pilaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pushToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  popToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  colaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  encolarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  desencolarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  arbolesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  autogenerarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ayudaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ToolStripMenuItem^  ingresoDatoADatoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  lecturaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  inordenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preordenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  postordenToolStripMenuItem;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::ToolStripMenuItem^  refrescarToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^  richTextBox3;
	private: System::Windows::Forms::HelpProvider^  helpProvider1;
private: System::Windows::Forms::Label^  labelTituloImagenes;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->archivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->guardarComoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->imprimirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->salirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaSimpleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlInicioToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoALaMitadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlFinalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaDobleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlInicioToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoALaMitadToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlFinalToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaCircularSimpleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlInicioToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoALaMitadToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlFinalToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->listaCircularDobleToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlInicioToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlFinalToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoAlFinalToolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pilasYColasToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pilaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pushToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->popToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->encolarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->desencolarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arbolesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->autogenerarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ingresoDatoADatoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->lecturaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inordenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preordenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->postordenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ayudaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->refrescarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->helpProvider1 = (gcnew System::Windows::Forms::HelpProvider());
			this->labelTituloImagenes = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->archivoToolStripMenuItem,
					this->listasToolStripMenuItem, this->pilasYColasToolStripMenuItem, this->arbolesToolStripMenuItem, this->ayudaToolStripMenuItem,
					this->refrescarToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1367, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// archivoToolStripMenuItem
			// 
			this->archivoToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->guardarComoToolStripMenuItem,
					this->imprimirToolStripMenuItem, this->salirToolStripMenuItem
			});
			this->archivoToolStripMenuItem->Name = L"archivoToolStripMenuItem";
			this->archivoToolStripMenuItem->Size = System::Drawing::Size(71, 24);
			this->archivoToolStripMenuItem->Text = L"Archivo";
			// 
			// guardarComoToolStripMenuItem
			// 
			this->guardarComoToolStripMenuItem->Name = L"guardarComoToolStripMenuItem";
			this->guardarComoToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->guardarComoToolStripMenuItem->Text = L"Guardar Como";
			this->guardarComoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::guardarComoToolStripMenuItem_Click);
			// 
			// imprimirToolStripMenuItem
			// 
			this->imprimirToolStripMenuItem->Name = L"imprimirToolStripMenuItem";
			this->imprimirToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->imprimirToolStripMenuItem->Text = L"Imprimir";
			this->imprimirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::imprimirToolStripMenuItem_Click);
			// 
			// salirToolStripMenuItem
			// 
			this->salirToolStripMenuItem->Name = L"salirToolStripMenuItem";
			this->salirToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->salirToolStripMenuItem->Text = L"Salir";
			this->salirToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::salirToolStripMenuItem_Click);
			// 
			// listasToolStripMenuItem
			// 
			this->listasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->listaSimpleToolStripMenuItem,
					this->listaDobleToolStripMenuItem, this->listaCircularSimpleToolStripMenuItem, this->listaCircularDobleToolStripMenuItem
			});
			this->listasToolStripMenuItem->Name = L"listasToolStripMenuItem";
			this->listasToolStripMenuItem->Size = System::Drawing::Size(57, 24);
			this->listasToolStripMenuItem->Text = L"Listas";
			// 
			// listaSimpleToolStripMenuItem
			// 
			this->listaSimpleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ingresoAlInicioToolStripMenuItem,
					this->ingresoALaMitadToolStripMenuItem, this->ingresoAlFinalToolStripMenuItem, this->eliminarToolStripMenuItem
			});
			this->listaSimpleToolStripMenuItem->Name = L"listaSimpleToolStripMenuItem";
			this->listaSimpleToolStripMenuItem->Size = System::Drawing::Size(218, 26);
			this->listaSimpleToolStripMenuItem->Text = L"Lista Simple";
			// 
			// ingresoAlInicioToolStripMenuItem
			// 
			this->ingresoAlInicioToolStripMenuItem->Name = L"ingresoAlInicioToolStripMenuItem";
			this->ingresoAlInicioToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->ingresoAlInicioToolStripMenuItem->Text = L"Ingreso al inicio";
			this->ingresoAlInicioToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlInicioToolStripMenuItem_Click);
			// 
			// ingresoALaMitadToolStripMenuItem
			// 
			this->ingresoALaMitadToolStripMenuItem->Name = L"ingresoALaMitadToolStripMenuItem";
			this->ingresoALaMitadToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->ingresoALaMitadToolStripMenuItem->Text = L"Ingreso a la mitad";
			this->ingresoALaMitadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ingresoALaMitadToolStripMenuItem_Click);
			// 
			// ingresoAlFinalToolStripMenuItem
			// 
			this->ingresoAlFinalToolStripMenuItem->Name = L"ingresoAlFinalToolStripMenuItem";
			this->ingresoAlFinalToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->ingresoAlFinalToolStripMenuItem->Text = L"Ingreso al final";
			this->ingresoAlFinalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlFinalToolStripMenuItem_Click);
			// 
			// eliminarToolStripMenuItem
			// 
			this->eliminarToolStripMenuItem->Name = L"eliminarToolStripMenuItem";
			this->eliminarToolStripMenuItem->Size = System::Drawing::Size(204, 26);
			this->eliminarToolStripMenuItem->Text = L"Eliminar";
			this->eliminarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::eliminarToolStripMenuItem_Click);
			// 
			// listaDobleToolStripMenuItem
			// 
			this->listaDobleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ingresoAlInicioToolStripMenuItem1,
					this->ingresoALaMitadToolStripMenuItem1, this->ingresoAlFinalToolStripMenuItem1, this->eliminarToolStripMenuItem1
			});
			this->listaDobleToolStripMenuItem->Name = L"listaDobleToolStripMenuItem";
			this->listaDobleToolStripMenuItem->Size = System::Drawing::Size(218, 26);
			this->listaDobleToolStripMenuItem->Text = L"Lista Doble";
			// 
			// ingresoAlInicioToolStripMenuItem1
			// 
			this->ingresoAlInicioToolStripMenuItem1->Name = L"ingresoAlInicioToolStripMenuItem1";
			this->ingresoAlInicioToolStripMenuItem1->Size = System::Drawing::Size(204, 26);
			this->ingresoAlInicioToolStripMenuItem1->Text = L"Ingreso al inicio";
			this->ingresoAlInicioToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlInicioToolStripMenuItem1_Click);
			// 
			// ingresoALaMitadToolStripMenuItem1
			// 
			this->ingresoALaMitadToolStripMenuItem1->Name = L"ingresoALaMitadToolStripMenuItem1";
			this->ingresoALaMitadToolStripMenuItem1->Size = System::Drawing::Size(204, 26);
			this->ingresoALaMitadToolStripMenuItem1->Text = L"Ingreso a la mitad";
			this->ingresoALaMitadToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::ingresoALaMitadToolStripMenuItem1_Click);
			// 
			// ingresoAlFinalToolStripMenuItem1
			// 
			this->ingresoAlFinalToolStripMenuItem1->Name = L"ingresoAlFinalToolStripMenuItem1";
			this->ingresoAlFinalToolStripMenuItem1->Size = System::Drawing::Size(204, 26);
			this->ingresoAlFinalToolStripMenuItem1->Text = L"Ingreso al final";
			this->ingresoAlFinalToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlFinalToolStripMenuItem1_Click);
			// 
			// eliminarToolStripMenuItem1
			// 
			this->eliminarToolStripMenuItem1->Name = L"eliminarToolStripMenuItem1";
			this->eliminarToolStripMenuItem1->Size = System::Drawing::Size(204, 26);
			this->eliminarToolStripMenuItem1->Text = L"eliminar";
			this->eliminarToolStripMenuItem1->Click += gcnew System::EventHandler(this, &MyForm::eliminarToolStripMenuItem1_Click);
			// 
			// listaCircularSimpleToolStripMenuItem
			// 
			this->listaCircularSimpleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ingresoAlInicioToolStripMenuItem2,
					this->ingresoALaMitadToolStripMenuItem2, this->ingresoAlFinalToolStripMenuItem2, this->eliminarToolStripMenuItem2
			});
			this->listaCircularSimpleToolStripMenuItem->Name = L"listaCircularSimpleToolStripMenuItem";
			this->listaCircularSimpleToolStripMenuItem->Size = System::Drawing::Size(218, 26);
			this->listaCircularSimpleToolStripMenuItem->Text = L"Lista Circular Simple";
			// 
			// ingresoAlInicioToolStripMenuItem2
			// 
			this->ingresoAlInicioToolStripMenuItem2->Name = L"ingresoAlInicioToolStripMenuItem2";
			this->ingresoAlInicioToolStripMenuItem2->Size = System::Drawing::Size(204, 26);
			this->ingresoAlInicioToolStripMenuItem2->Text = L"Ingreso al inicio";
			this->ingresoAlInicioToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlInicioToolStripMenuItem2_Click);
			// 
			// ingresoALaMitadToolStripMenuItem2
			// 
			this->ingresoALaMitadToolStripMenuItem2->Name = L"ingresoALaMitadToolStripMenuItem2";
			this->ingresoALaMitadToolStripMenuItem2->Size = System::Drawing::Size(204, 26);
			this->ingresoALaMitadToolStripMenuItem2->Text = L"Ingreso a la mitad";
			this->ingresoALaMitadToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::ingresoALaMitadToolStripMenuItem2_Click);
			// 
			// ingresoAlFinalToolStripMenuItem2
			// 
			this->ingresoAlFinalToolStripMenuItem2->Name = L"ingresoAlFinalToolStripMenuItem2";
			this->ingresoAlFinalToolStripMenuItem2->Size = System::Drawing::Size(204, 26);
			this->ingresoAlFinalToolStripMenuItem2->Text = L"Ingreso al final";
			this->ingresoAlFinalToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlFinalToolStripMenuItem2_Click);
			// 
			// eliminarToolStripMenuItem2
			// 
			this->eliminarToolStripMenuItem2->Name = L"eliminarToolStripMenuItem2";
			this->eliminarToolStripMenuItem2->Size = System::Drawing::Size(204, 26);
			this->eliminarToolStripMenuItem2->Text = L"Eliminar";
			this->eliminarToolStripMenuItem2->Click += gcnew System::EventHandler(this, &MyForm::eliminarToolStripMenuItem2_Click);
			// 
			// listaCircularDobleToolStripMenuItem
			// 
			this->listaCircularDobleToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ingresoAlInicioToolStripMenuItem3,
					this->ingresoAlFinalToolStripMenuItem3, this->ingresoAlFinalToolStripMenuItem4, this->eliminarToolStripMenuItem3
			});
			this->listaCircularDobleToolStripMenuItem->Name = L"listaCircularDobleToolStripMenuItem";
			this->listaCircularDobleToolStripMenuItem->Size = System::Drawing::Size(218, 26);
			this->listaCircularDobleToolStripMenuItem->Text = L"Lista Circular Doble";
			// 
			// ingresoAlInicioToolStripMenuItem3
			// 
			this->ingresoAlInicioToolStripMenuItem3->Name = L"ingresoAlInicioToolStripMenuItem3";
			this->ingresoAlInicioToolStripMenuItem3->Size = System::Drawing::Size(204, 26);
			this->ingresoAlInicioToolStripMenuItem3->Text = L"Ingreso al inicio";
			this->ingresoAlInicioToolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlInicioToolStripMenuItem3_Click);
			// 
			// ingresoAlFinalToolStripMenuItem3
			// 
			this->ingresoAlFinalToolStripMenuItem3->Name = L"ingresoAlFinalToolStripMenuItem3";
			this->ingresoAlFinalToolStripMenuItem3->Size = System::Drawing::Size(204, 26);
			this->ingresoAlFinalToolStripMenuItem3->Text = L"Ingreso a la mitad";
			this->ingresoAlFinalToolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlFinalToolStripMenuItem3_Click);
			// 
			// ingresoAlFinalToolStripMenuItem4
			// 
			this->ingresoAlFinalToolStripMenuItem4->Name = L"ingresoAlFinalToolStripMenuItem4";
			this->ingresoAlFinalToolStripMenuItem4->Size = System::Drawing::Size(204, 26);
			this->ingresoAlFinalToolStripMenuItem4->Text = L"Ingreso al final";
			this->ingresoAlFinalToolStripMenuItem4->Click += gcnew System::EventHandler(this, &MyForm::ingresoAlFinalToolStripMenuItem4_Click);
			// 
			// eliminarToolStripMenuItem3
			// 
			this->eliminarToolStripMenuItem3->Name = L"eliminarToolStripMenuItem3";
			this->eliminarToolStripMenuItem3->Size = System::Drawing::Size(204, 26);
			this->eliminarToolStripMenuItem3->Text = L"Eliminar";
			this->eliminarToolStripMenuItem3->Click += gcnew System::EventHandler(this, &MyForm::eliminarToolStripMenuItem3_Click);
			// 
			// pilasYColasToolStripMenuItem
			// 
			this->pilasYColasToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->pilaToolStripMenuItem,
					this->colaToolStripMenuItem
			});
			this->pilasYColasToolStripMenuItem->Name = L"pilasYColasToolStripMenuItem";
			this->pilasYColasToolStripMenuItem->Size = System::Drawing::Size(103, 24);
			this->pilasYColasToolStripMenuItem->Text = L"Pilas Y Colas";
			// 
			// pilaToolStripMenuItem
			// 
			this->pilaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->pushToolStripMenuItem,
					this->popToolStripMenuItem
			});
			this->pilaToolStripMenuItem->Name = L"pilaToolStripMenuItem";
			this->pilaToolStripMenuItem->Size = System::Drawing::Size(114, 26);
			this->pilaToolStripMenuItem->Text = L"Pila";
			// 
			// pushToolStripMenuItem
			// 
			this->pushToolStripMenuItem->Name = L"pushToolStripMenuItem";
			this->pushToolStripMenuItem->Size = System::Drawing::Size(114, 26);
			this->pushToolStripMenuItem->Text = L"Push";
			this->pushToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pushToolStripMenuItem_Click);
			// 
			// popToolStripMenuItem
			// 
			this->popToolStripMenuItem->Name = L"popToolStripMenuItem";
			this->popToolStripMenuItem->Size = System::Drawing::Size(114, 26);
			this->popToolStripMenuItem->Text = L"Pop";
			this->popToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::popToolStripMenuItem_Click);
			// 
			// colaToolStripMenuItem
			// 
			this->colaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->encolarToolStripMenuItem,
					this->desencolarToolStripMenuItem
			});
			this->colaToolStripMenuItem->Name = L"colaToolStripMenuItem";
			this->colaToolStripMenuItem->Size = System::Drawing::Size(114, 26);
			this->colaToolStripMenuItem->Text = L"Cola";
			// 
			// encolarToolStripMenuItem
			// 
			this->encolarToolStripMenuItem->Name = L"encolarToolStripMenuItem";
			this->encolarToolStripMenuItem->Size = System::Drawing::Size(158, 26);
			this->encolarToolStripMenuItem->Text = L"Encolar";
			this->encolarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::encolarToolStripMenuItem_Click);
			// 
			// desencolarToolStripMenuItem
			// 
			this->desencolarToolStripMenuItem->Name = L"desencolarToolStripMenuItem";
			this->desencolarToolStripMenuItem->Size = System::Drawing::Size(158, 26);
			this->desencolarToolStripMenuItem->Text = L"Desencolar";
			this->desencolarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::desencolarToolStripMenuItem_Click);
			// 
			// arbolesToolStripMenuItem
			// 
			this->arbolesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->autogenerarToolStripMenuItem,
					this->ingresoDatoADatoToolStripMenuItem, this->lecturaToolStripMenuItem
			});
			this->arbolesToolStripMenuItem->Name = L"arbolesToolStripMenuItem";
			this->arbolesToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->arbolesToolStripMenuItem->Text = L"Arboles";
			// 
			// autogenerarToolStripMenuItem
			// 
			this->autogenerarToolStripMenuItem->Name = L"autogenerarToolStripMenuItem";
			this->autogenerarToolStripMenuItem->Size = System::Drawing::Size(215, 26);
			this->autogenerarToolStripMenuItem->Text = L"Autogenerar";
			this->autogenerarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::autogenerarToolStripMenuItem_Click);
			// 
			// ingresoDatoADatoToolStripMenuItem
			// 
			this->ingresoDatoADatoToolStripMenuItem->Name = L"ingresoDatoADatoToolStripMenuItem";
			this->ingresoDatoADatoToolStripMenuItem->Size = System::Drawing::Size(215, 26);
			this->ingresoDatoADatoToolStripMenuItem->Text = L"Ingreso dato a dato";
			this->ingresoDatoADatoToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ingresoDatoADatoToolStripMenuItem_Click);
			// 
			// lecturaToolStripMenuItem
			// 
			this->lecturaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->inordenToolStripMenuItem,
					this->preordenToolStripMenuItem, this->postordenToolStripMenuItem
			});
			this->lecturaToolStripMenuItem->Name = L"lecturaToolStripMenuItem";
			this->lecturaToolStripMenuItem->Size = System::Drawing::Size(215, 26);
			this->lecturaToolStripMenuItem->Text = L"Lectura";
			// 
			// inordenToolStripMenuItem
			// 
			this->inordenToolStripMenuItem->Name = L"inordenToolStripMenuItem";
			this->inordenToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->inordenToolStripMenuItem->Text = L"Inorden";
			this->inordenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::inordenToolStripMenuItem_Click);
			// 
			// preordenToolStripMenuItem
			// 
			this->preordenToolStripMenuItem->Name = L"preordenToolStripMenuItem";
			this->preordenToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->preordenToolStripMenuItem->Text = L"Preorden";
			this->preordenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::preordenToolStripMenuItem_Click);
			// 
			// postordenToolStripMenuItem
			// 
			this->postordenToolStripMenuItem->Name = L"postordenToolStripMenuItem";
			this->postordenToolStripMenuItem->Size = System::Drawing::Size(150, 26);
			this->postordenToolStripMenuItem->Text = L"Postorden";
			this->postordenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::postordenToolStripMenuItem_Click);
			// 
			// ayudaToolStripMenuItem
			// 
			this->ayudaToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->helpToolStripMenuItem
			});
			this->ayudaToolStripMenuItem->Name = L"ayudaToolStripMenuItem";
			this->ayudaToolStripMenuItem->Size = System::Drawing::Size(63, 24);
			this->ayudaToolStripMenuItem->Text = L"Ayuda";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->helpToolStripMenuItem->Text = L"Help!";
			this->helpToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::helpToolStripMenuItem_Click);
			// 
			// refrescarToolStripMenuItem
			// 
			this->refrescarToolStripMenuItem->Name = L"refrescarToolStripMenuItem";
			this->refrescarToolStripMenuItem->Size = System::Drawing::Size(82, 24);
			this->refrescarToolStripMenuItem->Text = L"Refrescar";
			this->refrescarToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::refrescarToolStripMenuItem_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->pictureBox1->Location = System::Drawing::Point(0, 31);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1189, 740);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->richTextBox2);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->richTextBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(1195, 41);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(165, 716);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(9, 524);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(142, 25);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Datos Sacados:";
			this->label5->Visible = false;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(13, 567);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(138, 92);
			this->richTextBox2->TabIndex = 18;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Visible = false;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(8, 195);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(142, 26);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Despues de...";
			this->label4->Visible = false;
			// 
			// textBox2
			// 
			this->textBox2->Enabled = false;
			this->textBox2->Location = System::Drawing::Point(9, 233);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(138, 22);
			this->textBox2->TabIndex = 16;
			this->textBox2->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(35, 669);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(79, 30);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Graficar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(8, 337);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 36);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Datos encontrados:";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(11, 376);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(138, 128);
			this->richTextBox1->TabIndex = 13;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(35, 281);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(79, 30);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Agregar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(8, 120);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(142, 35);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Escriba un valor...";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 158);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(138, 22);
			this->textBox1->TabIndex = 10;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Location = System::Drawing::Point(5, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 72);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Lista XXX: Ingreso al XXX";
			// 
			// richTextBox3
			// 
			this->richTextBox3->AcceptsTab = true;
			this->richTextBox3->Enabled = false;
			this->richTextBox3->Location = System::Drawing::Point(12, 701);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->Size = System::Drawing::Size(1160, 56);
			this->richTextBox3->TabIndex = 3;
			this->richTextBox3->Text = L"";
			this->richTextBox3->Visible = false;
			// 
			// helpProvider1
			// 
			this->helpProvider1->HelpNamespace = L"C:\\Users\\WladymirLadislao\\Documents\\Visual Studio 2015\\Projects\\ProyectoFinalEstr"
				L"ucturaDeDatos\\ProyectoFinalEstructuraDeDatos\\proyectoestructura.chm";
			// 
			// labelTituloImagenes
			// 
			this->labelTituloImagenes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTituloImagenes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->labelTituloImagenes->Location = System::Drawing::Point(401, 89);
			this->labelTituloImagenes->Name = L"labelTituloImagenes";
			this->labelTituloImagenes->Size = System::Drawing::Size(424, 52);
			this->labelTituloImagenes->TabIndex = 20;
			this->labelTituloImagenes->Text = L"Lista XXX: Ingreso al XXX";
			this->labelTituloImagenes->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1367, 769);
			this->Controls->Add(this->labelTituloImagenes);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->helpProvider1->SetShowHelp(this, true);
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"ProyectoFinalEstructuraDeDatos";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{	
		int Aux = 10;
		int AuxVertical = 30;
		for (int i = 0;i < 20;i++)
		{
			Posiciones[i] = gcnew Point(0, 0);
			PosicionesPantalla[i] = gcnew Point(Aux,200);
			PosicionesPantallaPilas[i] = gcnew Point(200,AuxVertical);
			PosicionesPantallaBasurero[i] = gcnew Point(400, AuxVertical);
			Aux += 90;
			AuxVertical += 50;
		}
		BanderaPos = NULL;
		label1->Visible = false;
		groupBox1->Enabled = false;	
		ColaNueva.delante = NULL;
		ColaNueva.atras = NULL;
		ColaBasura.delante = NULL;
		ColaBasura.atras = NULL;
	}
			 //true frente
			 //false atras
	public: void DibujarFlechas(Graphics^&Lienzo, Point^ Inicial, Point^ Final, bool Flecha)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);	
		Lienzo->DrawLine(Lapiz, Inicial->X,Inicial->Y, Final->X,Final->Y);
		if (Flecha)
		{
			Lienzo->DrawLine(Lapiz, Final->X, Final->Y, Final->X-5, Final->Y-5);
			Lienzo->DrawLine(Lapiz, Final->X, Final->Y, Final->X - 5, Final->Y + 5);
		}
		else
		{
			Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y, Inicial->X + 5, Inicial->Y - 5);
			Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y, Inicial->X + 5, Inicial->Y + 5);
		}
		delete Lapiz;
	}
			//true final
			//false inicio
			// Ap tam de la linea 
	public: void DibujarFlechaFinal(Graphics^&Lienzo, Point^ Inicial, Point^ Final, bool Flecha, int Ap)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);
		Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y, Inicial->X, Inicial->Y+Ap);
		Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y+Ap, Final->X, Final->Y + Ap);
		Lienzo->DrawLine(Lapiz, Final->X, Final->Y - Ap, Final->X, Final->Y + Ap);
		if (Flecha)
		{
			Lienzo->DrawLine(Lapiz, Final->X, Final->Y -Ap, Final->X-5, Final->Y +5);
			Lienzo->DrawLine(Lapiz, Final->X, Final->Y - Ap, Final->X + 5, Final->Y +5);
		}
		else
		{
			Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y-Ap, Inicial->X+5, Inicial->Y +5);
			Lienzo->DrawLine(Lapiz, Inicial->X, Inicial->Y-Ap, Inicial->X - 5, Inicial->Y + 5);
		}
		delete Lapiz;	
	}
	public: void GraficarPilas(Graphics^&Lienzo, int Cont, int Insertar)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);
		Label^ Dato = gcnew Label();
		Lienzo->DrawRectangle(Lapiz, PosicionesPantallaPilas[Cont]->X, PosicionesPantallaPilas[Cont]->Y, 50, 30);
		LabelsLista[Cont] = Dato;
		this->Controls->Add(Dato);
		Dato->BringToFront();
		Dato->BackColor = Color::Transparent;
		Dato->Name = Convert::ToString(Insertar);
		Dato->Text = Convert::ToString(Insertar);
		Dato->Size = System::Drawing::Size(20, 20);
		Dato->Location = System::Drawing::Point(PosicionesPantallaPilas[Cont]->X + 20, PosicionesPantallaPilas[Cont]->Y + 35);
	}
	public: void GraficarPilasBAsura(Graphics^&Lienzo, int Cont, int Insertar)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);
		Label^ Dato = gcnew Label();
		Lienzo->DrawRectangle(Lapiz, PosicionesPantallaBasurero[Cont]->X, PosicionesPantallaBasurero[Cont]->Y, 50, 30);
		LabelsListaBasurero[Cont] = Dato;
		this->Controls->Add(Dato);
		Dato->BringToFront();
		Dato->BackColor = Color::Transparent;
		Dato->Name = Convert::ToString(Insertar);
		Dato->Text = Convert::ToString(Insertar);
		Dato->Size = System::Drawing::Size(20, 20);
		Dato->Location = System::Drawing::Point(PosicionesPantallaBasurero[Cont]->X + 20, PosicionesPantallaBasurero[Cont]->Y + 35);
	}
	public: void GraficarNodo(Graphics^&Lienzo, int Cont, int Insertar)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);
		Lienzo->DrawRectangle(Lapiz,PosicionesPantalla[Cont]->X, PosicionesPantalla[Cont]->Y,50,30);
		Lienzo->DrawLine(Lapiz, PosicionesPantalla[Cont]->X + 5, PosicionesPantalla[Cont]->Y, PosicionesPantalla[Cont]->X + 5, PosicionesPantalla[Cont]->Y + 30);
		Lienzo->DrawLine(Lapiz, PosicionesPantalla[Cont]->X + 45, PosicionesPantalla[Cont]->Y, PosicionesPantalla[Cont]->X + 45, PosicionesPantalla[Cont]->Y + 30);	
		Label^ Dato = gcnew Label();
		LabelsLista[Cont] = Dato;
		this->Controls->Add(Dato);
		Dato->BringToFront();
		Dato->BackColor = Color::Transparent;
		Dato->Name = Convert::ToString(Insertar);
		Dato->Text = Convert::ToString(Insertar);
		Dato->Size = System::Drawing::Size(20, 20);
		Dato->Location = System::Drawing::Point(PosicionesPantalla[Cont]->X+20, PosicionesPantalla[Cont]->Y+35);
		delete Lapiz;
	}
	public: void VaciarArreglos()
	{	
		for (int i = 0;i < 20;i++)
		{
			this->Controls->Remove(Labels[i]);
			this->Controls->Remove(LabelsLista[i]);
			this->Controls->Remove(LabelsListaBasurero[i]);
		}
	}
	public: void LabelNULL(String^ texto, int Cont)
	{
		Label^ Dato = gcnew Label();	
		this->Controls->Add(Dato);
		Dato->BringToFront();
		Dato->BackColor = Color::Transparent;
		Dato->Name = texto;
		Dato->Text =texto;
		Dato->Size = System::Drawing::Size(40, 15);
		Dato->TextAlign = ContentAlignment::MiddleLeft;
		Dato->Location = System::Drawing::Point(PosicionesPantalla[Cont]->X+5 , PosicionesPantalla[Cont]->Y + 35);
		LabelsLista[Cont] = Dato;
	}
	public:	void DibujarHojas(Graphics^ &Lienzo, int Valor, int X, int Y)
	{
		SolidBrush^ Pincel = gcnew SolidBrush(Color::LightBlue);
		Pen^ Lapiz = gcnew Pen(Color::Black, 3);
		Label^ Numero = gcnew Label();
		Lienzo->FillEllipse(Pincel, X, Y, 50, 50);
		this->Controls->Add(Numero);
		Numero->BringToFront();
		Numero->BackColor = Color::LightBlue;
		Numero->Name = Convert::ToString(Valor);
		Numero->Text = Convert::ToString(Valor);
		Numero->Size = System::Drawing::Size(20, 20);
		Numero->Location = System::Drawing::Point(X + 20, Y + 45);
		this->Posiciones[cont] = gcnew Point(X, Y);
		this->Labels[cont] = Numero;
		delete Pincel;
	}
	public:	void insertanodonuevo(Graphics^ &Lienzo, ARBOL *rarbol, int c, int nodo, int nuevo)
	{
		Pen^ Lapiz = gcnew Pen(Color::Black, 2);
		int localizar = 0, posX = 0, posY = 0;
		if (*rarbol == NULL)
		{                          //CREACION DE UN NUEVO NODO
			*rarbol = (NODO *)malloc(sizeof(NODO));
			if (*rarbol != NULL)
			{
				//ASIGNACION DE VALORES NUEVOS EN EL NODO NUEVO
				(*rarbol)->info = nuevo;
				(*rarbol)->izqnodo = NULL;
				(*rarbol)->dernodo = NULL;
				if (c == 0)
				{
					DibujarHojas(Lienzo, nuevo, 370, 30);
				}
				if (c == 1)
				{
					for (int i = 0;i < cont;i++)
					{
						if (ValoresCopia[i] == nodo)
						{
							localizar = i;
							break;
						}
					}
					posX = Posiciones[localizar]->X + Apertura;
					posY = Posiciones[localizar]->Y + 60;
					Lienzo->DrawLine(Lapiz, Posiciones[localizar]->X + 25, Posiciones[localizar]->Y + 25, posX + 25, posY + 25);
					DibujarHojas(Lienzo, nuevo, posX, posY);
				}
				if (c == 2)
				{
					for (int i = 0;i < cont;i++)
					{
						if (ValoresCopia[i] == nodo)
						{
							localizar = i;
							break;
						}
					}
					posX = Posiciones[localizar]->X - Apertura;
					posY = Posiciones[localizar]->Y + 60;
					Lienzo->DrawLine(Lapiz, Posiciones[localizar]->X + 25, Posiciones[localizar]->Y + 25, posX + 25, posY + 25);
					DibujarHojas(Lienzo, nuevo, posX, posY);
				}
			}
		}
		else
			if (nuevo<(*rarbol)->info)  //checa si el elemento nuevo es mayor que el elemento padre
				insertanodonuevo(Lienzo, &((*rarbol)->izqnodo), 2, (*rarbol)->info, nuevo);  //coloca el elemento a la izquierda del padre o raiz
			else
				if (nuevo>(*rarbol)->info)  //checa si el elemento nuevo es menor que el elemento padre
					insertanodonuevo(Lienzo, &((*rarbol)->dernodo), 1, (*rarbol)->info, nuevo);  //coloca el elemento a la derecha del padre o raiz

	}
	public: void Refresco()
	{
		cont = 0;
		contArrD = 0;
		Apertura = 120;	
		pictureBox1->Refresh();		
		VaciarArreglos();
	}
	public: int DatoIngresado()
	{
		int retorno = 0;
		try
		{
			if (textBox1->Text->Length == 0)
			{
				MessageBox::Show("Casillero en blanco");
				retorno = NULL;
			}
			else
			{
				retorno = Convert::ToInt32(textBox1->Text);
			}
		}
		catch (FormatException^e)
		{
			retorno = NULL;
			MessageBox::Show("Error: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return retorno;
	}
	public: int DatoIngresadoDespuesDe()
	{
		int retorno = 0;
		try
		{
			if (textBox2->Text->Length == 0)
			{
				MessageBox::Show("Casillero en blanco");
				retorno = NULL;
			}
			else
			{
				retorno = Convert::ToInt32(textBox2->Text);
			}
		}
		catch (FormatException^e)
		{
			retorno = NULL;
			MessageBox::Show("Error: "+e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		return retorno;
	}
			/*
				textbox1 -> dato ingresado
				label1 -> nombre y titulo
				button1 -> boton agregar 
				label4 -> para los agregar despues de 
				textbox2 -> para los agregar despues de
			*/
	public: void Etiquetas(int setBandera, String^ txtBoton, String^ txtLabel)
	{
		BanderaPos = setBandera;
		ContadorDeClicks = 0;
		richTextBox2->Enabled = false;		
		richTextBox2->Text = "";
		textBox1->Text = "";
		textBox2->Text = "";
		label5->Visible = false;
		richTextBox2->Visible = false;
		groupBox1->Enabled = true;
		label4->Visible = false;
		textBox2->Visible = false;
		textBox2->Enabled = false;
		button1->Text = txtBoton;
		button1->Enabled = true;
		textBox1->Enabled = true;
		label1->Text = txtLabel;
		richTextBox3->Enabled = false;
		richTextBox3->Text = "";
		richTextBox3->Visible = false;
		labelTituloImagenes->Text = txtLabel;
		label1->Show();
	}
	//Lista simple ingreso al inicio	0	
	private: System::Void ingresoAlInicioToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{	
		Etiquetas(0, "Agregar", "Lista Simple: Ingreso al Inicio");
	}
			 // Lista Simple, ingreso en el medio de 1
	private: System::Void ingresoALaMitadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(1, "Agregar", "Lista Simple: Ingreso al Medio");
		label4->Visible = true;
		textBox2->Visible = true;
		textBox2->Enabled = true;
	}
			 // Lista simple Ingreso al final de la lista 2
	private: System::Void ingresoAlFinalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Etiquetas(2, "Agregar", "Lista Simple: Ingreso al Final");
	}
			 //Lista Simple, Eliminar un elemento 3
	private: System::Void eliminarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(3, "Eliminar", "Lista Simple: Eliminar");
	}
			 //Lista doble insertar al inicio 4
	private: System::Void ingresoAlInicioToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(4, "Agregar", "Lista Doble: Ingreso al Inicio");
	}
			 //Lista doble insertar al medio de  5
	private: System::Void ingresoALaMitadToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(5, "Agregar", "Lista Doble: Ingreso al Medio");
		label4->Visible = true;
		textBox2->Visible = true;
		textBox2->Enabled = true;
	}
			 //Lista doble insertar al final	6
	private: System::Void ingresoAlFinalToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(6, "Agregar", "Lista Doble: Ingreso al Final");
	}
			 //Lista doble eliminar		7
	private: System::Void eliminarToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(7, "Eliminar", "Lista Doble: Eliminar");
	}
			 //Circular simple ingreso al inicio	8
	private: System::Void ingresoAlInicioToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(8, "Agregar", "Lista Circular Simple: Ingreso al Inicio");
	}
			 //Circular simple ingreso al medio		9
	private: System::Void ingresoALaMitadToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(9, "Agregar", "Lista Circular Simple: Ingreso al Medio");
		label4->Visible = true;
		textBox2->Visible = true;
		textBox2->Enabled = true;
	}
			 //Circular simple ingreso al final			10
	private: System::Void ingresoAlFinalToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(10, "Agregar", "Lista Circular Simple: Ingreso al Final");
	}
			 //Circular simple Eliminar			11
	private: System::Void eliminarToolStripMenuItem2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Etiquetas(7, "Eliminar", "Lista Circular Simple: Eliminar");
	}
			 //Circular doble ingreso al inicio		12
	private: System::Void ingresoAlInicioToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(12, "Agregar", "Lista Circular Doble: Ingreso al Inicio");
	}
			 //Circular doble ingreso a la mitad		13
	private: System::Void ingresoAlFinalToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(13, "Agregar", "Lista Circular Doble: Ingreso al Medio");
		label4->Visible = true;
		textBox2->Visible = true;
		textBox2->Enabled = true;
	}
			 //Circular doble ingreso al final		14
	private: System::Void ingresoAlFinalToolStripMenuItem4_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(14, "Agregar", "Lista Circular Doble: Ingreso al Final");
	}
			 //Circular doble eliminar		15
	private: System::Void eliminarToolStripMenuItem3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(15, "Eliminar", "Lista Circular Doble: Eliminar");
	}
			 // Pila Push		16
	private: System::Void pushToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(16, "Push", "Pila: Push");
		button1->Enabled = true;
	}
			 //Pila Pop 17
	private: System::Void popToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Etiquetas(17, "Pop", "Pila: Pop");
		textBox1->Enabled = false;
		richTextBox2->Enabled = true;
		label5->Visible = true;
		richTextBox2->Visible = true;
	}
			 //Cola encolar		18
	private: System::Void encolarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(18, "Encolar", "Cola: Encolar");
	}
			 //Cola desencolar		19
	private: System::Void desencolarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(19, "Desencolar", "Cola: Desencolar");
		textBox1->Enabled = false;
		richTextBox2->Enabled = true;
		label5->Visible = true;
		richTextBox2->Visible = true;		
	}
			 //llamar a la autogeneracion para los arboles		20
	private: System::Void autogenerarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{		
		NuevoArbol = NULL;
		Etiquetas(20, "Agregar", "Arboles: Datos Autogenerados");
		textBox1->Enabled = false;
		button1->Enabled = false;
		this->Ventana->ShowDialog();
		this->cantidadDeDatos = Ventana->CantidadDeDatos();
		this->ValoresCopia = Ventana->ValoresArbol;
		richTextBox1->Text = Ventana->Desplegar;
	}
			 // Arboles ingreso dato a dato			21
	private: System::Void ingresoDatoADatoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		Etiquetas(21, "Agregar", "Arboles: Ingreso Dato a Dato");		
		NuevoArbol = NULL;
		button1->Enabled = true;
		richTextBox1->Text ="";		
		richTextBox1->Visible = true;
	}
		//Arboles lectura inorden		22				//no el mismo boton
	private: System::Void inordenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ Mensaje = "";
		if (NuevoArbol != NULL)
		{
			label1->Text = "Arboles Lectura Inorden";
			label1->Enabled = true;
			inorden(NuevoArbol, Mensaje);
			richTextBox3->Text = Mensaje;
			richTextBox3->Enabled = true;
			richTextBox3->Visible = true;
		}		
	}
			 //Arboles lectura en preorden		23			//no el mismo boton
	private: System::Void preordenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ Mensaje = "";
		if (NuevoArbol != NULL)
		{
			label1->Text = "Arboles Lectura Preorden";
			label1->Enabled = true;
			preorden(NuevoArbol, Mensaje);
			richTextBox3->Text = Mensaje;
			richTextBox3->Enabled = true;
			richTextBox3->Visible = true;
		}	
	}
			 //Arboles Letura en postorden		24			//no el mismo boton
	private: System::Void postordenToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		String^ Mensaje = "";
		if (NuevoArbol != NULL)
		{
			label1->Text = "Arboles Lectura Postorden";
			label1->Enabled = true;
			postorden(NuevoArbol, Mensaje);
			richTextBox3->Text = Mensaje;
			richTextBox3->Enabled = true;
			richTextBox3->Visible = true;
		}		
	}
			 //Borrar pantalla
	private: System::Void refrescarToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		textBox1->Text = "";
		textBox2->Text = "";
		richTextBox1->Text = "";
		richTextBox2->Text = "";
		richTextBox3->Text = "";
		ValoresCopia = new int[15];
		ContadorValoresAuxArbol = 0;
		ListaDobleNueva = NULL;
		ColaNueva.delante = NULL;
		ColaNueva.atras = NULL;
		ColaBasura.delante = NULL;
		ColaBasura.atras = NULL;
		NuevaPila = NULL;
		Basurero = NULL;
		ListaSimpleNueva = NULL;
		ListaCircularNueva = NULL;
		ListaDobleCircularNueva = NULL;
		Refresco();		
	}
			 //guarda en formato de imagenes 
	private: System::Void guardarComoToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{	
		Point ^Aux = gcnew Point(this->Location.X,this->Location.Y);
		this->Location = pictureBox1->Location;
		if(BanderaPos!=16&& BanderaPos != 17 && BanderaPos != 18 && BanderaPos != 19 )labelTituloImagenes->Visible = true;
		CapturarPantalla();
		labelTituloImagenes->Visible = false;
		SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "JPeg Image|*.jpg|Bitmap Image|*.bmp|Gif Image|*.gif";			
		saveFileDialog1->Title = "Guardar Como";
		saveFileDialog1->ShowDialog();		
		if (saveFileDialog1->FileName != "")		
		{							
			switch (saveFileDialog1->FilterIndex)
			{
			case 1:				
				memoryImage->Save(saveFileDialog1->FileName, ImageFormat::Jpeg);				
				break;
			case 2:
				memoryImage->Save(saveFileDialog1->FileName, ImageFormat::Bmp);
				break;
			case 3:
				memoryImage->Save(saveFileDialog1->FileName, ImageFormat::Png);
				break;
			}
		}
		this->Location = System::Drawing::Point(Aux->X,Aux->Y);
	}
	public: void CapturarPantalla()
	{
		Graphics^ MyGraphics = this->CreateGraphics();
		System::Drawing::Size tam = this->pictureBox1->Size;
		memoryImage = gcnew Bitmap(tam.Width+60,tam.Height+5,MyGraphics);
		Graphics^ MemoryGraphics = Graphics::FromImage(memoryImage);
		MemoryGraphics->CopyFromScreen(this->pictureBox1->Location.X , this->pictureBox1->Location.Y + 70, 0, 0, tam, CopyPixelOperation::SourceCopy);
	}
			 //imprimir archivo
	public: void PrtDoc_PrintPage(System::Object^  sender, PrintPageEventArgs^ e)
	{		
		e->Graphics->DrawImage(memoryImage, 0, 0);
	}
	private: System::Void imprimirToolStripMenuItem_Click(System::Object^  sender,  System::EventArgs^  e) 
	{
		Point ^Aux = gcnew Point(this->Location.X, this->Location.Y);
		this->Location = pictureBox1->Location;
		if (BanderaPos != 16 && BanderaPos != 17 && BanderaPos != 18 && BanderaPos != 19) labelTituloImagenes->Visible = true;
		CapturarPantalla();
		labelTituloImagenes->Visible = false;
		PrtDoc->PrintPage += gcnew PrintPageEventHandler(this,&MyForm::PrtDoc_PrintPage);
		PrintDialog^ PD = gcnew PrintDialog();	
		PageSetupDialog^ PS = gcnew PageSetupDialog();
		PS->AllowMargins;
		PS->AllowOrientation;
		PS->Document = PrtDoc;		
		if (PS->ShowDialog()==System::Windows::Forms::DialogResult::OK)
		{
			if (PD->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				PrtDoc->DefaultPageSettings = PS->PageSettings;
				PD->Document = PS->Document;
				PD->Document->Print();
			}
		}
		this->Location = System::Drawing::Point(Aux->X, Aux->Y);
	}
			 //About por terminar 
	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		system("About.txt");
	}
			 //Ayuda
	private: System::Void helpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		system("proyectoestructura.chm");
	}
			 //salir del programa
	private: System::Void salirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->Close();
	}
			 //Boton agregar datos !!	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		int aux = 0;
		switch (BanderaPos)
		{
		case 0:
			if (DatoIngresado() != NULL)
			{
				ListaSimpleNueva->Insertar(ListaSimpleNueva, DatoIngresado());
				richTextBox1->Text = ListaSimpleNueva->MostrarDatos(ListaSimpleNueva);
			}			
			break;			
		case 1:
			if (DatoIngresado() != NULL&&DatoIngresadoDespuesDe() != NULL)
			{
				ListaSimpleNueva->inserartluegode(ListaSimpleNueva, DatoIngresado(), DatoIngresadoDespuesDe());
				richTextBox1->Text = ListaSimpleNueva->MostrarDatos(ListaSimpleNueva);
			}
			break;
		case 2:
			if (DatoIngresado() != NULL)
			{
				ListaSimpleNueva->ingresarfinal(ListaSimpleNueva, DatoIngresado());
				richTextBox1->Text = ListaSimpleNueva->MostrarDatos(ListaSimpleNueva);
			}
			break;
		case 3:
			if (DatoIngresado() != NULL)
			{
				ListaSimpleNueva->Borrar(ListaSimpleNueva, DatoIngresado());
				richTextBox1->Text = ListaSimpleNueva->MostrarDatos(ListaSimpleNueva);
			}
			break;
		case 4:
			if (DatoIngresado() != NULL)
			{
				ListaDobleNueva->Insertar(ListaDobleNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleNueva->MostrarDatos(ListaDobleNueva);
			}
			break;
		case 5:
			if (DatoIngresado() != NULL&&DatoIngresadoDespuesDe() != NULL)
			{
				ListaDobleNueva->insertarluegode(ListaDobleNueva, DatoIngresadoDespuesDe(), DatoIngresado());
				richTextBox1->Text = ListaDobleNueva->MostrarDatos(ListaDobleNueva);
			}
			break;
		case 6:
			if (DatoIngresado() != NULL)
			{
				ListaDobleNueva->insertarincio(ListaDobleNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleNueva->MostrarDatos(ListaDobleNueva);
			}
			break;
		case 7:
			if (DatoIngresado() != NULL)
			{
				ListaDobleNueva->Borrar(ListaDobleNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleNueva->MostrarDatos(ListaDobleNueva);
			}
			break;
		case 8:
			if (DatoIngresado() != NULL)
			{
				ListaCircularNueva->Insertar(ListaCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaCircularNueva->MostrarDatos(ListaCircularNueva);
			}
			break;
		case 9:
			if (DatoIngresado() != NULL&&DatoIngresadoDespuesDe()!=NULL)
			{
				ListaCircularNueva->InsertarDespuesDe(ListaCircularNueva,DatoIngresadoDespuesDe(), DatoIngresado());
				richTextBox1->Text = ListaCircularNueva->MostrarDatos(ListaCircularNueva);
			}
			break;
		case 10:
			if (DatoIngresado() != NULL)
			{
				ListaCircularNueva->InsertarFinal(ListaCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaCircularNueva->MostrarDatos(ListaCircularNueva);
			}
			break;
		case 11:
			if (DatoIngresado() != NULL)
			{
				ListaCircularNueva->Borrar(ListaCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaCircularNueva->MostrarDatos(ListaCircularNueva);
			}
			break;
			//circular doble 
		case 12:
			if (DatoIngresado() != NULL)
			{
				ListaDobleCircularNueva->Insertar(ListaDobleCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleCircularNueva->MostrarDatos(ListaDobleCircularNueva);
			}
			break;
		case 13:
			if (DatoIngresado() != NULL&&DatoIngresadoDespuesDe()!=NULL)
			{
				ListaDobleCircularNueva->InsertarDespuesDe(ListaDobleCircularNueva, DatoIngresadoDespuesDe(), DatoIngresado());
				richTextBox1->Text = ListaDobleCircularNueva->MostrarDatos(ListaDobleCircularNueva);
			}
			break;
		case 14:
			if (DatoIngresado() != NULL)
			{
				ListaDobleCircularNueva->InsertarFinal(ListaDobleCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleCircularNueva->MostrarDatos(ListaDobleCircularNueva);
			}
			break;
		case 15:
			if (DatoIngresado() != NULL)
			{
				ListaDobleCircularNueva->Borrar(ListaDobleCircularNueva, DatoIngresado());
				richTextBox1->Text = ListaDobleCircularNueva->MostrarDatos(ListaDobleCircularNueva);
			}
			break;
			//Pilas 
		case 16:
			if (DatoIngresado() != NULL)
			{
				NuevaPila->Push(NuevaPila, DatoIngresado());
				richTextBox1->Text = NuevaPila->Mostrar(NuevaPila);
			}
			break;
		case 17:
			aux = NuevaPila->Pop(NuevaPila);
			Basurero->Push(Basurero,aux);
			if (aux!=NULL)
			{
				richTextBox2->Text = Basurero->Mostrar(Basurero);
			}
			richTextBox1->Text = NuevaPila->Mostrar(NuevaPila);
			break;
			//colas
		case 18:
			if (DatoIngresado() != NULL)
			{
				encolar(ColaNueva, DatoIngresado());
				richTextBox1->Text = muestraCola(ColaNueva);
			}		
			break;
		case 19:
			if (ColaNueva.delante!=NULL)
			{
				aux = desencolar(ColaNueva);
				encolar(ColaBasura, aux);
			}			
			if (aux != NULL)
			{
				richTextBox2->Text = muestraCola(ColaBasura);
			}
			richTextBox1->Text = muestraCola(ColaNueva);
			break;		
		case 21:			
			if (ContadorValoresAuxArbol<10)
			{
				ValoresCopia[ContadorValoresAuxArbol] = DatoIngresado();
				Random^ R = gcnew Random(DateTime::Now.Millisecond);
				for (int i = 0;i < ContadorValoresAuxArbol;i++)
				{
					for (int j = i; j < ContadorValoresAuxArbol;j++)
					{
						if (DatoIngresado() == ValoresCopia[j])
						{
							ValoresCopia[j] = R->Next(5, 15);
							j = i;
						}
					}
				}
				ContadorValoresAuxArbol++;
				richTextBox1->Text = "";
				for (int i = 0;i < ContadorValoresAuxArbol;i++)
				{
					richTextBox1->Text += Convert::ToString(ValoresCopia[i]) + "\n";
				}				
			}
			break;		
		default:
			break;
		}
	}
	//50 ancho 15 bajar 
	public: void DibujarListaSimple(Graphics^& Lienzo)
	{
		int cont = 0;
		ListaSimple Aux = NULL;
		Aux = ListaSimpleNueva;
		Point^ PosInicial = gcnew Point(0, 0);
		Point^ PosFinal = gcnew Point(0, 0);		
		while (Aux != NULL&&cont<9)
		{
			PosInicial->X = PosicionesPantalla[cont]->X + 50;
			PosInicial->Y = PosicionesPantalla[cont]->Y + 15;
			PosFinal->X = PosicionesPantalla[cont + 1]->X;
			PosFinal->Y = PosicionesPantalla[cont + 1]->Y + 15;			
			if (Aux->getSiguiente() == NULL)
			{
				LabelNULL("NULL",cont+1);
			}
			GraficarNodo(Lienzo, cont, Aux->getDato());
			DibujarFlechas(Lienzo, PosInicial, PosFinal, true);
			Aux = Aux->getSiguiente();
			cont++;
		}		
	}
	public: void DibujarListaDoble(Graphics^& Lienzo)
	{
		int cont = 1;
		ListaDoble Aux = NULL;
		Point^ PosInicial = gcnew Point(0, 0);
		Point^ PosInicial2 = gcnew Point(PosicionesPantalla[0]->X + 50, PosicionesPantalla[0]->Y + 10);
		Point^ PosFinal = gcnew Point(0, 0);
		Point^ PosFinal2 = gcnew Point(PosicionesPantalla[1]->X, PosicionesPantalla[1]->Y + 10);
		Aux = ListaDobleNueva;
		LabelNULL("NULL", 0);
		DibujarFlechas(Lienzo, PosInicial2, PosFinal2, false);
		while (Aux != NULL&&cont<8)
		{
			PosInicial->X = PosicionesPantalla[cont]->X + 50;
			PosInicial->Y = PosicionesPantalla[cont]->Y + 10;
			PosFinal->X = PosicionesPantalla[cont + 1]->X;
			PosFinal->Y = PosicionesPantalla[cont + 1]->Y + 10;
			PosInicial2->X = PosicionesPantalla[cont]->X + 50;
			PosInicial2->Y = PosicionesPantalla[cont]->Y + 20;
			PosFinal2->X = PosicionesPantalla[cont + 1]->X;
			PosFinal2->Y = PosicionesPantalla[cont + 1]->Y + 20;
			if (Aux->getSiguiente() == NULL)
			{
				LabelNULL("NULL", cont + 1);
				DibujarFlechas(Lienzo, PosInicial, PosFinal, true);
			}
			else
			{
				DibujarFlechas(Lienzo, PosInicial, PosFinal, true);
				DibujarFlechas(Lienzo, PosInicial2, PosFinal2, false);
			}
			GraficarNodo(Lienzo, cont, Aux->getDato());
			Aux = Aux->getSiguiente();
			cont++;
		}		
	}
	public: void DibujarListaCircular(Graphics^& Lienzo)
	{
		int cont = 0;
		ListaCircular Aux = NULL;
		Point^ PosInicial = gcnew Point(0, 0);
		Point^ PosFinal = gcnew Point(0, 0);
		Aux = ListaCircularNueva;
		do
		{
			if (Aux!=ListaCircularNueva)
			{
				PosInicial->X = PosicionesPantalla[cont]->X + 50;
				PosInicial->Y = PosicionesPantalla[cont]->Y + 15;
				PosFinal->X = PosicionesPantalla[cont + 1]->X;
				PosFinal->Y = PosicionesPantalla[cont + 1]->Y + 15;
				DibujarFlechas(Lienzo, PosInicial, PosFinal, true);
				GraficarNodo(Lienzo, cont, Aux->getDato());				
				cont++;
			}
			Aux = Aux->getSiguiente();
		}while (Aux != ListaCircularNueva&&cont < 9);
		PosInicial->X = PosicionesPantalla[0]->X + 25;
		PosInicial->Y = PosicionesPantalla[0]->Y + 30;
		PosFinal->X = PosicionesPantalla[cont ]->X+48;
		PosFinal->Y = PosicionesPantalla[cont ]->Y + 30;
		GraficarNodo(Lienzo, cont, ListaCircularNueva->getDato());
		DibujarFlechaFinal(Lienzo,PosInicial,PosFinal,false,15);
	}
	public: void DibujarListaCircularDoble(Graphics^& Lienzo)
	{
		int cont = 0;
		ListaCircular Aux = NULL;
		Point^ PosInicial = gcnew Point(0, 0);
		Point^ PosFinal = gcnew Point(0, 0);
		Aux = ListaDobleCircularNueva;
		do
		{
			if (Aux != ListaDobleCircularNueva)
			{
				PosInicial->X = PosicionesPantalla[cont]->X + 50;
				PosInicial->Y = PosicionesPantalla[cont]->Y + 15;
				PosFinal->X = PosicionesPantalla[cont + 1]->X;
				PosFinal->Y = PosicionesPantalla[cont + 1]->Y + 15;
				DibujarFlechas(Lienzo, PosInicial, PosFinal, true);
				GraficarNodo(Lienzo, cont, Aux->getDato());
				cont++;
			}
			Aux = Aux->getSiguiente();
		} while (Aux != ListaDobleCircularNueva&&cont < 9);
		PosInicial->X = PosicionesPantalla[0]->X + 25;
		PosInicial->Y = PosicionesPantalla[0]->Y + 30;
		PosFinal->X = PosicionesPantalla[cont]->X + 48;
		PosFinal->Y = PosicionesPantalla[cont]->Y + 30;
		GraficarNodo(Lienzo, cont, ListaDobleCircularNueva->getDato());
		DibujarFlechaFinal(Lienzo, PosInicial, PosFinal, false, 15);
		DibujarFlechaFinal(Lienzo, PosInicial, PosFinal, true, 15);
	}
			// true incluye la basura
			// false no incluye la basura
	public: void DibujarPila(Graphics^&Lienzo, bool Basura)
	{
		Pila_simple Aux = NULL;
		int cont = 0;
		Aux = NuevaPila;
		if (Basura)
		{			
			while (Aux != NULL&&cont<8)
			{
				GraficarPilas(Lienzo, cont, Aux->getDato());
				cont++;
				Aux = Aux->getSiguiente();
			}
		}
		else
		{
			Pila_simple OtraPila = NULL;
			int cont1 = 0;
			OtraPila = Basurero;
			while (Aux != NULL&&cont<8)
			{
				GraficarPilas(Lienzo, cont, Aux->getDato());
				cont++;
				Aux = Aux->getSiguiente();
			}
			while (OtraPila != NULL&&cont1<8)
			{
				GraficarPilasBAsura(Lienzo, cont1, OtraPila->getDato());
				cont1++;
				OtraPila = OtraPila->getSiguiente();
			}
		}
	}			
	public: void DibujarCola(Graphics^&Lienzo, bool Basura)
	{
		struct nodo *aux;
		int cont = 0;
		aux = ColaNueva.delante;
		if (Basura)
		{
			while (aux != NULL&&cont<8)
			{
				GraficarPilas(Lienzo, cont, aux->nro);
				cont++;
				aux = aux->sgte;
			}
		}
		else
		{
			struct nodo *OtraCola;
			int cont1 = 0;
			OtraCola = ColaBasura.delante;
			while (OtraCola != NULL&&cont1<8)
			{
				GraficarPilasBAsura(Lienzo, cont1, OtraCola->nro);
				cont1++;
				OtraCola = OtraCola->sgte;
			}
			while (aux != NULL&&cont<8)
			{
				GraficarPilas(Lienzo, cont, aux->nro);
				cont++;
				aux = aux->sgte;
			}
		}
	}
			 //Boton Graficar !! 
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		Refresco();
		NuevoArbol = NULL;
		Graphics^ Lienzo = pictureBox1->CreateGraphics();		
		switch (BanderaPos)
		{
			//simple
		case 0:			
			DibujarListaSimple(Lienzo);			
			break;
		case 1:			
			DibujarListaSimple(Lienzo);
			break;
		case 2:			
			DibujarListaSimple(Lienzo);
			break;
		case 3:			
			DibujarListaSimple(Lienzo);
			break;
			//doble
		case 4:			
			DibujarListaDoble(Lienzo);
			break;
		case 5:
			DibujarListaDoble(Lienzo);
			break;
		case 6:			
			DibujarListaDoble(Lienzo);
			break;
		case 7:			
			DibujarListaDoble(Lienzo);
			break;
			//circular
		case 8:			
			DibujarListaCircular(Lienzo);
			break;
		case 9:			
			DibujarListaCircular(Lienzo);
			break;
		case 10:			
			DibujarListaCircular(Lienzo);
			break;
		case 11:			
			DibujarListaCircular(Lienzo);
			break;
			//circular doble
		case 12:
			DibujarListaCircularDoble(Lienzo);
			break;
		case 13:
			DibujarListaCircularDoble(Lienzo);
			break;
		case 14:
			DibujarListaCircularDoble(Lienzo);
			break;
		case 15:
			DibujarListaCircularDoble(Lienzo);
			break;
			//pilas
		case 16:
			DibujarPila(Lienzo, true);
			break;
		case 17:
			DibujarPila(Lienzo, false);
			break;
			//colas
		case 18:
			DibujarCola(Lienzo, true);
			break;
		case 19:
			if (ColaBasura.delante!=NULL)
			{
				DibujarCola(Lienzo, false);
			}
			break;
			//arboles
		case 20:					
			if (ValoresCopia!=NULL)
			{				
				for (int i = 0;i < this->cantidadDeDatos&&i<10;i++)
				{
					insertanodonuevo(Lienzo, &NuevoArbol, 0, ValoresCopia[i], ValoresCopia[i]);
					cont++;
					Apertura -= 6;
				}
			}
			break;
			//dato a dato
		case 21:			
			if (ValoresCopia != NULL)
			{					
				for (int i = 0;i <ContadorValoresAuxArbol&&i<10;i++)
				{					
					insertanodonuevo(Lienzo, &NuevoArbol, 0, ValoresCopia[i], ValoresCopia[i]);
					cont++;
					Apertura -= 6;
				}
			}
			break;
		default:
			break;
		}		
	}
};
}
