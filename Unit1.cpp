//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include <Math.h>
#include <stdlib.h>
#include <time.h>
#include <sys\types.h>
//---------------------------------------------------------------------------
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
#define FLIP(x)         ((double)random(1000000L) < ((double)(x) * (1000000.)))
//---------------------------------------------------------------------------
TSARS_Form *SARS_Form;
//---------------------------------------------------------------------------
// TSARS_Form(TComponent* Owner): 當初次啟動此表單時，執行此方法
//---------------------------------------------------------------------------
__fastcall TSARS_Form::TSARS_Form(TComponent* Owner) : TForm(Owner)
{
        srand((unsigned)time(NULL)); // 啟動隨機亂數的種子數
}
//---------------------------------------------------------------------------
// Button_ExitClick(TObject *Sender): 當按下「結束按鈕」時，執行此方法
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_ExitClick(TObject *Sender)
{
        Close(); // 離開SARS模擬系統
}
//---------------------------------------------------------------------------
// Form_Create(TObject *send): 初始化TSARS_Form類別中的成員變數與元件
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::FormCreate(TObject *Sender)
{
        initMeasure();
        initVariables();
        initComponents();
}
//---------------------------------------------------------------------------
// initMeasure(void): 初始化TSARS_Form類別中專門用來存放平均數的二維陣列成員變數
//---------------------------------------------------------------------------
void TSARS_Form::initMeasure(void)
{
        for (long i = measure.size = 0; i < MAX_VALUE_SIZE; i++)
                for (long j = 0; j < STATE_SIZE; j++)
                        measure.value1[i][j] = measure.value2[i][j] = 0;
}
//---------------------------------------------------------------------------
// initVariables(void): 初始化TSARS_Form類別中的成員變數
//---------------------------------------------------------------------------
void TSARS_Form::initVariables(void)
{
        for (long i = 0; i < STATE_SIZE; i++)
                oldStatistic[i] = statistic[i] = 0;
        partialView.x = Edit_MaxWorldWidth->Text.ToInt()  / 2;
        partialView.y = Edit_MaxWorldHeight->Text.ToInt() / 2;
        serial = (unsigned)time(NULL);
        infectedByHospital = infectedByNormal = 0;
}
//---------------------------------------------------------------------------
// initComponents(void): 初始化TSARS_Form類別中的元件
//---------------------------------------------------------------------------
void TSARS_Form::initComponents(void)
{
        initLatticeComponent();
        initPartialLatticeComponent();
        initOtherComponents();
}
//---------------------------------------------------------------------------
// initLatticeComponent(void): 初始化TSARS_Form類別中應用於巨觀的的二維棋盤元件
//---------------------------------------------------------------------------
void TSARS_Form::initLatticeComponent(void)
{
        Lattice->Canvas->MoveTo(0, 0);
        Lattice->Canvas->Pen->Color = DEFAULT_COLOR;
        Lattice->Canvas->Brush->Color = DEFAULT_COLOR;
        Lattice->Canvas->Rectangle(0, 0, Lattice->Width, Lattice->Height);
}
//---------------------------------------------------------------------------
// initPartialLatticeComponent(void): 初始化TSARS_Form類別中應用於圍觀的二維棋盤元件
//---------------------------------------------------------------------------
void TSARS_Form::initPartialLatticeComponent(void)
{
        partialLattice->Canvas->MoveTo(0, 0);
        partialLattice->Canvas->Pen->Color = DEFAULT_COLOR;
        partialLattice->Canvas->Brush->Color = DEFAULT_COLOR;
        partialLattice->Canvas->Rectangle(0, 0, Lattice->Width, Lattice->Height);
}
//---------------------------------------------------------------------------
// initOtherComponents(void): 初始化TSARS_Form類別中的各種統計圖表元件
//---------------------------------------------------------------------------
void TSARS_Form::initOtherComponents(void)
{
        for (long i = 0; i < TotalCase_Chart->SeriesCount(); TotalCase_Chart->Series[i++]->Clear());
        for (long i = 0; i < Case_Chart->SeriesCount(); Case_Chart->Series[i++]->Clear());
        for (long i = 0; i < IsolatedCase_Chart->SeriesCount(); IsolatedCase_Chart->Series[i++]->Clear());
        for (long i = 0; i < InfectedCase_Chart->SeriesCount(); InfectedCase_Chart->Series[i++]->Clear());
        for (long i = 0; i < TotalQuarantinedCase_Chart->SeriesCount(); TotalQuarantinedCase_Chart->Series[i++]->Clear());
        for (long i = 0; i < QuarantinedCase_Chart->SeriesCount(); QuarantinedCase_Chart->Series[i++]->Clear());
        ProgressBar->Max = Edit_MaxPopulation->Text.ToInt();
        disableComponents(); // 除了「初始化」按鈕外，禁止使用者按其他的按鈕
}
//---------------------------------------------------------------------------
// initOutputFiles(void): 初始化每次模擬時需要的日誌檔
//---------------------------------------------------------------------------
bool TSARS_Form::initOutputFiles(void)
{
        if (mkdir(AnsiString(serial).c_str())) {
                ShowMessage(AnsiString("Unable to create directory\n"));
                return false;
        }
        if (chdir(AnsiString(serial).c_str())) {
                ShowMessage(AnsiString("Unable to change directory\n"));
                return false;
        }
        if (CheckBox_OutputFile1->Checked && (outFile1 = fopen("OUTPUT1.TXT", "wt")) == NULL) {
                ShowMessage(AnsiString("Cannot open output1.txt\n"));
                return false;
        }
        if (CheckBox_OutputFile2->Checked && (outFile2 = fopen("OUTPUT2.TXT", "wt")) == NULL) {
                ShowMessage(AnsiString("Cannot open output2.txt\n"));
                return false;
        }
        if (CheckBox_OutputFile3->Checked && (outFile3 = fopen("OUTPUT3.TXT", "wt")) == NULL) {
                ShowMessage(AnsiString("Cannot open output3.txt\n"));
                return false;
        }
        if (CheckBox_OutputFile4->Checked && (outFile4 = fopen("OUTPUT4.TXT", "wt")) == NULL) {
                ShowMessage(AnsiString("Cannot open output4.txt\n"));
                return false;
        }
        if (CheckBox_OutputFile1->Checked) {
                fprintf(outFile1, "------------------------------------------------------------------------------\n");
                fprintf(outFile1, "              當        日        人        數              累  積  人  數    \n");
                fprintf(outFile1, "      ------------------------------------------------  ----------------------\n");
                fprintf(outFile1, "天數  易感染者  潛伏期  發病期  康復期  免疫期  死亡者  康復者  死亡者  死亡率\n");
                fprintf(outFile1, "----  --------  ------  ------  ------  ------  ------  ------  ------  ------\n");
        }
        if (CheckBox_OutputFile2->Checked) {
                fprintf(outFile2, "------------------------------------------------------------------------------------------------------------------------------------\n");
                fprintf(outFile2, "        該      日      新      增      加      之      人      數      該      日      新      增      加      之      人      數  \n");
                fprintf(outFile2, "      --------------------------------------------------------------  --------------------------------------------------------------\n");
                fprintf(outFile2, "天數  易感染  潛伏期  傳染者  康復者  免疫者  死亡者  治療者  隔離者  易感染  潛伏期  傳染者  康復者  免疫者  死亡者  治療者  隔離者\n");
                fprintf(outFile2, "----  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------  ------\n");
        }
        if (CheckBox_OutputFile4->Checked) {
                fprintf(outFile4, "------------------------------------------------------------------------------------\n");
                fprintf(outFile4, "        平      均      每      日      新      增      加      之      人      數  \n");
                fprintf(outFile4, "      ------------------------------------------------------------------------------\n");
                fprintf(outFile4, "天數   易感染    潛伏期    傳染者    康復者    免疫者    死亡者    治療者    隔離者 \n");
                fprintf(outFile4, "----  --------  --------  --------  --------  --------  --------  --------  --------\n");
        }
        return true;
}
//---------------------------------------------------------------------------
// Button_CreateClick(TObject *Sender): 當按下「初始化」按鈕時，執行此方法
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_CreateClick(TObject *Sender)
{
        // 假如日誌檔成功開啟，則繼續執行，否則不做任何動作
        if (initOutputFiles()) {

                Edit_AverageCount->Text = AnsiString(++measure.size);

                initVariables();
                initComponents();

                backupStatistic();

                initWorld();
                initSociety(Sender);

                generateDistributedAgents();

                drawLattice();
                drawPartialLattice(partialView);

                changeGraphicData();
                showMsg("O.K.");

                enableComponents();
        }
}
//---------------------------------------------------------------------------
// initPolicies(TObject *Sender): 啟動或禁止此模擬系統中的各項公衛政策
//---------------------------------------------------------------------------
void TSARS_Form::initPolicies(TObject *Sender)
{
        CheckBox_HospitalClick(Sender);         // 啟動或禁止醫院治療政策
        CheckBox_HomeClick(Sender);             // 啟動或禁止居家隔離政策
        CheckBox_MaskClick(Sender);             // 啟動或禁止戴口罩、勤洗手政策
        CheckBox_TempClick(Sender);             // 啟動或禁止測量體溫政策
        CheckBox_VisitClick(Sender);            // 啟動或禁止醫院探訪政策
        CheckBox_ContactClick(Sender);          // 啟動或禁止公共場所減少活動
        CheckBox_MedicalPolicyClick(Sender);    // 啟動或禁止醫護人員帶口罩、手套政策
}
//---------------------------------------------------------------------------
// initWorld(void): 初始化TSARS_Form類別中的world成員變數，也等於模型中的細胞自動機
//---------------------------------------------------------------------------
void TSARS_Form::initWorld(void)
{
        for (long MaxHeight = Edit_MaxWorldHeight->Text.ToInt(), i = 0; i < MaxHeight; i++)
                for (long MaxWidth = Edit_MaxWorldWidth->Text.ToInt(), j = 0; j < MaxWidth; j++) {
                        world[i][j].peopleID = world[i][j].agentNo = EMPTY;
                        world[i][j].color    = DEFAULT_COLOR;
                }
}
//---------------------------------------------------------------------------
// initSociety(TObject *Sender): 初始化TSARS_Form類別中的實際社會
//---------------------------------------------------------------------------
void TSARS_Form::initSociety(TObject *Sender)
{
        for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = society.day = 0; i < MaxPopulation; initPeople(i++));
        initPolicies(Sender);
}
//---------------------------------------------------------------------------
// initPeople(long ID): 初始化TSARS_Form類別中的人群
//---------------------------------------------------------------------------
void TSARS_Form::initPeople(long ID)
{
        // 設定每個人的ID、身體狀態（在某個機率下，個體具有免疫力）等屬性值
        society.people[ID].ID    = ID;
        society.people[ID].state = (FLIP(Edit_ImmuneProb->Text.ToDouble()) ? IMMUNE : SUSCEPTIBLE);
        society.people[ID].count = 0;
        society.people[ID].limit = 0;

        initAttribute(ID, society.people[ID].state);
        initAgents(ID);
}
//---------------------------------------------------------------------------
// initAttribute(long ID, UState state): 初始化TSARS_Form類別中每個人的屬性值
//---------------------------------------------------------------------------
void TSARS_Form::initAttribute(long ID, UState state)
{
        society.people[ID].attr.immunity         = (state == IMMUNE);
        society.people[ID].attr.super            = false;
        society.people[ID].attr.timer            = 0;
        society.people[ID].attr.age              = (FLIP(Edit_PopulationRateOldMan->Text.ToDouble()) ? OLD_MAN : (FLIP(Edit_PopulationRateYoungMan->Text.ToDouble()) ? YOUNG_MAN : PRIME_MAN));
        society.people[ID].attr.isolated         = false;
        society.people[ID].attr.quarantined      = false;
        society.people[ID].attr.quarantinedCount = 0;
        society.people[ID].attr.quarantinedLevel = 0;
        for (long i = 0; i < MAX_POLICY; society.people[ID].attr.policy[i++] = false);
}
//---------------------------------------------------------------------------
// initAgents(long ID): 初始化每個人的分身點為空值
//---------------------------------------------------------------------------
void TSARS_Form::initAgents(long ID)
{
        for (long MaxAgent = Edit_MaxAgent->Text.ToInt(), i = 0; i < MaxAgent; initAgent(ID, i++));
}
//---------------------------------------------------------------------------
// initAgent(long ID, long no): 初始化每個人的分身點的屬性值
//---------------------------------------------------------------------------
void TSARS_Form::initAgent(long ID, long no)
{
        society.people[ID].agent[no].no         = no;
        society.people[ID].agent[no].visible    = false;
        society.people[ID].agent[no].home       = false;
        society.people[ID].agent[no].location.x = EMPTY;
        society.people[ID].agent[no].location.y = EMPTY;
}
//---------------------------------------------------------------------------
// generateDistributedAgent(void): 在細胞自動機上產生每個人的分身點，並設定相關的屬性資料
//---------------------------------------------------------------------------
void TSARS_Form::generateDistributedAgents(void)
{
        long n1, n2, n3, n4;
        long ID, no, count[MAX_AGENT];
        long MaxPopulation = Edit_MaxPopulation->Text.ToInt();
        long MaxAgent = Edit_MaxAgent->Text.ToInt();
        double superRate = Edit_SuperRate->Text.ToDouble();

        for (long i = 0; i < MaxPopulation; i++) {
                n1 = (long)_lrand() % MaxAgent + 1;
                n2 = (long)_lrand() % MaxAgent + 1;
                n3 = (long)_lrand() % MaxAgent + 1;
                n4 = (long)_lrand() % MaxAgent + 1;
                society.people[i].limit = (n1 + n2 + n3 + n4) / 4;
        }
        // 將細胞自動機的每個晶格與每個人的社會分身點對應連接
        for (long i = Edit_MaxWorldHeight->Text.ToInt() - 1; i >= 0; i--)
                for (long j = Edit_MaxWorldWidth->Text.ToInt() - 1; j >= 0; j--) {
                        do {} while (society.people[(ID = (long)_lrand() % MaxPopulation)].count >= society.people[ID].limit);

                        society.people[ID].agent[(no = society.people[ID].count++)].visible = true;
                        society.people[ID].agent[no].location.x = j;
                        society.people[ID].agent[no].location.y = i;

                        world[i][j].peopleID = ID;
                        world[i][j].agentNo  = no;
                        world[i][j].color    = getColor(society.people[ID].state);
                }
        for (long i = 0; i < MAX_AGENT; count[i++] = 0);
        // 針對每個人，設定某個社會分身點為住家，並根據某個機率，決定是否為超級感染者
        for (long i = 0; i < MaxPopulation; i++) {
                if (society.people[i].count > 0) {
                        society.people[i].agent[rand() % society.people[i].count].home = true;
                        society.people[i].attr.super = FLIP(superRate);
                }
                ++count[society.people[i].count];
        }
        // 顯示關於分身點的統計資料
        Memo_Population->Lines->Clear();
        for (long MaxAgent = Edit_MaxAgent->Text.ToInt(), i = 1; i <= MaxAgent; i++)
                Memo_Population->Lines->Append("count[" + AnsiString(i) + "] = " + AnsiString(count[i]));
}
//---------------------------------------------------------------------------
// getColor(UState state): 針對不同的狀態傳回不同的顏色
//---------------------------------------------------------------------------
TColor TSARS_Form::getColor (UState state)
{
        TColor color = DEFAULT_COLOR;
        switch (state) {
                case SUSCEPTIBLE:
                        color = SUSCEPTIBLE_COLOR;
                        break;
                case EXPOSED:
                        color = EXPOSED_COLOR;
                        break;
                case INFECTIVE:
                        color = INFECTIVE_COLOR;
                        break;
                case RECOVERED:
                        color = RECOVERED_COLOR;
                        break;
                case IMMUNE:
                        color = IMMUNE_COLOR;
                        break;
                case DIED:
                        color = DIED_COLOR;
                        break;
        }
        return color;
}
//---------------------------------------------------------------------------
// drawLattice(void): 在表單的畫布元件上，畫出整個細胞自動機
//---------------------------------------------------------------------------
void TSARS_Form::drawLattice(void)
{
        for (long MaxHeight = Edit_MaxWorldHeight->Text.ToInt(), i = 0; i < MaxHeight; i++)
                for (long MaxWidth = Edit_MaxWorldWidth->Text.ToInt(), j = 0; j < MaxWidth; j++)
                        drawGrid(j, i, (society.people[world[i][j].peopleID].agent[world[i][j].agentNo].visible ? world[i][j].color : INVISIBLE_COLOR));
}
//---------------------------------------------------------------------------
// drawGrid(long x, long y, TColor color): 在表單的畫布元件上，畫出細胞自動機的每個晶格的顏色
//---------------------------------------------------------------------------
void TSARS_Form::drawGrid(long x, long y, TColor color)
{
        Lattice->Canvas->Pixels[x][y] = color;
}
//---------------------------------------------------------------------------
// drawPartialLattice(POINT partialView): 在表單的畫布元件上，畫出部分的細胞自動機
//---------------------------------------------------------------------------
void TSARS_Form::drawPartialLattice(POINT partialView)
{
        POINT start;

        start.x = (partialView.x - (PARTIAL_LATTICE_SIZE / 2) + Edit_MaxWorldWidth->Text.ToInt()) % Edit_MaxWorldWidth->Text.ToInt();
        start.y = (partialView.y - (PARTIAL_LATTICE_SIZE / 2) + Edit_MaxWorldHeight->Text.ToInt()) % Edit_MaxWorldHeight->Text.ToInt();

        for (long i = 0; i < PARTIAL_LATTICE_SIZE; i++)
                for (long j = 0; j < PARTIAL_LATTICE_SIZE; j++) {
                        long ID = world[(start.y + i) % Edit_MaxWorldHeight->Text.ToInt()][(start.x + j) % Edit_MaxWorldWidth->Text.ToInt()].peopleID;
                        long no = world[(start.y + i) % Edit_MaxWorldHeight->Text.ToInt()][(start.x + j) % Edit_MaxWorldWidth->Text.ToInt()].agentNo;

                        partialLattice->Canvas->Pen->Color   = (society.people[ID].agent[no].visible ? world[(start.y + i) % Edit_MaxWorldHeight->Text.ToInt()][(start.x + j) % Edit_MaxWorldWidth->Text.ToInt()].color : INVISIBLE_COLOR);
                        partialLattice->Canvas->Brush->Color = partialLattice->Canvas->Pen->Color;
                        partialLattice->Canvas->Rectangle(j * PARTIAL_CELL_SIZE, i * PARTIAL_CELL_SIZE, j * PARTIAL_CELL_SIZE + (PARTIAL_CELL_SIZE - 1), i * PARTIAL_CELL_SIZE + (PARTIAL_CELL_SIZE - 1));
                }
}
//---------------------------------------------------------------------------
void TSARS_Form::enableComponents(void)
{
        Button_Create->Enabled          = false;
        Button_Exit->Enabled            = false;

        Button_NewCase->Enabled         = true;
        Button_Run->Enabled             = true;
        Button_Stop->Enabled            = true;
        Button_Termination->Enabled     = true;

        Button_East->Enabled            = true;
        Button_West->Enabled            = true;
        Button_South->Enabled           = true;
        Button_North->Enabled           = true;
        Button_Middle->Enabled          = true;

        Edit_NewCase->Enabled           = true;
        Edit_Period->Enabled            = true;
        Edit_Gossip->Enabled            = true;

        CheckBox_Super->Enabled         = true;
        RadioButton_Exposed->Enabled    = true;
        RadioButton_Infective->Enabled  = true;

        enablePrintAndSaveButtons();
        showMainPage();
}
//---------------------------------------------------------------------------
void TSARS_Form::disableComponents(void)
{
        Button_Create->Enabled          = true;
        Button_Exit->Enabled            = true;

        Button_NewCase->Enabled         = false;
        Button_Run->Enabled             = false;
        Button_Stop->Enabled            = false;
        Button_Termination->Enabled     = false;

        Button_East->Enabled            = false;
        Button_West->Enabled            = false;
        Button_South->Enabled           = false;
        Button_North->Enabled           = false;
        Button_Middle->Enabled          = false;

        Edit_NewCase->Enabled           = false;
        Edit_Period->Enabled            = false;
        Edit_Gossip->Enabled            = false;

        CheckBox_Super->Enabled         = false;
        RadioButton_Exposed->Enabled    = false;
        RadioButton_Infective->Enabled  = false;

        disablePrintAndSaveButtons();
        showMainPage();
        MemoStatus->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_TerminationClick(TObject *Sender)
{
        disableComponents();
        if (CheckBox_OutputFile1->Checked) {
                fprintf(outFile1, "------------------------------------------------------------------------------\n");
                fclose(outFile1);
        }
        if (CheckBox_OutputFile2->Checked) {
                fprintf(outFile2, "------------------------------------------------------------------------------------------------------------------------------------\n");
                fclose(outFile2);
        }
        fclose(outFile3);
        if (CheckBox_OutputFile4->Checked) {
                fprintf(outFile4, "------------------------------------------------------------------------------------\n");
                fprintf(outFile4, "上述數據為 %d 次的平均結果\n", measure.size);
                fclose(outFile4);
        }
        TotalCase_Chart->SaveToMetafile("Accumulative Graph-" + AnsiString(society.day) + ".wmf");
        Case_Chart->SaveToMetafile("Daily Graph-" + AnsiString(society.day) + ".wmf");
        IsolatedCase_Chart->SaveToMetafile("Notifiable Graph-" + AnsiString(society.day) + ".wmf");
        InfectedCase_Chart->SaveToMetafile("Infective Graph-" + AnsiString(society.day) + ".wmf");
        TotalQuarantinedCase_Chart->SaveToMetafile("Accumulative Quarantined-" + AnsiString(society.day) + ".wmf");
        QuarantinedCase_Chart->SaveToMetafile("Daily Quarantine-" + AnsiString(society.day) + ".wmf");
        chdir("..");
        showMsg("Finish");
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_NewCaseClick(TObject *Sender)
{
        long ID;
        UState state;

        if (!CheckBox_InputAsWellAsRun->Checked)
                society.day++;
        backupStatistic();
        for (long i = Edit_NewCase->Text.ToInt(); i > 0; i--) {
                do {} while (society.people[(ID = (long)_lrand() % Edit_MaxPopulation->Text.ToInt())].state != SUSCEPTIBLE || society.people[ID].attr.immunity || society.people[ID].count == 0);

                if ((state = society.people[ID].state = (RadioButton_Exposed->Checked ? EXPOSED : INFECTIVE)) == EXPOSED)
                        society.people[ID].attr.timer = random(Edit_AvgExposedPeriod->Text.ToInt());
                else
                        society.people[ID].attr.timer = random(Edit_AvgSymptomaticPeriod->Text.ToInt());
                society.people[ID].attr.super = CheckBox_Super->Checked;
                ++statistic[(int)state];
                for (long count = society.people[ID].count, j = 0; j < count; j++)
                        world[society.people[ID].agent[j].location.y][society.people[ID].agent[j].location.x].color = getColor(state);
        }
        if (CheckBox_InputAsWellAsRun->Checked)
                changeSociety();
        changeGraphicData();
        outputResult();
        if (CheckBox_OutputFile3->Checked)
                fprintf(outFile3, "[動作]: 在 %4d 天，輸入 %d 名 %s。\n", society.day, Edit_NewCase->Text.ToInt(), (CheckBox_Super->Checked ? (RadioButton_Exposed->Checked ? "超級潛伏期者" : "超級傳染期者") : (RadioButton_Infective->Checked ? "正常潛伏期者" : "正常傳染期者")));
        showResult();
}
//---------------------------------------------------------------------------
void TSARS_Form::resetWorld(void)
{
        for (long MaxHeight = Edit_MaxWorldHeight->Text.ToInt(), i = 0; i < MaxHeight; i++)
                for (long MaxWidth = Edit_MaxWorldWidth->Text.ToInt(), j = 0; j < MaxWidth; j++)
                        world[i][j].color = getColor(society.people[world[i][j].peopleID].state);
}
//---------------------------------------------------------------------------
void TSARS_Form::showMsg(AnsiString msg)
{
        MemoStatus->Lines->Append(msg);
}
//---------------------------------------------------------------------------
void TSARS_Form::showStatus(void)
{
        long sum[STATE_SIZE];

        for (long i = 0; i < STATE_SIZE; sum[i++] = 0);
        for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; sum[(long)(society.people[i++].state)]++);

        MemoStatus->Lines->Clear();
        MemoStatus->Lines->Append("day(s) = "   + AnsiString(society.day));
        MemoStatus->Lines->Append("(S) = " + AnsiString(sum[SUSCEPTIBLE]) + ", " +
                                  "(E) = " + AnsiString(sum[EXPOSED])     + ", " +
                                  "(I) = " + AnsiString(sum[INFECTIVE])   + ", " +
                                  "(R) = " + AnsiString(sum[RECOVERED])   + ", " +
                                  "(M) = " + AnsiString(sum[IMMUNE])      + ", " +
                                  "(D) = " + AnsiString(sum[DIED]));

        StatusBar->Panels->Items[7]->Text = ("Day = " + AnsiString(society.day));
        if (statistic[(int)RECOVERED] + statistic[(int)DIED] > 0)
                StatusBar->Panels->Items[8]->Text = ("(R) "         + AnsiString(statistic[(int)RECOVERED]) + " person(s), " +
                                                     "(D) "         + AnsiString(statistic[(int)DIED])      + " person(s), " +
                                                     "mortality = " + AnsiString((long)(((double)statistic[(int)DIED] / (statistic[(int)RECOVERED] + statistic[(int)DIED])) * 100)) + "%");
        else
                StatusBar->Panels->Items[8]->Text = ("(R) "         + AnsiString(statistic[(int)RECOVERED]) + " person(s), " +
                                                     "(D) "         + AnsiString(statistic[(int)DIED])      + " person(s)");
}
//---------------------------------------------------------------------------
void TSARS_Form::outputResult(void)
{
        long sum[STATE_SIZE];

        for (long i = 0; i < STATE_SIZE; sum[i++] = 0);
        for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; sum[(long)(society.people[i++].state)]++);

        if (CheckBox_OutputFile1->Checked) {
                fprintf(outFile1, "%4d  %8d  %6d  %6d  %6d  %6d  %6d  %6d  %6d", society.day, sum[SUSCEPTIBLE], sum[EXPOSED], sum[INFECTIVE], sum[RECOVERED], sum[IMMUNE], sum[DIED], statistic[(int)RECOVERED], statistic[(int)DIED]);
                fprintf(outFile1, "  %5.2f%\n", ((statistic[(int)DIED] > 0) ? ((double)statistic[(int)DIED] / (statistic[(int)RECOVERED] + statistic[(int)DIED])) * 100 : 0));
        }
        if (CheckBox_OutputFile2->Checked) {
                fprintf(outFile2, "%4d  ", society.day);
                for (long i = 0; i < STATE_SIZE; i++)
                        fprintf(outFile2, "%6d  ", statistic[i] - oldStatistic[i]);
                for (long i = 0; i < STATE_SIZE; i++)
                        fprintf(outFile2, "%6d  ", statistic[i]);
                fprintf(outFile2, "\n");
        }
        if (CheckBox_OutputFile4->Checked) {
                fprintf(outFile4, "%4d  ", society.day);
                for (long i = 0; i < STATE_SIZE; i++)
                        fprintf(outFile4, "%8.2f  ", measure.value2[society.day][i]);
                fprintf(outFile4, "\n");
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_RunClick(TObject *Sender)
{
        SimulationTimer->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_StopClick(TObject *Sender)
{
        SimulationTimer->Enabled = false;
}
//---------------------------------------------------------------------------
void TSARS_Form::runSimulation(void)
{
        static long count = 0;

        if (count == 0 && CheckBox_OutputFile3->Checked)
                fprintf(outFile3, "[動作]: 在 %4d 天，連續模擬 %d 天，每天 %s 活動 %d 次，。\n", society.day, Edit_Period->Text.ToInt(), (RadioButton_Fixed->Checked ? "固定" : "變動"), Edit_Gossip->Text.ToInt());
        if (count < Edit_Period->Text.ToInt()) {
                backupStatistic();
                changeSociety();
                changeGraphicData();
                outputResult();
                count++;
        }
        else {
                count = 0;
                showResult();
                SimulationTimer->Enabled = false;
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::backupStatistic(void)
{
        for (long i = 0; i < STATE_SIZE; i++)
                oldStatistic[i] = statistic[i];
}
//---------------------------------------------------------------------------
void TSARS_Form::changeGraphicData(void)
{
        long totalInfectedPerson;

        for (long size = measure.size, i = 1; i < STATE_SIZE - 1; i++) {
                measure.value1[society.day][i] += statistic[i] - oldStatistic[i];
                measure.value2[society.day][i] = measure.value1[society.day][i] / (double)size;

                TotalCase_Chart->Series[i - 1]->AddY(statistic[i], society.day);
                Case_Chart->Series[i - 1]->AddY(statistic[i] - oldStatistic[i], society.day);
        }
        IsolatedCase_Chart->Series[0]->AddY(statistic[ISOLATED]  - oldStatistic[ISOLATED],  society.day);
        IsolatedCase_Chart->Series[1]->AddY(statistic[(int)DIED] - oldStatistic[(int)DIED], society.day);
        IsolatedCase_Chart->Series[2]->AddY((measure.value2[society.day][ISOLATED] + measure.value2[society.day][(int)DIED]), society.day);
        InfectedCase_Chart->Series[0]->AddY(infectedByNormal,   society.day);
        InfectedCase_Chart->Series[1]->AddY(infectedByHospital, society.day);
        Edit_InfectedByNormal->Text   = AnsiString(infectedByNormal);
        Edit_InfectedByHospital->Text = AnsiString(infectedByHospital);
        if ((totalInfectedPerson = (infectedByNormal + infectedByHospital)) > 0) {
                Edit_InfectedByNormalRate->Text   = AnsiString(((double)infectedByNormal   / totalInfectedPerson) * 100) + "%";
                Edit_InfectedByHospitalRate->Text = AnsiString(((double)infectedByHospital / totalInfectedPerson) * 100) + "%";
        }
        TotalQuarantinedCase_Chart->Series[0]->AddY(statistic[QUARANTINED], society.day);
        QuarantinedCase_Chart->Series[0]->AddY(statistic[QUARANTINED] - oldStatistic[QUARANTINED], society.day);
}
//---------------------------------------------------------------------------
void TSARS_Form::showResult(void)
{
        ProgressBar->Position = 0;
        resetWorld();
        drawLattice();
        drawPartialLattice(partialView);
        showStatus();
}
//---------------------------------------------------------------------------
void TSARS_Form::showMainPage(void)
{
        PageControl1->Pages[PAGE_CONTROL_1_MAIN_PAGE]->Show();
        PageControl2->Pages[PAGE_CONTROL_2_MAIN_PAGE]->Show();
}
//---------------------------------------------------------------------------
void TSARS_Form::changeSociety(void)
{
        bool dir = FLIP(0.5);

        ProgressBar->Position = 0;
        MemoStatus->Lines->Append(AnsiString(++society.day));
        for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = (dir ? 0 : MaxPopulation - 1); (dir ? i < MaxPopulation : i >= 0); (dir ? i++ : i--)) {
                changePeople(i);
                if ((i % STEP_SIZE) == 0) ProgressBar->Position = i;
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::changePeople(long ID)
{
        if (society.people[ID].count > 0) {
                UState state = society.people[ID].state;
                if (state == SUSCEPTIBLE || state == EXPOSED || state == INFECTIVE)
                        if (society.people[ID].attr.policy[HOME] && society.people[ID].attr.quarantined)
                                quarantinePeopleByOngoing(ID, state);

                state = society.people[ID].state;
                if (state == EXPOSED || state == INFECTIVE || state == RECOVERED || (state == IMMUNE && !society.people[ID].attr.immunity))
                        changePeopleByOngoing(ID, state);

                state = society.people[ID].state;
                if (state == SUSCEPTIBLE || ((state == EXPOSED || state == INFECTIVE) && society.people[ID].attr.policy[HOME] && !society.people[ID].attr.quarantined))
                        changePeopleByGossip(ID);
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::quarantinePeopleByOngoing(long ID, UState state)
{
        if (++society.people[ID].attr.quarantinedCount > QUARANTINED_PERIOD) {
                society.people[ID].attr.quarantined      = false;
                society.people[ID].attr.quarantinedCount = 0;
                society.people[ID].attr.quarantinedLevel = 0;
                if (!society.people[ID].attr.policy[HOSPITAL] || !society.people[ID].attr.isolated)
                        for (long count = society.people[ID].count, i = 0; i < count; society.people[ID].agent[i++].visible = true);
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::changePeopleByOngoing(long ID, UState state)
{
        long timer = ++society.people[ID].attr.timer;

        if (state == EXPOSED && timer > EXPOSED_PERIOD) {
                ++statistic[(int)(society.people[ID].state = INFECTIVE)];
                society.people[ID].attr.timer = 0;
        }
        if (state == INFECTIVE && society.people[ID].attr.policy[HOSPITAL] && !society.people[ID].attr.isolated)
                isolatePeopleByHospital(ID, state, timer);
        if (state == INFECTIVE && timer > SYMPTOMATIC_PERIOD) {
                ++statistic[(int)(society.people[ID].state = (FLIP(getDiedRate(ID)) ? DIED : RECOVERED))];
                society.people[ID].attr.timer = 0;

                if (society.people[ID].state == DIED)
                        for (long count = society.people[ID].count, i = 0; i < count; i++)
                                society.people[ID].agent[i].visible = society.people[ID].agent[i].home;
                else
                        for (long count = society.people[ID].count, i = 0; i < count; i++)
                                society.people[ID].agent[i].visible = true;

                if (society.people[ID].attr.isolated)
                        finishMedicalPolicy(ID);

                society.people[ID].attr.isolated         = false;
                society.people[ID].attr.quarantined      = false;
                society.people[ID].attr.quarantinedCount = 0;
                society.people[ID].attr.quarantinedLevel = 0;
        }
        if (state == RECOVERED && timer > RECOVERED_PERIOD) {
                ++statistic[(int)(society.people[ID].state = IMMUNE)];
                society.people[ID].attr.immunity = (IMMUNE_PERIOD == 0);
                society.people[ID].attr.timer = 0;
        }
        if (state == IMMUNE && timer > IMMUNE_PERIOD) {
                ++statistic[(int)(society.people[ID].state = SUSCEPTIBLE)];
                society.people[ID].attr.timer = 0;
                society.people[ID].attr.policy[VACCINE] = false;
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::isolatePeopleByHospital(long ID, UState state, long timer)
{
        if ((society.people[ID].attr.policy[TAKE_TEMPERATURE] && FLIP(Edit_TempEffect->Text.ToDouble())) ||
            (timer > INFECTIVE_PERIOD && FLIP(Edit_DetectRate->Text.ToDouble()))) {
                society.people[ID].attr.isolated = true;
                ++statistic[ISOLATED];
                if (society.people[ID].attr.policy[HOME] && society.people[ID].attr.quarantined) {
                        society.people[ID].attr.quarantined      = false;
                        society.people[ID].attr.quarantinedCount = 0;
                        society.people[ID].attr.quarantinedLevel = 0;
                }
                for (long count = society.people[ID].count, i = 0; i < count; i++)
                        society.people[ID].agent[i].visible = society.people[ID].agent[i].home;
                if (CheckBox_TraceOn->Checked)
                        traceContactPeople(ID, 1);
                if (CheckBox_MedicalPolicy->Checked)
                        startMedicalPolicy(ID);
        }
}
//---------------------------------------------------------------------------
void TSARS_Form::startMedicalPolicy(long ID)
{
        long MaxWorldWidth  = Edit_MaxWorldWidth->Text.ToInt();
        long MaxWorldHeight = Edit_MaxWorldHeight->Text.ToInt();

        for (long count = society.people[ID].count, i = 0; i < count; i++)
                if (society.people[ID].agent[i].home)
                        for (long middleX = society.people[ID].agent[i].location.x, currX = middleX - 1; currX <= middleX + 1; currX++) {
                                long locX = (currX + MaxWorldWidth) % MaxWorldWidth;
                                for (long middleY = society.people[ID].agent[i].location.y, currY = middleY - 1; currY <= middleY + 1; currY++) {
                                        long locY   = (currY + MaxWorldHeight) % MaxWorldHeight;
                                        long tempID = world[locY][locX].peopleID;
                                        if (!society.people[tempID].attr.policy[MEDICAL_POLICY])
                                                society.people[tempID].attr.policy[MEDICAL_POLICY] = FLIP(Edit_MedicalPolicyAvailable->Text.ToDouble());
                                }
                        }
}
//---------------------------------------------------------------------------
void TSARS_Form::finishMedicalPolicy(long ID)
{
        long MaxWorldWidth  = Edit_MaxWorldWidth->Text.ToInt();
        long MaxWorldHeight = Edit_MaxWorldHeight->Text.ToInt();

        for (long count = society.people[ID].count, i = 0; i < count; i++)
                if (society.people[ID].agent[i].home)
                        for (long middleX = society.people[ID].agent[i].location.x, currX = middleX - 1; currX <= middleX + 1; currX++) {
                                long locX = (currX + MaxWorldWidth) % MaxWorldWidth;
                                for (long middleY = society.people[ID].agent[i].location.y, currY = middleY - 1; currY <= middleY + 1; currY++) {
                                        long locY   = (currY + MaxWorldHeight) % MaxWorldHeight;
                                        society.people[world[locY][locX].peopleID].attr.policy[MEDICAL_POLICY] = false;
                                }
                        }
}
//---------------------------------------------------------------------------
void TSARS_Form::changePeopleByGossip(long ID)
{
        bool dir = FLIP(0.5);

        for (long count = society.people[ID].count, i = (dir ? 0 : count - 1); (dir ? i < count : i >= 0); (dir ? i++ : i--))
                if (society.people[ID].agent[i].visible && (society.people[ID].agent[i].home || !society.people[ID].attr.policy[STOP_CONTACT] || FLIP(1. / society.people[ID].count)) && changeAgentByGossip(ID, i))
                        break;
}
//---------------------------------------------------------------------------
bool TSARS_Form::changeAgentByGossip(long ID, long no)
{
        bool changed   = false;
        long MaxGossip = ((society.people[ID].attr.policy[STOP_CONTACT] && !society.people[ID].agent[no].home) ? random(Edit_Gossip->Text.ToInt() + 1) : (RadioButton_Fixed->Checked ? Edit_Gossip->Text.ToInt() : (random(Edit_Gossip->Text.ToInt()) + 1)));

        for (long i = 0; !changed && i < MaxGossip; i++)
                if (society.people[ID].agent[no].visible)
                        changed = touchOtherAgent(ID, no);
        return changed;
}
//---------------------------------------------------------------------------
bool TSARS_Form::touchOtherAgent(long ID, long no)
{
        bool changed   = false;
        long target    = random(NEIGHBORS_SIZE) % NEIGHBORS_SIZE;
        long MaxHeight = Edit_MaxWorldHeight->Text.ToInt();
        long MaxWidth  = Edit_MaxWorldWidth->Text.ToInt();
        long baseY     = society.people[ID].agent[no].location.y;
        long baseX     = society.people[ID].agent[no].location.x;

        for (long count = 0, row = -1; row <= 1; row++)
                for (long column = -1; column <= 1; column++, count++)
                        if (row != 0 || column != 0) {
                                long x = (baseX + column + MaxWidth)  % MaxWidth;
                                long y = (baseY + row    + MaxHeight) % MaxHeight;
                                long gID = world[y][x].peopleID;
                                if (society.people[gID].attr.super && society.people[gID].state == INFECTIVE) {
                                        target = count;
                                        exit;
                                }
                        }

        if (target != AGENT_SELF) {
                long x = (baseX + ((target == 0 || target == 3 || target == 6) ? -1 : ((target == 2 || target == 5 || target == 8) ? 1 : 0)) + MaxWidth)  % MaxWidth;
                long y = (baseY + ((0 <= target && target <= 2) ? -1 : ((6 <= target && target <= 8) ? 1 : 0)) + MaxHeight) % MaxHeight;
                long gID = world[y][x].peopleID;
                long gNo = world[y][x].agentNo;

                if (!society.people[gID].agent[gNo].visible)
                        return changed;

                UState gState = society.people[gID].state;

                if (society.people[ID].state == SUSCEPTIBLE && gState == INFECTIVE) {
                        if (society.people[gID].attr.policy[HOSPITAL] && society.people[gID].attr.isolated)
                                if (society.people[ID].attr.policy[STOP_VISITANT] && !society.people[ID].agent[no].home)
                                        return changed;
                        if (FLIP(getTransmissionRate(ID, no, gID, gNo))) {
                                ++statistic[(int)(society.people[ID].state = EXPOSED)];
                                society.people[ID].attr.timer = 0;
                                changed = true;
                                if (society.people[gID].attr.isolated)
                                        ++infectedByHospital;
                                else
                                        ++infectedByNormal;
                        }
                }
                if (society.people[ID].attr.policy[HOSPITAL] && !society.people[ID].attr.isolated &&
                    society.people[ID].attr.policy[HOME]     && !society.people[ID].attr.quarantined) {

                        if (society.people[gID].attr.policy[HOSPITAL] && society.people[gID].attr.isolated) {
                                society.people[ID].attr.quarantined      = true;
                                society.people[ID].attr.quarantinedLevel = 1;
                                if (CheckBox_TraceOn->Checked)
                                        traceContactPeople(ID, 2);
                        }
                        else if (society.people[gID].attr.policy[HOME] && society.people[gID].attr.quarantined && society.people[gID].attr.quarantinedLevel == 1 && RadioButton_IsolatedLevelB->Checked) {
                                society.people[ID].attr.quarantined      = true;
                                society.people[ID].attr.quarantinedLevel = 2;
                        }
                        if (society.people[ID].attr.policy[HOME] && society.people[ID].attr.quarantined) {
                                ++statistic[QUARANTINED];
                                society.people[ID].attr.quarantinedCount = 0;
                                for (long count = society.people[ID].count, i = 0; i < count; i++)
                                        society.people[ID].agent[i].visible = society.people[ID].agent[i].home;
                        }
                }
        }
        return changed;
}
//---------------------------------------------------------------------------
void TSARS_Form::traceContactPeople(long ID, long level)
{
        long MaxWorldWidth  = Edit_MaxWorldWidth->Text.ToInt();
        long MaxWorldHeight = Edit_MaxWorldHeight->Text.ToInt();

        for (long count = society.people[ID].count, i = 0; i < count; i++)
                for (long middleX = society.people[ID].agent[i].location.x, currX = middleX - 1; currX <= middleX + 1; currX++) {
                        long locX = (currX + MaxWorldWidth) % MaxWorldWidth;
                        for (long middleY = society.people[ID].agent[i].location.y, currY = middleY - 1; currY <= middleY + 1; currY++) {
                                long locY      = (currY + MaxWorldHeight) % MaxWorldHeight;
                                long tempID    = world[locY][locX].peopleID;
                                long tempState = society.people[tempID].state;
                                if (tempState == SUSCEPTIBLE || tempState == EXPOSED || tempState == INFECTIVE)
                                        if (society.people[tempID].attr.policy[HOME] && !society.people[tempID].attr.quarantined) {
                                                society.people[tempID].attr.quarantined      = true;
                                                society.people[tempID].attr.quarantinedCount = 0;
                                                society.people[tempID].attr.quarantinedLevel = level;
                                                for (long count = society.people[tempID].count, k = 0; k < count; k++)
                                                        society.people[tempID].agent[k].visible = society.people[tempID].agent[k].home;
                                                ++statistic[QUARANTINED];
                                                if (RadioButton_IsolatedLevelB->Checked && level == 1)
                                                        traceContactPeople(tempID, 2);
                                }
                        }
                }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_MiddleClick(TObject *Sender)
{
        Button_Middle->Caption = AnsiString((Button_Middle->Caption.ToInt() + 1) % MAX_MOVE_SIZE);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_NorthClick(TObject *Sender)
{
        partialView.y -= powl(MOVE_BASE, Button_Middle->Caption.ToInt());
        drawPartialLattice(partialView);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_SouthClick(TObject *Sender)
{
        partialView.y += powl(MOVE_BASE, Button_Middle->Caption.ToInt());
        drawPartialLattice(partialView);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_WestClick(TObject *Sender)
{
        partialView.x -= powl(MOVE_BASE, Button_Middle->Caption.ToInt());
        drawPartialLattice(partialView);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_EastClick(TObject *Sender)
{
        partialView.x += powl(MOVE_BASE, Button_Middle->Caption.ToInt());
        drawPartialLattice(partialView);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::partialLatticeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
        long x  = (partialView.x - (PARTIAL_LATTICE_SIZE / 2) + X / PARTIAL_CELL_SIZE + Edit_MaxWorldWidth->Text.ToInt()) % Edit_MaxWorldWidth->Text.ToInt();
        long y  = (partialView.y - (PARTIAL_LATTICE_SIZE / 2) + Y / PARTIAL_CELL_SIZE + Edit_MaxWorldHeight->Text.ToInt()) % Edit_MaxWorldHeight->Text.ToInt();
        long ID = world[y][x].peopleID;

        showStatusBar(x, y, ID);

        Edit_PeopleState->Text = AnsiString(society.people[ID].attr.immunity ? "Immune" : "Susceptible") + ", " +
                                 (society.people[ID].attr.super ? AnsiString("Super Spreader, ") : AnsiString("")) +
                                 (society.people[ID].state == SUSCEPTIBLE ? AnsiString("") : "day = " + AnsiString(society.people[ID].attr.timer) + ", ") +
                                 (society.people[ID].attr.age == OLD_MAN ? "Old" : society.people[ID].attr.age == PRIME_MAN ? "Prime" : "Young") + ", " +
                                 (society.people[ID].attr.isolated ? AnsiString("Isolated") : (society.people[ID].attr.quarantined ? (AnsiString("Home Quarantine, day = ") + AnsiString(society.people[ID].attr.quarantinedCount) + AnsiString(", Class:") + AnsiString(society.people[ID].attr.quarantinedLevel)) : AnsiString("Free")));
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::LatticeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
        if (Button == mbLeft) {
                partialView.x = X;
                partialView.y = Y;
                drawPartialLattice(partialView);
                PageControl1->Pages[1]->Show();
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::LatticeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
        showStatusBar(X, Y, world[Y][X].peopleID);
}
//---------------------------------------------------------------------------
void TSARS_Form::showStatusBar(long x, long y, long ID)
{
        StatusBar->Panels->Items[0]->Text = "X = "          + AnsiString(x);
        StatusBar->Panels->Items[1]->Text = "Y = "          + AnsiString(y);
        StatusBar->Panels->Items[2]->Text = "No. = "        + AnsiString(ID);
        StatusBar->Panels->Items[3]->Text = "amount = "     + AnsiString(society.people[ID].count);
        StatusBar->Panels->Items[4]->Text = "state = "      + getStateCode(society.people[ID].state, society.people[ID].attr.isolated, society.people[ID].attr.quarantined);
        StatusBar->Panels->Items[5]->Text = "Identity = "   + AnsiString(world[y][x].agentNo);
        StatusBar->Panels->Items[6]->Text = society.people[ID].agent[world[y][x].agentNo].home ? "Root" : "Other";
        StatusBar->Panels->Items[7]->Text = "day = "        + AnsiString(society.day);
}
//---------------------------------------------------------------------------
AnsiString TSARS_Form::getStateCode(UState state, bool isolated, bool quarantined)
{
        AnsiString msg;

        switch (state) {
                case SUSCEPTIBLE:
                        msg = AnsiString("(S)");
                        break;
                case EXPOSED:
                        msg = AnsiString("(E)");
                        break;
                case INFECTIVE:
                        msg = AnsiString("(I)");
                        break;
                case RECOVERED:
                        msg = AnsiString("(R)");
                        break;
                case IMMUNE:
                        msg = AnsiString("(M)");
                        break;
                case DIED:
                        msg = AnsiString("(D)");
                        break;
        }
        return (msg += AnsiString((isolated ? ".(I)" : (quarantined ? ".(Q)" : ""))));
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::TabSheet_TotalCaseShow(TObject *Sender)
{
        Button_Print->Tag   = 3;
        Button_Save->Tag    = 3;
        Edit_FileName->Text = AnsiString("Accumulative Graph");
        visiblePrintAndSaveButtons();
        invisiblePeopleStateComponents();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::TabSheet_ZoomShow(TObject *Sender)
{
        invisiblePrintAndSaveButtons();
        visiblePeopleStateComponents();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::TabSheet_LatticeShow(TObject *Sender)
{
        invisiblePrintAndSaveButtons();
        invisiblePeopleStateComponents();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::TabSheet_CaseShow(TObject *Sender)
{
        Button_Print->Tag   = 4;
        Button_Save->Tag    = 4;
        Edit_FileName->Text = AnsiString("Daily Graph");
        visiblePrintAndSaveButtons();
        invisiblePeopleStateComponents();
}
//---------------------------------------------------------------------------
void TSARS_Form::disablePrintAndSaveButtons(void)
{
        Button_Print->Enabled      = false;
        Button_Save->Enabled       = false;
        Label_FileName->Enabled    = false;
        Edit_FileName->Enabled     = false;
        Edit_PeopleState->Enabled  = false;
        Label_PeopleState->Enabled = false;
}
//---------------------------------------------------------------------------
void TSARS_Form::enablePrintAndSaveButtons(void)
{
        Button_Print->Enabled      = true;
        Button_Save->Enabled       = true;
        Label_FileName->Enabled    = true;
        Edit_FileName->Enabled     = true;
        Edit_PeopleState->Enabled  = true;
        Label_PeopleState->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_PrintClick(TObject *Sender)
{
        if (Button_Print->Tag == 3)
                TotalCase_Chart->Print();
        if (Button_Print->Tag == 4)
                Case_Chart->Print();
        if (Button_Print->Tag == 5)
                IsolatedCase_Chart->Print();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_SaveClick(TObject *Sender)
{
        if (Button_Save->Tag == 3)
                TotalCase_Chart->SaveToMetafile(Edit_FileName->Text + "-" + AnsiString(society.day) + ".wmf");
        if (Button_Save->Tag == 4)
                Case_Chart->SaveToMetafile(Edit_FileName->Text + "-" + AnsiString(society.day) + ".wmf");
        if (Button_Save->Tag == 5)
                IsolatedCase_Chart->SaveToMetafile(Edit_FileName->Text + "-" + AnsiString(society.day) + ".wmf");
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_MaskClick(TObject *Sender)
{
        if (!Edit_MaskAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[FACE_MASK] = CheckBox_Mask->Checked && FLIP(Edit_MaskAvailable->Text.ToDouble()));
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「宣導戴口罩、手套與勤洗手」政策，", society.day, (CheckBox_Mask->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "疾病感染預防率: %6.4f，", Edit_MaskEffect->Text.ToDouble());
                        fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_MaskAvailable->Text.ToDouble());
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_MaskAvailableChange(TObject *Sender)
{
        if (CheckBox_Mask->Checked)
                CheckBox_MaskClick(Sender);
}
//---------------------------------------------------------------------------
double TSARS_Form::getTransmissionRate(long ID, long no, long gID, long gNo)
{
        double transmissionProb = Edit_TransmissionProb->Text.ToDouble();

        if ((society.people[gID].attr.policy[HOSPITAL] && society.people[gID].attr.isolated) ||
            (society.people[gID].attr.policy[HOME]     && society.people[gID].attr.quarantined))
                transmissionProb *= society.people[gID].count;

        if (society.people[ID].attr.policy[MEDICAL_POLICY] && !Edit_MedicalPolicyEffect->Text.IsEmpty())
                transmissionProb *= (1. - Edit_MedicalPolicyEffect->Text.ToDouble());
        else if (society.people[ID].attr.policy[FACE_MASK] && !Edit_MaskEffect->Text.IsEmpty())
                transmissionProb *= (1. - Edit_MaskEffect->Text.ToDouble());

        if (society.people[gID].attr.policy[FACE_MASK] && !Edit_MaskEffect->Text.IsEmpty())
                transmissionProb *= (1. - Edit_MaskEffect->Text.ToDouble());

        if (society.people[ID].attr.policy[TAKE_TEMPERATURE] && society.people[gID].attr.policy[TAKE_TEMPERATURE])
                transmissionProb *= (1. - Edit_TempEffect->Text.ToDouble());

        return transmissionProb;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_HospitalClick(TObject *Sender)
{
        if (!Edit_HospitalAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; i++)
                        society.people[i].attr.policy[HOSPITAL] = CheckBox_Hospital->Checked && FLIP(Edit_HospitalAvailable->Text.ToDouble());
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「醫療體系」政策，", society.day, (CheckBox_Hospital->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "降低死亡率效果: %6.4f，", Edit_HospitalEffect->Text.ToDouble());
                        fprintf(outFile3, "就醫普及率: %6.4f。\n", Edit_HospitalAvailable->Text.ToDouble());
                }
        }
        if (!CheckBox_Hospital->Checked)
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.isolated = false);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_HospitalAvailableChange(TObject *Sender)
{
        if (CheckBox_Hospital->Checked)
                CheckBox_HospitalClick(Sender);
}
//---------------------------------------------------------------------------
double TSARS_Form::getDiedRate(long ID)
{
        double mortality;
        UAge age = society.people[ID].attr.age;

        if (age == YOUNG_MAN)
                mortality = Edit_MortalityYoungMan->Text.ToDouble();
        if (age == PRIME_MAN)
                mortality = Edit_MortalityPrimeMan->Text.ToDouble();
        if (age == OLD_MAN)
                mortality = Edit_MortalityOldMan->Text.ToDouble();

        if (society.people[ID].attr.isolated && !Edit_HospitalEffect->Text.IsEmpty())
                mortality *= (1. - Edit_HospitalEffect->Text.ToDouble());

        return mortality;
}
//---------------------------------------------------------------------------
void TSARS_Form::invisiblePrintAndSaveButtons(void)
{
        Button_Print->Visible   = false;
        Button_Save->Visible    = false;
        Label_FileName->Visible = false;
        Edit_FileName->Visible  = false;
}
//---------------------------------------------------------------------------
void TSARS_Form::visiblePrintAndSaveButtons(void)
{
        Button_Print->Visible   = true;
        Button_Save->Visible    = true;
        Label_FileName->Visible = true;
        Edit_FileName->Visible  = true;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::TabSheet_IsolatedCaseShow(TObject *Sender)
{
        Button_Print->Tag = 5;
        Button_Save->Tag  = 5;
        Edit_FileName->Text = AnsiString("Notifiable Graph");
        visiblePrintAndSaveButtons();
        invisiblePeopleStateComponents();
}
//---------------------------------------------------------------------------
void TSARS_Form::invisiblePeopleStateComponents(void)
{
        Edit_PeopleState->Visible  = false;
        Label_PeopleState->Visible = false;
}
//---------------------------------------------------------------------------
void TSARS_Form::visiblePeopleStateComponents(void)
{
        Edit_PeopleState->Visible  = true;
        Label_PeopleState->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_TempClick(TObject *Sender)
{
        if (!Edit_TempAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[TAKE_TEMPERATURE] = CheckBox_Temp->Checked && FLIP(Edit_TempAvailable->Text.ToDouble()));
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「測量體溫」政策，", society.day, (CheckBox_Temp->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "發燒偵測成功率: %6.4f，", Edit_TempEffect->Text.ToDouble());
                        fprintf(outFile3, "測量普及率: %6.4f。\n", Edit_TempAvailable->Text.ToDouble());
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_TempAvailableChange(TObject *Sender)
{
        if (CheckBox_Temp->Checked)
                CheckBox_TempClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_VisitClick(TObject *Sender)
{
        if (!Edit_VisitAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[STOP_VISITANT] = CheckBox_Visit->Checked && FLIP(Edit_VisitAvailable->Text.ToDouble()));
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「除家人外，禁止到醫院探病」政策，", society.day, (CheckBox_Visit->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "政策普及率: %6.4f。\n", Edit_VisitAvailable->Text.ToDouble());
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_VisitAvailableChange(TObject *Sender)
{
        if (CheckBox_Visit->Checked)
                CheckBox_VisitClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_VaccineForeverClick(TObject *Sender)
{
        CheckBox_VaccinePeriod->Checked = !CheckBox_VaccineForever->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_VaccinePeriodClick(TObject *Sender)
{
        CheckBox_VaccineForever->Checked = !CheckBox_VaccinePeriod->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_VaccineClick(TObject *Sender)
{
        long ID;

        if (!Edit_VaccineAvailable->Text.IsEmpty()) {
                for (long vaccine = Edit_VaccineAvailable->Text.ToInt(), i = 0; i < vaccine; i++) {
                        do {} while (society.people[(ID = (long)_lrand() % Edit_MaxPopulation->Text.ToInt())].attr.policy[VACCINE]);
                        society.people[ID].attr.policy[VACCINE] = true;
                        if (!society.people[ID].attr.immunity) {
                                ++statistic[(int)(society.people[ID].state = IMMUNE)];
                                society.people[ID].attr.immunity = CheckBox_VaccineForever->Checked;
                                society.people[ID].attr.timer    = 0;
                        }
                }
                if (CheckBox_OutputFile3->Checked)
                        fprintf(outFile3, "[政策]: 在 %4d 天，施打 %d 劑 %s 疫苗。\n", society.day, Edit_VaccineAvailable->Text.ToInt(), (CheckBox_VaccineForever->Checked ? "永久有效" : "短期有效"));
                showResult();
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_HomeClick(TObject *Sender)
{
        if (!Edit_HomeAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[HOME] = CheckBox_Home->Checked && FLIP(Edit_HomeAvailable->Text.ToDouble()));
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「實施居家隔離」政策，", society.day, (CheckBox_Home->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "%s 主動追蹤接觸史，", (CheckBox_TraceOn->Checked ? "開啟" : "關閉"));
                        fprintf(outFile3, " %s 級隔離，", (RadioButton_IsolatedLevelA->Checked ? "A" : "B"));
                        fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                        fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
                }
        }

        if (!CheckBox_Home->Checked)
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; i++) {
                        society.people[i].attr.quarantined      = false;
                        society.people[i].attr.quarantinedCount = 0;
                        society.people[i].attr.quarantinedLevel = 0;
                }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_HomeAvailableChange(TObject *Sender)
{
        if (CheckBox_Home->Checked)
                CheckBox_HomeClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_TraceOnClick(TObject *Sender)
{
        CheckBox_TraceOff->Checked = !CheckBox_TraceOn->Checked;
        if (CheckBox_OutputFile3->Checked && CheckBox_Home->Checked) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「實施居家隔離」政策，", society.day);
                fprintf(outFile3, "開啟 主動追蹤接觸史，");
                fprintf(outFile3, " %s 級隔離，", (RadioButton_IsolatedLevelA->Checked ? "A" : "B"));
                fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_TraceOffClick(TObject *Sender)
{
        CheckBox_TraceOn->Checked = !CheckBox_TraceOff->Checked;
        if (CheckBox_OutputFile3->Checked && CheckBox_Home->Checked) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「實施居家隔離」政策，", society.day);
                fprintf(outFile3, "關閉 主動追蹤接觸史，");
                fprintf(outFile3, " %s 級隔離，", (RadioButton_IsolatedLevelA->Checked ? "A" : "B"));
                fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_ContactClick(TObject *Sender)
{
        if (!Edit_ContactAvailable->Text.IsEmpty()) {
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[STOP_CONTACT] = CheckBox_Contact->Checked && FLIP(Edit_ContactAvailable->Text.ToDouble()));
                if (CheckBox_OutputFile3->Checked) {
                        fprintf(outFile3, "[政策]: 在 %4d 天，%s「減少公共場合接觸」政策，", society.day, (CheckBox_Contact->Checked ? "啟動" : "取消"));
                        fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_ContactAvailable->Text.ToDouble());
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_ContactAvailableChange(TObject *Sender)
{
        if (CheckBox_Contact->Checked)
                CheckBox_ContactClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::RadioButton_IsolatedLevelAClick(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Home->Checked) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「實施居家隔離」政策，", society.day);
                fprintf(outFile3, "%s 主動追蹤接觸史，", (CheckBox_TraceOn->Checked ? "開啟" : "關閉"));
                fprintf(outFile3, " A 級隔離，");
                fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::RadioButton_IsolatedLevelBClick(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Home->Checked) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「實施居家隔離」政策，", society.day);
                fprintf(outFile3, "%s 主動追蹤接觸史，", (CheckBox_TraceOn->Checked ? "開啟" : "關閉"));
                fprintf(outFile3, " B 級隔離，");
                fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_ClearClick(TObject *Sender)
{
        initMeasure();
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_MaskEffectChange(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Mask->Checked && !Edit_MaskEffect->Text.IsEmpty()) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「宣導戴口罩、手套與勤洗手」政策，", society.day);
                fprintf(outFile3, "疾病感染預防率: %6.4f，", Edit_MaskEffect->Text.ToDouble());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_MaskAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_TempEffectChange(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Temp->Checked && !Edit_TempEffect->Text.IsEmpty()) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「測量體溫」政策，", society.day);
                fprintf(outFile3, "發燒偵測成功率: %6.4f，", Edit_TempEffect->Text.ToDouble());
                fprintf(outFile3, "測量普及率: %6.4f。\n", Edit_TempAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_QuarantinedPeriodChange(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Home->Checked && !Edit_QuarantinedPeriod->Text.IsEmpty()) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「實施居家隔離」政策，", society.day);
                fprintf(outFile3, "%s 主動追蹤接觸史，", (CheckBox_TraceOn->Checked ? "開啟" : "關閉"));
                fprintf(outFile3, " %s 級隔離，", (RadioButton_IsolatedLevelA->Checked ? "A" : "B"));
                fprintf(outFile3, "隔離 %d 天，", Edit_QuarantinedPeriod->Text.ToInt());
                fprintf(outFile3, "觀念普及率: %6.4f。\n", Edit_HomeAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_HospitalEffectChange(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked && CheckBox_Hospital->Checked && Edit_HospitalEffect->Text.IsEmpty()) {
                fprintf(outFile3, "[政策]: 在 %4d 天，啟動「醫療體系」政策，", society.day);
                fprintf(outFile3, "降低死亡率效果: %6.4f，", Edit_HospitalEffect->Text.ToDouble());
                fprintf(outFile3, "就醫普及率: %6.4f。\n", Edit_HospitalAvailable->Text.ToDouble());
        }
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_GossipChange(TObject *Sender)
{
        if (CheckBox_OutputFile3->Checked)
                fprintf(outFile3, "[政策]: 在 %4d 天，Gossip次數變成每日 %d 次。\n", society.day, Edit_Gossip->Text.ToInt());
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Button_SmallWorldClick(TObject *Sender)
{
        long ID1, ID2;
        long maxPopulation = Edit_MaxPopulation->Text.ToInt();
        long maxHeight     = Edit_MaxWorldHeight->Text.ToInt();
        long maxWidth      = Edit_MaxWorldWidth->Text.ToInt();
        bool found;
        double avgDegree   = 0.;

        for (long count = Edit_Count->Text.ToInt(), i = 0; i < count; i++) {
                Memo_System->Lines->Append(AnsiString(i) + ":");
                do {} while (society.people[(ID1 = (long)_lrand() % maxPopulation)].count == 0);
                do {} while (society.people[(ID2 = (long)_lrand() % maxPopulation)].count == 0);

                Memo_System->Lines->Append("ID1 = " + AnsiString(ID1));
                for (long count = society.people[ID1].count, j = 0; j < count; j++)
                        Memo_System->Lines->Append("(x, y) = " + AnsiString(society.people[ID1].agent[j].location.x) + ", " + AnsiString(society.people[ID1].agent[j].location.y));
                Memo_System->Lines->Append("ID2 = " + AnsiString(ID2));
                for (long count = society.people[ID2].count, j = 0; j < count; j++)
                        Memo_System->Lines->Append("(x, y) = " + AnsiString(society.people[ID2].agent[j].location.x) + ", " + AnsiString(society.people[ID2].agent[j].location.y));

                for (long j = degree = 0; j < maxPopulation; relations[j] = neighbors[j] = false, j++);
                relations[ID1] = true;
                found = false;

                do {
                        ++degree;
                        for (long j = 0; !found && j < maxPopulation; j++)
                                if (relations[j]) {
                                        for (long maxAgent = society.people[j].count, k = 0; !found && k < maxAgent; k++) {
                                                long midY = society.people[j].agent[k].location.y;
                                                long midX = society.people[j].agent[k].location.x;
                                                for (long currY = midY - 1; !found && currY <= midY + 1; currY++) {
                                                        long locY = (currY + maxHeight) % maxHeight;
                                                        for (long currX = midX - 1; !found && currX <= midX + 1; currX++) {
                                                                long locX = (currX + maxWidth) % maxWidth;
                                                                if (locY != midY || locX != midX) {
                                                                        long nID = world[locY][locX].peopleID;
                                                                        if (nID == ID2) {
                                                                                found = true;
                                                                                break;
                                                                        }
                                                                        neighbors[nID] = true;
                                                                }
                                                        }
                                                }
                                        }
                                }
                        if (!found)
                                for (long k = 0; k < maxPopulation; relations[k] = neighbors[k], neighbors[k] = false, k++);
                } while (!found);
                avgDegree += degree;
                Memo_System->Lines->Append("degree = " + AnsiString(degree));
        }
        Memo_System->Lines->Append("avg. degree = " + AnsiString(avgDegree / Edit_Count->Text.ToInt()));
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::CheckBox_MedicalPolicyClick(TObject *Sender)
{
        if (!Edit_MedicalPolicyAvailable->Text.IsEmpty() && CheckBox_OutputFile3->Checked) {
                fprintf(outFile3, "[政策]: 在 %4d 天，%s「醫護人員戴口罩、手套與勤洗手」政策，", society.day, (CheckBox_MedicalPolicy->Checked ? "啟動" : "取消"));
                fprintf(outFile3, "疾病感染預防率: %6.4f，", Edit_MedicalPolicyEffect->Text.ToDouble());
                fprintf(outFile3, "政策貫測率: %6.4f。\n", Edit_MedicalPolicyAvailable->Text.ToDouble());
        }
        if (!CheckBox_MedicalPolicy->Checked)
                for (long MaxPopulation = Edit_MaxPopulation->Text.ToInt(), i = 0; i < MaxPopulation; society.people[i++].attr.policy[MEDICAL_POLICY] = false);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_MedicalPolicyEffectChange(TObject *Sender)
{
        CheckBox_MedicalPolicyClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::Edit_MedicalPolicyAvailableChange(TObject *Sender)
{
        CheckBox_MedicalPolicyClick(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TSARS_Form::SimulationTimerTimer(TObject *Sender)
{
        runSimulation();
}
//---------------------------------------------------------------------------

