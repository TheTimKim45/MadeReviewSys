#include "MadeScore.h"
#include <string>
namespace MS
{
	MadeScore::ScoreDIV::ScoreDIV()
	{

	}

	MadeScore::ScoreCAT::ScoreCAT()
	{
	}

	MadeScore::MadeScore()
	{
		//Initial Game Score
		GameGrade = 0;
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

	MadeScore::ResCode MadeScore::Set_DIV_Grade(ScoreDIV& divisionUnit, const DivCat DivCode)
	{
		if (DivCode < M || DivCode > E)
			return ERROR;
		//MODULARITY:
		//Come back here and add an extra if needed
		std::string c1, c2, c3;
		if (DivCode == M)
		{
			c1 = M_C1;
			c2 = M_C2;
			c3 = M_C3;
		}
		else if (DivCode == A)
		{
			c1 = A_C1;
			c2 = A_C2;
			c3 = A_C3;
		}
		else if (DivCode == D)
		{
			c1 = D_C1;
			c2 = D_C2;
			c3 = D_C3;
		}
		else 
		{
			c1 = E_C1;
			c2 = E_C2;
			c3 = E_C3;
		}
		//Actual calc time
		float calcGrade = 0.f;
		calcGrade += static_cast<float>(divisionUnit.CAT[c1].weight * (divisionUnit.CAT[c1].grade + CAT_MUL1));
		calcGrade += static_cast<float>(divisionUnit.CAT[c2].weight * (divisionUnit.CAT[c2].grade + CAT_MUL1));
		calcGrade += static_cast<float>(divisionUnit.CAT[c3].weight * (divisionUnit.CAT[c3].grade + CAT_MUL1));
		calcGrade /= static_cast<float>(divisionUnit.CAT[c1].weight + divisionUnit.CAT[c2].weight + divisionUnit.CAT[c3].weight);
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

	void MadeScore::Print_Menu()
	{
		printf("FINAL SCORE: %d\n", GameGrade);
		printf("M : %d\n", GradeM.Grade);
		printf("A : %d\n", GradeA.Grade);
		printf("D : %d\n", GradeD.Grade);
		printf("E : %d\n", GradeE.Grade);
	}
}
