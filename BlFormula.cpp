//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "BlFormula.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormulaForm *FormulaForm;
//---------------------------------------------------------------------------
__fastcall TFormulaForm::TFormulaForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormulaForm::BitBtn1Click(TObject *Sender)
{
OleContainer1->Copy();    //�������� ������� � �����
ModalResult = mrOk;       //���������� ��������� ��� ��� ��
}
//---------------------------------------------------------------------------

void __fastcall TFormulaForm::BitBtn2Click(TObject *Sender)
{
 ModalResult = mrCancel;      //������ ��������������
}
//---------------------------------------------------------------------------


void __fastcall TFormulaForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    OleContainer1->Close();    //��������� ���������
}
//---------------------------------------------------------------------------

void __fastcall TFormulaForm::FormActivate(TObject *Sender)
{
OleContainer1->SetFocus(); //�������� ����� ���������� � ���� ��������� ���
}
//---------------------------------------------------------------------------

