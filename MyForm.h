#pragma once

namespace webBrowser {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::Button^ btnBack;
	private: System::Windows::Forms::Button^ btnForward;
	private: System::Windows::Forms::TextBox^ txtNavigate;
	protected:


	private: System::Windows::Forms::Button^ btnNavigate;
	private: System::Windows::Forms::WebBrowser^ webBrowser;


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
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->btnForward = (gcnew System::Windows::Forms::Button());
			this->txtNavigate = (gcnew System::Windows::Forms::TextBox());
			this->btnNavigate = (gcnew System::Windows::Forms::Button());
			this->webBrowser = (gcnew System::Windows::Forms::WebBrowser());
			this->SuspendLayout();
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(0, 0);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(31, 30);
			this->btnBack->TabIndex = 0;
			this->btnBack->Text = L"<";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &MyForm::btnBack_Click);
			// 
			// btnForward
			// 
			this->btnForward->Location = System::Drawing::Point(37, 0);
			this->btnForward->Name = L"btnForward";
			this->btnForward->Size = System::Drawing::Size(31, 30);
			this->btnForward->TabIndex = 1;
			this->btnForward->Text = L">";
			this->btnForward->UseVisualStyleBackColor = true;
			this->btnForward->Click += gcnew System::EventHandler(this, &MyForm::btnForward_Click);
			// 
			// txtNavigate
			// 
			this->txtNavigate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtNavigate->Location = System::Drawing::Point(74, 0);
			this->txtNavigate->Name = L"txtNavigate";
			this->txtNavigate->Size = System::Drawing::Size(659, 22);
			this->txtNavigate->TabIndex = 2;
			// 
			// btnNavigate
			// 
			this->btnNavigate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->btnNavigate->Location = System::Drawing::Point(739, 0);
			this->btnNavigate->Name = L"btnNavigate";
			this->btnNavigate->Size = System::Drawing::Size(75, 23);
			this->btnNavigate->TabIndex = 3;
			this->btnNavigate->Text = L"Navigate";
			this->btnNavigate->UseVisualStyleBackColor = true;
			this->btnNavigate->Click += gcnew System::EventHandler(this, &MyForm::btnNavigate_Click);
			// 
			// webBrowser
			// 
			this->webBrowser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->webBrowser->Location = System::Drawing::Point(0, 36);
			this->webBrowser->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser->Name = L"webBrowser";
			this->webBrowser->Size = System::Drawing::Size(814, 407);
			this->webBrowser->TabIndex = 4;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(832, 479);
			this->Controls->Add(this->webBrowser);
			this->Controls->Add(this->btnNavigate);
			this->Controls->Add(this->txtNavigate);
			this->Controls->Add(this->btnForward);
			this->Controls->Add(this->btnBack);
			this->Name = L"MyForm";
			this->Text = L"Not a Web Browser";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		webBrowser->GoBack();
	}
private: System::Void btnForward_Click(System::Object^ sender, System::EventArgs^ e) 
{
	webBrowser->GoForward();
}
private: System::Void btnNavigate_Click(System::Object^ sender, System::EventArgs^ e) 
{
	webBrowser->Navigate(txtNavigate->Text);
}
};
}
