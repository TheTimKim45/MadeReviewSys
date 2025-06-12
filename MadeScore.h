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
			ScoreDIV(std::initializer_list < std::pair < std::string, ScoreCAT>> items) { for (auto& p : items) CAT[p.first] = p.second; };
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

	public:
		//Ctor
		MadeScore();
		//Calculators
		void CalculateFinalGrade();
		DivCat CalcDivCat(const int num);
		//Manipulators
		ResCode Set_DIV_Grade(ScoreDIV& divisionUnit, const DivCat DivCode);
		ResCode Set_CAT_Grade(const int newGrade, ScoreCAT& scoreUnit);
		ResCode Set_CAT_Weight(const int newWeight, ScoreCAT& scoreUnit);
		ResCode Set_CAT_Note(const std::string newNote, ScoreCAT& scoreUnit);
		ResCode Set_DIV_Weight(const int newWeight, ScoreDIV& divisionUnit);
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
		//Displayers - printf stuff
		void Print_Menu();
		//Menu Simulation
	};
}

