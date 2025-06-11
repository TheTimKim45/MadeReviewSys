#pragma once

namespace MS
{
	class MadeScore
	{
	private:
		//Final Score
		int GameGrade;
		
		struct ScoreUnit
		{
			int s_grade;
			int s_weight;
			ScoreUnit();
		};

		enum ResCode
		{
			ERROR = -1,
			SUCCESS
		};

		//Divisions
		ScoreUnit GradeM, GradeA, GradeD, GradeE;
		//Categories
		ScoreUnit m_actions, m_controls, m_environment;
		ScoreUnit a_writing, a_audio, a_visuals;
		ScoreUnit d_performance, d_accessibility, d_experience;
		ScoreUnit e_barriers, e_extramediacontent, e_ethics;


	public:
		MadeScore();
		void CalculateFinalGrade();
		//Manipulators
		void Set_Division_Grade( ScoreUnit& c1,  ScoreUnit& c2,  ScoreUnit& c3, ScoreUnit& divisionUnit);
		ResCode Set_SU_Grade(const int newGrade, ScoreUnit& scoreUnit);
		ResCode Set_SU_Weight(const int newWeight, ScoreUnit& scoreUnit);
		ResCode Set_Division_Weight(const int newWeight, ScoreUnit& divisionUnit);
		//Accessors
		ScoreUnit& Get_M_C1() { return m_actions; } 
		ScoreUnit& Get_M_C2() { return m_controls; } 
		ScoreUnit& Get_M_C3() { return m_environment; } 
		ScoreUnit& Get_M() { return GradeM; } 

		ScoreUnit& Get_A_C1() { return a_writing; } 
		ScoreUnit& Get_A_C2() { return a_audio; } 
		ScoreUnit& Get_A_C3() { return a_visuals; } 
		ScoreUnit& Get_A() { return GradeA; } 

		ScoreUnit& Get_D_C1() { return d_performance; } 
		ScoreUnit& Get_D_C2() { return d_accessibility; } 
		ScoreUnit& Get_D_C3() { return d_experience; } 
		ScoreUnit& Get_D() { return GradeD; } 

		ScoreUnit& Get_E_C1() { return e_barriers; } 
		ScoreUnit& Get_E_C2() { return e_extramediacontent; } 
		ScoreUnit& Get_E_C3() { return e_ethics; } 
		ScoreUnit& Get_E() { return GradeE; } 
	};
}

