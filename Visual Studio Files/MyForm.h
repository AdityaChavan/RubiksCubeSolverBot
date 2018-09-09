#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include <msclr/marshal_cppstd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <cstdio>
#include <opencv2\opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <windows.h>
#include <string>
#include <Windows.h>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>

using namespace std;
namespace SerialComm1 {

	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Diagnostics;

	//void putStrings(int, int, int, Mat);
	//void updatefinalstring();
	//void handleoutput();
	//void encodestring();


	
	static char face_string[] = "UUUUUUUUU";
	static cv::String saved_face_string = "UUUUUUUUU";
	//char test[]        =            "bdrfuululululrddrubbflfbdbbfdrrdbdurlrudlffurfrdfblbfl";
	static char finalstr[] = "_______up____right____front_____down_____left_____back";
	static char finalencodedstr[] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
	static char up;
	static char down;
	static char left1;
	static char right1;
	static char front;
	static char back;
	static int sidecount = 0;
	static int temp = 0;
	static int red_value = 7;
	static int yellow_value = 115;
	static int blue_value = 100;
	static char soln[56];
	static int confirm = 0;
	static int grabbed = 0;
	static char solutionofcube[100];
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
			findPorts();
			
			
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
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3_STATUS;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button5;

	private: System::Windows::Forms::Button^  button7;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::Button^  button8;

	private: System::Windows::Forms::Label^  label4;





	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;

	private: System::Windows::Forms::Button^  button9;

	private:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button10;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker2;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;







	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3_STATUS = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker2 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 3000;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(126, 56);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(138, 21);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(37, 98);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(83, 49);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Initialise Port";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(126, 98);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 49);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Close Port";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 329);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(179, 20);
			this->textBox1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 231);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(81, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Manual Control:";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(226, 328);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(72, 21);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Send";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label3_STATUS
			// 
			this->label3_STATUS->AutoSize = true;
			this->label3_STATUS->Location = System::Drawing::Point(149, 17);
			this->label3_STATUS->Name = L"label3_STATUS";
			this->label3_STATUS->Size = System::Drawing::Size(67, 13);
			this->label3_STATUS->TabIndex = 7;
			this->label3_STATUS->Text = L"Not Running";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(34, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(43, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Status: ";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(29, 257);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(135, 61);
			this->button4->TabIndex = 9;
			this->button4->Text = L"Start Camera";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(304, 38);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 384);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(170, 257);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(127, 61);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Stop Camera";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(29, 359);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(83, 63);
			this->button7->TabIndex = 13;
			this->button7->Text = L"Scan";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			// 
			// button8
			// 
			this->button8->AllowDrop = true;
			this->button8->Location = System::Drawing::Point(215, 359);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(83, 63);
			this->button8->TabIndex = 14;
			this->button8->Text = L"Solve";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(845, 257);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(10, 13);
			this->label4->TabIndex = 15;
			this->label4->Text = L" ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(892, 257);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(10, 13);
			this->label8->TabIndex = 21;
			this->label8->Text = L" ";
			this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(948, 257);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(10, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L" ";
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(126, 359);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(83, 63);
			this->button9->TabIndex = 23;
			this->button9->Text = L"Clear";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 25;
			this->label1->Text = L"COM Port:";
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Calibri Light", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(848, 329);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(137, 67);
			this->button6->TabIndex = 26;
			this->button6->Text = L"START";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(215, 98);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(83, 49);
			this->button10->TabIndex = 27;
			this->button10->Text = L"Rescan Ports";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// backgroundWorker2
			// 
			this->backgroundWorker2->WorkerReportsProgress = true;
			this->backgroundWorker2->WorkerSupportsCancellation = true;
			this->backgroundWorker2->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker2_DoWork);
			this->backgroundWorker2->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker2_ProgressChanged);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(45, 153);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(114, 38);
			this->button11->TabIndex = 28;
			this->button11->Text = L"Hold Cube";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(170, 153);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(114, 39);
			this->button12->TabIndex = 29;
			this->button12->Text = L"Leave Cube";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(848, 50);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(137, 23);
			this->button13->TabIndex = 30;
			this->button13->Text = L"Start";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(848, 90);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(137, 23);
			this->button14->TabIndex = 31;
			this->button14->Text = L"Right";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(848, 130);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(137, 23);
			this->button15->TabIndex = 32;
			this->button15->Text = L"Front";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button16
			// 
			this->button16->Location = System::Drawing::Point(848, 170);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(137, 23);
			this->button16->TabIndex = 33;
			this->button16->Text = L"Down";
			this->button16->UseVisualStyleBackColor = true;
			this->button16->Click += gcnew System::EventHandler(this, &MyForm::button16_Click);
			// 
			// button17
			// 
			this->button17->Location = System::Drawing::Point(848, 210);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(137, 23);
			this->button17->TabIndex = 34;
			this->button17->Text = L"Left";
			this->button17->UseVisualStyleBackColor = true;
			this->button17->Click += gcnew System::EventHandler(this, &MyForm::button17_Click);
			// 
			// button18
			// 
			this->button18->Location = System::Drawing::Point(848, 250);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(137, 23);
			this->button18->TabIndex = 35;
			this->button18->Text = L"Back";
			this->button18->UseVisualStyleBackColor = true;
			this->button18->Click += gcnew System::EventHandler(this, &MyForm::button18_Click);
			// 
			// button19
			// 
			this->button19->Location = System::Drawing::Point(848, 290);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(137, 23);
			this->button19->TabIndex = 36;
			this->button19->Text = L"Send";
			this->button19->UseVisualStyleBackColor = true;
			this->button19->Click += gcnew System::EventHandler(this, &MyForm::button19_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1004, 433);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label3_STATUS);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->comboBox1);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"Cube Solver";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

			
		// find available ports
	private: void findPorts(void)
	{
		// get port names
		array<Object^>^ objectArray = SerialPort::GetPortNames();
		// add string array to combobox
		this->comboBox1->Items->AddRange(objectArray);
		this->button2->Enabled = false;

	}

		//select com port box
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	   //Initialize Button
	public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->label3_STATUS->Text = "Initialising";

		if (this->comboBox1->Text == System::String::Empty)
			this->label3_STATUS->Text = "Please Select COM Port";
		else {
			this->button1->Enabled = false;
			this->button2->Enabled = true;

			try{
				// make sure port isn't open	
				if (!this->serialPort1->IsOpen){
					this->serialPort1->PortName = this->comboBox1->Text;
					//this->textBox1->Text=this->comboBox1->Text;
					this->serialPort1->BaudRate = 9600;
					//this->textBox1->Text=this->comboBox2->Text;
					this->textBox1->Text = "Enter Steps Here";
					//open serial port 
					this->serialPort1->Open();
					this->label3_STATUS->Text = "COM Port Open";
				}
				else
					this->label3_STATUS->Text = "Error Opening Port";
			}
			catch (UnauthorizedAccessException^){
				this->label3_STATUS->Text = "Unauthorized Access";
			}
		}


	}

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	findPorts();
}
	  //Close Button
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//close serialPort
		this->button2->Enabled = false;
		this->button1->Enabled = true;

		this->serialPort1->Close();

	}

		//send to com port button
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {

		// add sender name
		System::String^ name = this->serialPort1->PortName;
		// grab text and store in send buffer
		System::String^ message = this->textBox1->Text;
		// write to serial
		if (this->serialPort1->IsOpen)
			//this->_serialPort->WriteLine(String::Format("<{0}>: {1}",name,message));
			this->serialPort1->WriteLine(message);
		else
			this->label3_STATUS->Text = "Port Not Opened";
		while (1)
		{
			try{
				System::String^ input = this->serialPort1->ReadLine();
				std::string inp = msclr::interop::marshal_as<std::string>(input);

				if (strlen(inp.c_str())>=1)
				{
					this->label3_STATUS->Text = input;
					break;
				}
			}
			catch (TimeoutException^){
				this->label3_STATUS->Text = "Timeout Exception";
				break;
			}
		}


	}//send button
//ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
//code starts


 string colourrec(int H, int S, int V)							//guess colour
	 {
	 char TestStr[10];
	 if(((H >= 0 && H <= 24) ||(H >= 160 && H <= 180)) &&(S >= 0 && S <= 300)		   && (V >= 0 && V <= 175)){ sprintf_s(TestStr, "Red"); }			//hue based		
					//	  ^red_value here																																				//					
else if((H >= 0 && H <= 24 || (H >= 160 && H <= 180)) &&(S >= 0 && S <= 300)		   && (V >= 175 && V <= 255)){ sprintf_s(TestStr, "Orange"); }		// RY hue based	\\YW
		//    ^red_value here																																										//			
else if(H >= 25 && H <= 55									  &&(S >= 40 && S <= 220) && (V >= 0 && V <= 255)){ sprintf_s(TestStr, "Yellow"); }		//sat based		\\
																																										//		
else if(H >= 56 && H <= 84								      &&(S >= 80 && S <= 255)&& (V >= 0 && V <= 255)){ sprintf_s(TestStr, "Green"); }		//sat based		//
																																														//		
else if((H >= 25 && H <= 159|| (H == 0 && S == 0))			  &&(S >= 0 && S <= blue_value)	   && (V >= 0 && V <= 255)){ sprintf_s(TestStr, "White"); }		//sat based		//
																																										//
else if(H >= 85 && H <= 159									  &&(S >= blue_value && S <= 300)  && (V >= 0 && V <= 255)){ sprintf_s(TestStr, "Blue"); }			//sat based

else  { sprintf_s(TestStr, "Unknown");
}

return TestStr;
	 }


 void putStrings(int a, int b, int j, Mat frame)
 {
	 Mat HSV;
	 Mat sample = frame(Rect(a, b, 1, 1));
	 cvtColor(sample, HSV, CV_BGR2HSV);
	 Vec3b hsv = HSV.at<Vec3b>(0, 0);

	 int H = hsv.val[0]; //hue
	 int S = hsv.val[1]; // sat
	 int V = hsv.val[2]; // sat

	 char TestStr1[10];
	 char TestStr2[10];
	 char TestStr3[10];

	 sprintf_s(TestStr1, "%d", H);
	 sprintf_s(TestStr2, "%d", S);
	 sprintf_s(TestStr3, "%d", V);
	 string TestStr = colourrec(H, S, V);//recognizes colour

	 putText(frame, TestStr, cv::Point(a + 15, b), CV_FONT_NORMAL, 0.5, Scalar(255, 255, 255), 1, 1); //Colour is Shown  
	 putText(frame, TestStr1, cv::Point(a - 40, b + 40), CV_FONT_NORMAL, 0.5, Scalar(255, 255, 255), 1, 1); //Hue is shown 
	 putText(frame, TestStr2, cv::Point(a + 00, b + 40), CV_FONT_NORMAL, 0.5, Scalar(255, 255, 255), 1, 1); //Sat is shown 
	 putText(frame, TestStr3, cv::Point(a + 40, b + 40), CV_FONT_NORMAL, 0.5, Scalar(255, 255, 255), 1, 1); //Value is shown 

	 rectangle(frame, cv::Point(a - 10, b - 10), cv::Point(a + 10, b + 10), Scalar(0, 255, 255), 1, 8);


	 face_string[j] = TestStr.at(0);     // first letter of colour
 } 
 void updatefinalstring()
 {
	 int strt = 0;


	 if (sidecount == 0){ up = saved_face_string[4]; strt = 0; }
	 else if (sidecount == 1){ right1 = saved_face_string[4]; strt = 9; }
	 else if (sidecount == 2){ front = saved_face_string[4]; strt = 18; }
	 else if (sidecount == 3){ down = saved_face_string[4]; strt = 27; }
	 else if (sidecount == 4){ left1 = saved_face_string[4]; strt = 36; }
	 else if (sidecount == 5){ back = saved_face_string[4]; strt = 45; }
	 else return;

	 for (int j = 0; j <= 8; j++)
	 {
		 finalstr[strt + j] = saved_face_string[j];
	 }
 }
 void encodestring()
 {

	 for (int i = 0; i <= 53; i++)
	 {
		 if (finalstr[i] == up)
			 finalencodedstr[i] = 'U';
		 else if (finalstr[i] == back)
			 finalencodedstr[i] = 'B';
		 else if (finalstr[i] == left1)
			 finalencodedstr[i] = 'L';
		 else if (finalstr[i] == down)
			 finalencodedstr[i] = 'D';
		 else if (finalstr[i] == right1)
			 finalencodedstr[i] = 'R';
		 else if (finalstr[i] == front)
			 finalencodedstr[i] = 'F';
		 else finalencodedstr[i] = 'X';
	 }

	 //123456789123456789123456789123456789123456789123456789
	 //UUUUUUUUURRRRRRRRRFFFFFFFFFDDDDDDDDDLLLLLLLLLBBBBBBBBB
	 //000000000011111111112222222222333333333344444444445555
	 //012345678901234567890123456789012345678901234567890123

	 //UF UR UB UL DF DR DB DL FR FL BR BL UFR URB UBL ULF DRF DFL DLB DBR
	 //0000000000111111111122222222223333333333444444444455555555556666666
	 //0123456789012345678901234567890123456789012345678901234567890123456
	 /*soln[00] = finalencodedstr[07];
	 soln[1] = finalencodedstr[19];

	 soln[3] = finalencodedstr[05];
	 soln[4] = finalencodedstr[10];
	 
	 soln[6] = finalencodedstr[01];
	 soln[7] = finalencodedstr[46];
	 
	 soln[9] = finalencodedstr[03];
	 soln[10] = finalencodedstr[37];
	 
	 soln[12] = finalencodedstr[28];
	 soln[13] = finalencodedstr[25];
	 
	 soln[15] = finalencodedstr[32];
	 soln[16] = finalencodedstr[16];
	 
	 soln[18] = finalencodedstr[34];
	 soln[19] = finalencodedstr[52];
	 
	 soln[21] = finalencodedstr[30];
	 soln[22] = finalencodedstr[43];
	 
	 soln[24] = finalencodedstr[23];
	 soln[25] = finalencodedstr[12];
	 
	 soln[27] = finalencodedstr[21];
	 soln[28] = finalencodedstr[41];

	 soln[30] = finalencodedstr[48];
	 soln[31] = finalencodedstr[14];
	 
	 soln[33] = finalencodedstr[50];
	 soln[34] = finalencodedstr[39];

	 soln[36] = finalencodedstr[8];
	 soln[37] = finalencodedstr[20];
	 soln[38] = finalencodedstr[9];
	 
	 soln[40] = finalencodedstr[2];
	 soln[41] = finalencodedstr[11];
	 soln[42] = finalencodedstr[45];
	 
	 soln[44] = finalencodedstr[0];
	 soln[45] = finalencodedstr[47];
	 soln[46] = finalencodedstr[36];
	 
	 soln[48] = finalencodedstr[6];
	 soln[49] = finalencodedstr[38];
	 soln[50] = finalencodedstr[18];
	 
	 soln[52] = finalencodedstr[29];
	 soln[53] = finalencodedstr[15];
	 soln[54] = finalencodedstr[26];
	 
	 soln[56] = finalencodedstr[27];
	 soln[57] = finalencodedstr[24];
	 soln[58] = finalencodedstr[44];

	 soln[60] = finalencodedstr[33];
	 soln[61] = finalencodedstr[42];
	 soln[62] = finalencodedstr[53];
	 
	 soln[64] = finalencodedstr[35];
	 soln[65] = finalencodedstr[51];
	 soln[66] = finalencodedstr[17];
	 char spc= ' ';
	 soln[2] = soln[5] = soln[8] = soln[11] = soln[14] = soln[17] = soln[20] = soln[23] = soln[26] = soln[29] = soln[32] = soln[35] = soln[39] = soln[43] = soln[47] = soln[51] = soln[55] = soln[59] = soln[63] = spc;
	 */

 }
 void handleoutput()
 {
	
	 AllocConsole();
	 freopen("conout$", "w", stdout);
	 printf("\nSolution:\n");
	 
	 //char sol[100] = "kociemba FDBRUUDUULFDBRRLFFRBBBFRFUFDLUFDLUBDUUBLLDRDLLRRFBDRLB";//testing
	 char sol[100] = "kociemba ";
	 
	 strcat(sol, finalencodedstr);
	 
	//char abc[55]= "FDBRUUDUULFDBRRLFFRBBBFRFUFDLUFDLUBDUUBLLDRDLLRRFBDRLB";  strcat(url, abc);

	 FILE   *pPipe;

	 pPipe = _popen(sol, "rt");
		 
	 string line;
	 std::string output;
	 int p = 0;
	 ifstream myfile(pPipe);
	 if (myfile.is_open())
	 {
		
		 while (getline(myfile, line))
		 {
			 cout << "opened" << endl;
			 output = line;
			 cout <<"Solution: "<< line << endl; 
		 }
		 myfile.close();
	 }

	 else cout<<"Unable to open file"<<endl;

	 _pclose(pPipe);

	 for (int c = 0; c < output.length();c++)
	 {
		 solutionofcube[c] = output[c];
	 }
	 
	 ofstream fout("output.txt");
	 fout <<"cube: "<< finalstr << "\n" << up << front << right1 << down << left1 << back << "\n" <<"encoded cube: "<< finalencodedstr << "\n" << "Solution: "<< output << endl;
	 fout.close();
	 this->label3_STATUS->Text = "Solved";
	 confirm = 0;
	 
	 //this->timer1->Enabled = false;

 }
 //oooooooooooooooooooooooooooooooooooooooooooooooooooooooooo


 //start CAM button
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		this->button5->Enabled = "True"; 
		this->button7->Enabled = "True";
		this->button8->Enabled = "True";
		this->button4->Enabled = "False";


	backgroundWorker1->RunWorkerAsync(10);  //starting background worker

			this->label3_STATUS->Text = "Starting Camera..";
			
	}		
	


//background worker 1
private: System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) 
{
	
	Mat frame;

	VideoCapture cap(0); // open the video camera no. 0
	if (!cap.isOpened())  // if not success, exit program
	{
		AllocConsole();
		freopen("conout$", "w", stdout);
		printf("Cannot open the video cam");

	}
	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
	backgroundWorker1->ReportProgress(1);  //reporting progress

	

		while (1)
		{
			if (backgroundWorker1->CancellationPending) //if it was cancelled
			{
				e->Cancel = true;
				break;
			}

			//if not success, break loop
			cap.read(frame); // read a new frame from video

			Mat frame2 = frame;
			///////////////////////////////////////////////////////
			// Global Variables

			int MAX_KERNEL_LENGTH = 8;
			//for (int i = 1; i < MAX_KERNEL_LENGTH; i = i + 2){blur(frame, frame, cv::Size(i, i), cv::Point(-1, -1));}

			//erode(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			//dilate(frame, frame, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));//morphological blurring

			//////////////////////////////////////////////////////
			//UP
			putStrings(200, 130, 0, frame); //recognizes colour at x,y and puts strings in mat frame
			putStrings(350, 160, 1, frame);
			putStrings(500, 130, 2, frame);
			//MIDDLE
			putStrings(240, 270, 3, frame);
			putStrings(350, 270, 4, frame);
			putStrings(450, 270, 5, frame);
			//DOWN
			putStrings(200, 400, 6, frame);
			putStrings(350, 390, 7, frame);
			putStrings(500, 410, 8, frame);


			//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
										

			//setMouseCallback("pictureBox1", CallBackFunc, NULL);
			

//imshow("MyVideo", frame); //show the frame in "MyVideo" window

			DrawCVImage(pictureBox1, frame);

			//cvShowImage("MyVideo", img);

			

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	
}
 void backgroundWorker1_ProgressChanged(Object^ /*sender*/, ProgressChangedEventArgs^ e)
 {
	// this->timer1->Enabled = "True";
	 temp = 1;
			 this->label3_STATUS->Text = "Scanning Cube..";
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {}
		 void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage)
		 {
			 System::Drawing::Graphics^ graphics = control->CreateGraphics();
			 System::IntPtr ptr(colorImage.ptr());
			 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			 graphics->DrawImage(b, rect);
		 }





		 //close cam
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			backgroundWorker1->CancelAsync();												//cancel backgroundworker

			this->button4->Enabled = "True";
		this->label3_STATUS->Text = "Camera Closed";
		this->button5->Enabled = "False";
		this->button7->Enabled = "False";
		this->button8->Enabled = "False";

	}

		 //scan button
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
// scan button
	AllocConsole();
	freopen("conout$", "w", stdout);
	saved_face_string = face_string;
	for (int i = 0; i < (saved_face_string.length()); i++)
	{
		if (saved_face_string[i] == 'U')
		{
			goto dontsave;
		}
	}
	updatefinalstring();
	sidecount = sidecount + 1;
dontsave:
	cout << "Cube Saved " << finalstr << endl;
	
}//scan
		
		 //send to alg
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

	//this->timer1->Enabled = "True";


	//send button 
	backgroundWorker1->CancelAsync();												//cancel backgroundworker1
	this->button4->Enabled = "True";
	this->label3_STATUS->Text = "Camera Closed";
	this->button5->Enabled = false;
	this->button7->Enabled = false;
	this->button8->Enabled = false;

	encodestring();

	AllocConsole();
	freopen("conout$", "w", stdout);
	cout << "cube sent to algorithm \n\n" << up << right1 << front << down << left1 << back << "\n\n" << finalencodedstr << "\n\n"<< endl;

	handleoutput();
	/*
	cout << finalstr << "\n" << finalencodedstr << "\n" << soln << "\n" << endl;
	ofstream fout("cubestring.txt");
	fout << soln << endl;
	fout.close();
	*/

}

//private: System::Void trackBar3_Scroll(System::Object^  sender, System::EventArgs^  e) {//blue-white trackbar
//blue_value = this->trackBar3->Value;
//this->label9->Text = blue_value.ToString();
//}

	     //clear
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	char finalstr1[55] = "_______up____right____front_____down_____left_____back";
 char finalencodedstr1[53] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
 for (int i = 0; i < 55; i++)
 {
	 finalstr[i] = finalstr1[i];
 } 
 for (int i = 0; i < 53; i++)
 {
	 finalencodedstr[i] = finalencodedstr1[i];
 }
	 sidecount = 0;
	 
	;
}

private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
		 
/*public: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
	
	System::String^ timerstr = timerlabel->Text;

	float a = (float)(Convert::ToDouble(timerstr)+00.019);
	timerlabel->Text = a.ToString();


}*/
	
		
		int scan()
		{
			int error = 0; 
		scanst:
			saved_face_string = face_string;
			for (int i = 0; i < (saved_face_string.length()); i++)
			{
				if (saved_face_string[i] == 'U')
				{
					error++;
					goto dontsave;
					AllocConsole();
					freopen("conout$", "w", stdout);
					cout << saved_face_string << endl;

				}
				
			}
			updatefinalstring();
			sidecount = sidecount + 1;
			return 0;
		dontsave:
			if (error<10)
			{
				goto scanst;
			}
			else return error;
		}
private: System::Void label5_Click(System::Object^  sender, System::EventArgs^  e) {
}
		 
		 
		 
	//KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK	 
		 //Auto Start
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {//MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
		if (grabbed == 1)
		{
			backgroundWorker1->RunWorkerAsync(10);  //starting background worker

			this->label3_STATUS->Text = "Starting Camera..";

			System::Threading::Thread::Sleep(7 * 1000);

			//backgroundWorker2->RunWorkerAsync(10);//start timer

			AllocConsole();
			freopen("conout$", "w", stdout);

			//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//start
			restart:
			System::String^ name = this->serialPort1->PortName;
			if (this->serialPort1->IsOpen)
			{
				this->serialPort1->WriteLine("Start.");

				cout << "Start Written" << endl;
				printf("Start Written\n");

				while (1)
				{
					try{
						System::String^ input = this->serialPort1->ReadLine();

						std::string inp = msclr::interop::marshal_as<std::string>(input);//string^ to string
						cout << inp << endl;
						if (strcmp(inp.c_str(), "Ready.") == 0)
						{
							printf("Ready Received\n");

							this->label3_STATUS->Text = "Ready Received.";
							//////////
							if (scan() < 1)
							{
								goto right;
							}
							else{
								printf( "Error in Colour Calibration\n" );
								goto end;
							}
							/////////
						}
					}
					catch (TimeoutException^){
						this->label3_STATUS->Text = "Timeout Exception@Ready";
						goto restart;
					}
				}
				
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
				
			right:
				if (this->serialPort1->IsOpen)
				{
					
					this->serialPort1->WriteLine("Right.");

					printf("Right Written\n");

					while (1)
					{
						try{
							System::String^ inputR = this->serialPort1->ReadLine();

							std::string inpR = msclr::interop::marshal_as<std::string>(inputR);//string^ to string
							cout << inpR << endl;
							if (strcmp(inpR.c_str(), "Right.") == 0)
							{
								printf("Right Received.\n" );
								//////////
								if (scan() < 1)
								{
									goto front;
								}
								else{
									printf("Error in Colour Calibration");
									goto end;
								}
								/////////

							}
						}
						catch (TimeoutException^){
							this->label3_STATUS->Text = "Timeout Exception@Right";
							goto right;
						}
					}
				}
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//front
			front:
				if (this->serialPort1->IsOpen)
				{
					
					this->serialPort1->WriteLine("Front.");

					printf("Front Written\n" );

					while (1)
					{
						try{
							System::String^ inputF = this->serialPort1->ReadLine();

							std::string inpF = msclr::interop::marshal_as<std::string>(inputF);//string^ to string
							cout << inpF << endl;
							if (strcmp(inpF.c_str(), "Front.") == 0)
							{
								printf("Front Received.\n");//////////
								if (scan() < 1)
								{
									goto down;
								}
								else{
									printf("Error in Colour Calibration");
									goto end;
								}
								/////////
							}
						}
						catch (TimeoutException^){
							this->label3_STATUS->Text = "Timeout Exception@Front";
							goto front;
						}
					}
				}
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//down
			down:
				if (this->serialPort1->IsOpen)
				{
					this->serialPort1->WriteLine("Down.");

					printf("Down Written\n" );

					while (1)
					{
						try{
							System::String^ inputD = this->serialPort1->ReadLine();

							std::string inpD = msclr::interop::marshal_as<std::string>(inputD);//string^ to string
							cout << inpD << endl;
							if (strcmp(inpD.c_str(), "Down.") == 0)
							{
								printf("Down Received.\n" );//////////
								if (scan() < 1)
								{
									goto left;
								}
								else{
									printf("Error in Colour Calibration");
									goto end;
								}
								/////////
							}
						}
						catch (TimeoutException^){
							this->label3_STATUS->Text = "Timeout Exception@Down";
							goto down;
						}
					}
				}
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//Left
			left:
				if (this->serialPort1->IsOpen)
				{
					
					this->serialPort1->WriteLine("Left.");

					printf("Left Written\n");

					while (1)
					{
						try{
							System::String^ inputL = this->serialPort1->ReadLine();

							std::string inpL = msclr::interop::marshal_as<std::string>(inputL);//string^ to string
							cout << inpL << endl;
							if (strcmp(inpL.c_str(), "Left.") == 0)
							{
								printf("Left Received.\n" );//////////
								if (scan() < 1)
								{
									goto back;
								}
								else{
									printf("Error in Colour Calibration");
									goto end;
								}
								/////////
							}
						}
						catch (TimeoutException^){
							this->label3_STATUS->Text = "Timeout Exception@Left";
							goto left;
						}
					}
				}
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//back
			back:
				if (this->serialPort1->IsOpen)
				{
					this->serialPort1->WriteLine("Back.");

					printf("Back Written\n");

					while (1)
					{
						try{
							System::String^ inputB = this->serialPort1->ReadLine();

							std::string inpB = msclr::interop::marshal_as<std::string>(inputB);//string^ to string
							cout << inpB << endl;
							if (strcmp(inpB.c_str(), "Back.") == 0)
							{
								printf("Back Received.\n");//////////
								if (scan() < 1)
								{
									goto sol;
								}
								else{
									printf("Error in Colour Calibration\n");
									goto end;
								}
								/////////
							}
						}
						catch (TimeoutException^){
							this->label3_STATUS->Text = "Timeout Exception@Back";
							goto back;
						}
					}
				}
				encodestring();
				handleoutput();
				//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//back
			sol:
				
				cout << "Back Received\n" << solutionofcube << "\n"<<endl;
				if (this->serialPort1->IsOpen)
				{
					printf(finalencodedstr);
					printf("\n");

					strcat(solutionofcube, ".");
					System::String^ solution = msclr::interop::marshal_as<System::String^>(solutionofcube);

					this->serialPort1->WriteLine(solution);
					printf(solutionofcube);
					printf("\nSolution Sent\n" );
					//System::Threading::Thread::Sleep(1000 * 4); //wait atleast 4 sec before tring to read
					while (1)
					{
					wait:
						try{
							System::String^ inputDone = this->serialPort1->ReadLine();

							std::string inpDone = msclr::interop::marshal_as<std::string>(inputDone);//string^ to string
							cout << inpDone << endl;
							if (strcmp(inpDone.c_str(), "Done") == 0)
							{
								printf("Done Received. \n\nSolving Complete.\n");
								backgroundWorker2->CancelAsync();

								goto end;
							}


						}

						catch (TimeoutException^){
							goto wait;
						}
					}

				end:
					backgroundWorker1->CancelAsync();												//cancel backgroundworker

				}

			}
		}
		else{
			AllocConsole();
			freopen("conout$", "w", stdout);
			cout << "Hold Cube First" << endl;
			this->label3_STATUS->Text = "Cube not Held";


		}
	}

	//KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
	
		//timer backworker
private: System::Void backgroundWorker2_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	while (1)
	{
		cout << "_" << endl;
		backgroundWorker2->ReportProgress(1);  //reporting progress

		cout << "." << endl;
		//	this->timer1->Enabled = "true";
		if (backgroundWorker2->CancellationPending) //if it was cancelled
		{
			e->Cancel = true;
			break;
		}
	}
}

		 void backgroundWorker2_ProgressChanged(Object^ /*sender*/, ProgressChangedEventArgs^ e)
		 {
			 /////
//			 System::String^ timerstr = timerlabel->Text;

	//		 float a = (float)(Convert::ToDouble(timerstr) + 00.019);
//			 timerlabel->Text = a.ToString();
			 /////
		 }

		 //hold button
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	grabbed = 1;

	System::String^ name = this->serialPort1->PortName;
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->WriteLine("Grab.");


		while (1)
		{
			try{
				System::String^ input = this->serialPort1->ReadLine();

				std::string inp = msclr::interop::marshal_as<std::string>(input);//string^ to string
				cout << inp << endl;
				if (strcmp(inp.c_str(), "Grabbed.") == 0)
				{
					this->label3_STATUS->Text = "Cube is Held.";
				}
			}
			catch (TimeoutException^){
				this->label3_STATUS->Text = "Timeout Exception@Grab";
				break;
			}
		}


	}

}
		 //leave button
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {

	grabbed = 0;
	System::String^ name = this->serialPort1->PortName;
	if (this->serialPort1->IsOpen)
	{
		this->serialPort1->WriteLine("Ungrab.");


		while (1)
		{
			try{
				System::String^ input = this->serialPort1->ReadLine();

				std::string inp = msclr::interop::marshal_as<std::string>(input);//string^ to string
				cout << inp << endl;
				if (strcmp(inp.c_str(), "Ungrabbed.") == 0)
				{
					this->label3_STATUS->Text = "Cube is not Held.";
				}
			}
			catch (TimeoutException^){
				this->label3_STATUS->Text = "Timeout Exception@UnGrab";
				break;
			}
		}
	}

}



		 /*
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	AllocConsole();
	freopen("conout$", "w", stdout);
	int abcd = scan();
	if (abcd < 1)
	{
		encodestring();
		printf(finalencodedstr);
		printf("Successs");
		cout << "Succes" << endl;
	}
	else{
		printf("Error in Colour Calibration\n");
		cout << "Error" << abcd<< endl;
	}
}*/
//start
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	
	
	if (this->serialPort1->IsOpen)
			this->serialPort1->WriteLine("Start.");
	else
		this->label3_STATUS->Text = "Port Not Opened";
	labelA:
	while (1)
	{
		try{
			System::String^ input = this->serialPort1->ReadLine();
			std::string inp = msclr::interop::marshal_as<std::string>(input);

			if (strlen(inp.c_str()) >= 1)
			{
				this->label3_STATUS->Text = input;
				break;
			}	}
		catch (TimeoutException^){
			this->label3_STATUS->Text = "Timeout Exception @START";
			break;
		}
	}
}
		 //right
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {

	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine("Right.");
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
		 //front
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine("Front.");
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
		 //Down
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine("Down.");
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
		 //left
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine("Left.");
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
		 //back
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
		this->serialPort1->WriteLine("Back.");
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
		 //send
private: System::Void button19_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->serialPort1->IsOpen)
	{
		System::String^ solution1 = msclr::interop::marshal_as<System::String^>(solutionofcube);

		this->serialPort1->WriteLine(solution1);
		cout << "Solution Sent :\n"<< solutionofcube << endl;
	}
	else
		this->label3_STATUS->Text = "Port Not Opened";

}
};
 }
