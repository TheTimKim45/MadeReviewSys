#pragma once
#include <iostream>
#include <unordered_map>
//precompiler MACROS
//MAIN MACROS
#define MIN_WEIGHT	0
#define MAX_WEIGHT	5
#define MIN_GRADE	-5
#define MAX_GRADE	5
//SUB-DIV CATS
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
		
		struct ScoreUnit
		{
			std::unordered_map < std::string, ScoreUnit> CAT;
			int grade = 0;
			int weight = 3;
			std::string notes = "";
			ScoreUnit();
			ScoreUnit(std::initializer_list < std::pair < std::string, ScoreUnit>> items) { for (auto& p : items) CAT[p.first] = p.second; };
		};

		enum ResCode
		{
			ERROR = -1,
			SUCCESS
		};

		//Divisions
		ScoreUnit GradeM, GradeA, GradeD, GradeE;
		//Categories
		/*ScoreUnit m_actions, m_controls, m_environment;
		ScoreUnit a_writing, a_audio, a_visuals;
		ScoreUnit d_performance, d_accessibility, d_experience;
		ScoreUnit e_barriers, e_extramediacontent, e_ethics;*/

	public:
		MadeScore();
		void CalculateFinalGrade();
		//Manipulators
		void Set_DIV_Grade( ScoreUnit& c1,  ScoreUnit& c2,  ScoreUnit& c3, ScoreUnit& divisionUnit);
		ResCode Set_CAT_Grade(const int newGrade, ScoreUnit& scoreUnit);
		ResCode Set_CAT_Weight(const int newWeight, ScoreUnit& scoreUnit);
		ResCode Set_CAT_Note(const std::string newNote, ScoreUnit& scoreUnit);
		ResCode Set_DIV_Weight(const int newWeight, ScoreUnit& divisionUnit);
		//Accessors
		ScoreUnit& Get_M() { return GradeM; } 
		ScoreUnit& Get_M_C1() { return GradeM.CAT[M_C1]; }
		ScoreUnit& Get_M_C2() { return GradeM.CAT[M_C2]; }
		ScoreUnit& Get_M_C3() { return GradeM.CAT[M_C3]; }

		ScoreUnit& Get_A() { return GradeA; }
		ScoreUnit& Get_A_C1() { return GradeA.CAT[A_C1]; }
		ScoreUnit& Get_A_C2() { return GradeA.CAT[A_C2]; }
		ScoreUnit& Get_A_C3() { return GradeA.CAT[A_C3]; }

		ScoreUnit& Get_D() { return GradeD; }
		ScoreUnit& Get_D_C1() { return GradeD.CAT[D_C1]; }
		ScoreUnit& Get_D_C2() { return GradeD.CAT[D_C2]; }
		ScoreUnit& Get_D_C3() { return GradeD.CAT[D_C3]; }

		ScoreUnit& Get_E() { return GradeE; }
		ScoreUnit& Get_E_C1() { return GradeE.CAT[E_C1]; }
		ScoreUnit& Get_E_C2() { return GradeE.CAT[E_C2]; }
		ScoreUnit& Get_E_C3() { return GradeE.CAT[E_C3]; }
		//Displayers - printf stuff
		void Print_Menu();
		//Menu Simulation
	};
}

