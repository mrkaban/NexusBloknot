//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <Clipbrd.hpp>
#include <IniFiles.hpp>
#pragma hdrstop

#include "BlMain.h"
#include "BlFormula.h"
#include "blAbout.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RxRichEd"
#pragma resource "*.dfm"
TBlock *Block;


AnsiString FilesName[4];
TOleContainer *Formula[4];


// ���� ��������  "Ambiduity between 'CHARFORMAT2A' and 'RichEdit::CHARFORMAT2A'"
//�� �������� CHARFORMAT2A ��   RichEdit::CHARFORMAT2A

//---------------------------------------------------------------------------
__fastcall TBlock::TBlock(TComponent* Owner)
  : TForm(Owner)
{
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditCutClick(TObject *Sender)
{
  Memo->CutToClipboard();   //�������� ���������� � �����
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditCopyClick(TObject *Sender)
{
  Memo->CopyToClipboard();  //�������� ���������� � �����
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditPasteClick(TObject *Sender)
{
  Memo->PasteFromClipboard();    //��������� �� ������
}


//---------------------------------------------------------------------------
void __fastcall TBlock::EditSelectAllClick(TObject *Sender)
{
  Memo->SelectAll();  // �������� ���� �����
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileNewClick(TObject *Sender)  // �������� ������ ����� �
                                                       //�������� ������������� ����������
{
  if (Memo->Modified)                           // ���� ����� �������
   {
    int Res = Application->MessageBox(          // �������� ���������� ����
      "������� ���� �������. ��������� ���������?","�������: ��������������", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // ���� ������ "������" ������������
    if (Res == IDYES) FileSaveClick(Sender);    // ���� ������ "��" �������� ��������� ���������� �����
                                                // ���� ������ "���" ������ �� ������
   }
  if (Memo->Lines->Count > 0) Memo->Clear();    // ���� � ���� "����" ���� ������, �� ������� ��

  SaveDialog->FileName = "";                    //������� ��� �����, ��� � ��� �������� ��������� ������ �����
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileOpenClick(TObject *Sender)  // �������� �����
{

  if (Memo->Modified)                           // ���� ����� �������
   {
    int Res = Application->MessageBox(          // �������� ���������� ����
      "������� ���� �������. ��������� ���������?","�������: ��������������", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // ���� ������ "������" ������������
    if (Res == IDYES) FileSaveClick(0);         // ���� ������ "��" �������� ��������� ���������� �����
                                                // ���� ������ "���" ������ �� ������
   }

  OpenDialog->FileName = "";
  OpenDialog->Title = "�������";                     // ������������� ��� �������
  if (OpenDialog->Execute())                         //�������� ������ ���������� �����
  {
    if (Memo->Lines->Count > 0) Memo->Clear();      // ���� � ���� "����" ���� ������, �� ������� ��
    Memo->Lines->LoadFromFile(OpenDialog->FileName); // ��������� ��������� ����
    SaveDialog->FileName = OpenDialog->FileName;     // ���������� ��� ����� ��� ����������







    int i;

  //�������� "�������" �������� ������
  for (i = 0; i< 4; i++)
    if (FilesName[i] == "<empty>")
   {
    FilesName[i] = OpenDialog->FileName;
    break;
   }


   if (i == 4)
    {
      FilesName[3] = FilesName[2];
      FilesName[2] = FilesName[1];
      FilesName[1] = FilesName[0];
      FilesName[0] = OpenDialog->FileName;
    }

   F1->Caption = FilesName[0];
   F2->Caption = FilesName[1];
   F3->Caption = FilesName[2];
   F4->Caption = FilesName[3];





  }
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FileSaveClick(TObject *Sender)
{
  SaveDialog->Title = "���������";       // ������������� ��� �������
  if (SaveDialog->FileName != "")        // ���� � ��� ���� ��� �����, ��������� ����
   {
    Memo->Lines->SaveToFile(SaveDialog->FileName);
    Memo->Modified = false;  // ������� ���� ��������� �������, ��� ��� ����� �� ���������
   }
   else
    FileSaveAsClick(Sender);      // ���� � ��� ��� ����� ����� (�.�. ���� �����) �������� ���������
                                  // ���������� ��� ������ ������
}



//---------------------------------------------------------------------------
void __fastcall TBlock::FileSaveAsClick(TObject *Sender)
{
  SaveDialog->Title = "��������� ���";       // ������������� ��� �������
  if (SaveDialog->Execute())        // �������� ������ ���������� ����� ��� ����� ������
   {
    Memo->Lines->SaveToFile(SaveDialog->FileName);
    Memo->Modified = false;              // ������� ���� ��������� ������, ��� ��� ����� �� ���������
   }
}


//����� ���� ������ ���������
//---------------------------------------------------------------------------
void __fastcall TBlock::EditUndoClick(TObject *Sender)
{
  SendMessage(Memo->Handle, WM_UNDO, 0, 0);  // �������� ������ ���������
}



//����� ���� "�������"
//---------------------------------------------------------------------------
void __fastcall TBlock::EditWordWrapClick(TObject *Sender)
{
  Memo->WordWrap = !Memo->WordWrap;        // ������ �������� TMemo::WordWrap
  EditWordWrap->Checked = Memo->WordWrap;  //������������� � ���� ������, ����
                                           //� ��� TMemo->WordWrap = true

  if (Memo->WordWrap) Memo->ScrollBars = ssVertical; //���� � ��� ������� �������,
                                // �� ������� ������ ������������ ������ ���������
   else
    Memo->ScrollBars = ssBoth;   // ����� ������� ��� ������ ���������
}


//---------------------------------------------------------------------------
void __fastcall TBlock::PrintButtonClick(TObject *Sender)     //������� ������ ������
{
 if (PrintDialog1->Execute()) Memo->Print(Block->Caption);   //���� ������ �� ��������
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FontDClick(TObject *Sender)      //������� ������ ������ ������
{
 if (FontDialog1->Execute()) Memo->Font = FontDialog1->Font;    //���� ������ �� ������ �����
}


//---------------------------------------------------------------------------
void __fastcall TBlock::OnHint(TObject* Sender)         // ��������� ���������
{
  StatusBar->SimpleText = Application->Hint;
}


//---------------------------------------------------------------------------
void __fastcall TBlock::FormCreate(TObject *Sender)         //�������� �����
{
  Application->OnHint = OnHint;
}



//---------------------------------------------------------------------------
void __fastcall TBlock::F4Click(TObject *Sender)   //�������� ������ �� "�������"
{
  int n;
  if (Sender == F1) n = 0;
  if (Sender == F2) n = 1;
  if (Sender == F3) n = 2;
  if (Sender == F4) n = 3;


 if (FilesName[n] != "<empty>")
 {
 if (Memo->Modified)                           // ���� ����� �������
   {
    int Res = Application->MessageBox(          // �������� ���������� ����
      "������� ���� �������. ��������� ���������?","�������: ��������������", MB_YESNOCANCEL);

    if (Res == IDCANCEL) return;                // ���� ������ "������" ������������
    if (Res == IDYES) FileSaveClick(0);         // ���� ������ "��" �������� ��������� ���������� �����
                                                // ���� ������ "���" ������ �� ������
   }
   Memo->Lines->LoadFromFile(FilesName[n]); //��������� �� �����
   }
}




//---------------------------------------------------------------------------
void __fastcall TBlock::FormActivate(TObject *Sender)     //������������� ���������
{

//��������� ������ ������� ������
TIniFile *RegFile;
  RegFile = new TIniFile(ExtractFilePath(Application->ExeName) + "prog.ini"); //��������� ini ����

  FilesName[0] = RegFile->ReadString("Names", "1", "<empty>");
  FilesName[1] = RegFile->ReadString("Names", "2", "<empty>");
  FilesName[2] = RegFile->ReadString("Names", "3", "<empty>");
  FilesName[3] = RegFile->ReadString("Names", "4", "<empty>");

 RegFile->Free();

   F1->Caption = FilesName[0];
   F2->Caption = FilesName[1];
   F3->Caption = FilesName[2];
   F4->Caption = FilesName[3];




}
//---------------------------------------------------------------------------



void __fastcall TBlock::FormClose(TObject *Sender, TCloseAction &Action)     //����� �� �����
{

//���������� ������� ������
  TIniFile *RegFile;
  RegFile = new TIniFile(ExtractFilePath(Application->ExeName)+ "prog.ini"); //��������� ini ����

  RegFile->WriteString("Names", "1", FilesName[0]);
  RegFile->WriteString("Names", "2", FilesName[1]);
  RegFile->WriteString("Names", "3", FilesName[2]);
  RegFile->WriteString("Names", "4", FilesName[3]);

  RegFile->Free();        
}
//---------------------------------------------------------------------------



void __fastcall TBlock::FormulaButtonClick(TObject *Sender)      //������� �� ������
{
 if (FormulaForm->ShowModal() == mrOk) Memo->PasteFromClipboard();
        
}
//---------------------------------------------------------------------------


void __fastcall TBlock::HelpAboutClick(TObject *Sender)          //�������� ���� "� ���������"
{
AboutBox->ShowModal();        
}
//---------------------------------------------------------------------------

void __fastcall TBlock::FormCloseQuery(TObject *Sender, bool &CanClose)    //�����
{
  if (Memo->Modified)                           // ���� ����� �������
   {
    int Res = Application->MessageBox(          // �������� ���������� ����
      "������� ���� �������. ��������� ���������?", "�������: ��������������", MB_YESNOCANCEL);

    if (Res == IDCANCEL)                        // ���� ������ "������" ������������
     {
       CanClose = false;
       return;
     }
    if (Res == IDYES) FileSaveClick(0);         // ���� ������ "��" �������� ��������� ���������� �����
                                                // ���� ������ "���" ������ �� ������
   }

}
//---------------------------------------------------------------------------

void __fastcall TBlock::FileExitClick(TObject *Sender)   //����� ���� "�����"
{
 Close();        
}
//---------------------------------------------------------------------------

