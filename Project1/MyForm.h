#pragma once

#include <string>

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:

	private:
		/// <summary>
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 45);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 21;
			this->dataGridView1->Size = System::Drawing::Size(541, 239);
			this->dataGridView1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(581, 334);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:

		DataGridViewButtonColumn^ CreateButtonColumn() {
			auto dgvButton = gcnew DataGridViewButtonColumn();
			dgvButton->Text = "Save";
			dgvButton->UseColumnTextForButtonValue = true;
			return dgvButton;
		}

		DataGridViewImageColumn^ CreateImageColumn(
			std::string name,
			std::string imageFileName) {
			//DataGridViewImageColumn�̍쐬
			auto dgvImgCol = gcnew DataGridViewImageColumn();
			//��̖��O��ݒ�
			dgvImgCol->Name = gcnew String(name.c_str());
			//Icon�^�ł͂Ȃ��AImage�^�̃f�[�^��\������
			//�f�t�H���g��False�Ȃ̂ŁA�ύX����K�v�͂Ȃ�
			dgvImgCol->ValuesAreIcons = false;
			//�l�̐ݒ肳��Ă��Ȃ��Z���ɕ\������C���[�W��ݒ肷��
			dgvImgCol->Image = nullptr;
				//gcnew Bitmap(gcnew String(imageFileName.c_str()));
			//�C���[�W���c���̔䗦���ێ����Ċg��A�k���\������
			dgvImgCol->ImageLayout = DataGridViewImageCellLayout::Zoom;
			//�C���[�W�̐���
			//�Z�����N���b�v�{�[�h�ɃR�s�[�������Ɏg�p�����
			dgvImgCol->Description = "�C���[�W";
			return dgvImgCol;
		}

		private: void SetupDataGridView() {
			dataGridView1->ColumnCount = 1;
			dataGridView1->Columns[0]->Name = "idx";
			dataGridView1->AllowUserToAddRows = false;

			//DataGridViewImageColumn�̍쐬
			auto column1 = CreateImageColumn("Image1",
				"Images\\dambo3.jpg");
			dataGridView1->Columns->Add(column1);

			auto column2 = CreateImageColumn("Image2",
				"Images\\dambo3.jpg");
			dataGridView1->Columns->Add(column2);

			auto dgvButton = CreateButtonColumn();
			dataGridView1->Columns->Add(dgvButton);

			//"Image"��̈�ԏ�̃Z���̃C���[�W��ύX����
			auto tmp = dataGridView1->Rows->Count;
			dataGridView1->Rows->Add(1);
			dataGridView1["Image1", 0]->Value = gcnew Bitmap(
				"./Images\\pc-wallpaper-11.jpg");

			dataGridView1["Image2", 0]->Value = gcnew Bitmap(
				"./Images\\dambo3.jpg");
			dataGridView1->Rows->Add(1);
			tmp = dataGridView1->Rows->Count;
			dataGridView1["Image1", 1]->Value = gcnew Bitmap(
				"./Images\\dambo3.jpg");

			dataGridView1["Image2", 1]->Value = gcnew Bitmap(
				"./Images\\pc-wallpaper-11.jpg");
		}

		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			SetupDataGridView();
		}
	};
}
