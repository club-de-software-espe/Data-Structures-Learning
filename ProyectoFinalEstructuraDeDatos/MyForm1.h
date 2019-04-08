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
#pragma once
namespace ProyectoFinalEstructuraDeDatos
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Random;
	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	public: int *ValoresArbol = new int[15]; //almacenamiento de valores para el arbol
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	public: String^ Desplegar = "";
	private: System::Windows::Forms::Button^  button3;
	public:
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(71, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Cantidad de datos";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(74, 56);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 22);
			this->textBox1->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(74, 127);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(117, 101);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(71, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(120, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Datos Generados";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(12, 247);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(71, 32);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(186, 247);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 32);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Generar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(89, 247);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 32);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Cancelar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(273, 336);
			this->ControlBox = false;
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm1";
			this->Text = L"Generar Datos";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//generar los datos para ser enviados 
		public: void GenerarDatos(int Datos[])
		{
			int pos1, pos2, temp;
			Random ^R = gcnew Random(DateTime::Now.Millisecond);
			for (int i = 0; i < 15; i++)
			{
				Datos[i] = i + 1;
			}
			for (int k = 0; k < 15; k++)
			{
				pos1 = R->Next(0, 14);
				pos2 = R->Next(0, 14);
				temp = Datos[pos1];
				Datos[pos1] = Datos[pos2];
				Datos[pos2] = temp;
			}
			pos2 = R->Next(0, 14);
			temp = Datos[14];
			Datos[14] = Datos[pos2];
			Datos[pos2] = temp;
		}
		public: int CantidadDeDatos()
		{
			int retorno = 0;
			try
			{
				if (textBox1->Text->Length == 0)
				{
					MessageBox::Show("Casillero en blanco");
				}
				else
				{
					if (Convert::ToInt32(textBox1->Text) > 11)
					{
						retorno= 0;
					}
					else
					{
						button1->Enabled = true;
						retorno= Convert::ToInt32(textBox1->Text);
					}
				}
			}
			catch (FormatException^e)
			{				
				retorno= 0;
				MessageBox::Show("Error: " + e->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return retorno;
		}
				//mostrar generar;
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{		
		GenerarDatos(ValoresArbol);
		this->Desplegar = "";
		for (int i = 0; i < CantidadDeDatos();i++)
		{
			Desplegar += Convert::ToString(ValoresArbol[i])+"\n";
		}
		richTextBox1->Text = Desplegar;
	}
	// guardar
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{		
		if (textBox1->Text->Length==0)
		{
			MessageBox::Show("Casillero en blanco");
		}
		else
		{
			if (CantidadDeDatos() == 0)
			{
				MessageBox::Show("Ingrese una cantidad entre 1 y 15");
			}
			else
			{
				MessageBox::Show("Datos Guardados Exitosamente!!!");
				this->Close();
			}
		}		
	}
			 //cancelar
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		textBox1->Text = "0";
		this->richTextBox1->Text = "";
		this->Desplegar = "";
		button1->Enabled = false;
		this->ValoresArbol = new int[15];
		this->Close();
	}
};
}
