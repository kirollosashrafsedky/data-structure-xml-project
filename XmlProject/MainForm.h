#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <msclr/marshal_cppstd.h>
#include "XmlDocument.h"
#include "XmlCompression.h"

namespace XmlProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			currentWindowsFormSate = this->WindowState;
			sideMenuOpened = true;
			formDrag = false;
			isSyntaxChecked = false;
			isConsistancyChecked = false;
			xmlTree = new XmlDocument;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblXmlFactory;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnMaximize;
	private: System::Windows::Forms::Button^ btnMinimize;
	private: System::Windows::Forms::Panel^ pnlTitleBar;
	private: System::Windows::Forms::Panel^ sideMenu;
	private: System::Windows::Forms::Panel^ pnlTitleBarControls;
	private: System::Windows::Forms::Panel^ pnlTextArea;
	private: System::Windows::Forms::SplitContainer^ splitContainerMainArea;




	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::Button^ btnMinify;

	private: System::Windows::Forms::Panel^ pnlInputTextBox;
	private: System::Windows::Forms::Panel^ pnlInputRegion;
	private: System::Windows::Forms::Label^ lblInputFile;
	private: System::Windows::Forms::Panel^ pnlOutputTextbox;
	private: System::Windows::Forms::Panel^ pnlOutputRegion;
	private: System::Windows::Forms::Label^ lblOutputfile;
	private: System::Windows::Forms::Panel^ pnlSeparator4;
	private: System::Windows::Forms::Button^ btnSideMenu;
	private: System::Windows::Forms::Panel^ pnlLblNameWrapper;
	private: System::Windows::Forms::Panel^ pnlSideMenuControls;
	private: System::Windows::Forms::Panel^ pnlSeparator1;
	private: System::Windows::Forms::Label^ lblInputFileName;
	private: System::Windows::Forms::Button^ btnLoad;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnDecompress;
	private: System::Windows::Forms::Button^ btnCompress;
	private: System::Windows::Forms::Button^ btnToJson;
	private: System::Windows::Forms::Button^ btnPrettify;
	private: System::Windows::Forms::Button^ btnCheckConsistancy;
	private: System::Windows::Forms::Button^ btnCheckSyntax;
	private: System::Windows::Forms::Panel^ pnlSeparator2;
	private: System::Windows::Forms::Panel^ pnlSeparator3;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::TextBox^ richTextBoxInput;
	private: System::Windows::Forms::TextBox^ richTextBoxOutput;

















	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->lblXmlFactory = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnMaximize = (gcnew System::Windows::Forms::Button());
			this->btnMinimize = (gcnew System::Windows::Forms::Button());
			this->pnlTitleBar = (gcnew System::Windows::Forms::Panel());
			this->btnSideMenu = (gcnew System::Windows::Forms::Button());
			this->pnlTitleBarControls = (gcnew System::Windows::Forms::Panel());
			this->sideMenu = (gcnew System::Windows::Forms::Panel());
			this->pnlSideMenuControls = (gcnew System::Windows::Forms::Panel());
			this->btnDecompress = (gcnew System::Windows::Forms::Button());
			this->btnCompress = (gcnew System::Windows::Forms::Button());
			this->btnToJson = (gcnew System::Windows::Forms::Button());
			this->btnPrettify = (gcnew System::Windows::Forms::Button());
			this->btnCheckConsistancy = (gcnew System::Windows::Forms::Button());
			this->btnCheckSyntax = (gcnew System::Windows::Forms::Button());
			this->pnlSeparator1 = (gcnew System::Windows::Forms::Panel());
			this->btnMinify = (gcnew System::Windows::Forms::Button());
			this->pnlLblNameWrapper = (gcnew System::Windows::Forms::Panel());
			this->pnlSeparator4 = (gcnew System::Windows::Forms::Panel());
			this->pnlTextArea = (gcnew System::Windows::Forms::Panel());
			this->splitContainerMainArea = (gcnew System::Windows::Forms::SplitContainer());
			this->pnlInputTextBox = (gcnew System::Windows::Forms::Panel());
			this->richTextBoxInput = (gcnew System::Windows::Forms::TextBox());
			this->pnlSeparator2 = (gcnew System::Windows::Forms::Panel());
			this->pnlInputRegion = (gcnew System::Windows::Forms::Panel());
			this->lblInputFileName = (gcnew System::Windows::Forms::Label());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->lblInputFile = (gcnew System::Windows::Forms::Label());
			this->pnlOutputTextbox = (gcnew System::Windows::Forms::Panel());
			this->richTextBoxOutput = (gcnew System::Windows::Forms::TextBox());
			this->pnlSeparator3 = (gcnew System::Windows::Forms::Panel());
			this->pnlOutputRegion = (gcnew System::Windows::Forms::Panel());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblOutputfile = (gcnew System::Windows::Forms::Label());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pnlTitleBar->SuspendLayout();
			this->pnlTitleBarControls->SuspendLayout();
			this->sideMenu->SuspendLayout();
			this->pnlSideMenuControls->SuspendLayout();
			this->pnlLblNameWrapper->SuspendLayout();
			this->pnlTextArea->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerMainArea))->BeginInit();
			this->splitContainerMainArea->Panel1->SuspendLayout();
			this->splitContainerMainArea->Panel2->SuspendLayout();
			this->splitContainerMainArea->SuspendLayout();
			this->pnlInputTextBox->SuspendLayout();
			this->pnlInputRegion->SuspendLayout();
			this->pnlOutputTextbox->SuspendLayout();
			this->pnlOutputRegion->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblXmlFactory
			// 
			this->lblXmlFactory->BackColor = System::Drawing::Color::Transparent;
			this->lblXmlFactory->Cursor = System::Windows::Forms::Cursors::Default;
			this->lblXmlFactory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lblXmlFactory->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblXmlFactory->ForeColor = System::Drawing::Color::White;
			this->lblXmlFactory->Location = System::Drawing::Point(0, 0);
			this->lblXmlFactory->Name = L"lblXmlFactory";
			this->lblXmlFactory->Size = System::Drawing::Size(276, 57);
			this->lblXmlFactory->TabIndex = 0;
			this->lblXmlFactory->Text = L"Xml Factory";
			this->lblXmlFactory->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// btnClose
			// 
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnClose->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(228)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->ForeColor = System::Drawing::Color::White;
			this->btnClose->Location = System::Drawing::Point(109, 0);
			this->btnClose->Margin = System::Windows::Forms::Padding(0);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(52, 46);
			this->btnClose->TabIndex = 3;
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MainForm::btnClose_Click);
			// 
			// btnMaximize
			// 
			this->btnMaximize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMaximize.BackgroundImage")));
			this->btnMaximize->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnMaximize->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMaximize->FlatAppearance->BorderSize = 0;
			this->btnMaximize->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnMaximize->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnMaximize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMaximize->ForeColor = System::Drawing::Color::Transparent;
			this->btnMaximize->Location = System::Drawing::Point(52, 0);
			this->btnMaximize->Margin = System::Windows::Forms::Padding(0);
			this->btnMaximize->Name = L"btnMaximize";
			this->btnMaximize->Size = System::Drawing::Size(52, 46);
			this->btnMaximize->TabIndex = 4;
			this->btnMaximize->UseVisualStyleBackColor = true;
			this->btnMaximize->Click += gcnew System::EventHandler(this, &MainForm::btnMaximize_Click);
			// 
			// btnMinimize
			// 
			this->btnMinimize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMinimize.BackgroundImage")));
			this->btnMinimize->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnMinimize->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMinimize->FlatAppearance->BorderSize = 0;
			this->btnMinimize->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnMinimize->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnMinimize->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMinimize->ForeColor = System::Drawing::Color::Transparent;
			this->btnMinimize->Location = System::Drawing::Point(0, 0);
			this->btnMinimize->Margin = System::Windows::Forms::Padding(0);
			this->btnMinimize->Name = L"btnMinimize";
			this->btnMinimize->Size = System::Drawing::Size(52, 46);
			this->btnMinimize->TabIndex = 5;
			this->btnMinimize->Tag = L"";
			this->btnMinimize->UseVisualStyleBackColor = true;
			this->btnMinimize->Click += gcnew System::EventHandler(this, &MainForm::btnMinimize_Click);
			// 
			// pnlTitleBar
			// 
			this->pnlTitleBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(13)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->pnlTitleBar->Controls->Add(this->btnSideMenu);
			this->pnlTitleBar->Controls->Add(this->pnlTitleBarControls);
			this->pnlTitleBar->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTitleBar->Location = System::Drawing::Point(0, 0);
			this->pnlTitleBar->Name = L"pnlTitleBar";
			this->pnlTitleBar->Size = System::Drawing::Size(1159, 46);
			this->pnlTitleBar->TabIndex = 6;
			this->pnlTitleBar->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pnlTitleBar_MouseDown);
			this->pnlTitleBar->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pnlTitleBar_MouseMove);
			this->pnlTitleBar->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::pnlTitleBar_MouseUp);
			// 
			// btnSideMenu
			// 
			this->btnSideMenu->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSideMenu.BackgroundImage")));
			this->btnSideMenu->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnSideMenu->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSideMenu->FlatAppearance->BorderSize = 0;
			this->btnSideMenu->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnSideMenu->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnSideMenu->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSideMenu->ForeColor = System::Drawing::Color::Transparent;
			this->btnSideMenu->Location = System::Drawing::Point(0, 0);
			this->btnSideMenu->Margin = System::Windows::Forms::Padding(0);
			this->btnSideMenu->Name = L"btnSideMenu";
			this->btnSideMenu->Size = System::Drawing::Size(52, 46);
			this->btnSideMenu->TabIndex = 6;
			this->btnSideMenu->Tag = L"";
			this->btnSideMenu->UseVisualStyleBackColor = true;
			this->btnSideMenu->Click += gcnew System::EventHandler(this, &MainForm::btnSideMenu_Click);
			// 
			// pnlTitleBarControls
			// 
			this->pnlTitleBarControls->BackColor = System::Drawing::Color::Transparent;
			this->pnlTitleBarControls->Controls->Add(this->btnMaximize);
			this->pnlTitleBarControls->Controls->Add(this->btnClose);
			this->pnlTitleBarControls->Controls->Add(this->btnMinimize);
			this->pnlTitleBarControls->Dock = System::Windows::Forms::DockStyle::Right;
			this->pnlTitleBarControls->Location = System::Drawing::Point(998, 0);
			this->pnlTitleBarControls->Margin = System::Windows::Forms::Padding(0);
			this->pnlTitleBarControls->Name = L"pnlTitleBarControls";
			this->pnlTitleBarControls->Size = System::Drawing::Size(161, 46);
			this->pnlTitleBarControls->TabIndex = 8;
			// 
			// sideMenu
			// 
			this->sideMenu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->sideMenu->Controls->Add(this->pnlSideMenuControls);
			this->sideMenu->Controls->Add(this->pnlLblNameWrapper);
			this->sideMenu->Controls->Add(this->pnlSeparator4);
			this->sideMenu->Dock = System::Windows::Forms::DockStyle::Left;
			this->sideMenu->Location = System::Drawing::Point(0, 46);
			this->sideMenu->Name = L"sideMenu";
			this->sideMenu->Size = System::Drawing::Size(276, 687);
			this->sideMenu->TabIndex = 7;
			// 
			// pnlSideMenuControls
			// 
			this->pnlSideMenuControls->AutoScroll = true;
			this->pnlSideMenuControls->Controls->Add(this->btnDecompress);
			this->pnlSideMenuControls->Controls->Add(this->btnCompress);
			this->pnlSideMenuControls->Controls->Add(this->btnToJson);
			this->pnlSideMenuControls->Controls->Add(this->btnPrettify);
			this->pnlSideMenuControls->Controls->Add(this->btnCheckConsistancy);
			this->pnlSideMenuControls->Controls->Add(this->btnCheckSyntax);
			this->pnlSideMenuControls->Controls->Add(this->pnlSeparator1);
			this->pnlSideMenuControls->Controls->Add(this->btnMinify);
			this->pnlSideMenuControls->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlSideMenuControls->Location = System::Drawing::Point(0, 59);
			this->pnlSideMenuControls->Name = L"pnlSideMenuControls";
			this->pnlSideMenuControls->Size = System::Drawing::Size(276, 628);
			this->pnlSideMenuControls->TabIndex = 5;
			// 
			// btnDecompress
			// 
			this->btnDecompress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnDecompress->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDecompress->FlatAppearance->BorderSize = 0;
			this->btnDecompress->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnDecompress->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnDecompress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDecompress->ForeColor = System::Drawing::Color::White;
			this->btnDecompress->Location = System::Drawing::Point(0, 455);
			this->btnDecompress->Margin = System::Windows::Forms::Padding(0);
			this->btnDecompress->Name = L"btnDecompress";
			this->btnDecompress->Size = System::Drawing::Size(276, 60);
			this->btnDecompress->TabIndex = 10;
			this->btnDecompress->Text = L"De-compress File";
			this->btnDecompress->UseVisualStyleBackColor = false;
			this->btnDecompress->Click += gcnew System::EventHandler(this, &MainForm::btnDecompress_Click);
			// 
			// btnCompress
			// 
			this->btnCompress->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnCompress->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCompress->FlatAppearance->BorderSize = 0;
			this->btnCompress->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCompress->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCompress->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCompress->ForeColor = System::Drawing::Color::White;
			this->btnCompress->Location = System::Drawing::Point(0, 385);
			this->btnCompress->Margin = System::Windows::Forms::Padding(0);
			this->btnCompress->Name = L"btnCompress";
			this->btnCompress->Size = System::Drawing::Size(276, 60);
			this->btnCompress->TabIndex = 9;
			this->btnCompress->Text = L"Compress File";
			this->btnCompress->UseVisualStyleBackColor = false;
			this->btnCompress->Click += gcnew System::EventHandler(this, &MainForm::btnCompress_Click);
			// 
			// btnToJson
			// 
			this->btnToJson->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnToJson->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnToJson->FlatAppearance->BorderSize = 0;
			this->btnToJson->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnToJson->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnToJson->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnToJson->ForeColor = System::Drawing::Color::White;
			this->btnToJson->Location = System::Drawing::Point(0, 315);
			this->btnToJson->Margin = System::Windows::Forms::Padding(0);
			this->btnToJson->Name = L"btnToJson";
			this->btnToJson->Size = System::Drawing::Size(276, 60);
			this->btnToJson->TabIndex = 8;
			this->btnToJson->Text = L"Convert to JSON";
			this->btnToJson->UseVisualStyleBackColor = false;
			this->btnToJson->Click += gcnew System::EventHandler(this, &MainForm::btnToJson_Click);
			// 
			// btnPrettify
			// 
			this->btnPrettify->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnPrettify->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnPrettify->FlatAppearance->BorderSize = 0;
			this->btnPrettify->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnPrettify->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnPrettify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPrettify->ForeColor = System::Drawing::Color::White;
			this->btnPrettify->Location = System::Drawing::Point(0, 245);
			this->btnPrettify->Margin = System::Windows::Forms::Padding(0);
			this->btnPrettify->Name = L"btnPrettify";
			this->btnPrettify->Size = System::Drawing::Size(276, 60);
			this->btnPrettify->TabIndex = 7;
			this->btnPrettify->Text = L"Prettify";
			this->btnPrettify->UseVisualStyleBackColor = false;
			this->btnPrettify->Click += gcnew System::EventHandler(this, &MainForm::btnPrettify_Click);
			// 
			// btnCheckConsistancy
			// 
			this->btnCheckConsistancy->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnCheckConsistancy->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCheckConsistancy->FlatAppearance->BorderSize = 0;
			this->btnCheckConsistancy->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCheckConsistancy->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCheckConsistancy->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckConsistancy->ForeColor = System::Drawing::Color::White;
			this->btnCheckConsistancy->Location = System::Drawing::Point(0, 105);
			this->btnCheckConsistancy->Margin = System::Windows::Forms::Padding(0);
			this->btnCheckConsistancy->Name = L"btnCheckConsistancy";
			this->btnCheckConsistancy->Size = System::Drawing::Size(276, 60);
			this->btnCheckConsistancy->TabIndex = 6;
			this->btnCheckConsistancy->Text = L"Check Constistancy";
			this->btnCheckConsistancy->UseVisualStyleBackColor = false;
			this->btnCheckConsistancy->Click += gcnew System::EventHandler(this, &MainForm::btnCheckConsistancy_Click);
			// 
			// btnCheckSyntax
			// 
			this->btnCheckSyntax->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnCheckSyntax->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnCheckSyntax->FlatAppearance->BorderSize = 0;
			this->btnCheckSyntax->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCheckSyntax->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnCheckSyntax->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCheckSyntax->ForeColor = System::Drawing::Color::White;
			this->btnCheckSyntax->Location = System::Drawing::Point(0, 35);
			this->btnCheckSyntax->Margin = System::Windows::Forms::Padding(0);
			this->btnCheckSyntax->Name = L"btnCheckSyntax";
			this->btnCheckSyntax->Size = System::Drawing::Size(276, 60);
			this->btnCheckSyntax->TabIndex = 5;
			this->btnCheckSyntax->Text = L"Check Syntax";
			this->btnCheckSyntax->UseVisualStyleBackColor = false;
			this->btnCheckSyntax->Click += gcnew System::EventHandler(this, &MainForm::btnCheckSyntax_Click);
			// 
			// pnlSeparator1
			// 
			this->pnlSeparator1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->pnlSeparator1->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSeparator1->Location = System::Drawing::Point(0, 0);
			this->pnlSeparator1->Name = L"pnlSeparator1";
			this->pnlSeparator1->Size = System::Drawing::Size(276, 2);
			this->pnlSeparator1->TabIndex = 4;
			// 
			// btnMinify
			// 
			this->btnMinify->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnMinify->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnMinify->FlatAppearance->BorderSize = 0;
			this->btnMinify->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnMinify->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(13)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnMinify->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMinify->ForeColor = System::Drawing::Color::White;
			this->btnMinify->Location = System::Drawing::Point(0, 175);
			this->btnMinify->Margin = System::Windows::Forms::Padding(0);
			this->btnMinify->Name = L"btnMinify";
			this->btnMinify->Size = System::Drawing::Size(276, 60);
			this->btnMinify->TabIndex = 1;
			this->btnMinify->Text = L"Minify Xml";
			this->btnMinify->UseVisualStyleBackColor = false;
			this->btnMinify->Click += gcnew System::EventHandler(this, &MainForm::btnMinify_Click);
			// 
			// pnlLblNameWrapper
			// 
			this->pnlLblNameWrapper->Controls->Add(this->lblXmlFactory);
			this->pnlLblNameWrapper->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlLblNameWrapper->Location = System::Drawing::Point(0, 2);
			this->pnlLblNameWrapper->Name = L"pnlLblNameWrapper";
			this->pnlLblNameWrapper->Size = System::Drawing::Size(276, 57);
			this->pnlLblNameWrapper->TabIndex = 4;
			// 
			// pnlSeparator4
			// 
			this->pnlSeparator4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->pnlSeparator4->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSeparator4->Location = System::Drawing::Point(0, 0);
			this->pnlSeparator4->Name = L"pnlSeparator4";
			this->pnlSeparator4->Size = System::Drawing::Size(276, 2);
			this->pnlSeparator4->TabIndex = 3;
			// 
			// pnlTextArea
			// 
			this->pnlTextArea->Controls->Add(this->splitContainerMainArea);
			this->pnlTextArea->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlTextArea->Location = System::Drawing::Point(276, 46);
			this->pnlTextArea->Name = L"pnlTextArea";
			this->pnlTextArea->Size = System::Drawing::Size(883, 687);
			this->pnlTextArea->TabIndex = 8;
			// 
			// splitContainerMainArea
			// 
			this->splitContainerMainArea->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)), static_cast<System::Int32>(static_cast<System::Byte>(63)));
			this->splitContainerMainArea->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainerMainArea->Location = System::Drawing::Point(0, 0);
			this->splitContainerMainArea->Name = L"splitContainerMainArea";
			// 
			// splitContainerMainArea.Panel1
			// 
			this->splitContainerMainArea->Panel1->BackColor = System::Drawing::Color::White;
			this->splitContainerMainArea->Panel1->Controls->Add(this->pnlInputTextBox);
			this->splitContainerMainArea->Panel1->Controls->Add(this->pnlInputRegion);
			this->splitContainerMainArea->Panel1MinSize = 300;
			// 
			// splitContainerMainArea.Panel2
			// 
			this->splitContainerMainArea->Panel2->BackColor = System::Drawing::Color::White;
			this->splitContainerMainArea->Panel2->Controls->Add(this->pnlOutputTextbox);
			this->splitContainerMainArea->Panel2->Controls->Add(this->pnlOutputRegion);
			this->splitContainerMainArea->Panel2MinSize = 300;
			this->splitContainerMainArea->Size = System::Drawing::Size(883, 687);
			this->splitContainerMainArea->SplitterDistance = 441;
			this->splitContainerMainArea->TabIndex = 1;
			// 
			// pnlInputTextBox
			// 
			this->pnlInputTextBox->Controls->Add(this->richTextBoxInput);
			this->pnlInputTextBox->Controls->Add(this->pnlSeparator2);
			this->pnlInputTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlInputTextBox->Location = System::Drawing::Point(0, 59);
			this->pnlInputTextBox->Name = L"pnlInputTextBox";
			this->pnlInputTextBox->Size = System::Drawing::Size(441, 628);
			this->pnlInputTextBox->TabIndex = 2;
			// 
			// richTextBoxInput
			// 
			this->richTextBoxInput->BackColor = System::Drawing::Color::White;
			this->richTextBoxInput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxInput->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxInput->Location = System::Drawing::Point(0, 2);
			this->richTextBoxInput->Multiline = true;
			this->richTextBoxInput->Name = L"richTextBoxInput";
			this->richTextBoxInput->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->richTextBoxInput->Size = System::Drawing::Size(441, 626);
			this->richTextBoxInput->TabIndex = 12;
			this->richTextBoxInput->TextChanged += gcnew System::EventHandler(this, &MainForm::richTextBoxInput_TextChanged);
			// 
			// pnlSeparator2
			// 
			this->pnlSeparator2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->pnlSeparator2->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSeparator2->Location = System::Drawing::Point(0, 0);
			this->pnlSeparator2->Name = L"pnlSeparator2";
			this->pnlSeparator2->Size = System::Drawing::Size(441, 2);
			this->pnlSeparator2->TabIndex = 11;
			// 
			// pnlInputRegion
			// 
			this->pnlInputRegion->Controls->Add(this->lblInputFileName);
			this->pnlInputRegion->Controls->Add(this->btnLoad);
			this->pnlInputRegion->Controls->Add(this->lblInputFile);
			this->pnlInputRegion->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlInputRegion->Location = System::Drawing::Point(0, 0);
			this->pnlInputRegion->Name = L"pnlInputRegion";
			this->pnlInputRegion->Size = System::Drawing::Size(441, 59);
			this->pnlInputRegion->TabIndex = 1;
			// 
			// lblInputFileName
			// 
			this->lblInputFileName->AutoSize = true;
			this->lblInputFileName->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInputFileName->Location = System::Drawing::Point(3, 33);
			this->lblInputFileName->Name = L"lblInputFileName";
			this->lblInputFileName->Size = System::Drawing::Size(0, 20);
			this->lblInputFileName->TabIndex = 6;
			// 
			// btnLoad
			// 
			this->btnLoad->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnLoad->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLoad->Dock = System::Windows::Forms::DockStyle::Right;
			this->btnLoad->FlatAppearance->BorderSize = 0;
			this->btnLoad->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnLoad->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnLoad->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLoad->ForeColor = System::Drawing::Color::White;
			this->btnLoad->Location = System::Drawing::Point(311, 0);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(130, 59);
			this->btnLoad->TabIndex = 5;
			this->btnLoad->Text = L"Load File";
			this->btnLoad->UseVisualStyleBackColor = false;
			this->btnLoad->Click += gcnew System::EventHandler(this, &MainForm::btnLoad_Click);
			// 
			// lblInputFile
			// 
			this->lblInputFile->AutoSize = true;
			this->lblInputFile->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblInputFile->Location = System::Drawing::Point(3, 2);
			this->lblInputFile->Name = L"lblInputFile";
			this->lblInputFile->Size = System::Drawing::Size(120, 27);
			this->lblInputFile->TabIndex = 0;
			this->lblInputFile->Text = L"Input File";
			// 
			// pnlOutputTextbox
			// 
			this->pnlOutputTextbox->Controls->Add(this->richTextBoxOutput);
			this->pnlOutputTextbox->Controls->Add(this->pnlSeparator3);
			this->pnlOutputTextbox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlOutputTextbox->Location = System::Drawing::Point(0, 59);
			this->pnlOutputTextbox->Name = L"pnlOutputTextbox";
			this->pnlOutputTextbox->Size = System::Drawing::Size(438, 628);
			this->pnlOutputTextbox->TabIndex = 1;
			// 
			// richTextBoxOutput
			// 
			this->richTextBoxOutput->BackColor = System::Drawing::Color::White;
			this->richTextBoxOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBoxOutput->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBoxOutput->Location = System::Drawing::Point(0, 2);
			this->richTextBoxOutput->Multiline = true;
			this->richTextBoxOutput->Name = L"richTextBoxOutput";
			this->richTextBoxOutput->ReadOnly = true;
			this->richTextBoxOutput->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->richTextBoxOutput->Size = System::Drawing::Size(438, 626);
			this->richTextBoxOutput->TabIndex = 13;
			this->richTextBoxOutput->WordWrap = false;
			// 
			// pnlSeparator3
			// 
			this->pnlSeparator3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(74)), static_cast<System::Int32>(static_cast<System::Byte>(27)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->pnlSeparator3->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlSeparator3->Location = System::Drawing::Point(0, 0);
			this->pnlSeparator3->Name = L"pnlSeparator3";
			this->pnlSeparator3->Size = System::Drawing::Size(438, 2);
			this->pnlSeparator3->TabIndex = 12;
			// 
			// pnlOutputRegion
			// 
			this->pnlOutputRegion->Controls->Add(this->btnSave);
			this->pnlOutputRegion->Controls->Add(this->lblOutputfile);
			this->pnlOutputRegion->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlOutputRegion->Location = System::Drawing::Point(0, 0);
			this->pnlOutputRegion->Name = L"pnlOutputRegion";
			this->pnlOutputRegion->Size = System::Drawing::Size(438, 59);
			this->pnlOutputRegion->TabIndex = 0;
			// 
			// btnSave
			// 
			this->btnSave->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(63)), static_cast<System::Int32>(static_cast<System::Byte>(14)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->btnSave->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSave->Dock = System::Windows::Forms::DockStyle::Right;
			this->btnSave->FlatAppearance->BorderSize = 0;
			this->btnSave->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnSave->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(83)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->btnSave->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSave->ForeColor = System::Drawing::Color::White;
			this->btnSave->Location = System::Drawing::Point(308, 0);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(130, 59);
			this->btnSave->TabIndex = 6;
			this->btnSave->Text = L"Save File";
			this->btnSave->UseVisualStyleBackColor = false;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// lblOutputfile
			// 
			this->lblOutputfile->AutoSize = true;
			this->lblOutputfile->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblOutputfile->Location = System::Drawing::Point(8, 6);
			this->lblOutputfile->Name = L"lblOutputfile";
			this->lblOutputfile->Size = System::Drawing::Size(140, 27);
			this->lblOutputfile->TabIndex = 1;
			this->lblOutputfile->Text = L"Output File";
			// 
			// openFileDialog
			// 
			this->openFileDialog->AddExtension = false;
			this->openFileDialog->DefaultExt = L"xml";
			this->openFileDialog->FileName = L"openFileDialog";
			this->openFileDialog->Filter = L"Xml files (*.xml)|*.xml|Compressed Xml (*.cxml)|*.cxml";
			this->openFileDialog->ShowHelp = true;
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->Filter = L"Xml file|*.xml";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1159, 733);
			this->Controls->Add(this->pnlTextArea);
			this->Controls->Add(this->sideMenu);
			this->Controls->Add(this->pnlTitleBar);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Montserrat Medium", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MinimumSize = System::Drawing::Size(600, 400);
			this->Name = L"MainForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Xml Project";
			this->Resize += gcnew System::EventHandler(this, &MainForm::MainForm_Resize);
			this->pnlTitleBar->ResumeLayout(false);
			this->pnlTitleBarControls->ResumeLayout(false);
			this->sideMenu->ResumeLayout(false);
			this->pnlSideMenuControls->ResumeLayout(false);
			this->pnlLblNameWrapper->ResumeLayout(false);
			this->pnlTextArea->ResumeLayout(false);
			this->splitContainerMainArea->Panel1->ResumeLayout(false);
			this->splitContainerMainArea->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainerMainArea))->EndInit();
			this->splitContainerMainArea->ResumeLayout(false);
			this->pnlInputTextBox->ResumeLayout(false);
			this->pnlInputTextBox->PerformLayout();
			this->pnlInputRegion->ResumeLayout(false);
			this->pnlInputRegion->PerformLayout();
			this->pnlOutputTextbox->ResumeLayout(false);
			this->pnlOutputTextbox->PerformLayout();
			this->pnlOutputRegion->ResumeLayout(false);
			this->pnlOutputRegion->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private:
	bool sideMenuOpened;
	FormWindowState currentWindowsFormSate;

private: 
	System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();	
	}

private: 
	System::Void btnMaximize_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->currentWindowsFormSate == FormWindowState::Normal)
		{
			this->WindowState = FormWindowState::Maximized;
		}
		else
		{
			this->WindowState = FormWindowState::Normal;
		}
	}

private: 
	System::Void btnMinimize_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = FormWindowState::Minimized;
	}

private: 
	System::Void MainForm_Resize(System::Object^ sender, System::EventArgs^ e) {
		currentWindowsFormSate  = this->WindowState;
		if (this->Width < 850)
		{
			this->sideMenu->Width = 0;
			sideMenuOpened = false;
		}
	}

private: 
	System::Void btnSideMenu_Click(System::Object^ sender, System::EventArgs^ e) {
		if (sideMenuOpened)
		{
			this->sideMenu->Width = 0;
			sideMenuOpened = false;
		}
		else
		{
			this->sideMenu->Width = 276;
			sideMenuOpened = true;
		}
	}

private:
	bool formDrag;
	int mouseX;
	int mouseY;

private:
	System::Void pnlTitleBar_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		formDrag = true;
		mouseX = Cursor->Position.X - this->Left;
		mouseY = Cursor->Position.Y - this->Top;
	}

private:
	System::Void pnlTitleBar_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		formDrag = false;
	}

private:
	System::Void pnlTitleBar_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (formDrag)
		{
			this->Left = Cursor->Position.X - mouseX;
			this->Top = Cursor->Position.Y - mouseY;
		}
	}

private: 
	System::Void btnLoad_Click(System::Object^ sender, System::EventArgs^ e) {
		Windows::Forms::DialogResult result = this->openFileDialog->ShowDialog();
		if (result == Windows::Forms::DialogResult::OK)
		{
			std::string fileName = msclr::interop::marshal_as< std::string >(this->openFileDialog->FileName);
			std::ifstream input(fileName, std::ios::binary);
			std::string xml(std::istreambuf_iterator<char>(input), {});
			input.close();

			String^ systemXml;
			if (System::IO::Path::GetExtension(this->openFileDialog->FileName) == ".cxml")
			{
				this->richTextBoxInput->Tag = "cxml";
				char* compressedStrArr = new char[xml.size() + 1];
				std::copy(xml.begin(), xml.end(), compressedStrArr);
				compressedStrArr[xml.size()] = '\0';
				String^ test = gcnew String(compressedStrArr, 0, xml.length());
				test = test->Replace("\0", "<null>");
				systemXml = test;
			}
			else
			{
				this->richTextBoxInput->Tag = "xml";
				systemXml = gcnew String(xml.c_str());
			}


			this->richTextBoxInput->Text = systemXml;
			this->lblInputFileName->Text = System::IO::Path::GetFileName(this->openFileDialog->FileName);
		}
	}

private:
	System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if(String::String::IsNullOrWhiteSpace(this->richTextBoxOutput->Text))
		{
			MessageBox::Show("Empty text", "Error");
			return;
		}
		String^ xmlOutString = this->richTextBoxOutput->Text;

		if (this->richTextBoxOutput->Tag == "json")
		{
			this->saveFileDialog->Filter = "Json files (*.json)|*.json";
		}
		else if(this->richTextBoxOutput->Tag == "cxml")
		{
			this->saveFileDialog->Filter = "Compressed Xml files (*.cxml)|*.cxml";
			xmlOutString = xmlOutString->Replace("<null>", "\0");
		}
		else
		{
			this->saveFileDialog->Filter = "Xml files (*.xml)|*.xml";
		}
		Windows::Forms::DialogResult result = this->saveFileDialog->ShowDialog();
		if (result == Windows::Forms::DialogResult::OK)
		{
			std::string fileName = msclr::interop::marshal_as< std::string >(this->saveFileDialog->FileName);
			std::string xmlOut = msclr::interop::marshal_as< std::string >(xmlOutString);


			std::ofstream CompreesedXmlFile(fileName, std::ios::out | std::ios::binary);
			char* c = new char[xmlOut.size() + 1];
			std::copy(xmlOut.begin(), xmlOut.end(), c);
			c[xmlOut.size()] = '\0';
			CompreesedXmlFile.write(c, xmlOut.size());
			CompreesedXmlFile.close();

			std::string testBinary = "";
			for (int i = 0; i < xmlOut.length(); i++)
			{
			    testBinary += toBinary(xmlOut[i]);
			}
		}
	}

private:
	bool isSyntaxChecked;
	bool isConsistancyChecked;

private:
	System::Void richTextBoxInput_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		isSyntaxChecked = false;
		isConsistancyChecked = false;
	}

private: 
	System::Void btnCheckSyntax_Click(System::Object^ sender, System::EventArgs^ e) {
		checkSyntax(true);
	}

private:
	System::Void btnCheckConsistancy_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isSyntaxChecked)
		{
			checkSyntax(false);
			if (!isSyntaxChecked)
				return;
		}
		checkConsistancy(true);
	}

private: 
	System::Void btnMinify_Click(System::Object^ sender, System::EventArgs^ e) {
		if(!isSyntaxChecked)
		{
			checkSyntax(false);
			if (!isSyntaxChecked)
				return;
		}
		if (!isConsistancyChecked)
		{
			checkConsistancy(false);
			if (!isConsistancyChecked)
				return;
		}
		minify();
	}

private: 
	System::Void btnPrettify_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isSyntaxChecked)
		{
			checkSyntax(false);
			if (!isSyntaxChecked)
				return;
		}
		if (!isConsistancyChecked)
		{
			checkConsistancy(false);
			if (!isConsistancyChecked)
				return;
		}
		prettify();
	}

private: 
	System::Void btnToJson_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!isSyntaxChecked)
		{
			checkSyntax(false);
			if (!isSyntaxChecked)
				return;
		}
		if (!isConsistancyChecked)
		{
			checkConsistancy(false);
			if (!isConsistancyChecked)
				return;
		}
		toJson();
	}

private: 
	System::Void btnCompress_Click(System::Object^ sender, System::EventArgs^ e) {		
		if (String::IsNullOrWhiteSpace(this->richTextBoxInput->Text))
		{
			MessageBox::Show("Empty text", "Error");
			return;
		}
		compress();
	}

private:
	System::Void btnDecompress_Click(System::Object^ sender, System::EventArgs^ e) {
		if (String::IsNullOrWhiteSpace(this->richTextBoxInput->Text))
		{
			MessageBox::Show("Empty text", "Error");
			return;
		}
		decompress();
	}

private:
	void checkSyntax(bool showMsg);
	void checkConsistancy(bool showMsg);
	void minify(void);
	void prettify(void);
	void toJson(void);
	void compress(void);
	void decompress(void);

private:
	XmlDocument *xmlTree;

};
}