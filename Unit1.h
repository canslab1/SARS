//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#define MAX_CELL_HEIGHT          500
#define MAX_CELL_WIDTH           500
#define MAX_PEOPLE            250000
#define MAX_AGENT                 20
//---------------------------------------------------------------------------
#define NEIGHBORS_SIZE             9
#define STATE_SIZE                 8
#define AGENT_SELF                 4
#define EMPTY                     -1
#define STEP_SIZE               1000
#define MAX_MOVE_SIZE              8
#define MOVE_BASE                  2
#define MAX_GRAPHIC_DATA_SIZE    100
#define PARTIAL_CELL_SIZE          5
#define PARTIAL_LATTICE_SIZE     100
#define MAX_POLICY                10
#define ISOLATED                   6
#define QUARANTINED                7
#define MAX_VALUE_SIZE           365
//---------------------------------------------------------------------------
#define FACE_MASK                  0
#define TAKE_TEMPERATURE           1
#define STOP_VISITANT              2
#define VACCINE                    3
#define STOP_CONTACT               4
#define MEDICAL_POLICY             5
#define HOME                       8
#define HOSPITAL                   9
//---------------------------------------------------------------------------
#define DEFAULT_COLOR              (clSkyBlue)
#define SUSCEPTIBLE_COLOR          (DEFAULT_COLOR)
#define EXPOSED_COLOR              (DEFAULT_COLOR)
#define INFECTIVE_COLOR            (clRed)
#define RECOVERED_COLOR            (clSilver)
#define IMMUNE_COLOR               (DEFAULT_COLOR)
#define DIED_COLOR                 (clBlack)
#define INVISIBLE_COLOR            (clGray)
#define ISOLATED_COLOR             (DEFAULT_COLOR)
#define QUARANTINED_COLOR          (DEFAULT_COLOR)
//---------------------------------------------------------------------------
#define EXPOSED_PERIOD             (Edit_AvgExposedPeriod->Text.ToInt())
#define SYMPTOMATIC_PERIOD         (Edit_AvgSymptomaticPeriod->Text.ToInt())
#define INFECTIVE_PERIOD           (Edit_AvgInfectiousPeriod->Text.ToInt())
#define RECOVERED_PERIOD           (Edit_AvgRecoveredPeriod->Text.ToInt())
#define IMMUNE_PERIOD              (Edit_AvgAntibodyPeriod->Text.ToInt())
#define QUARANTINED_PERIOD         (Edit_QuarantinedPeriod->Text.ToInt())
//---------------------------------------------------------------------------
#define PAGE_CONTROL_1_MAIN_PAGE   0
#define PAGE_CONTROL_2_MAIN_PAGE   4
#define ISOLATED_CASE_PAGE         4
#define TOTAL_ISOLATED_CASE_PAGE   5
//---------------------------------------------------------------------------
#include <dir.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
//---------------------------------------------------------------------------
struct UCell
{
        long peopleID;
        long agentNo;
        TColor color;
};

enum UState {SUSCEPTIBLE = 0, EXPOSED = 1, INFECTIVE = 2, RECOVERED = 3, IMMUNE = 4, DIED = 5};

enum UAge {YOUNG_MAN, PRIME_MAN, OLD_MAN};

struct UAttribute
{
        bool immunity;
        bool super;
        long timer;
        UAge age;
        bool policy[MAX_POLICY];
        bool isolated;
        bool quarantined;
        long quarantinedCount;
        long quarantinedLevel;
};

struct UAgent
{
        long no;
        bool visible;
        bool home;
        POINT location;
};

struct UPeople
{
        long ID;
        UState state;
        long count;
        long limit;
        UAttribute attr;
        UAgent agent[MAX_AGENT];
};

struct USociety
{
        long day;
        UPeople people[MAX_PEOPLE];
};

struct UMeasure
{
        long size, value1[MAX_VALUE_SIZE][STATE_SIZE];
        double value2[MAX_VALUE_SIZE][STATE_SIZE];
};
//---------------------------------------------------------------------------
class TSARS_Form : public TForm
{
__published:
        TStatusBar *StatusBar;
        TPageControl *PageControl2;
        TTabSheet *TabSheet_Population;
        TTabSheet *TabSheet_Disease;
        TTabSheet *TabSheet_PolicySegment1;
        TPanel *Panel_Policies;
        TCheckBox *CheckBox_Mask;
        TEdit *Edit_MaskEffect;
        TEdit *Edit_TempEffect;
        TCheckBox *CheckBox_Temp;
        TCheckBox *CheckBox_Home;
        TRadioButton *RadioButton_IsolatedLevelA;
        TRadioButton *RadioButton_IsolatedLevelB;
        TEdit *Edit_QuarantinedPeriod;
        TLabel *Label_HomePeriod;
        TPanel *Panel_Disease;
        TEdit *Edit_MortalityOldMan;
        TEdit *Edit_MortalityPrimeMan;
        TEdit *Edit_TransmissionProb;
        TEdit *Edit_ImmuneProb;
        TEdit *Edit_AvgSymptomaticPeriod;
        TEdit *Edit_AvgRecoveredPeriod;
        TLabel *Label_AvgRecoveredPeriod;
        TLabel *Label_AvgSymptomaticPeriod;
        TLabel *Label_ImmuneProb;
        TLabel *Label_TransmissionProb;
        TLabel *Label_MortalityPrimeMan;
        TLabel *Label_MortalityOldMan;
        TEdit *Edit_AvgExposedPeriod;
        TLabel *Label_AvgExposedPeriod;
        TPanel *Panel_Population;
        TLabel *Label_PopulationRateOldMan;
        TEdit *Edit_PopulationRateOldMan;
        TPageControl *PageControl1;
        TTabSheet *TabSheet_Lattice;
        TTabSheet *TabSheet_Zoom;
        TImage *Lattice;
        TButton *Button_Exit;
        TButton *Button_Create;
        TButton *Button_NewCase;
        TEdit *Edit_NewCase;
        TLabel *Label_Person;
        TButton *Button_Run;
        TEdit *Edit_Period;
        TLabel *Label_Day;
        TMemo *MemoStatus;
        TProgressBar *ProgressBar;
        TRadioButton *RadioButton_Exposed;
        TRadioButton *RadioButton_Infective;
        TButton *Button_West;
        TButton *Button_North;
        TButton *Button_Middle;
        TButton *Button_East;
        TButton *Button_South;
        TButton *Button_Termination;
        TLabel *Label_MaskAvailable;
        TEdit *Edit_MaskAvailable;
        TLabel *Label_TempAvailable;
        TEdit *Edit_TempAvailable;
        TLabel *Label_Home;
        TEdit *Edit_HomeAvailable;
        TTabSheet *TabSheet_System;
        TTabSheet *TabSheet_Environment;
        TPanel *Panel_Environment;
        TPanel *Panel_System;
        TEdit *Edit_Gossip;
        TLabel *Label_Active;
        TEdit *Edit_MortalityYoungMan;
        TLabel *Label_MortalityYoungMan;
        TLabel *Label_PopulationRateYoungMan;
        TEdit *Edit_PopulationRateYoungMan;
        TLabel *Label_AvgInfectiousPeriod;
        TEdit *Edit_AvgInfectiousPeriod;
        TLabel *Label_DetectRate;
        TEdit *Edit_DetectRate;
        TLabel *Label_AvgAntiBodyPeriod;
        TEdit *Edit_AvgAntibodyPeriod;
        TImage *partialLattice;
        TTabSheet *TabSheet_TotalCase;
        TChart *TotalCase_Chart;
        TLineSeries *Series_TotalInfectiveCase;
        TTabSheet *TabSheet_Case;
        TChart *Case_Chart;
        TLineSeries *Series_TotalExposedCase;
        TLineSeries *Series_TotalRecoveredCase;
        TLineSeries *Series_TotalImmuneCase;
        TLineSeries *Series_TotalDiedCase;
        TLineSeries *Series_ExposedCase;
        TLineSeries *Series_RecoveredCase;
        TLineSeries *Series_ImmuneCase;
        TLineSeries *Series_DiedCase;
        TButton *Button_Print;
        TButton *Button_Save;
        TEdit *Edit_FileName;
        TLabel *Label_FileName;
        TBarSeries *Series_InfectiveCase;
        TCheckBox *CheckBox_Hospital;
        TEdit *Edit_HospitalAvailable;
        TLabel *Label_HospitalAvailable;
        TLabel *Label_HospitalEffect;
        TEdit *Edit_HospitalEffect;
        TLabel *Label_HomeLevel;
        TTabSheet *TabSheet_IsolatedCase;
        TChart *IsolatedCase_Chart;
        TBarSeries *Series_IsolatedCase;
        TLineSeries *Series_TotalIsolatedCase;
        TLineSeries *Series_IsolatedCase2;
        TLabel *Label_TempEffect;
        TLabel *Label_MaskEffect;
        TLabel *Label_Vaccine;
        TLabel *Label3;
        TCheckBox *CheckBox_TraceOn;
        TCheckBox *CheckBox_TraceOff;
        TEdit *Edit_PeopleState;
        TLabel *Label_PeopleState;
        TBarSeries *Series_InfectiveCase2;
        TTabSheet *TabSheet_TotalQuarantinedCase;
        TChart *TotalQuarantinedCase_Chart;
        TLineSeries *Series_TotalQuarantinedCase;
        TTabSheet *TabSheet_QuarantinedCase;
        TChart *QuarantinedCase_Chart;
        TBarSeries *Series_QuarantinedCase;
        TCheckBox *CheckBox_Super;
        TLabel *Label_MaxPopulation;
        TEdit *Edit_MaxPopulation;
        TLabel *Label_MaxAgent;
        TEdit *Edit_MaxAgent;
        TLabel *Label1;
        TRadioButton *RadioButton_Fixed;
        TRadioButton *RadioButton_Floating;
        TLabel *Label_SuperRate;
        TEdit *Edit_SuperRate;
        TLabel *Label_WorldHeight;
        TEdit *Edit_MaxWorldHeight;
        TEdit *Edit_MaxWorldWidth;
        TLabel *Label_WorldWidth;
        TCheckBox *CheckBox_OutputFile2;
        TCheckBox *CheckBox_OutputFile3;
        TLineSeries *Series_AverageCount;
        TButton *Button_Clear;
        TEdit *Edit_AverageCount;
        TLabel *Label_AverageCount;
        TCheckBox *CheckBox_OutputFile4;
        TTabSheet *TabSheet_InfectedCase;
        TChart *InfectedCase_Chart;
        TBarSeries *Series_InfectedByNormal;
        TBarSeries *Series_InfectedByHospital;
        TLabel *Label_InfectedByNormal;
        TLabel *Label_InfectedByHospital;
        TLabel *Label_Infected;
        TEdit *Edit_InfectedByNormal;
        TEdit *Edit_InfectedByHospital;
        TEdit *Edit_InfectedByNormalRate;
        TEdit *Edit_InfectedByHospitalRate;
        TTabSheet *TabSheet_SmallWorld;
        TPanel *Panel_SmallWorld;
        TLabel *Label_Count;
        TButton *Button_SystemWorld;
        TMemo *Memo_System;
        TEdit *Edit_Count;
        TCheckBox *CheckBox_OutputFile1;
        TMemo *Memo_Population;
        TTabSheet *TabSheet_PolicySegment2;
        TPanel *Panel1;
        TCheckBox *CheckBox_Contact;
        TLabel *Label_ContactAvailable;
        TEdit *Edit_ContactAvailable;
        TCheckBox *CheckBox_InputAsWellAsRun;
        TButton *Button_Vaccine;
        TEdit *Edit_VaccineAvailable;
        TLabel *Label_VaccineEffect;
        TCheckBox *CheckBox_VaccineForever;
        TCheckBox *CheckBox_VaccinePeriod;
        TCheckBox *CheckBox_MedicalPolicy;
        TLabel *Label_MedicalPolicyEffect;
        TEdit *Edit_MedicalPolicyEffect;
        TEdit *Edit_MedicalPolicyAvailable;
        TLabel *Label_MedicalPolicyAvailable;
        TCheckBox *CheckBox_Visit;
        TLabel *Label_Visit;
        TEdit *Edit_VisitAvailable;
        TTimer *SimulationTimer;
        TButton *Button_Stop;

        void __fastcall FormCreate(TObject *Sender);

        void __fastcall Button_ExitClick(TObject *Sender);
        void __fastcall Button_CreateClick(TObject *Sender);
        void __fastcall Button_TerminationClick(TObject *Sender);
        void __fastcall Button_NewCaseClick(TObject *Sender);
        void __fastcall Button_RunClick(TObject *Sender);
        void __fastcall Button_MiddleClick(TObject *Sender);
        void __fastcall Button_NorthClick(TObject *Sender);
        void __fastcall Button_SouthClick(TObject *Sender);
        void __fastcall Button_WestClick(TObject *Sender);
        void __fastcall Button_EastClick(TObject *Sender);
        void __fastcall partialLatticeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
        void __fastcall LatticeMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall LatticeMouseMove(TObject *Sender, TShiftState Shift, int X, int Y);
        void __fastcall TabSheet_TotalCaseShow(TObject *Sender);
        void __fastcall TabSheet_ZoomShow(TObject *Sender);
        void __fastcall TabSheet_LatticeShow(TObject *Sender);
        void __fastcall TabSheet_CaseShow(TObject *Sender);
        void __fastcall Button_PrintClick(TObject *Sender);
        void __fastcall Button_SaveClick(TObject *Sender);
        void __fastcall CheckBox_MaskClick(TObject *Sender);
        void __fastcall Edit_MaskAvailableChange(TObject *Sender);
        void __fastcall CheckBox_HospitalClick(TObject *Sender);
        void __fastcall Edit_HospitalAvailableChange(TObject *Sender);
        void __fastcall TabSheet_IsolatedCaseShow(TObject *Sender);
        void __fastcall CheckBox_TempClick(TObject *Sender);
        void __fastcall Edit_TempAvailableChange(TObject *Sender);
        void __fastcall CheckBox_VisitClick(TObject *Sender);
        void __fastcall Edit_VisitAvailableChange(TObject *Sender);
        void __fastcall CheckBox_VaccineForeverClick(TObject *Sender);
        void __fastcall CheckBox_VaccinePeriodClick(TObject *Sender);
        void __fastcall Button_VaccineClick(TObject *Sender);
        void __fastcall CheckBox_HomeClick(TObject *Sender);
        void __fastcall Edit_HomeAvailableChange(TObject *Sender);
        void __fastcall CheckBox_TraceOnClick(TObject *Sender);
        void __fastcall CheckBox_TraceOffClick(TObject *Sender);
        void __fastcall CheckBox_ContactClick(TObject *Sender);
        void __fastcall RadioButton_IsolatedLevelAClick(TObject *Sender);
        void __fastcall RadioButton_IsolatedLevelBClick(TObject *Sender);
        void __fastcall Button_ClearClick(TObject *Sender);
        void __fastcall Edit_MaskEffectChange(TObject *Sender);
        void __fastcall Edit_TempEffectChange(TObject *Sender);
        void __fastcall Edit_QuarantinedPeriodChange(TObject *Sender);
        void __fastcall Edit_HospitalEffectChange(TObject *Sender);
        void __fastcall Edit_GossipChange(TObject *Sender);
        void __fastcall Button_SmallWorldClick(TObject *Sender);
        void __fastcall Edit_ContactAvailableChange(TObject *Sender);
        void __fastcall CheckBox_MedicalPolicyClick(TObject *Sender);
        void __fastcall Edit_MedicalPolicyEffectChange(TObject *Sender);
        void __fastcall Edit_MedicalPolicyAvailableChange(TObject *Sender);
        void __fastcall Button_StopClick(TObject *Sender);
        void __fastcall SimulationTimerTimer(TObject *Sender);
private:
        void initMeasure(void);
        void initVariables(void);
        void initComponents(void);
        void initLatticeComponent(void);
        void initPartialLatticeComponent(void);
        void initOtherComponents(void);
        bool initOutputFiles(void);
        void initWorld(void);
        void initSociety(TObject *Sender);
        void initPolicies(TObject *Sender);
        void initPeople(long ID);
        void initAttribute(long ID, UState state);
        void initAgents(long ID);
        void initAgent(long ID, long no);

        void resetWorld(void);
        void generateDistributedAgents(void);
        void runSimulation(void);
        void backupStatistic(void);
        double getTransmissionRate(long ID, long no, long gID, long gNo);
        double getDiedRate(long ID);

        void changeSociety(void);
        void changePeople(long ID);
        void quarantinePeopleByOngoing(long ID, UState state);
        void changePeopleByOngoing(long ID, UState state);
        void isolatePeopleByHospital(long ID, UState state, long timer);
        void changePeopleByGossip(long ID);
        bool changeAgentByGossip(long ID, long no);
        bool touchOtherAgent(long ID, long no);
        void changeGraphicData(void);
        void traceContactPeople(long ID, long level);
        void startMedicalPolicy(long ID);
        void finishMedicalPolicy(long ID);

        TColor getColor(UState state);
        AnsiString getStateCode(UState state, bool isolated, bool quarantined);

        void drawLattice(void);
        void drawGrid(long x, long y, TColor color);
        void drawPartialLattice(POINT partialView);

        void showMsg(AnsiString msg);
        void showStatus(void);
        void showResult(void);
        void showMainPage(void);
        void showStatusBar(long x, long y, long ID);
        void outputResult(void);

        void enableComponents(void);
        void disableComponents(void);
        void enablePrintAndSaveButtons(void);
        void disablePrintAndSaveButtons(void);
        void visiblePrintAndSaveButtons(void);
        void invisiblePrintAndSaveButtons(void);
        void visiblePeopleStateComponents(void);
        void invisiblePeopleStateComponents(void);

        USociety society;
        UCell world[MAX_CELL_HEIGHT][MAX_CELL_WIDTH];
        UMeasure measure;

        long oldStatistic[STATE_SIZE], statistic[STATE_SIZE];
        long serial, infectedByHospital, infectedByNormal;
        POINT partialView;
        FILE *outFile1, *outFile2, *outFile3, *outFile4;


        long degree;
        bool relations[MAX_PEOPLE], neighbors[MAX_PEOPLE];        
public:
        __fastcall TSARS_Form(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSARS_Form *SARS_Form;
//---------------------------------------------------------------------------

#endif
