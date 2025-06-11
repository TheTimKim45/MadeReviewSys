#include "MadeScore.h"

namespace MS
{
	MadeScore::ScoreUnit::ScoreUnit()
	{
		grade = 0;
		weight = 3;

	}

	MadeScore::MadeScore()
	{
		//Initial Game Score
		GameGrade = 0;
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
		float calcGrade = static_cast<float>(c1.weight * (c1.grade + 5));
		calcGrade += static_cast<float>(c2.weight * (c2.grade + 5));
		calcGrade += static_cast<float>(c3.weight * (c3.grade + 5));
		calcGrade /= static_cast<float>(c1.weight + c2.weight + c3.weight);
		calcGrade *= 10.f;
		divisionUnit.grade = static_cast<int>(calcGrade + 0.5f);
	}

	MadeScore::ResCode MadeScore::Set_CAT_Grade(const int newGrade, ScoreUnit& scoreUnit)
	{
		if (newGrade >= -5 && newGrade <= 5)
		{
			scoreUnit.grade = newGrade;
			return SUCCESS;
		}
		else
			return ERROR;
	}

	MadeScore::ResCode MadeScore::Set_CAT_Weight(const int newWeight, ScoreUnit& scoreUnit)
	{
		if (newWeight >= 0 && newWeight <= 5)
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
		if (newWeight >= 0 && newWeight <= 5)
		{
			divisionUnit.weight = newWeight;
			return SUCCESS;
		}
		else
			return ERROR;
	}
}
