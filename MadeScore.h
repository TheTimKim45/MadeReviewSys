#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
//precompiler MACROS
//MAIN MACROS
#define MIN_WEIGHT	0
#define MAX_WEIGHT	5
#define MIN_GRADE	-5
#define MAX_GRADE	5
//SUB-DIV CATS <-- MODULARITY POINT
#define NUM_CATS	3

#define M_C1	"actions"
#define M_C2	"controls"
#define M_C3	"environment"

#define A_C1	"writing"
#define A_C2	"audio"
#define A_C3	"visuals"

#define D_C1	"performance"
#define D_C2	"accessibility"
#define D_C3	"experience"

#define E_C1	"barriers"
#define E_C2	"extramedia content"
#define E_C3	"ethics"

#define CAT_MUL1	5
#define CAT_MUL2	10.f
namespace MS
{
	class MadeScore
	{
	private:
		//Final Score
		int GameGrade;
		//Game Title
		std::string GameTitle;

		//Further Modulation
		//MODULARITY POINT-
		//Should we desire the capability of creating aggregate scoring
		//WE MUST create a std::vector of different ScoreCATs based off of their respective ScoreDIV
		//EXAMPLE:
		//ScoreDIV GradeM.CAT -> std::vector<ScoreCAT> DIVCATS_M
		//WHEN Set_DIV_Grade is called, we then ACCESS DIVCATS specifically
		//NOTE: REMEMBER, these are only used locally on the machine, NOT database interaction
		//From there, when we call Set_DIV_Grade:
		// float calcGrade = 0.f
		// int calcDivide = 0;
		//for(auto& cat : DIVCATS)
		//{
		//	calcGrade += static_cast<float>(cat.weight * (cat.graade + CAT_MULT1));
		//	calcDivide += cat.weight;
		//}
		//calcGrade /= static_cast<float>(calcDivide);
		//calcGrade *= 10.f;
		//THIS would then make the Set_DIV_Grade into a more modular function BUT
		//To make this work, we need to ensure that each ScoreDIV is able to unload ALL of its CAT content into the std::vector<ScoreCAT> FIRST
		//and BEFORE THAT: we need to make sure that the program is able to understand that if there are multiple titles with the SAME NAME
		//We must ensure that the system is able to unload and APPEND to the pre-existing std::vector<ScoreCAT>, NOT create a new one
		//For Display Purposes:
		//We must ensure that under ONE TITLE, different reviews will ONLY show reviewer-specific grade, weight, and notes
		//Division Grade and Overall Grade will be unified under the "Title Header"

		struct ScoreCAT
		{
			int grade = 0;
			int weight = 3;
			std::string notes = "";
			ScoreCAT();
		};

		struct ScoreDIV
		{
			std::unordered_map < std::string, ScoreCAT> CAT;
			int Grade = 0;
			int Weight = 3;
			ScoreDIV();
			ScoreDIV(std::initializer_list < std::pair < std::string, ScoreCAT>> items);
		};

		enum ResCode
		{
			ERROR = -1,
			SUCCESS
		};

		enum DivCat
		{
			M = 0,
			A,
			D,
			E
		};

		//Divisions
		ScoreDIV GradeM, GradeA, GradeD, GradeE;
		//Cat Vectors
		std::vector<ScoreCAT> AGRCAT_M, AGRCAT_A, AGRCAT_D, AGRCAT_E;
		//Cat Tracker
		int catNum = 1;

	public:
		//Ctor
		MadeScore();
		//Calculators
		void CalculateFinalGrade();
		DivCat CalcDivCat(const int num);
		MadeScore CombineDupTitles(const MadeScore newGameEntry);
		void CrunchTitleEntry(MadeScore& testScore);
		//Manipulators
		ResCode Set_DIV_Grade(ScoreDIV& divisionUnit, const DivCat DivCode);
		ResCode Set_CAT_Grade(const int newGrade, ScoreCAT& scoreUnit);
		ResCode Set_CAT_Weight(const int newWeight, ScoreCAT& scoreUnit);
		ResCode Set_CAT_Note(const std::string newNote, ScoreCAT& scoreUnit);
		ResCode Set_DIV_Weight(const int newWeight, ScoreDIV& divisionUnit);
		ResCode Set_Game_Title(const char* newTitle);
		ResCode Add_To_AGRCAT(const ScoreDIV divUnit, const DivCat divCode);
		//Accessors
		ScoreDIV& Get_M() { return GradeM; } 
		ScoreCAT& Get_M_C1() { return GradeM.CAT[M_C1]; }
		ScoreCAT& Get_M_C2() { return GradeM.CAT[M_C2]; }
		ScoreCAT& Get_M_C3() { return GradeM.CAT[M_C3]; }

		ScoreDIV& Get_A() { return GradeA; }
		ScoreCAT& Get_A_C1() { return GradeA.CAT[A_C1]; }
		ScoreCAT& Get_A_C2() { return GradeA.CAT[A_C2]; }
		ScoreCAT& Get_A_C3() { return GradeA.CAT[A_C3]; }

		ScoreDIV& Get_D() { return GradeD; }
		ScoreCAT& Get_D_C1() { return GradeD.CAT[D_C1]; }
		ScoreCAT& Get_D_C2() { return GradeD.CAT[D_C2]; }
		ScoreCAT& Get_D_C3() { return GradeD.CAT[D_C3]; }

		ScoreDIV& Get_E() { return GradeE; }
		ScoreCAT& Get_E_C1() { return GradeE.CAT[E_C1]; }
		ScoreCAT& Get_E_C2() { return GradeE.CAT[E_C2]; }
		ScoreCAT& Get_E_C3() { return GradeE.CAT[E_C3]; }

		int Get_GameGrade() { return GameGrade; };
		std::string Get_GameTitle() { return GameTitle; };
		//Displayers - printf stuff
		void Print_Menu();
		//Menu Simulation
	};
}

