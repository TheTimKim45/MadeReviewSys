#include "MadeScore.h"

namespace MS
{
	MadeScore::ScoreUnit::ScoreUnit()
	{
		/*grade = 0;
		weight = 3;
		notes = "";*/
	}

	MadeScore::MadeScore()
	{
		//Initial Game Score
		GameGrade = 0;
		GradeM = ScoreUnit({
			{M_C1, ScoreUnit()},
			{M_C2, ScoreUnit()},
			{M_C3, ScoreUnit()}
			});
		GradeA = ScoreUnit({
			{A_C1, ScoreUnit()},
			{A_C2, ScoreUnit()},
			{A_C3, ScoreUnit()}
			});
		GradeD = ScoreUnit({
			{D_C1, ScoreUnit()},
			{D_C2, ScoreUnit()},
			{D_C3, ScoreUnit()}
			});
		GradeE = ScoreUnit({
			{E_C1, ScoreUnit()},
			{E_C2, ScoreUnit()},
			{E_C3, ScoreUnit()}
			});
	}

	void MadeScore::CalculateFinalGrade()
	{
		float calcGrade = ((GradeM.grade * GradeM.weight) +
			(GradeA.grade * GradeA.weight) +
			(GradeD.grade * GradeD.weight)) /
			(GradeM.weight + GradeA.weight + GradeD.weight);
		GameGrade = static_cast<int>(calcGrade + 0.5f);
	}

	void MadeScore::Set_DIV_Grade(ScoreUnit& c1, ScoreUnit& c2, ScoreUnit& c3, ScoreUnit& divisionUnit)
	{
		float calcGrade = static_cast<float>(c1.weight * (c1.grade + CAT_MUL1));
		calcGrade += static_cast<float>(c2.weight * (c2.grade + CAT_MUL1));
		calcGrade += static_cast<float>(c3.weight * (c3.grade + CAT_MUL1));
		calcGrade /= static_cast<float>(c1.weight + c2.weight + c3.weight);
		calcGrade *= CAT_MUL2;
		divisionUnit.grade = static_cast<int>(calcGrade + 0.5f);
	}

	MadeScore::ResCode MadeScore::Set_CAT_Grade(const int newGrade, ScoreUnit& scoreUnit)
	{
		if (newGrade >= MIN_GRADE && newGrade <= MAX_GRADE)
		{
			scoreUnit.grade = newGrade;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Weight(const int newWeight, ScoreUnit& scoreUnit)
	{
		if (newWeight >= MIN_WEIGHT && newWeight <= MAX_WEIGHT)
		{
			scoreUnit.weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Note(const std::string newNote, ScoreUnit& scoreUnit)
	{
		if (newNote.size() <= 0)
			return ERROR;
		scoreUnit.notes = newNote;
		return SUCCESS;
	}

	MadeScore::ResCode MadeScore::Set_DIV_Weight(const int newWeight, ScoreUnit& divisionUnit)
	{
		if (newWeight >= MIN_WEIGHT && newWeight <= MAX_WEIGHT)
		{
			divisionUnit.weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	void MadeScore::Print_Menu()
	{
		/*printf("%s\n", MENU_TITLE);
		printf("%s\n", MSG_01);
		printf("\n%s\n", SEL_ONE);
		printf("%s\n", SEL_TWO);*/
	}
}
