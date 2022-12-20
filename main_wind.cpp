//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_wind.h"
#include "core.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainWnd *mainWnd;

char* methodName;
bool  CycleBreak=false;
double buffer;
core Core;
//---------------------------------------------------------------------------
__fastcall TmainWnd::TmainWnd(TComponent* Owner): TForm(Owner)
{
        buttonReset->Enabled = false;
        buttonStart->Enabled = false;
        buttonStop->Enabled = false;
        lEditU1->Enabled = false;
        lEditU2->Enabled = false;
        lEditDx->Enabled = false;
        lEditDt->Enabled = false;
        lEditA->Enabled = false;
        radioBtnBW->Enabled = false;
        radioGroupMethods->Enabled = true;
        labelIterationClock->Enabled=false;
        labelIterationClock->Caption=0;
}
//---------------------------------------------------------------------------
void __fastcall TmainWnd::radioGroupMethodsClick(TObject *Sender)
{
        buttonReset->Enabled = true;
        buttonStart->Enabled = false;
        buttonStop->Enabled = false;
        lEditU1->Enabled = true;
        lEditU2->Enabled = true;
        lEditDx->Enabled = true;
        lEditDt->Enabled = true;
        lEditA->Enabled = true;
        radioBtnBW->Enabled = true;
        radioGroupMethods->Enabled = true;
        labelIterationClock->Enabled=false;
        if (radioGroupMethods->ItemIndex==0)
        {
                methodName="expl";
        }
        if (radioGroupMethods->ItemIndex==1)
        {
                methodName="impl";
        }
}
//---------------------------------------------------------------------------
void __fastcall TmainWnd::buttonResetClick(TObject *Sender)
{
        if(lEditA->Text==""||lEditDt->Text==""||lEditDx->Text==""||lEditU2->Text==""||lEditU1->Text=="")
        {
        	ShowMessage("Some value was not set-up!");
        	return ;
        }
        if(radioBtnBW->Checked==false && lEditU1->Text.ToDouble()==0 && lEditU2->Text.ToDouble()==0)
        {
        	ShowMessage("You will see no action at this preset.\nI'll change them, nothing personal.");
                radioBtnBW->Checked=true;
        }
        buttonReset->Enabled = true;
        buttonStart->Enabled = true;
        buttonStop->Enabled = false;
        lEditU1->Enabled = true;
        lEditU2->Enabled = true;
        lEditDx->Enabled = true;
        lEditDt->Enabled = true;
        lEditA->Enabled = true;
        radioBtnBW->Enabled = true;
        radioGroupMethods->Enabled = true;
        labelIterationClock->Enabled=false;
        labelIterationClock->Caption=0;
        Series1->Clear();
        Core.makeReset();
        buffer=lEditU1->Text.ToDouble();
        if(lEditU1->Text.ToDouble()>=lEditU2->Text.ToDouble())
        {
                buffer=lEditU1->Text.ToDouble();
        }
        else
        {
                buffer=lEditU2->Text.ToDouble();
        }
        if(lEditU1->Text.ToDouble()==0 && lEditU2->Text.ToDouble()==0)
        {
                buffer=1;
        }
        buffer+=buffer;
        mainChart->LeftAxis->Maximum=buffer;
        mainChart->LeftAxis->Minimum=-buffer;
        Core.setValue(lEditU1->Text.ToDouble(),"u1");
        Core.setValue(lEditU2->Text.ToDouble(),"u2");
        Core.setValue(lEditDx->Text.ToDouble(),"dx");
        Core.setValue(lEditDt->Text.ToDouble(),"dt");
        Core.setValue(lEditA->Text.ToDouble(),"a");
        Core.computeLambda(methodName);
        if(radioBtnBW->Checked)
        {
                Core.computeBasicWave();
        }
        Series1->AddArray(Core.layerLower_,200);

}
//---------------------------------------------------------------------------



void __fastcall TmainWnd::buttonStartClick(TObject *Sender)
{
        buttonReset->Enabled = false;
        buttonStart->Enabled = false;
        buttonStop->Enabled = true;
        lEditU1->Enabled = false;
        lEditU2->Enabled = false;
        lEditDx->Enabled = false;
        lEditDt->Enabled = false;
        lEditA->Enabled = false;
        radioBtnBW->Enabled = false;
        radioGroupMethods->Enabled = false;
        labelIterationClock->Enabled=true;
        if(CycleBreak==true)
        {
                CycleBreak=false;
        }
        while(CycleBreak==false)
        {

                Core.computeAndMoveLayer(methodName);
                labelIterationClock->Caption=Core.showValue("clock");
                Series1->Clear();
                Series1->AddArray(Core.layerLower_,200);
                Application->ProcessMessages();
                if(CycleBreak==true)
                {
                        break;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TmainWnd::buttonStopClick(TObject *Sender)
{
        buttonReset->Enabled = true;
        buttonStart->Enabled = true;
        buttonStop->Enabled = false;
        lEditU1->Enabled = true;
        lEditU2->Enabled = true;
        lEditDx->Enabled = true;
        lEditDt->Enabled = true;
        lEditA->Enabled = true;
        radioBtnBW->Enabled = true;
        radioGroupMethods->Enabled = true;
        labelIterationClock->Enabled=false;
        if(CycleBreak==false)
        {
                CycleBreak=true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TmainWnd::FormClose(TObject *Sender, TCloseAction &Action)
{
        if(CycleBreak==false)
        {
                CycleBreak=true;
        }
}
//---------------------------------------------------------------------------





void __fastcall TmainWnd::developerMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        developer->Visible=false;        
}
//---------------------------------------------------------------------------

