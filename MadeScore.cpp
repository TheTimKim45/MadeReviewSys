#include "MadeScore.h"
#include <string>
namespace MS
{
	MadeScore::ScoreDIV::ScoreDIV()
	{

	}

	MadeScore::ScoreDIV::ScoreDIV(std::initializer_list<std::pair<std::string, ScoreCAT>> items)
	{
		for (auto& p : items) 
			CAT[p.first] = p.second;
	}

	MadeScore::ScoreCAT::ScoreCAT()
	{
	}

	MadeScore::MadeScore()
	{
		//Initial Game Score
		GameGrade = 0;
		//Initial Game Title
		GameTitle = "";
		//CAT Details
		GradeM = ScoreDIV({
			{M_C1, ScoreCAT()},
			{M_C2, ScoreCAT()},
			{M_C3, ScoreCAT()}
			});
		GradeA = ScoreDIV({
			{A_C1, ScoreCAT()},
			{A_C2, ScoreCAT()},
			{A_C3, ScoreCAT()}
			});
		GradeD = ScoreDIV({
			{D_C1, ScoreCAT()},
			{D_C2, ScoreCAT()},
			{D_C3, ScoreCAT()}
			});
		GradeE = ScoreDIV({
			{E_C1, ScoreCAT()},
			{E_C2, ScoreCAT()},
			{E_C3, ScoreCAT()}
			});
		//CAT Vectors
		AGRCAT_M.resize(0);
		AGRCAT_A.resize(0);
		AGRCAT_D.resize(0);
		AGRCAT_E.resize(0);
	}

	void MadeScore::CalculateFinalGrade()
	{
		float calcGrade = ((GradeM.Grade * GradeM.Weight) +
			(GradeA.Grade * GradeA.Weight) +
			(GradeD.Grade * GradeD.Weight)) /
			(GradeM.Weight + GradeA.Weight + GradeD.Weight);
		GameGrade = static_cast<int>(calcGrade + 0.5f);
	}

	MadeScore::DivCat MadeScore::CalcDivCat(const int num)
	{
		if (num < 0 || num > 3)
			return M;
		else if (num == 0)
			return M;
		else if (num == 1)
			return A;
		else if (num == 2)
			return D;
		else
			return E;
	}

	MadeScore MadeScore::CombineDupTitles(const MadeScore newGameEntry)
	{
		
		for (auto& c : newGameEntry.AGRCAT_M)
			AGRCAT_M.push_back(c);
		for (auto& c : newGameEntry.AGRCAT_A)
			AGRCAT_A.push_back(c);
		for (auto& c : newGameEntry.AGRCAT_D)
			AGRCAT_D.push_back(c);
		for (auto& c : newGameEntry.AGRCAT_E)
			AGRCAT_E.push_back(c);

		return *this;
	}

	void MadeScore::CrunchTitleEntry(MadeScore& testScore)
	{
		
		//Actual Calculation Phase
		testScore.Set_DIV_Grade(testScore.Get_M(), testScore.CalcDivCat(0));
		testScore.Set_DIV_Grade(testScore.Get_A(), testScore.CalcDivCat(1));
		testScore.Set_DIV_Grade(testScore.Get_D(), testScore.CalcDivCat(2));
		testScore.Set_DIV_Grade(testScore.Get_E(), testScore.CalcDivCat(3));

		testScore.CalculateFinalGrade();
	}

	MadeScore::ResCode MadeScore::Set_DIV_Grade(ScoreDIV& divisionUnit, const DivCat DivCode)
	{
		if (DivCode < M || DivCode > E)
			return ERROR;
		//MODULARITY:
		//Come back here and add an extra if needed
		std::vector<MadeScore::ScoreCAT>* catScores;
		if (DivCode == M)
			catScores = &AGRCAT_M;
		else if (DivCode == A)
			catScores = &AGRCAT_A;
		else if (DivCode == D)
			catScores = &AGRCAT_D;
		else
			catScores = &AGRCAT_E;
		//Actual calc time
		float calcGrade = 0.f;
		int calcWeight = 0;
		for (auto& s : *catScores)
		{
			calcGrade += static_cast<float>(s.weight * (s.grade + CAT_MUL1));
			calcWeight += s.weight;
		}
		//ERROR CHECK : Cannot divide by 0
		if (calcWeight == 0)
		{
			calcWeight = 1;
		}
		if (calcWeight == 1 && calcGrade == 0)
		{
			calcGrade = CAT_MUL1;
		}
		calcGrade /= static_cast<float>(calcWeight);
		calcGrade *= CAT_MUL2;
		divisionUnit.Grade = static_cast<int>(calcGrade + 0.5f);
		return SUCCESS;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Grade(const int newGrade, ScoreCAT& scoreUnit)
	{
		if (newGrade >= MIN_GRADE && newGrade <= MAX_GRADE)
		{
			scoreUnit.grade = newGrade;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Weight(const int newWeight, ScoreCAT& scoreUnit)
	{
		if (newWeight >= MIN_WEIGHT && newWeight <= MAX_WEIGHT)
		{
			scoreUnit.weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Note(const std::string newNote, ScoreCAT& scoreUnit)
	{
		if (newNote.size() <= 0)
			return ERROR;
		scoreUnit.notes = newNote;
		return SUCCESS;
	}

	MadeScore::ResCode MadeScore::Set_DIV_Weight(const int newWeight, ScoreDIV& divisionUnit)
	{
		if (newWeight >= MIN_WEIGHT && newWeight <= MAX_WEIGHT)
		{
			divisionUnit.Weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_Game_Title(const char* newTitle)
	{
		if (newTitle == "")
			return ERROR;
		GameTitle = newTitle;
		return SUCCESS;
	}

	MadeScore::ResCode MadeScore::Add_To_AGRCAT(const ScoreDIV divUnit, const DivCat divCode)
	{
		if (divCode < M || divCode > E)
			return ERROR;
		else if (divUnit.CAT.size() == 0)
			return ERROR;
		if (divCode == M)
		{
			for (auto& m : divUnit.CAT)
				AGRCAT_M.push_back(m.second);
		}
		else if (divCode == A)
		{
			for (auto& a : divUnit.CAT)
				AGRCAT_A.push_back(a.second);
		}
		else if (divCode == D)
		{
			for (auto& d : divUnit.CAT)
				AGRCAT_D.push_back(d.second);
		}
		else
		{
			for (auto& e : divUnit.CAT)
				AGRCAT_E.push_back(e.second);
		}
		return SUCCESS;
	}

	void MadeScore::Print_Menu()
	{
		printf("FINAL SCORE: %d\n", GameGrade);
		printf("M : %d\n", GradeM.Grade);
		printf("A : %d\n", GradeA.Grade);
		printf("D : %d\n", GradeD.Grade);
		printf("E : %d\n", GradeE.Grade);
	}
}
